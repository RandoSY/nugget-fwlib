''' ================================================================
''' rb_led_bank.inc
''' Addressable LED bank primitive for REDBOARD / PIC16F18424.
'''
''' Purpose:
'''   Provide a CLI-friendly way to address LEDs by number.
'''
''' Current verified map:
'''   LED 0 = status LED on RC0, active-high.
'''
''' Pending board-map verification:
'''   LED 1..7 are reserved symbolic addresses. Fill them in once
'''   the exact REDBOARD LED pin map is confirmed.
'''
''' Design rule:
'''   The CLI may ask for LED n ON/OFF, but the board layer must be
'''   honest about which LED addresses are implemented.
''' ================================================================

#define RB_LED_COUNT 8
#define RB_LED_STATUS_INDEX 0


Sub RB_LEDBank_Init
    ' Initialize currently proven LED hardware.
    RB_LED_Status_Init
End Sub


Function RB_LEDBank_IsValid(In RB_LEDIndex As Byte) As Bit
    If RB_LEDIndex < RB_LED_COUNT Then
        RB_LEDBank_IsValid = RB_TRUE
    Else
        RB_LEDBank_IsValid = RB_FALSE
    End If
End Function


Function RB_LEDBank_IsImplemented(In RB_LEDIndex As Byte) As Bit
    ' Only LED0 / status LED is implemented until the complete
    ' REDBOARD LED pin map is verified.
    If RB_LEDIndex = RB_LED_STATUS_INDEX Then
        RB_LEDBank_IsImplemented = RB_TRUE
    Else
        RB_LEDBank_IsImplemented = RB_FALSE
    End If
End Function


Function RB_LEDBank_Set(In RB_LEDIndex As Byte, In RB_State As Bit) As Bit
    ' Returns RB_TRUE if the request was implemented.
    ' Returns RB_FALSE if the LED address is reserved but not mapped yet.

    RB_LEDBank_Set = RB_FALSE

    If RB_LEDIndex = 0 Then
        If RB_State = RB_TRUE Then
            RB_LED_Status_On
        Else
            RB_LED_Status_Off
        End If
        RB_LEDBank_Set = RB_TRUE
    End If

End Function


Function RB_LEDBank_Toggle(In RB_LEDIndex As Byte) As Bit
    RB_LEDBank_Toggle = RB_FALSE

    If RB_LEDIndex = 0 Then
        RB_LED_Status_Toggle
        RB_LEDBank_Toggle = RB_TRUE
    End If

End Function


Sub RB_LEDBank_PrintMap
    HSerPrint "LED MAP"
    HSerPrintCRLF
    HSerPrint "LED 0 = STATUS RC0 IMPLEMENTED"
    HSerPrintCRLF
    HSerPrint "LED 1..7 = RESERVED, BOARD MAP PENDING"
    HSerPrintCRLF
End Sub
