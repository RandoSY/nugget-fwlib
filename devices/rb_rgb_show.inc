''' R&G Show: number/status -> red/green display.
Sub RB_RG_Init
    Dir PORTC.0 Out
    Dir PORTC.1 Out
    ANSELC.0 = 0
    ANSELC.1 = 0
    LATC.0 = 0
    LATC.1 = 0
End Sub
Sub RB_RG_Green
    LATC.0 = 1
    LATC.1 = 0
End Sub
Sub RB_RG_Red
    LATC.0 = 0
    LATC.1 = 1
End Sub
Sub RB_RG_Off
    LATC.0 = 0
    LATC.1 = 0
End Sub
Sub RB_RG_ShowThreshold(In RB_Value As Word, In RB_Threshold As Word)
    If RB_Value >= RB_Threshold Then
        RB_RG_Green
    Else
        RB_RG_Red
    End If
End Sub
