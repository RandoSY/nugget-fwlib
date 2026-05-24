''' UART print helpers: the PIC speaks readable text.
Sub RB_UART_Init9600()
    ' Typical programs use #define USART_BAUD_RATE 9600 near the top.
End Sub
Sub RB_UART_PrintLine(In RB_Text As String)
    HSerPrint RB_Text
    HSerPrintCRLF
End Sub
Sub RB_UART_PrintKV_Int(In RB_Label As String, In RB_Value As Long)
    HSerPrint RB_Label
    HSerPrint " "
    HSerPrint RB_Value
    HSerPrintCRLF
End Sub
Sub RB_UART_PrintCSV2_Int(In RB_A As Long, In RB_B As Long)
    HSerPrint RB_A
    HSerPrint ","
    HSerPrint RB_B
    HSerPrintCRLF
End Sub
