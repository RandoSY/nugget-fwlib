Sub RB_SelfTest_LED
    LATC.0 = 1
    Wait 100 ms
    LATC.0 = 0
    Wait 100 ms
    LATC.0 = 1
    Wait 100 ms
    LATC.0 = 0
End Sub
Sub RB_SelfTest_BootMessage
    HSerPrint "BOOT NUGGET-REDBOARD PIC16F18424"
    HSerPrintCRLF
End Sub
