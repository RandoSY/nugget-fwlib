# CLI I/O Primitives: Addressable LEDs and Seven-Segment Output

## Purpose

The Nugget CLI Monitor needs two important command-line I/O primitives:

```text
1. Select an LED by address and turn it on/off/toggle it.
2. Select a seven-segment digit and send it a displayable character.
```

These primitives are central to a useful firmware monitor. They let a programmer interrogate the board directly from the serial terminal.

## LED Primitive

The addressable LED bank API is defined in:

```text
gpio/rb_led_bank.inc
```

Current verified address:

```text
LED 0 = status LED on RC0
```

Reserved future addresses:

```text
LED 1..7 = board-map pending
```

CLI commands:

```text
M = print LED map
N = select next LED
+ = selected LED on
- = selected LED off
L = selected LED toggle
```

Expected response examples:

```text
SELECTED LED 0 IMPLEMENTED
OK LED 0 ON
OK LED 0 OFF
OK LED 0 TOGGLE
ERR LED 3 NOT_IMPLEMENTED
```

## Seven-Segment Primitive

The seven-segment API is defined in:

```text
devices/rb_7seg.inc
```

Current status:

```text
Character-to-segment pattern table exists.
Digit and segment hardware map is pending.
```

CLI commands:

```text
Y = print 7-seg map
G = select next digit
C = send next demo character to selected digit
```

The `C` command cycles through demo characters beginning with `0`.

Expected response while pin map is pending:

```text
7SEG DIGIT 0 CHAR ASCII 48 PATTERN 63
ERR 7SEG PIN_MAP_PENDING
```

This is useful even before hardware output is enabled because it verifies the character translation layer.

## Why These Are Firmware-Library Primitives

These commands are not merely cosmetic. They exercise key responsibilities of the firmware library:

```text
symbolic device address
board resource map
safe dispatch
visible hardware output
serial result reporting
honest error response when a map is incomplete
```

The primitives move the CLI monitor toward the role of a real board bring-up console.

## Future Full Line Commands

Once the serial line parser is verified, these single-key commands should grow into full GSA-style commands:

```text
LED 0 ON
LED 0 OFF
LED 3 TOGGLE
LED MAP
SEG 0 A
SEG 1 7
SEG 2 -
SEG MAP
```

For now the single-character command layer keeps the CLI buildable while local serial receive syntax is still being verified.
