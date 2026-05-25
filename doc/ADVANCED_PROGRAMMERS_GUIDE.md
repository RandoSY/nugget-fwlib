# Advanced Programmer's Guide

## Intent and Architecture Reference for `nugget-fwlib`

`nugget-fwlib` is not intended to be merely a collection of GCBASIC snippets. It is a small, teaching-first firmware framework for turning low-cost PIC16F18424 programs into readable, reusable, protocol-speaking instruments.

The programmer should understand the central intent before adding code:

```text
working circuit behavior
→ named software behavior
→ reusable include file
→ example program
→ serial/GSA report
→ dashboard-ready instrument
```

The library exists to make embedded behavior visible, explainable, and repeatable.

## Why the px-fwlib Pattern Was Chosen

The organization of `nugget-fwlib` was inspired by the architecture discipline of `px-fwlib`, not by copying its implementation language or scale.

`px-fwlib` is a portable bare-metal C firmware and documentation library for microcontrollers. Its repository separates concerns into folders such as architecture support, board support, common services, communications, data handling, devices, documentation, tools, and utilities. Its public goals include teaching good firmware development practices, publishing quick-start guides, providing a standard framework and drivers, and minimizing porting by using unified peripheral APIs.

That same pattern is valuable here because the Nugget/REDBOARD work has the same structural problem at a smaller educational scale:

```text
How do we keep small embedded programs from becoming scattered, one-off examples?
```

The answer is to separate:

```text
chip facts
board facts
behavior classes
device drivers
protocol text
examples
host tools
documentation
```

## What Is Different from px-fwlib

`nugget-fwlib` is deliberately smaller and more transparent.

`px-fwlib` is a professional bare-metal C framework intended for portability across many targets. `nugget-fwlib` is a GCBASIC teaching framework centered first on PIC16F18424 / REDBOARD / PIC Black Box work.

The goal is not maximum abstraction. The goal is understandable abstraction.

A good `nugget-fwlib` routine should be:

```text
small enough to read
specific enough to compile
named clearly enough to teach
reusable enough to justify being a library
```

## Core Design Principle

Do not hide magic. Name behavior.

Bad library design for this project:

```text
A mysterious include file makes the circuit work.
```

Good library design:

```text
RB_SW1_InitPullup explains that RA0 is a switch-to-ground input with a weak pull-up.
RB_SW1_PressedEvent explains that voltage transition became a one-shot human event.
RB_LED_Status_Toggle explains that a software action became visible output.
RB_ADC_ReadAverage_AN2 explains that repeated analog samples became one stable number.
```

The user of the library should be able to open the include file and understand the chain from electricity to software behavior.

## Library Layers

### 1. Architecture Layer: `arch/`

This layer contains chip-specific facts.

For example:

```text
arch/pic16f1/pic16f18424/rb_chip_16f18424.inc
```

This is where compile-proven facts belong:

```gcb
ANSELA = 0
ANSELC = 0
```

This is also where rejected local assumptions are documented:

```gcb
' Do not assume ANSELB exists in this profile.
' Do not assume OPTION_REG.WPUEN exists in this profile.
' Do not assume WPUEN exists in this profile.
```

The architecture layer is the place for chip reality, not teaching prose alone.

### 2. Board Layer: `boards/`

This layer defines the REDBOARD convention.

Example board facts:

```text
SW1 = RA0, switch-to-ground
STATUS LED = RC0, active-high
ADC demo input = RA2 / AN2
```

The board layer should answer:

```text
What physical board are we talking about?
Where are the useful pins?
What names do we give to classroom-visible hardware?
```

### 3. GPIO and Human I/O Layer: `gpio/`

This layer converts pin operations into named behaviors:

```text
LED on
LED off
LED toggle
switch pressed
switch released
debounced press
one-shot pressed event
toggle latch
```

This is where the library first becomes pedagogically powerful. A raw pin read becomes a named human action.

```text
PORTA.0 = 0
```

becomes:

```text
SW1 is pressed.
```

### 4. Timing Layer: `timing/`

This layer should eventually contain:

