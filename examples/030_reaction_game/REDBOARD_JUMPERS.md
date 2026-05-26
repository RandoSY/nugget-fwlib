# REDBOARD Reaction Game Jumper Setup

This setup matches `030_reaction_game.gcb` firmware version `FW=0.3.0`.

## Required jumpers / connections

| Jumper / connection | Setting | Function | PIC signal |
|---|---:|---|---:|
| JP3 | CLOSED | MCLR pull-up for reset/programming stability | MCLR |
| JP7 | CLOSED | SW2 reaction switch input | RA2 |
| JP12 | CLOSED | L2 GO LED | RA1 |
| JP16 | CLOSED | L6 armed/status/error LED | RC0 |
| JP23 | 1-2 CLOSED | BEEP / piezo buzzer | RC5 |
| RC4 header/wire | connect to Arduino Nano D7 | software UART TX | RC4 |
| GND | connect to Arduino Nano GND | common ground | GND |

## Jumpers to avoid for this firmware

Keep display and alternate-function jumpers open unless you are deliberately testing those circuits separately.

| Jumper | Recommended setting | Reason |
|---|---:|---|
| JP4 | OPEN | Avoid 7-segment/display loading on C-port signals |
| JP5 | OPEN | Avoid display mode loading |
| JP6 | OPEN | Avoid display mode loading |
| JP8 | OPEN | Avoid display digit/display support loading |
| JP9 | OPEN | Avoid display digit/display support loading |
| JP10 | OPEN | Avoid display digit/display support loading |
| JP11 | OPEN | Do not load RA0; firmware uses SW2/RA2 instead |
| JP13 | OPEN | Do not put another load on RA2 while using SW2 |
| JP24 | OPEN | Do not connect POT/LDR/AN0 for this game |
| JP27 | OPEN | Do not load RC0 as display digit enable while using L6/status LED |

## Firmware I/O contract

```text
RA2 = SW2 reaction switch, active-low, weak pull-up enabled
RA1 = L2 GO LED
RC0 = L6 armed/status/error LED
RC5 = BEEP / piezo buzzer
RC4 = software UART TX, 9600 baud, 8N1, to Arduino Nano D7
```

## Arduino Nano bridge wiring

| REDBOARD | Arduino Nano | Purpose |
|---|---|---|
| RC4 | D7 | PIC software UART TX into Nano SoftwareSerial RX |
| GND | GND | common ground |

Do not connect Nano TX back to the PIC for this version. The bridge is listen-only.

## Standalone behavior without serial

The game still works with no serial receiver connected:

| Event | Human feedback |
|---|---|
| Armed | L6/status LED on + chirp |
| GO | L2/GO LED on + chirp |
| Valid press | GO LED off + result chirps |
| Fast result | one chirp |
| Normal result | two chirps |
| Slow result | three chirps |
| False start / anticipated | L6/status/error LED + error double-beep |

## Programming setup reminder

The known-good SNAP/IPECMD programming pattern for this example is documented in `flash_reaction_game_snap.ps1`:

```powershell
ipecmd.exe -TPPK4 -TS021038102RYN013580 -P16F18424 -F".\030_reaction_game.hex" -M -Y -OL
```

Do not use `-TPSNAP` or `-S021038102RYN013580` for this working SNAP setup. In IPECMD, `-S` is interpreted as an SQTP file option.
