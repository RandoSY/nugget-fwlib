;'Program compiled by GCBASIC (2025.10.04 (Windows 64 bit) : Build 1523) for Microchip PIC-AS using FreeBASIC 1.07.1/2025-10-03 CRC248
;'  Please donate to help support the operational costs of the project.  Donate via https://gcbasic.com/donate/
;'  
;'  See the GCBASIC forums at http://sourceforge.net/projects/gcbasic/forums,
;'  Check the documentation and Help at http://gcbasic.sourceforge.net/help/,
;'or, email:
;'   evanvennn at users dot sourceforge dot net
;'********************************************************************************
;'   Installation Dir : C:\GCstudio\gcbasic
;'   Source file      : C:\Users\rasyoung\Desktop\nugget-fwlib\examples\012_cooperative_tick_demo\012_cooperative_tick_demo.gcb
;'   Setting file     : C:\GCstudio\gcbasic\use.ini
;'   Preserve mode    : 0
;'   Assembler        : "C:\Program Files\Microchip\xc8\v2.36\pic-as\bin\pic-as.exe"
;'   Programmer       : 
;'   Output file      : C:\Users\rasyoung\Desktop\nugget-fwlib\examples\012_cooperative_tick_demo\012_cooperative_tick_demo.asm
;'   Float Capability : 0
;'********************************************************************************

;'Set up the assembler options (Chip type, clock source, other bits and pieces)
;'PROCESSOR   16F18424
 PAGEWIDTH   180
 RADIX       DEC
 TITLE       "C:\Users\rasyoung\Desktop\nugget-fwlib\examples\012_cooperative_tick_demo\012_cooperative_tick_demo.gcb"
 SUBTITLE    "05-24-2026 17:00:35"

;' Reverse lookup file(s)
;' C:\Users\rasyoung\.mchp_packs\Microchip\PIC16F1xxxx_DFP\1.31.465\xc8\pic\include\proc\pic16f18424.inc
;' C:\Program Files\Microchip\xc8\v2.36\pic\dat\cfgdata\16f18424.cfgdata

;'********************************************************************************

;'********************************************************************************
;'Explicit CONFIG
 CONFIG FCMEN=ON                                 ;C1 Reverselookup FCMEN = ON
 CONFIG CLKOUTEN=OFF                             ;C1 Reverselookup CLKOUTEN = OFF
 CONFIG RSTOSC=HFINT32                           ;C1 Reverselookup RSTOSC = HFINT32
 CONFIG FEXTOSC=OFF                              ;C1 Reverselookup FEXTOSC = OFF
 CONFIG MCLRE=ON                                 ;C1 Reverselookup MCLRE = ON
 CONFIG WDTE=OFF                                 ;C1 Reverselookup WDTE = OFF
 CONFIG LVP=ON                                   ;C1 Reverselookup LVP = ON
 CONFIG WRTSAF=OFF                               ;C1 Reverselookup WRTSAF = OFF
 CONFIG WRTD=OFF                                 ;C1 Reverselookup WRTD = OFF
 CONFIG WRTB=OFF                                 ;C1 Reverselookup WRTB = OFF
 CONFIG CP=OFF                                   ;C1 Reverselookup CP = OFF
;'Inferred CONFIG


;'********************************************************************************
;' The XC8 xc.inc include file.  This MUST be placed after the CONFIG statements.

 #include <xc.inc>

;'********************************************************************************

