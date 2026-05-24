''' ================================================================
''' rb_chip_16f18424.inc
''' Low-level PIC16F18424 setup helpers.
''' v0.1.1: conservative setup based on the local solid compile.
''' ================================================================

Sub RB_Core_AllDigital
    ANSELA = 0
    ANSELC = 0
End Sub

Sub RB_Core_ClearLatches
    LATA = 0
    LATC = 0
End Sub

Sub RB_Core_Init
    RB_Core_AllDigital
    RB_Core_ClearLatches
End Sub
