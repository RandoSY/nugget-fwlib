# Design Notes

## Core design rule

A module should not merely expose registers. It should expose a behavior that a learner can understand.

```text
Bad teaching abstraction:  WPUA.0 = 1
Better behavior:          RB_SW1_InitPullup()
Best explanation:         SW1 is open = HIGH, pressed to ground = LOW, and the function returns pressed = 1.
```

## Behavior-class architecture

```text
Peripheral feature → behavior class → classroom pattern → project use
```

## Naming rule

Use `RB_` prefix for REDBOARD/Nugget functions.

```text
RB_<Class>_<Object>_<Action>()
```

Examples:

```gcb
RB_SW1_InitPullup()
RB_SW1_PressedEvent()
RB_LED_Status_Toggle()
RB_UART_PrintLine("HELLO")
RB_GSA_ProcessLine()
```

## No-magic rule

Every module should explain electrical meaning, software meaning, human behavior meaning, and use in a real instrument.
