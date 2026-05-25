# Nugget CLI Monitor

The Nugget CLI Monitor is the marquee application for `nugget-fwlib`.

It is inspired by the role played by command-line monitor applications in more mature firmware libraries: a small program sits on the serial port, waits for commands, and exercises important library functions.

## Why this matters

A firmware library becomes real when a programmer can interrogate it from a terminal.

The CLI monitor lets the user test:

```text
board identity
status LED
SW1 switch input
ADC reading
streaming telemetry
diagnostic blink behavior
future I2C scan command path
```

## Current command vocabulary

```text
? or H = help
I      = identity
S      = status
B      = blink status LED
L      = toggle status LED
0      = LED off
1      = LED on
P      = print SW1 state
A      = read ADC once
R      = run ADC stream
T      = stop ADC stream
D      = diagnostic blink code
X      = I2C scan placeholder
```

## Important receive note

The current file contains an isolated serial receive adapter:

```gcb
Function CLI_PollSerial As Bit
    CLI_PollSerial = RB_FALSE
End Function
```

This is intentional. The exact GCBASIC serial receive syntax needs to be verified locally for the installed compiler and PIC16F18424 profile.

Once receive syntax is known, only `CLI_PollSerial` should need to change. The command dispatcher, help menu, and library exercise logic should remain stable.

## Design rule

Do not bury uncertainty in the application logic.

Keep uncertain low-level syntax in one adapter section, and keep the CLI architecture readable.

## Future expansion

The `X` command is reserved for I2C scanning.

A future verified version should scan addresses `0x08` through `0x77` and report detected devices. This will make the CLI monitor an even closer analogue to the Piconomix / px-fwlib style command monitor.
