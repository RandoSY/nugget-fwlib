# API Map

## Core

```gcb
RB_Core_Init()
RB_Core_AllDigital()
RB_Core_ClearLatches()
RB_Core_EnableWeakPullups()
```

## LED

```gcb
RB_LED_Status_Init()
RB_LED_Status_On()
RB_LED_Status_Off()
RB_LED_Status_Toggle()
RB_LED_Status_Pulse100()
RB_LED_Status_Heartbeat()
RB_LED_Status_BlinkCode(code)
```

## Switch

```gcb
RB_SW1_InitPullup()
RB_SW1_IsPressed()
RB_SW1_DebouncedPressed()
RB_SW1_WaitForPress()
RB_SW1_WaitForRelease()
RB_SW1_PressedEvent()
RB_SW1_ToggleLatch()
RB_SW1_LongPress1s()
```

## ADC / UART / GSA

```gcb
RB_ADC_ReadAverage_AN2(samples)
RB_UART_PrintLine(text)
RB_GSA_Init()
RB_GSA_AddChar(ch)
RB_GSA_IsLineReady()
RB_GSA_ProcessLine()
RB_GSA_SendDataInt(label, value)
```
