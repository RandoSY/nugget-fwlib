''' ADC behavior helpers: external voltage becomes a number.
Sub RB_ADC_Init()
    ' Great Cow BASIC ReadAD handles much of the detail on supported chips.
End Sub
Function RB_ADC_Read_AN0 As Word
    RB_ADC_Read_AN0 = ReadAD(AN0)
End Function
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
Function RB_ADC_ReadPercent_AN2 As Byte
    Dim RB_Value As Word
    RB_Value = ReadAD(AN2)
    RB_ADC_ReadPercent_AN2 = RB_Value / 10
End Function
