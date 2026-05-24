''' HX711 behavior placeholder. HX711 is clock/data, not I2C.
Sub RB_HX711_Init()
    Dir PORTA.1 In      ' DOUT
    ANSELA.1 = 0
    Dir PORTA.2 Out     ' SCK
    ANSELA.2 = 0
    LATA.2 = 0
End Sub
Function RB_HX711_IsReady As Bit
    If PORTA.1 = 0 Then
        RB_HX711_IsReady = 1
    Else
        RB_HX711_IsReady = 0
    End If
End Function
Function RB_HX711_ReadRaw As Long
    ' Teaching placeholder: implement exact 24-bit clocking here.
    RB_HX711_ReadRaw = 0
End Function
