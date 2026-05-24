''' ================================================================
''' rb_chip_16f18424.inc
''' Low-level PIC16F18424 setup helpers.
''' ================================================================

Sub RB_Core_AllDigital()
    ' Many PIC pins power up as analog inputs. Disable analog for digital behavior.
    ANSELA = 0
    ANSELB = 0
    ANSELC = 0
End Sub

Sub RB_Core_ClearLatches()
    LATA = 0
    LATB = 0
    LATC = 0
End Sub

Sub RB_Core_EnableWeakPullups()
    ' On many PIC16F1 parts, OPTION_REG.WPUEN is active-low: 0 = enabled.
    OPTION_REG.WPUEN = 0
End Sub

Sub RB_Core_Init()
    RB_Core_AllDigital()
    RB_Core_ClearLatches()
    RB_Core_EnableWeakPullups()
End Sub
