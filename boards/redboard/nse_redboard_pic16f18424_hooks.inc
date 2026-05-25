'===============================================================================
' nse_redboard_pic16f18424_hooks.inc
' REDBOARD / PIC16F18424 hardware hooks for portable Signal Expression core
'
' This file binds the portable NSE core to a specific board/chip:
'
'   Input  : RA2 / AN2
'   DAC    : RA0 / DAC1OUT
'   Tone   : RC5 / passive piezo using GCBASIC Tone
'   ONE    : RA1 / green LED path
'   ZERO   : RC0 / red LED path
'
' Keep chip-specific register writes here, not in the portable core.
'===============================================================================

#define NSE_ONE_LED_MASK    0x02
#define NSE_ADC2_MASK       0x04
#define NSE_ZERO_LED_MASK   0x01
#define NSE_SOUND_MASK      0x20
#define SoundOut            PORTC.5

#define NSE_BIT_ON_MS       220
#define NSE_BIT_GAP_MS      80
#define NSE_FRAME_GAP_MS    500

' DAC1CON0 setup for this test:
'   bit 7 EN  = 1, DAC enabled
'   bit 5 OE1 = 1, DAC voltage output on DAC1OUT pin
'   references = AVDD / AVSS
#define NSE_DAC1_ENABLE_AVDD_AVSS_OUT 0xA0


Sub NSE_AllOff
    LATA = LATA AND 0xFD
    LATC = LATC AND 0xFE
End Sub


Sub NSE_InitHardware
    ' RA0 = analog DAC output
    ' RA1 = digital ONE/GREEN LED output
    ' RA2 = analog input AN2
    ANSELA = 0x05
    TRISA = 0x35

    ' RC0 = digital ZERO/RED LED output
    ' RC5 = piezo output for Tone
    ANSELC = 0x00
    TRISC = 0x00

    LATA = 0x00
    LATC = 0x00

    DAC1CON1 = 0
    DAC1CON0 = NSE_DAC1_ENABLE_AVDD_AVSS_OUT

    NSE_AllOff
End Sub


Function NSE_ReadInput12 As Word
    ANSELA = ANSELA OR NSE_ADC2_MASK
    TRISA = TRISA OR NSE_ADC2_MASK
    NSE_ReadInput12 = ReadAD12(AN2)
End Function


Sub NSE_WriteDAC5(In NSE_DACValue As Byte)
    If NSE_DACValue > 31 Then
        NSE_DACValue = 31
    End If
    DAC1CON1 = NSE_DACValue
End Sub


Sub NSE_PlayToneHz(In NSE_Frequency As Word)
    Tone NSE_Frequency, 12
    Wait 120 ms
End Sub


Sub NSE_ShowBitOne
    LATC = LATC AND 0xFE
    LATA = LATA OR NSE_ONE_LED_MASK
    Wait NSE_BIT_ON_MS ms
    NSE_AllOff
    Wait NSE_BIT_GAP_MS ms
End Sub


Sub NSE_ShowBitZero
    LATA = LATA AND 0xFD
    LATC = LATC OR NSE_ZERO_LED_MASK
    Wait NSE_BIT_ON_MS ms
    NSE_AllOff
    Wait NSE_BIT_GAP_MS ms
End Sub


Sub NSE_ShowFrameStart
    Tone 1200, 6
    Wait 80 ms
End Sub


Sub NSE_ShowFrameEnd
    Tone 1400, 6
    Wait 80 ms
    Tone 1400, 6
    Wait 150 ms
    NSE_AllOff
End Sub


Sub NSE_DelayFrame
    Wait NSE_FRAME_GAP_MS ms
End Sub
