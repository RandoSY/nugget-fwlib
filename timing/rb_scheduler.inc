''' Cooperative service pattern: short turns, no operating system required.
Dim RB_TaskCounter10ms As Byte
Dim RB_TaskCounter100ms As Byte
Dim RB_Flag10ms As Bit
Dim RB_Flag100ms As Bit
Dim RB_Flag1s As Bit
Sub RB_Task_Init
    RB_TaskCounter10ms = 0
    RB_TaskCounter100ms = 0
    RB_Flag10ms = 0
    RB_Flag100ms = 0
    RB_Flag1s = 0
End Sub
Sub RB_Task_Tick10ms
    RB_Flag10ms = 1
    RB_TaskCounter10ms = RB_TaskCounter10ms + 1
    If RB_TaskCounter10ms >= 10 Then
        RB_TaskCounter10ms = 0
        RB_Flag100ms = 1
        RB_TaskCounter100ms = RB_TaskCounter100ms + 1
    End If
    If RB_TaskCounter100ms >= 10 Then
        RB_TaskCounter100ms = 0
        RB_Flag1s = 1
    End If
End Sub
Sub RB_Task_ClearFlags
    RB_Flag10ms = 0
    RB_Flag100ms = 0
    RB_Flag1s = 0
End Sub
