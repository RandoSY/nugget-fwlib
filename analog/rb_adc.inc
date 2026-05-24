''' ADC behavior helpers: external voltage becomes a number.

Sub RB_ADC_Init
    ' RA2 / AN2 is the default ADC demonstration input.
    Dir PORTA.2 In
    ANSELA.2 = 1
End Sub

Function RB_ADC_Read_AN2 As Word
    RB_ADC_Read_AN2 = ReadAD(AN2)
End Function

Function RB_ADC_ReadAverage_AN2(In RB_Samples As Byte) As Word
    Dim RB_i As Byte
    Dim RB_Total As Long
    RB_Total = 0
    For RB_i = 1 To RB_Samples
        RB_Total = RB_Total + ReadAD(AN2)
        Wait 2 ms
    Next
    RB_ADC_ReadAverage_AN2 = RB_Total / RB_Samples
End Function
