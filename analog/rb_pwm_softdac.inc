''' Software PWM / pseudo-DAC teaching helpers: number -> duty cycle.
Sub RB_SoftDAC_PulseWidth_RC0(In RB_Level As Byte)
    Dim RB_OnTime As Byte
    Dim RB_OffTime As Byte
    RB_OnTime = RB_Level
    RB_OffTime = 100 - RB_Level
    LATC.0 = 1
    Wait RB_OnTime ms
    LATC.0 = 0
    Wait RB_OffTime ms
End Sub
Sub RB_SoftDAC_Ramp_RC0()
    Dim RB_Level As Byte
    For RB_Level = 0 To 100 Step 5
        RB_SoftDAC_PulseWidth_RC0(RB_Level)
    Next
End Sub
