''' ================================================================
''' rb_nco.inc
''' Numerically Controlled Oscillator support layer.
''' Target concept: PIC16F18424 / REDBOARD / GCBASIC
'''
''' Purpose:
'''   Turn the PIC16F18424 NCO into a Nugget-visible behavior class:
'''
'''       number -> accumulator increment -> overflow rate -> frequency
'''
''' Important status:
'''   This is an advanced peripheral layer. The Microchip register
'''   family is known from the data sheet, but the exact GCBASIC
'''   chip-header register names must be verified locally before this
'''   module is promoted to compile-proven status.
'''
''' Design rule:
'''   Keep all uncertain register writes isolated in this file.
'''   Applications and CLI commands should call the RB_NCO_* API.
''' ================================================================

#define RB_NCO_STATUS_DISABLED 0
#define RB_NCO_STATUS_ENABLED 1

#define RB_NCO_MODE_FDC 0
#define RB_NCO_MODE_PFM 1

' Common demonstration increments.
' These are raw 20-bit increment values, not calibrated frequencies.
' Actual frequency depends on NCO clock source.
#define RB_NCO_INC_SLOW_L 1
#define RB_NCO_INC_SLOW_H 0
#define RB_NCO_INC_SLOW_U 0

#define RB_NCO_INC_MED_L 0
#define RB_NCO_INC_MED_H 1
#define RB_NCO_INC_MED_U 0

#define RB_NCO_INC_FAST_L 0
#define RB_NCO_INC_FAST_H 16
#define RB_NCO_INC_FAST_U 0

Dim RB_NCO_Status As Bit
Dim RB_NCO_Mode As Byte
Dim RB_NCO_IncL As Byte
Dim RB_NCO_IncH As Byte
Dim RB_NCO_IncU As Byte


Sub RB_NCO_InitState
    ' Software state only. Does not touch hardware registers.
    RB_NCO_Status = RB_NCO_STATUS_DISABLED
    RB_NCO_Mode = RB_NCO_MODE_FDC
    RB_NCO_IncL = RB_NCO_INC_SLOW_L
    RB_NCO_IncH = RB_NCO_INC_SLOW_H
    RB_NCO_IncU = RB_NCO_INC_SLOW_U
End Sub


Sub RB_NCO_SetIncrementBytes(In RB_L As Byte, In RB_H As Byte, In RB_U As Byte)
    ' Store the intended 20-bit increment value as three bytes.
    ' For the real hardware NCO, Microchip recommends writing upper/high
    ' bytes before low byte when the NCO is enabled, because the low-byte
    ' write loads the buffered increment.
    RB_NCO_IncU = RB_U
    RB_NCO_IncH = RB_H
    RB_NCO_IncL = RB_L
End Sub


Sub RB_NCO_SetDemoSlow
    RB_NCO_SetIncrementBytes(RB_NCO_INC_SLOW_L, RB_NCO_INC_SLOW_H, RB_NCO_INC_SLOW_U)
End Sub


Sub RB_NCO_SetDemoMedium
    RB_NCO_SetIncrementBytes(RB_NCO_INC_MED_L, RB_NCO_INC_MED_H, RB_NCO_INC_MED_U)
End Sub


Sub RB_NCO_SetDemoFast
    RB_NCO_SetIncrementBytes(RB_NCO_INC_FAST_L, RB_NCO_INC_FAST_H, RB_NCO_INC_FAST_U)
End Sub


Sub RB_NCO_SetModeFDC
    RB_NCO_Mode = RB_NCO_MODE_FDC
End Sub


Sub RB_NCO_SetModePFM
    RB_NCO_Mode = RB_NCO_MODE_PFM
End Sub


Sub RB_NCO_EnableSoftwareState
    ' Software status only until hardware register names are verified.
    RB_NCO_Status = RB_NCO_STATUS_ENABLED
End Sub


Sub RB_NCO_DisableSoftwareState
    ' Software status only until hardware register names are verified.
    RB_NCO_Status = RB_NCO_STATUS_DISABLED
End Sub


Sub RB_NCO_PrintStatus
    HSerPrint "NCO STATUS "
    If RB_NCO_Status = RB_NCO_STATUS_ENABLED Then
        HSerPrint "ENABLED"
    Else
        HSerPrint "DISABLED"
    End If

    HSerPrint " MODE "
    If RB_NCO_Mode = RB_NCO_MODE_PFM Then
        HSerPrint "PFM"
    Else
        HSerPrint "FDC"
    End If

    HSerPrint " INC_UHL "
    HSerPrint RB_NCO_IncU
    HSerPrint ":"
    HSerPrint RB_NCO_IncH
    HSerPrint ":"
    HSerPrint RB_NCO_IncL
    HSerPrintCRLF
End Sub


Sub RB_NCO_PrintFormulaNote
    HSerPrint "NCO FREQ = NCOCLK * INC / 2^20"
    HSerPrintCRLF
End Sub


''' ------------------------------------------------
''' Hardware adapter section
''' ------------------------------------------------
''' The following routine names define the intended hardware boundary.
''' They intentionally return RB_FALSE until the local GCB register names
''' for NCO1CON, NCO1CLK, NCO1INCU/H/L, and PPS output routing are proven.
'''
''' Once verified, this is where direct register writes belong.
''' ------------------------------------------------

Function RB_NCO_HardwareApplyIncrement As Bit
    ' Intended future implementation pattern:
    '   NCO1INCU = RB_NCO_IncU
    '   NCO1INCH = RB_NCO_IncH
    '   NCO1INCL = RB_NCO_IncL
    '
    ' Keep disabled until the exact GCB register names compile locally.
    RB_NCO_HardwareApplyIncrement = RB_FALSE
End Function


Function RB_NCO_HardwareEnable As Bit
    ' Intended future implementation pattern:
    '   configure NCO1CLK
    '   configure NCO1CON mode/polarity/output
    '   enable NCO
    '   route NCO output with PPS if output pin is desired
    '
    ' Keep disabled until register and PPS names compile locally.
    RB_NCO_HardwareEnable = RB_FALSE
End Function


Function RB_NCO_HardwareDisable As Bit
    ' Intended future implementation pattern:
    '   clear NCO enable bit in NCO1CON
    '
    ' Keep disabled until register names compile locally.
    RB_NCO_HardwareDisable = RB_FALSE
End Function
