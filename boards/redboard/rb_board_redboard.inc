''' rb_board_redboard.inc
''' REDBOARD board profile.

#include "../../arch/pic16f1/pic16f18424/rb_chip_16f18424.inc"

#define RB_FW_VERSION "0.1.1"
#define RB_BOARD_NAME "NUGGET-REDBOARD"
#define RB_CHIP_NAME "PIC16F18424"

Sub RB_Board_Init
    RB_Core_Init
End Sub

Sub RB_Board_SendIdentity
    HSerPrint "ID "
    HSerPrint RB_BOARD_NAME
    HSerPrint " "
    HSerPrint RB_CHIP_NAME
    HSerPrint " FW="
    HSerPrint RB_FW_VERSION
    HSerPrintCRLF
End Sub
