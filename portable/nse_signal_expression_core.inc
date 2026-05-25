'===============================================================================
' nse_signal_expression_core.inc
' Nugget Signal Expression portable core
'
' Purpose:
'   Portable Great Cow BASIC logic for expressing one measured value as:
'       DAC voltage
'       tone frequency
'       red/green visual bits
'
' Contract requirement:
'   The board/chip hook file must provide these routines:
'
'       NSE_InitHardware
'       NSE_ReadInput12
'       NSE_WriteDAC5
'       NSE_PlayToneHz
'       NSE_ShowBitOne
'       NSE_ShowBitZero
'       NSE_ShowFrameStart
'       NSE_ShowFrameEnd
'       NSE_DelayFrame
'
' Design rule:
'   This file should not contain chip-specific registers such as ANSELA,
'   TRISA, DAC1CON0, PPSLOCK, or NCO1CON.
'===============================================================================

#define NSE_ADC_FULLSCALE 4095
#define NSE_DAC5_MAX      31
#define NSE_TONE_BASE_HZ  300

Dim NSE_Value12 As Word
Dim NSE_StreamValue As Word
Dim NSE_BitWeight As Word
Dim NSE_BitIndex As Byte
Dim NSE_DAC5 As Byte
Dim NSE_ToneHz As Word


Sub NSE_ScaleValue
    ' Convert 12-bit input to 5-bit DAC value.
    NSE_DAC5 = NSE_Value12 / 128
    If NSE_DAC5 > NSE_DAC5_MAX Then
        NSE_DAC5 = NSE_DAC5_MAX
    End If

    ' Convert 12-bit input to simple teaching tone frequency.
    ' 0..4095 -> approximately 300..2347 Hz.
    NSE_ToneHz = NSE_TONE_BASE_HZ + NSE_Value12 / 2
End Sub


Sub NSE_Stream12Bits(In NSE_NewValue As Word)
    If NSE_NewValue > NSE_ADC_FULLSCALE Then
        NSE_NewValue = NSE_ADC_FULLSCALE
    End If

    NSE_StreamValue = NSE_NewValue
    NSE_BitWeight = 2048

    NSE_ShowFrameStart

    For NSE_BitIndex = 1 To 12
        If NSE_StreamValue >= NSE_BitWeight Then
            NSE_ShowBitOne
            NSE_StreamValue = NSE_StreamValue - NSE_BitWeight
        Else
            NSE_ShowBitZero
        End If
        NSE_BitWeight = NSE_BitWeight / 2
    Next

    NSE_ShowFrameEnd
End Sub


Sub NSE_RunOneFrame
    NSE_Value12 = NSE_ReadInput12

    If NSE_Value12 > NSE_ADC_FULLSCALE Then
        NSE_Value12 = NSE_ADC_FULLSCALE
    End If

    NSE_ScaleValue

    NSE_WriteDAC5 NSE_DAC5
    NSE_PlayToneHz NSE_ToneHz
    NSE_Stream12Bits NSE_Value12
    NSE_DelayFrame
End Sub
