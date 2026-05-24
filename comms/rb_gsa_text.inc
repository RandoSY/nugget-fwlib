''' ================================================================
''' rb_gsa_text.inc
''' GSA Tiny Text Protocol helpers.
''' ================================================================
Dim RB_GSA_DemoMode As Bit
Dim RB_GSA_Running As Bit
Sub RB_GSA_Init
    RB_LineBuf_Init
    RB_GSA_DemoMode = 0
    RB_GSA_Running = 0
End Sub
Sub RB_GSA_SendOK(In RB_Text As String)
    HSerPrint "OK"
    If RB_Text <> "" Then
        HSerPrint " "
        HSerPrint RB_Text
    End If
    HSerPrintCRLF
End Sub
Sub RB_GSA_SendERR(In RB_Text As String)
    HSerPrint "ERR "
    HSerPrint RB_Text
    HSerPrintCRLF
End Sub
Sub RB_GSA_SendID
    HSerPrint "ID NUGGET-REDBOARD PIC16F18424 FW=0.1.0"
    HSerPrintCRLF
End Sub
Sub RB_GSA_SendDataInt(In RB_Label As String, In RB_Value As Long)
    HSerPrint "DATA "
    HSerPrint RB_Label
    HSerPrint " "
    HSerPrint RB_Value
    HSerPrintCRLF
End Sub
Sub RB_GSA_SendFault(In RB_Text As String)
    HSerPrint "FAULT "
    HSerPrint RB_Text
    HSerPrintCRLF
End Sub
Function RB_GSA_IsLineReady As Bit
    RB_GSA_IsLineReady = RB_LineReady
End Function
Sub RB_GSA_AddChar(In RB_Ch As Byte)
    RB_LineBuf_AddChar(RB_Ch)
End Sub
Sub RB_GSA_ProcessLine
    If RB_LineTooLong = 1 Then
        RB_GSA_SendERR("LINE_TOO_LONG")
        RB_LineBuf_Clear
        Exit Sub
    End If
    If RB_Line = "HELLO" Then
        RB_GSA_SendID
    Else If RB_Line = "ID?" Then
        RB_GSA_SendID
    Else If RB_Line = "STATUS" Then
        If RB_GSA_Running = 1 Then
            RB_GSA_SendOK("STATUS RUNNING")
        Else
            RB_GSA_SendOK("STATUS READY")
        End If
    Else If RB_Line = "START" Then
        RB_GSA_Running = 1
        RB_GSA_SendOK("START")
    Else If RB_Line = "STOP" Then
        RB_GSA_Running = 0
        RB_GSA_SendOK("STOP")
    Else If RB_Line = "RESET" Then
        RB_GSA_Running = 0
        RB_GSA_DemoMode = 0
        RB_GSA_SendOK("RESET")
    Else If RB_Line = "TARE" Then
        RB_GSA_SendOK("TARE")
    Else If RB_Line = "READ" Then
        RB_GSA_SendDataInt("ADC", 0)
    Else If RB_Line = "DEMO ON" Then
        RB_GSA_DemoMode = 1
        RB_GSA_SendOK("DEMO ON")
    Else If RB_Line = "DEMO OFF" Then
        RB_GSA_DemoMode = 0
        RB_GSA_SendOK("DEMO OFF")
    Else If RB_Line = "" Then
        ' Ignore empty line.
    Else
        RB_GSA_SendERR("BAD_CMD")
    End If
    RB_LineBuf_Clear
End Sub
