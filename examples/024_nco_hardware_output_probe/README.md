# 024 NCO Hardware Output Probe

This folder contains the first real PIC16F18424 NCO output tests for Great Cow BASIC.

These examples are based on three confirmed ideas:

1. The PIC16F18424 NCO has increment registers, a control register, and a clock register.
2. `NCO1OUT` is a PPS output source with value `0x18` / decimal `24` on this chip family.
3. The increment bytes should be written upper/high before low when the NCO is enabled.

## Probe target pin

These examples route NCO1OUT to:

```text
RC1
```

Candidate PPS line:

```gcb
RC1PPS = 24
```

Use a scope, logic analyzer, or frequency counter on RC1.

If RC1 is not convenient on your REDBOARD, copy the example and change the pin to another PPS-capable output such as RA0, RA1, RA2, RC0, RC2, etc. Avoid pins currently used for UART, status LED, switch input, or display multiplexing unless you intend to override them.

## Compile order

Compile in this order:

```text
024a_nco_pps_rc1_route_compile_probe.gcb
024b_nco_raw_output_rc1_probe.gcb
024c_nco_disable_rc1_probe.gcb
```

## What each test proves

### 024a

Tests whether Great Cow BASIC accepts:

```gcb
PPSLOCK
RC1PPS
RC1PPS = 24
```

This is only a PPS compile probe.

### 024b

Attempts a real NCO waveform on RC1 using direct register values:

```gcb
NCO1INCU = 0
NCO1INCH = 0
NCO1INCL = 65
NCO1CLK  = 1
NCO1CON  = 192
RC1PPS   = 24
```

`NCO1CON = 192` means bits 7 and 6 are set: enable NCO and enable NCO output, with fixed-duty mode and active-high polarity implied by the remaining zero bits.

### 024c

Disables NCO and disconnects RC1 PPS output.

## Expected result

If 024b compiles and the register values are correct, RC1 should show a frequency output that can be measured.

If it compiles but no waveform appears, likely causes are:

```text
wrong NCO clock select value
wrong NCO1CON bit assumptions
PPS lock/unlock sequence not accepted as intended
RC1 not physically available or connected on the board
selected pin conflicts with another board function
```

## What to report back

For each file, report:

```text
compiled / failed
error line
exact error text
waveform observed yes/no
measured frequency if any
```

Once 024b works, its register writes should be moved into:

```text
peripherals/rb_nco.inc
```
