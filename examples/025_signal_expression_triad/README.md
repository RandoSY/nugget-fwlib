# 025 Signal Expression Triad

This example is the direct expression of the Nugget idea:

```text
input voltage
→ ADC number inside the PIC
→ DAC voltage, tone frequency, and red/green visual code
```

It reads one analog signal on **RA2 / AN2** and expresses the value three ways:

1. **DAC voltage** on **RA0 / DAC1OUT**, readable with a voltmeter.
2. **Tone** on **RC5 / passive piezo**, with pitch proportional to the ADC value.
3. **Red/Green Show**, a visible 12-bit MSB-first bitstream.

## Why AN2 is used

The earlier Red/Green Show used AN0/RA0 as the analog input. This triad test uses the chip's internal 5-bit DAC, and the DAC output appears on RA0 / DAC1OUT.

Therefore:

```text
RA0 = DAC output
RA2 = ADC input
```

This avoids trying to use RA0 as both input and output at the same time.

## Hardware roles

```text
RA0 / DAC1OUT = voltmeter output
RA1           = ONE / GREEN LED path
RA2 / AN2     = analog input signal, 0 V to VDD only
RC0           = ZERO / RED LED path
RC5           = passive piezo tone output
```

## Jumper discipline

Before running this test:

```text
Open the display jumpers.
Do not route the AN0 potentiometer source onto RA0.
Do not use RA2 as SW2 or an LED service in this test.
Use RC5 only if the piezo/tone jumper path supports it.
```

The purpose is to avoid fighting the board's display, LED, pot, and buzzer wiring.

## Test sequence

After reset, the program gives an alive announcement:

```text
short beep
green flash
red flash
both flash
```

Then each frame does this:

```text
1. Read AN2 as a 12-bit ADC value.
2. Scale ADC 0..4095 to DAC 0..31.
3. Write DAC1CON1 so RA0 changes voltage.
4. Scale ADC value to a tone frequency.
5. Play a short proportional tone on RC5.
6. Stream the 12-bit ADC value as red/green bits.
```

## Interpretation

### DAC path

The DAC path answers:

```text
Can I turn an internal number back into a measurable voltage?
```

Expected mapping:

```text
ADC near 0     -> DAC near 0
ADC near 4095  -> DAC near 31
```

Because the DAC is 5-bit, it has 32 steps.

### Tone path

The tone path answers:

```text
Can I turn an internal number into pitch?
```

The current program uses GCBASIC `Tone`:

```gcb
toneFreq = 300 + adcValue / 2
Tone toneFreq, 12
```

A later version can replace this with the hardware NCO after the NCO output probes are proven.

### Red/Green Show path

The Red/Green path answers:

```text
Can I turn an internal number into a visible symbolic code?
```

It streams 12 bits, MSB first:

```text
1 = green / ONE
0 = red / ZERO
```

## Why this matters

This example is not merely a demo. It is the Nugget signal-expression thesis:

```text
The PIC receives a signal, creates a number, and expresses that number as voltage, tone, light, and eventually text.
```

That is the small-machine version of making the invisible measurable.
