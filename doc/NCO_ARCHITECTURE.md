# Numerically Controlled Oscillator Architecture

## Why the NCO Belongs in Nugget

The PIC16F18424 includes a Numerically Controlled Oscillator, or NCO. This is one of the most important advanced peripherals for `nugget-fwlib` because it turns arithmetic into frequency.

The NCO demonstrates a powerful idea:

```text
number
→ repeated addition
→ accumulator overflow
→ output pulses
→ frequency
```

That makes the NCO a numerical frequency laboratory inside the PIC.

## Mathematical Soul

The core relationship is:

```text
f_out = f_NCOCLK × INC / 2^20
```

Plain English:

```text
The larger the increment value, the faster the accumulator overflows, and the higher the output frequency becomes.
```

This connects beautifully to the Nugget learning path:

```text
555 RC oscillator = frequency by physics
PIC NCO           = frequency by arithmetic
```

## Microchip Peripheral Concept

Microchip describes the NCO as an accumulator-based peripheral. A fixed increment value is repeatedly added to a 20-bit accumulator. Overflow events produce the NCO output.

The PIC16F18424 family includes one NCO peripheral with features such as:

```text
20-bit increment function
fixed-duty-cycle mode
pulse-frequency mode
pulse-width control
clock-source selection
polarity control
interrupt capability
```

## Nugget API Direction

The library file is:

```text
peripherals/rb_nco.inc
```

The first API layer is intentionally conservative:

```text
RB_NCO_InitState
RB_NCO_SetIncrementBytes
RB_NCO_SetDemoSlow
RB_NCO_SetDemoMedium
RB_NCO_SetDemoFast
RB_NCO_SetModeFDC
RB_NCO_SetModePFM
RB_NCO_EnableSoftwareState
RB_NCO_DisableSoftwareState
RB_NCO_PrintStatus
RB_NCO_PrintFormulaNote
```

These functions create the software vocabulary first.

## Why Hardware Writes Are Isolated

The Microchip data sheet gives the NCO register family, but the exact GCBASIC chip-header register symbols must be verified locally before hardware writes are enabled.

The hardware adapter routines are deliberately isolated:

```text
RB_NCO_HardwareApplyIncrement
RB_NCO_HardwareEnable
RB_NCO_HardwareDisable
```

They currently return `RB_FALSE` until direct register names and PPS routing are proven by compile.

This is the same development rule used elsewhere in `nugget-fwlib`:

```text
compile-proven behavior first
library abstraction second
CLI command third
```

## Future CLI Commands

Single-key monitor commands may use:

```text
O = print NCO status
V = print NCO formula note
J = set slow demo increment
K = set medium demo increment
Q = set fast demo increment
```

Later full GSA-style commands should become:

```text
NCO STATUS
NCO ON
NCO OFF
NCO INC 0 1 0
NCO MODE FDC
NCO MODE PFM
NCO FREQ 1000
```

## Success Criteria

The NCO layer succeeds when:

```text
it compiles locally
it prints NCO status over serial
it can store and report increment bytes
it can switch between FDC and PFM software modes
hardware register names are verified in one adapter file
NCO output can be routed to a measurable pin
frequency can be confirmed with a counter or oscilloscope
```

## Final Sentence

The NCO is the PIC16F18424's built-in demonstration that arithmetic can become a physical waveform.
