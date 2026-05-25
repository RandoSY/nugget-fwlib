# Macro Architecture

## Why Add a Macro Layer?

One of the strengths of px-fwlib is not merely that it has drivers. It has a disciplined firmware vocabulary. Its macro and configuration patterns help make code portable, readable, and systematic.

`nugget-fwlib` needs a similar idea, but adapted to GCBASIC and the PIC16F18424.

The purpose of the macro layer is not to make the code clever. The purpose is to make intent visible.

```text
raw value → named meaning
register fact → board role
string literal → protocol word
number → state or fault code
```

## The GCBASIC Constraint

GCBASIC is not C. Therefore `nugget-fwlib` should not blindly imitate C macro tricks.

The first safe macro layer uses simple `#define` constants only:

```gcb
#define RB_TRUE 1
#define RB_FALSE 0
#define RB_STATE_READY 1
#define RB_GSA_CMD_STATUS "STATUS"
```

This gives the programmer a useful symbolic vocabulary without hiding too much or relying on risky preprocessor behavior.

## What Belongs in `common/rb_macros.inc`

The macro layer should hold:

```text
boolean vocabulary
logic vocabulary
active-high / active-low naming
standard board role names
GSA command words
GSA response words
state-machine constants
fault constants
timing constants
ADC sample-count constants
```

Examples:

```gcb
#define RB_PRESSED 1
#define RB_RELEASED 0
#define RB_ACTIVE_LOW 0
#define RB_GSA_WORD_DATA "DATA"
#define RB_GSA_CMD_START "START"
#define RB_STATE_RUNNING 2
#define RB_FAULT_SENSOR_MISSING 3
#define RB_DEBOUNCE_MS 20
```

## What Does Not Belong in the Macro Layer Yet

Do not hide chip registers too early.

For example, this should stay visible in the actual switch helper:

```gcb
Dir PORTA.0 In
ANSELA.0 = 0
WPUA.0 = 1
```

A future macro could name the role, but the early library should not hide the electrical truth.

Avoid premature macros like:

```gcb
RB_CONFIG_PIN_AS_MAGIC_INPUT(SW1)
```

That would hide exactly the machine behavior the Nugget path is supposed to reveal.

## Relationship to Teaching

A macro should help the student read the code as a story.

Better:

```gcb
If RB_SW1_PressedEvent = RB_TRUE Then
```

Also acceptable:

```gcb
If RB_SW1_PressedEvent = RB_PRESSED Then
```

Less helpful:

```gcb
If RB_SW1_PressedEvent = 1 Then
```

The numeric version is valid, but the symbolic version carries the educational meaning.

## Relationship to GSA

The GSA protocol should avoid scattered string literals.

Instead of repeating:

```gcb
HSerPrint "STATUS"
HSerPrint "READY"
```

use named protocol words where practical:

```gcb
HSerPrint RB_GSA_WORD_STATUS
HSerPrint " "
HSerPrint RB_GSA_STATUS_READY
```

This helps keep firmware, dashboards, and documentation aligned.

## Conservative Rule

The macro layer must never make compile debugging harder.

The safest rule is:

```text
Macros may name intent.
Macros must not obscure chip-specific register behavior.
```

## Possible Future Macro Families

As the project matures, additional macro files may be added:

```text
common/rb_macros.inc              general symbolic vocabulary
arch/pic16f1/rb_pic16f1_macros.inc chip-family constants
boards/redboard/rb_redboard_roles.inc board-role constants
comms/rb_gsa_words.inc             protocol words
```

But for v0.1.1, the single conservative file is enough.

## Example Use

```gcb
#include "../../common/rb_macros.inc"
#include "../../arch/pic16f1/pic16f18424/rb_chip_16f18424.inc"
#include "../../gpio/rb_switch.inc"
#include "../../gpio/rb_led.inc"

Dim Running As Bit

RB_Core_Init
RB_SW1_InitPullup
RB_LED_Status_Init

Running = RB_FALSE

Do
    If RB_SW1_PressedEvent = RB_TRUE Then
        If Running = RB_TRUE Then
            Running = RB_FALSE
        Else
            Running = RB_TRUE
        End If
    End If
Loop
```

## Final Intent

The macro layer should give `nugget-fwlib` the same kind of disciplined vocabulary that makes px-fwlib feel organized, but without losing the transparency that makes GCBASIC valuable for teaching.
