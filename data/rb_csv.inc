''' CSV helpers for serial logging.
Sub RB_CSV_Header2(In RB_A As String, In RB_B As String)
    HSerPrint RB_A
    HSerPrint ","
    HSerPrint RB_B
    HSerPrintCRLF
End Sub
Sub RB_CSV_Row2_Int(In RB_A As Long, In RB_B As Long)
    HSerPrint RB_A
    HSerPrint ","
    HSerPrint RB_B
    HSerPrintCRLF
End Sub
Sub RB_CSV_Row3_Int(In RB_A As Long, In RB_B As Long, In RB_C As Long)
    HSerPrint RB_A
    HSerPrint ","
    HSerPrint RB_B
    HSerPrint ","
    HSerPrint RB_C
    HSerPrintCRLF
End Sub