;'Set aside RAM memory locations for variables. All variables are global.
 COMPORT                          EQU 32          ; 0X20
 DELAYTEMP                        EQU 112          ; 0X70 (SA)
 DELAYTEMP2                       EQU 113          ; 0X71 (SA)
 HSERPRINTCRLFCOUNT               EQU 33          ; 0X21
 PRINTLEN                         EQU 34          ; 0X22
 RB_TASKCOUNTER100MS              EQU 35          ; 0X23
 RB_TASKCOUNTER10MS               EQU 36          ; 0X24
 SERDATA                          EQU 37          ; 0X25
 STRINGPOINTER                    EQU 38          ; 0X26
 SYSBITVAR0                       EQU 39          ; 0X27
 SYSBITVAR1                       EQU 40          ; 0X28
 SYSPRINTDATAHANDLER              EQU 41          ; 0X29
 SYSPRINTDATAHANDLER_H            EQU 42          ; 0X2A
 SYSPRINTTEMP                     EQU 43          ; 0X2B
 SYSREPEATTEMP1                   EQU 44          ; 0X2C
 SYSSTRINGA                       EQU 119          ; 0X77 (SA)
 SYSSTRINGA_H                     EQU 120          ; 0X78 (SA)
 SYSTEMP1                         EQU 45          ; 0X2D
 SYSWAITTEMPMS                    EQU 114          ; 0X72 (SA)
 SYSWAITTEMPMS_H                  EQU 115          ; 0X73 (SA)

;'********************************************************************************

;'ALIAS VARIABLES
 AFSR0                            EQU 4
 AFSR0_H                          EQU 5

;'********************************************************************************

 PSECT   PROGMEM0,delta=2, abs
 RESETVEC:
;'VECTORS
	ORG	0
	PAGESEL	BASPROGRAMSTART
	GOTO	BASPROGRAMSTART
	ORG	4
	RETFIE

;'********************************************************************************

;'PROGRAM_MEMORY_PAGE: 0
	ORG	5
BASPROGRAMSTART:
;'CALL INITIALISATION ROUTINES
	CALL	INITSYS
	CALL	INITUSART

;'START_OF_THE_MAIN_PROGRAM
	CALL	RB_BOARD_INIT
	CALL	RB_LED_STATUS_INIT
	CALL	RB_SW1_INITPULLUP
	CALL	RB_TASK_INIT
SYSDOLOOP_S1:
	MOVLW	10
	MOVWF	SYSWAITTEMPMS
	CLRF	SYSWAITTEMPMS_H
	CALL	DELAY_MS
	CALL	RB_TASK_TICK10MS
	BTFSS	SYSBITVAR1,2
	GOTO	ENDIF1
	CALL	FN_RB_SW1_ISPRESSED
	BTFSS	SYSBITVAR0,2
	GOTO	ELSE3_1
	CALL	RB_LED_STATUS_ON
	GOTO	ENDIF3
ELSE3_1:
	CALL	RB_LED_STATUS_OFF
ENDIF3:
ENDIF1:
	BTFSS	SYSBITVAR1,3
	GOTO	ENDIF2
	MOVLW	LOW STRINGTABLE2
	MOVWF	SYSPRINTDATAHANDLER
	MOVLW	(HIGH STRINGTABLE2) | 128
	MOVWF	SYSPRINTDATAHANDLER_H
	MOVLW	1
	MOVWF	COMPORT
	CALL	HSERPRINT437
	MOVLW	1
	MOVWF	HSERPRINTCRLFCOUNT
	MOVLW	1
	MOVWF	COMPORT
	CALL	HSERPRINTCRLF
ENDIF2:
	CALL	RB_TASK_CLEARFLAGS
	GOTO	SYSDOLOOP_S1
SYSDOLOOP_E1:
BASPROGRAMEND:
	SLEEP
	GOTO	BASPROGRAMEND

;'********************************************************************************

DELAY_MS:
	INCF	SYSWAITTEMPMS_H, F
DMS_START:
	MOVLW	14
	MOVWF	DELAYTEMP2
DMS_OUTER:
	MOVLW	189
	MOVWF	DELAYTEMP
DMS_INNER:
	DECFSZ	DELAYTEMP, F
	GOTO	DMS_INNER
	DECFSZ	DELAYTEMP2, F
	GOTO	DMS_OUTER
	DECFSZ	SYSWAITTEMPMS, F
	GOTO	DMS_START
	DECFSZ	SYSWAITTEMPMS_H, F
	GOTO	DMS_START
	RETURN

;'********************************************************************************

