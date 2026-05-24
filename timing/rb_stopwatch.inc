''' Simple teaching stopwatch. This is a readable model, not yet an interrupt driver.
Dim RB_Stopwatch_ms As Long
Dim RB_Stopwatch_Running As Bit
Sub RB_Stopwatch_Reset
    RB_Stopwatch_ms = 0
    RB_Stopwatch_Running = 0
End Sub
Sub RB_Stopwatch_Start
    RB_Stopwatch_ms = 0
    RB_Stopwatch_Running = 1
End Sub
Sub RB_Stopwatch_Stop
    RB_Stopwatch_Running = 0
End Sub
Sub RB_Stopwatch_Tick1ms
    If RB_Stopwatch_Running = 1 Then
        RB_Stopwatch_ms = RB_Stopwatch_ms + 1
    End If
End Sub
Function RB_Stopwatch_ReadMs As Long
    RB_Stopwatch_ReadMs = RB_Stopwatch_ms
End Function
Function RB_Timeout_Expired(In RB_Value As Long, In RB_Limit As Long) As Bit
    If RB_Value >= RB_Limit Then
        RB_Timeout_Expired = 1
    Else
        RB_Timeout_Expired = 0
    End If
End Function
