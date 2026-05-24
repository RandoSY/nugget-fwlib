# Compile Corrections v0.1.1

This note records what was learned while turning `020_full_tiny_gsa_node` from a generated example into a locally compiling PIC16F18424 program.

## Verified local facts

These compiled in the user's Great Cow BASIC / PIC16F18424 setup:

```gcb
ANSELA = 0
ANSELC = 0
WPUA.0 = 1
Dir PORTA.0 In
Dir PORTC.0 Out
LATC.0 = 0
```

These did not compile in that profile and were removed from the v0.1.1 baseline:

```gcb
ANSELB = 0
OPTION_REG.WPUEN = 0
WPUEN = 0
```

## Design consequence

The REDBOARD/PIC16F18424 board layer is now conservative. It uses only the registers proven in the local compile. The switch helper enables `WPUA.0`, but does not attempt to set a global weak-pullup enable bit.

If the input floats on real hardware, use a physical 10 kOhm pull-up from RA0 to VDD while identifying the exact chip-header symbol for global WPU control.

## Library method

```text
1. Make a self-contained program compile.
2. Extract one behavior into one include file.
3. Compile again.
4. Move the include into the library tree.
5. Compile again.
6. Commit and push.
```