HSERPRINT437:
	MOVF	SYSPRINTDATAHANDLER,W
	MOVWF	FSR0L
	MOVF	SYSPRINTDATAHANDLER_H,W
	MOVWF	FSR0H
	MOVF	INDF0,W
	MOVWF	PRINTLEN
	MOVF	PRINTLEN,F
	BTFSC	STATUS,2
	GOTO	ENDIF8
	CLRF	SYSPRINTTEMP
	MOVLW	1
	SUBWF	PRINTLEN,W
	BTFSS	STATUS,0
	GOTO	SYSFORLOOPEND1
SYSFORLOOP1:
	INCF	SYSPRINTTEMP,F
	MOVF	SYSPRINTTEMP,W
	ADDWF	SYSPRINTDATAHANDLER,W
	MOVWF	FSR0L
	MOVLW	0
	ADDWFC	SYSPRINTDATAHANDLER_H,W
	MOVWF	FSR0H
	MOVF	INDF0,W
	MOVWF	SERDATA
	CALL	HSERSEND425
	MOVF	PRINTLEN,W
	SUBWF	SYSPRINTTEMP,W
	BTFSS	STATUS,0
	GOTO	SYSFORLOOP1
SYSFORLOOPEND1:
ENDIF8:
	RETURN

;'********************************************************************************

HSERPRINTCRLF:
	MOVF	HSERPRINTCRLFCOUNT,W
	MOVWF	SYSREPEATTEMP1
	BTFSC	STATUS,2
	GOTO	SYSREPEATLOOPEND1
SYSREPEATLOOP1:
	MOVLW	13
	MOVWF	SERDATA
	CALL	HSERSEND425
	MOVLW	10
	MOVWF	SERDATA
	CALL	HSERSEND425
	DECFSZ	SYSREPEATTEMP1,F
	GOTO	SYSREPEATLOOP1
SYSREPEATLOOPEND1:
	RETURN

;'********************************************************************************

HSERSEND425:
HSERSENDUSART1HANDLER:
	MOVF	SERDATA,W
	BANKSEL	TX1REG
	MOVWF	TX1REG
	MOVLW	1
	MOVWF	SYSWAITTEMPMS
	CLRF	SYSWAITTEMPMS_H
	BANKSEL	STATUS
	GOTO	DELAY_MS

;'********************************************************************************

INITSYS:
;'DEFAULT SETTINGS FOR MICROCONTROLLERS WITH _OSCCON1_
	MOVLW	96
	BANKSEL	OSCCON1
	MOVWF	OSCCON1
	CLRF	OSCCON3
	CLRF	OSCEN
	CLRF	OSCTUNE
;'THE MCU IS A CHIP FAMILY CHIPFAMILY
;'OSCCON TYPE IS 102
	MOVLW	6
	MOVWF	OSCFRQ
;'_COMPLETE_THE_CHIP_SETUP_OF_BSR_ADCS_ANSEL_AND_OTHER_KEY_SETUP_REGISTERS_OR_REGISTER_BITS
	BANKSEL	ADCON0
	BCF	ADCON0,2
	BCF	ADCON0,7
	BANKSEL	ANSELA
	CLRF	ANSELA
	CLRF	ANSELC
	BANKSEL	CM2CON0
	BCF	CM2CON0,7
	BCF	CM1CON0,7
	BANKSEL	PORTA
	CLRF	PORTA
	CLRF	PORTC
	RETURN

;'********************************************************************************

INITUSART:
	MOVLW	3
	BANKSEL	SP1BRGH
	MOVWF	SP1BRGH
	MOVLW	64
	MOVWF	SP1BRGL
	MOVLW	64
	MOVWF	SP1BRGL
	BSF	BAUD1CON,3
	BSF	TX1STA,2
	BCF	TX1STA,4
	BSF	TX1STA,5
	BSF	RC1STA,7
	BSF	RC1STA,4
	BSF	RC1STA,4
	BANKSEL	STATUS
	RETURN

;'********************************************************************************

RB_BOARD_INIT:
	GOTO	RB_CORE_INIT

;'********************************************************************************

