#include "../common/rb_status.inc"
Sub RB_Diag_Init
    RB_Status_Init
End Sub
Sub RB_Diag_SetFault(In RB_Code As Byte)
    RB_LastFault = RB_Code
End Sub
Sub RB_Diag_ClearFault
    RB_LastFault = RB_FAULT_NONE
End Sub
Function RB_Diag_HasFault As Bit
    If RB_LastFault = RB_FAULT_NONE Then
        RB_Diag_HasFault = 0
    Else
        RB_Diag_HasFault = 1
    End If
End Function
Sub RB_Diag_ReportFault
    HSerPrint "FAULT "
    HSerPrint RB_LastFault
    HSerPrintCRLF
End Sub
