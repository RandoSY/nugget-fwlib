''' ================================================================
''' rb_switch.inc
''' REDBOARD SW1 switch-to-ground behavior on RA0.
'''
''' Electrical meaning:
'''   Internal weak pull-up holds RA0 HIGH when switch is open.
'''   Pressing the switch connects RA0 to GND, so RA0 reads LOW.
''' Software meaning:
'''   These functions return human logic: pressed = 1, released = 0.
''' ================================================================
Dim RB_SW1_LastRaw As Bit
Dim RB_SW1_ToggleState As Bit
Sub RB_SW1_InitPullup()
    Dir PORTA.0 In
    ANSELA.0 = 0
    WPUA.0 = 1
    OPTION_REG.WPUEN = 0
    RB_SW1_LastRaw = PORTA.0
    RB_SW1_ToggleState = 0
End Sub
Function RB_SW1_IsPressed As Bit
    If PORTA.0 = 0 Then
        RB_SW1_IsPressed = 1
    Else
        RB_SW1_IsPressed = 0
    End If
End Function
Function RB_SW1_IsReleased As Bit
    If PORTA.0 = 1 Then
        RB_SW1_IsReleased = 1
    Else
        RB_SW1_IsReleased = 0
    End If
End Function
Function RB_SW1_DebouncedPressed As Bit
    If PORTA.0 = 0 Then
        Wait 20 ms
        If PORTA.0 = 0 Then
            RB_SW1_DebouncedPressed = 1
        Else
            RB_SW1_DebouncedPressed = 0
        End If
    Else
        RB_SW1_DebouncedPressed = 0
    End If
End Function
Sub RB_SW1_WaitForPress()
    Do While PORTA.0 = 1
    Loop
    Wait 20 ms
End Sub
Sub RB_SW1_WaitForRelease()
    Do While PORTA.0 = 0
    Loop
    Wait 20 ms
End Sub
Function RB_SW1_PressedEvent As Bit
    RB_SW1_PressedEvent = 0
    If RB_SW1_LastRaw = 1 Then
        If PORTA.0 = 0 Then
            Wait 20 ms
            If PORTA.0 = 0 Then
                RB_SW1_PressedEvent = 1
            End If
        End If
    End If
    RB_SW1_LastRaw = PORTA.0
End Function
Function RB_SW1_ToggleLatch As Bit
    If RB_SW1_PressedEvent() = 1 Then
        RB_SW1_ToggleState = !RB_SW1_ToggleState
    End If
    RB_SW1_ToggleLatch = RB_SW1_ToggleState
End Function
Function RB_SW1_LongPress1s As Bit
    RB_SW1_LongPress1s = 0
    If PORTA.0 = 0 Then
        Wait 1000 ms
        If PORTA.0 = 0 Then
            RB_SW1_LongPress1s = 1
        End If
    End If
End Function