```text
delays
stopwatch behavior
periodic ticks
heartbeat services
non-blocking timing patterns
cooperative scheduler helpers
```

Timing is the bridge from static logic to measurement.

### 5. Analog Layer: `analog/`

This layer handles ADC and pseudo-DAC behavior.

The ADC layer converts outside voltage into number.

```text
physical voltage → ADC count → scaled value → reportable measurement
```

For the present PIC16F18424 baseline, AN2 / RA2 is the default demonstration channel.

### 6. Communications Layer: `comms/`

This layer contains UART and GSA text helpers.

The communication layer should keep the PIC small and deterministic. It should not attempt desktop-style parsing or JSON-heavy behavior.

Preferred tiny protocol style:

```text
HELLO
STATUS
START
STOP
TARE
READ
```

Preferred response style:

```text
ID NUGGET-REDBOARD PIC16F18424 FW=0.1.1
OK STATUS READY
OK START
DATA ADC 512
ERR BAD_CMD
```

This is the moment the PIC becomes a GSA endpoint.

### 7. Data Layer: `data/`

This layer holds small text and formatting helpers:

```text
line buffers
CSV output
key=value output
small command strings
```

The data layer should remain conservative. The PIC should handle short, predictable lines, not unbounded strings.

### 8. Devices Layer: `devices/`

This layer should hold reusable wrappers for classroom devices:

```text
HX711 mass sensing
HC-SR04 distance timing
DS18B20 temperature
RGB / R&G show
```

A device driver should expose behavior, not just low-level pin wiggles.

Example:

```text
RB_HX711_IsReady
RB_HX711_ReadRaw
RB_HX711_Tare
RB_HX711_ReportGSA
```

### 9. Diagnostics Layer: `diagnostics/`

This layer should help the machine explain itself.

Examples:

```text
blink code
fault code
self-test
sensor missing
button stuck
bad command
line too long
```

Good embedded teaching devices should not simply fail. They should report how they failed.

### 10. Examples Layer: `examples/`

Examples are not throwaways. They are executable tutorials.

Each example should answer:

```text
What behavior is demonstrated?
What hardware is assumed?
What library files are used?
What should the student see?
What should appear on serial output?
```

A good example is a tested story.

### 11. Tools Layer: `tools/`

Host-side tools complete the GSA loop.

Examples:

```text
Web Serial dashboard
Python serial logger
test command script
CSV collector
```

The firmware should be designed so a small host tool can verify it.

## Behavior Classes

The library should be organized around behavior classes, not hardware trivia alone.

Important behavior classes include:

```text
GPIO behavior
switch input behavior
timer behavior
ADC behavior
pseudo-DAC / PWM behavior
UART behavior
GSA string handling
I2C / two-wire transaction behavior
sensor behavior
diagnostic behavior
cooperative multitasking behavior
state-machine behavior
```

This is the conceptual grammar of the library.

## The Golden Development Rule

Never generalize before one concrete program compiles.

Use this path:

```text
1. Write a self-contained program.
2. Compile it.
3. Extract one behavior into an include file.
4. Compile again.
5. Extract the next behavior.
6. Compile again.
7. Only then promote the behavior into the main library tree.
```

This rule prevents the library from becoming beautiful but unbuildable.

## Known v0.1.1 Lesson

The first real hardening lesson came from `020_full_tiny_gsa_node`.

The generated seed assumed some generic PIC register names:

```gcb
ANSELB = 0
OPTION_REG.WPUEN = 0
WPUEN = 0
```

The local PIC16F18424 / GCBASIC compile rejected those assumptions.

The compile-proven baseline used:

```gcb
ANSELA = 0
ANSELC = 0
WPUA.0 = 1
```

That lesson is now architectural:

```text
The chip profile must contain only compile-proven chip facts.
The board profile must not invent chip facts.
Examples must prefer direct includes until the master include path is proven.
```

## Direct Includes vs. Master Include

During early hardening, direct includes are preferred:

```gcb
#include "../../arch/pic16f1/pic16f18424/rb_chip_16f18424.inc"
#include "../../gpio/rb_switch.inc"
#include "../../gpio/rb_led.inc"
#include "../../analog/rb_adc.inc"
```

