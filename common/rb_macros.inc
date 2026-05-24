''' ================================================================
''' rb_macros.inc
''' Nugget/REDBOARD macro layer for Great Cow BASIC.
'''
''' Purpose:
'''   Provide a readable symbolic vocabulary, inspired by the macro
'''   discipline of px-fwlib, but kept conservative for GCB.
'''
''' Design rule:
'''   Prefer simple #define constants and symbolic names that are easy
'''   to read and unlikely to break the compiler.
'''
'''   Avoid clever C-style function macros until proven locally.
''' ================================================================

''' ------------------------------------------------
''' Boolean / logic vocabulary
''' ------------------------------------------------

#define RB_TRUE 1
#define RB_FALSE 0

#define RB_ON 1
#define RB_OFF 0

#define RB_HIGH 1
#define RB_LOW 0

#define RB_PRESSED 1
#define RB_RELEASED 0

#define RB_ACTIVE 1
#define RB_INACTIVE 0


''' ------------------------------------------------
''' Active-level vocabulary
''' ------------------------------------------------
''' Useful for documenting whether a signal is active-high or
''' active-low without hiding the actual electrical meaning.

#define RB_ACTIVE_HIGH 1
#define RB_ACTIVE_LOW 0


''' ------------------------------------------------
''' Standard REDBOARD pin-role constants
''' ------------------------------------------------
''' These are role declarations, not full pin macros.
''' The actual register operations remain explicit in the library.

#define RB_SW1_NAME "SW1"
#define RB_SW1_PORT_NAME "PORTA"
#define RB_SW1_BIT_NUMBER 0
#define RB_SW1_ACTIVE_LEVEL RB_ACTIVE_LOW

#define RB_LED_STATUS_NAME "STATUS_LED"
#define RB_LED_STATUS_PORT_NAME "PORTC"
#define RB_LED_STATUS_BIT_NUMBER 0
#define RB_LED_STATUS_ACTIVE_LEVEL RB_ACTIVE_HIGH

#define RB_ADC_DEMO_NAME "ADC_AN2"
#define RB_ADC_DEMO_CHANNEL_NUMBER 2


''' ------------------------------------------------
''' Device identity macros
''' ------------------------------------------------

#define RB_PRODUCT_NAME "nugget-fwlib"
#define RB_BOARD_NAME_MACRO "NUGGET-REDBOARD"
#define RB_CHIP_NAME_MACRO "PIC16F18424"
#define RB_FW_VERSION_MACRO "0.1.1"


''' ------------------------------------------------
''' GSA message vocabulary
''' ------------------------------------------------

#define RB_GSA_WORD_ID "ID"
#define RB_GSA_WORD_OK "OK"
#define RB_GSA_WORD_ERR "ERR"
#define RB_GSA_WORD_DATA "DATA"
#define RB_GSA_WORD_STATUS "STATUS"
#define RB_GSA_WORD_FAULT "FAULT"

#define RB_GSA_STATUS_READY "READY"
#define RB_GSA_STATUS_RUNNING "RUNNING"
#define RB_GSA_STATUS_STOPPED "STOPPED"
#define RB_GSA_STATUS_FAULT "FAULT"

#define RB_GSA_CMD_HELLO "HELLO"
#define RB_GSA_CMD_STATUS "STATUS"
#define RB_GSA_CMD_START "START"
#define RB_GSA_CMD_STOP "STOP"
#define RB_GSA_CMD_RESET "RESET"
#define RB_GSA_CMD_TARE "TARE"
#define RB_GSA_CMD_READ "READ"

#define RB_GSA_ERR_BAD_CMD "BAD_CMD"
#define RB_GSA_ERR_BAD_ARG "BAD_ARG"
#define RB_GSA_ERR_NOT_READY "NOT_READY"
#define RB_GSA_ERR_SENSOR_MISSING "SENSOR_MISSING"
#define RB_GSA_ERR_LINE_TOO_LONG "LINE_TOO_LONG"


''' ------------------------------------------------
''' Common numeric constants
''' ------------------------------------------------

#define RB_ZERO 0
#define RB_ONE 1

#define RB_DEBOUNCE_MS 20
#define RB_IDLE_POLL_MS 50
#define RB_HALF_SECOND_MS 500
#define RB_ONE_SECOND_MS 1000

#define RB_ADC_AVG_SAMPLES_4 4
#define RB_ADC_AVG_SAMPLES_8 8
#define RB_ADC_AVG_SAMPLES_16 16


''' ------------------------------------------------
''' State-machine constants
''' ------------------------------------------------

#define RB_STATE_BOOT 0
#define RB_STATE_READY 1
#define RB_STATE_RUNNING 2
#define RB_STATE_STOPPED 3
#define RB_STATE_FAULT 4
#define RB_STATE_DEMO 5
#define RB_STATE_CALIBRATE 6


''' ------------------------------------------------
''' Fault constants
''' ------------------------------------------------

#define RB_FAULT_NONE 0
#define RB_FAULT_BAD_CMD 1
#define RB_FAULT_BAD_ARG 2
#define RB_FAULT_SENSOR_MISSING 3
#define RB_FAULT_TIMEOUT 4
#define RB_FAULT_BUTTON_STUCK 5
#define RB_FAULT_LINE_TOO_LONG 6


''' ------------------------------------------------
''' Documentation-only macro rules
''' ------------------------------------------------
''' 1. Keep register writes visible in .inc modules.
''' 2. Use macros to name intent, states, roles, and protocol words.
''' 3. Do not use macros to hide chip-specific register surprises.
''' 4. Every macro should make code more readable to a learner.
''' ================================================================
