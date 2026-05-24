''' ================================================================
''' rb_led.inc
''' REDBOARD status LED behavior on RC0.
''' ================================================================
Sub RB_LED_Status_Init()
    Dir PORTC.0 Out
    ANSELC.0 = 0
    LATC.0 = 0
End Sub
Sub RB_LED_Status_On()
    LATC.0 = 1
End Sub
Sub RB_LED_Status_Off()
    LATC.0 = 0
End Sub
Sub RB_LED_Status_Toggle()
    LATC.0 = !LATC.0
End Sub
Sub RB_LED_Status_Pulse100()
    LATC.0 = 1
    Wait 100 ms
    LATC.0 = 0
End Sub
Sub RB_LED_Status_Heartbeat()
    LATC.0 = 1
    Wait 50 ms
    LATC.0 = 0
    Wait 950 ms
End Sub
Sub RB_LED_Status_BlinkCode(In RB_Code As Byte)
    Dim RB_i As Byte
    For RB_i = 1 To RB_Code
        LATC.0 = 1
        Wait 150 ms
        LATC.0 = 0
        Wait 200 ms
    Next
    Wait 600 ms
End Sub