This is more verbose, but it makes the dependency chain visible.

The master include:

```gcb
#include "../../nugget_fwlib_all.inc"
```

should be used only after it is locally proven. Convenience must not come before transparency.

## Naming Rules

Use names that reveal intent:

```text
RB_Core_Init
RB_SW1_InitPullup
RB_SW1_PressedEvent
RB_LED_Status_Toggle
RB_ADC_ReadAverage_AN2
RB_GSA_SendDataInt
```

Avoid names that hide the classroom meaning:

```text
DoThing
Setup1
HandleIt
MagicRead
```

Recommended pattern:

```text
RB_<behavior area>_<object>_<action>
```

Examples:

```text
RB_SW1_PressedEvent
RB_LED_Status_Off
RB_ADC_ReadAverage_AN2
```

## GCBASIC Style Discipline

This project should prefer the locally compile-proven style:

```gcb
RB_Core_Init
RB_SW1_InitPullup
RB_LED_Status_Toggle
```

instead of zero-argument calls with parentheses.

For functions with arguments, use the normal function style:

```gcb
Value = RB_ADC_ReadAverage_AN2(8)
```

Avoid mixing styles until the compiler has proven them.

## How to Extend the Library

When adding a new module, use this checklist.

### 1. Start with one working example

Do not begin with a generic library abstraction. Begin with a compiling program.

### 2. Extract one behavior

Move only one obvious behavior into an include file.

Good first extractions:

```text
LED heartbeat
button press event
ADC average
GSA status report
blink fault code
```

### 3. Keep comments electrical and behavioral

Each helper should explain:

```text
what the circuit does
what the register/pin means
what the function returns
what the student should observe
```

### 4. Compile after every extraction

A library that does not compile is a note collection, not a firmware library.

### 5. Document the lesson

If a register name fails or a chip-specific surprise appears, record it in:

```text
doc/COMPILE_CORRECTIONS_v0.1.1.md
```

or a later versioned correction note.

## How to Take Advantage of the Architecture

For a programmer, the main advantage is controlled growth.

Instead of writing a new program from nothing each time, start with the behavior layer you need:

```text
Need a button?       Use gpio/rb_switch.inc
Need a status LED?   Use gpio/rb_led.inc
Need ADC?            Use analog/rb_adc.inc
Need serial report?  Use comms/rb_uart.inc or comms/rb_gsa_text.inc
Need fault display?  Use diagnostics/rb_faults.inc
```

Then compose the application as a readable story:

```gcb
RB_Core_Init
RB_SW1_InitPullup
RB_LED_Status_Init
RB_ADC_Init

If RB_SW1_PressedEvent = 1 Then
    ' change state
End If

Value = RB_ADC_ReadAverage_AN2(8)
```

The resulting program should read like an instrument narrative, not a register dump.

## Relationship to GSA

`nugget-fwlib` is the lowest-cost firmware expression of the General Solution Architecture.

The pathway is:

```text
Phenomenon
→ sensor or switch
→ PIC behavior
→ GSA text line
→ serial link
→ browser or logger
→ record
→ interpretation
```

The PIC does not need to be powerful. It needs to be clear, deterministic, and able to speak a small disciplined language.

## Relationship to Curriculum

This library supports the larger Measured World / Measured Machine / Measured Self framework.

Examples:

```text
Measured World: ADC, temperature, mass, distance, timing
Measured Machine: GPIO, timers, latches, serial protocols, robot control
Measured Self: reaction timing, button events, wearable-node command patterns
```

The same software grammar can support all three domains.

## What Counts as Success

A successful `nugget-fwlib` module is not merely short code.

It succeeds when:

```text
it compiles locally
it is named clearly
it maps to visible hardware behavior
it can be explained to a learner
it can be reused in another example
it fits the GSA text/reporting path
```

## Final Architectural Sentence

`nugget-fwlib` exists to turn tiny PIC programs into understandable firmware instruments.

It borrows the organizational seriousness of px-fwlib, but redirects that seriousness toward REDBOARD, GCBASIC, classroom transparency, and the Nugget/PIC Black Box path.
