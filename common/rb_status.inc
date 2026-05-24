''' Shared status and fault constants.
#define RB_OK 0
#define RB_ERR 1
#define RB_FAULT_NONE 0
#define RB_FAULT_BAD_CMD 1
#define RB_FAULT_BAD_ARG 2
#define RB_FAULT_SENSOR_MISSING 3
#define RB_FAULT_TIMEOUT 4
#define RB_FAULT_BUTTON_STUCK 5
#define RB_FAULT_LINE_TOO_LONG 6
Dim RB_LastFault As Byte
Sub RB_Status_Init()
    RB_LastFault = RB_FAULT_NONE
End Sub
