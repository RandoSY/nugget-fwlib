''' ================================================================
''' rb_soft_uart_tx.inc
''' REDBOARD / Nugget FWLIB software UART transmit-only helper.
'''
''' Target style: PIC16F18424 / Great Cow BASIC / teaching firmware.
'''
''' Default TX pin:
'''   RC4, idle high, 9600 baud, 8N1
'''
''' Purpose:
'''   Provide a tiny TX-only serial output path for instruments where the
'''   hardware UART pins are unavailable, inconvenient, or reserved for some
'''   other role.
'''
''' Important:
'''   This is blocking bit-banged serial. Use it AFTER timing-sensitive
'''   measurement is complete. Do not print during a reaction-time timing loop.
''' ================================================================

#define RB_SOFTUART_BIT_US 104

Dim RB_SU_Data As Byte
Dim RB_SU_Mask As Byte
Dim RB_SU_i As Byte
Dim RB_SU_Value As Word
Dim RB_SU_Div As Word
Dim RB_SU_Digit As Byte
Dim RB_SU_Started As Bit

Sub RB_SoftUART_TX_Init
    Dir PORTC.4 Out
    ANSELC.4 = 0
    LATC.4 = 1
End Sub

Sub RB_SoftUART_TX_High
    LATC.4 = 1
End Sub

Sub RB_SoftUART_TX_Low
    LATC.4 = 0
End Sub

Sub RB_SoftUART_TxByte(In RB_SU_OutByte As Byte)

    RB_SU_Data = RB_SU_OutByte

    ' Start bit.
    RB_SoftUART_TX_Low
    Wait RB_SOFTUART_BIT_US us

    ' Eight data bits, least significant bit first.
    RB_SU_Mask = 1

    For RB_SU_i = 1 To 8
        If (RB_SU_Data AND RB_SU_Mask) = 0 Then
            RB_SoftUART_TX_Low
        Else
            RB_SoftUART_TX_High
        End If

        Wait RB_SOFTUART_BIT_US us
        RB_SU_Mask = RB_SU_Mask * 2
    Next

    ' Stop bit.
    RB_SoftUART_TX_High
    Wait RB_SOFTUART_BIT_US us

End Sub

Sub RB_SoftUART_PrintCRLF
    RB_SoftUART_TxByte(13)
    RB_SoftUART_TxByte(10)
End Sub

Sub RB_SoftUART_PrintSpace
    RB_SoftUART_TxByte(32)
End Sub

Sub RB_SoftUART_PrintWord(In RB_SU_InValue As Word)

    RB_SU_Value = RB_SU_InValue
    RB_SU_Started = 0

    RB_SU_Div = 10000

    Do
        RB_SU_Digit = RB_SU_Value / RB_SU_Div

        If RB_SU_Digit > 0 Then
            RB_SU_Started = 1
        End If

        If RB_SU_Started = 1 Then
            RB_SoftUART_TxByte(RB_SU_Digit + 48)
        End If

        RB_SU_Value = RB_SU_Value - (RB_SU_Digit * RB_SU_Div)

        If RB_SU_Div = 10000 Then
            RB_SU_Div = 1000
        Else
            If RB_SU_Div = 1000 Then
                RB_SU_Div = 100
            Else
                If RB_SU_Div = 100 Then
                    RB_SU_Div = 10
                Else
                    If RB_SU_Div = 10 Then
                        RB_SU_Div = 1
                    Else
                        RB_SU_Div = 0
                    End If
                End If
            End If
        End If

    Loop Until RB_SU_Div = 0

    If RB_SU_Started = 0 Then
        RB_SoftUART_TxByte(48)
    End If

End Sub