RB_CORE_ALLDIGITAL:
	BANKSEL	ANSELA
	CLRF	ANSELA
	CLRF	ANSELC
	BANKSEL	STATUS
	RETURN

;'********************************************************************************

RB_CORE_CLEARLATCHES:
	CLRF	LATA
	CLRF	LATC
	RETURN

;'********************************************************************************

RB_CORE_INIT:
	CALL	RB_CORE_ALLDIGITAL
	GOTO	RB_CORE_CLEARLATCHES

;'********************************************************************************

RB_LED_STATUS_INIT:
	BCF	TRISC,0
	BANKSEL	ANSELC
	BCF	ANSELC,0
	BANKSEL	LATC
	BCF	LATC,0
	RETURN

;'********************************************************************************

RB_LED_STATUS_OFF:
	BCF	LATC,0
	RETURN

;'********************************************************************************

RB_LED_STATUS_ON:
	BSF	LATC,0
	RETURN

;'********************************************************************************

RB_SW1_INITPULLUP:
	BSF	TRISA,0
	BANKSEL	ANSELA
	BCF	ANSELA,0
	BSF	WPUA,0
	BANKSEL	SYSBITVAR0
	BCF	SYSBITVAR0,0
	BTFSC	PORTA,0
	BSF	SYSBITVAR0,0
	BCF	SYSBITVAR0,1
	RETURN

;'********************************************************************************

FN_RB_SW1_ISPRESSED:
	BTFSC	PORTA,0
	GOTO	ELSE5_1
	BSF	SYSBITVAR0,2
	GOTO	ENDIF5
ELSE5_1:
	BCF	SYSBITVAR0,2
ENDIF5:
	RETURN

;'********************************************************************************

RB_TASK_CLEARFLAGS:
	BCF	SYSBITVAR1,1
	BCF	SYSBITVAR1,2
	BCF	SYSBITVAR1,3
	RETURN

;'********************************************************************************

RB_TASK_INIT:
	CLRF	RB_TASKCOUNTER10MS
	CLRF	RB_TASKCOUNTER100MS
	BCF	SYSBITVAR1,1
	BCF	SYSBITVAR1,2
	BCF	SYSBITVAR1,3
	RETURN

;'********************************************************************************

RB_TASK_TICK10MS:
	BSF	SYSBITVAR1,1
	INCF	RB_TASKCOUNTER10MS,F
	MOVLW	10
	SUBWF	RB_TASKCOUNTER10MS,W
	BTFSS	STATUS,0
	GOTO	ENDIF6
	CLRF	RB_TASKCOUNTER10MS
	BSF	SYSBITVAR1,2
	INCF	RB_TASKCOUNTER100MS,F
ENDIF6:
	MOVLW	10
	SUBWF	RB_TASKCOUNTER100MS,W
	BTFSS	STATUS,0
	GOTO	ENDIF7
	CLRF	RB_TASKCOUNTER100MS
	BSF	SYSBITVAR1,3
ENDIF7:
	RETURN

;'********************************************************************************

SYSSTRINGTABLES:
	MOVF	SYSSTRINGA_H,W
	MOVWF	PCLATH
	MOVF	SYSSTRINGA,W
	INCF	SYSSTRINGA,F
	BTFSC	STATUS,2
	INCF	SYSSTRINGA_H,F
	MOVWF	PCL

STRINGTABLE2:
	RETLW	12
	RETLW	83	;S
	RETLW	84	;T
	RETLW	65	;A
	RETLW	84	;T
	RETLW	85	;U
	RETLW	83	;S
	RETLW	32	; 
	RETLW	65	;A
	RETLW	76	;L
	RETLW	73	;I
	RETLW	86	;V
	RETLW	69	;E


;'********************************************************************************

;'PROGRAM_MEMORY_PAGE: 1
	PSECT	PROGMEM1,CLASS=CODE,SPACE=SPACE_CODE,DELTA=2, ABS, OVRLD 
	ORG	2048
;'
;' Declare Power-On-Reset entry point
;'
 END     RESETVEC
