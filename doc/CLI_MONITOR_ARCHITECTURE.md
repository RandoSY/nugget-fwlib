# Nugget CLI Monitor Architecture

## Why This Example Matters

One of the strongest application patterns in px-fwlib / Piconomix-style firmware is the command-line monitor: a small firmware image sits on a serial port, waits for commands, and exercises the important functions of the firmware library.

For `nugget-fwlib`, the analogous marquee application is the **Nugget CLI Monitor**.

It is not just a demo. It is the programmer's diagnostic console, board bring-up tool, library verification tool, and teaching instrument.

## Purpose

The CLI monitor should let a programmer or student connect a serial terminal and ask the PIC16F18424 to perform controlled actions:

```text
print identity
print help
read switch state
toggle LED
blink LED
read ADC
stream ADC values
print GSA status
exercise diagnostics
run future I2C scan
run future sensor checks
```

This turns the firmware library into a living system rather than a folder of include files.

## Marquee Role

The CLI monitor should become the first serious application a programmer studies after blink and switch input.

It demonstrates:

```text
architecture layer
board layer
GPIO behavior
switch behavior
ADC behavior
UART behavior
GSA text reporting
diagnostics
future I2C/device expansion
```

In other words, it exercises the library as a library.

## Command Style

The first version uses single-character commands because they are robust and easy to debug on a small PIC.

Recommended command vocabulary:

```text
? or H  help
I       identity
S       status
B       blink status LED
L       toggle status LED
0       LED off
1       LED on
P       print pushbutton state
A       read ADC once
R       run/stream ADC telemetry
T       stop streaming
D       diagnostic blink code
X       experimental I2C scan placeholder
```

This is intentionally simpler than a desktop CLI. It is a tiny instrument monitor.

## Why Single-Character Commands First?

A full line parser is attractive, but it introduces uncertainty early:

```text
receive buffering
CR/LF handling
string comparison
line length limits
command arguments
```

The first monitor should prove the serial receive path and library dispatch path with the smallest possible moving parts.

Once single-character command receive is reliable, the next layer can add full GSA words such as:

```text
HELLO
STATUS
START
STOP
READ
SCAN
```

## Important Local Verification Point

The TX side of the monitor uses already familiar GCB serial output:

```gcb
HSerPrint "text"
HSerPrintCRLF
```

The RX side depends on the exact GCBASIC serial receive syntax for the user's installed version and chip profile. Therefore the example isolates serial receive in a small adapter section.

The design rule is:

```text
If serial receive syntax changes, only the RX adapter should change.
The command dispatch logic should remain stable.
```

## I2C Scan Strategy

The CLI includes an `X` command as the future I2C scan entry point.

The first v0.1.x monitor may print:

```text
I2C SCAN NOT ENABLED IN THIS BUILD
```

Once the PIC16F18424 MSSP / GCB I2C syntax is locally verified, that command should become:

```text
scan addresses 0x08 through 0x77
print ACK responses
report detected addresses
```

This mirrors the role of I2C scan utilities in more mature firmware frameworks without pretending the unverified low-level syntax is already solved.

## Relationship to GSA

The CLI monitor is the human-facing diagnostic layer. GSA text is the machine-facing protocol layer. They should eventually converge.

Early CLI:

```text
A
```

Later GSA command:

```text
READ ADC
```

Early response:

```text
ADC 512
```

Later response:

```text
DATA ADC 512
```

The CLI monitor therefore helps grow the GSA device vocabulary safely.

## Success Criteria

The Nugget CLI Monitor succeeds when:

```text
it compiles locally
it prints a help menu
it can exercise LED output
it can read SW1
it can read AN2 ADC
it can stream periodic telemetry
it can stop streaming
it clearly marks unimplemented features
it keeps the RX adapter isolated
```

## Final Architectural Sentence

The CLI monitor is the marquee application because it lets the programmer interrogate the chip, verify the library, and teach the firmware architecture from a serial terminal.
