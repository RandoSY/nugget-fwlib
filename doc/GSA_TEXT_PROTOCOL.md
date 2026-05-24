# GSA Tiny Text Protocol

A tiny PIC should speak a small, disciplined text language.

## Commands

```text
HELLO
STATUS
START
STOP
RESET
TARE
READ
DEMO ON
DEMO OFF
```

## Responses

```text
ID NUGGET-REDBOARD PIC16F18424 FW=0.1.0
OK STATUS READY
OK START
OK STOP
DATA ADC 512
FAULT HX711_MISSING
ERR BAD_CMD
ERR BAD_ARG
```

## Prefix meanings

| Prefix | Meaning |
|---|---|
| `ID` | device identity |
| `OK` | command accepted |
| `ERR` | unsupported or malformed command |
| `DATA` | measurement or telemetry |
| `FAULT` | detected problem |
