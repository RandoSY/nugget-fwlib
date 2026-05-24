''' Key/value helpers.
Sub RB_KV_Int(In RB_Key As String, In RB_Value As Long)
    HSerPrint RB_Key
    HSerPrint "="
    HSerPrint RB_Value
    HSerPrintCRLF
End Sub
Sub RB_KV_Text(In RB_Key As String, In RB_Value As String)
    HSerPrint RB_Key
    HSerPrint "="
    HSerPrint RB_Value
    HSerPrintCRLF
End Sub
