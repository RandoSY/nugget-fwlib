# XC8 Assembly Programmer Review

**Input:** `nugget_cli_monitor.lst`

## Executive summary

- Physical listing lines: **4462**
- Recognized assembly/directive/label lines: **3881**
- Executable instruction lines: **3537**
- Labels: **309**
- Rough static cycle sum, one pass through listed instructions: **5350.5** cycles
- Findings: **186** — STRONG 1, WARN 50, INFO 135

The cycle number is not runtime. Loops, branches, skips, interrupts, and oscillator setup change real timing. It is a programmer-orientation metric.

## First recognized program lines

```asm
    4: C:\Users\rasyoung\Desktop\nugget-fwlib\apps\nugget_cli_monitor\nugget_cli_monitor.gcb                                                                      Mon May 25 13:42:24 2026
    7: processor	16F18424
    8: pagewidth 180
    9: psect	udata_shr,global,class=COMMON,space=1,delta=1,noexec
   10: psect	udata,global,class=RAM,space=1,delta=1,noexec
   11: psect	udata_bank0,global,class=BANK0,space=1,delta=1,noexec
   12: psect	udata_bank1,global,class=BANK1,space=1,delta=1,noexec
   13: psect	udata_bank2,global,class=BANK2,space=1,delta=1,noexec
   14: psect	udata_bank3,global,class=BANK3,space=1,delta=1,noexec
   15: psect	udata_bank4,global,class=BANK4,space=1,delta=1,noexec
   16: psect	udata_bank5,global,class=BANK5,space=1,delta=1,noexec
   17: psect	udata_bank6,global,class=BANK6,space=1,delta=1,noexec
   18: psect	code,global,class=CODE,delta=2
   19: psect	data,global,class=STRCODE,delta=2,noexec
   20: psect	edata,global,class=EEDATA,space=3,delta=2,noexec
   21: psect	PROGMEM0,global,abs,delta=2
   22: psect	PROGMEM1,global,abs,ovrld,class=CODE,delta=2
   23: psect	config,global,abs,ovrld,class=CONFIG,space=4,delta=2,noexec
   56: psect	edata
  188: psect	PROGMEM0
  189: 0000 RESETVEC:
  194: 0000 org	0
  195: 0000 pagesel	BASPROGRAMSTART
  196: 0001 goto	BASPROGRAMSTART
  197: 0004 org	4
  198: 0004 retfie
  202: 0005 org	5
  203: 0005 BASPROGRAMSTART:
  206: 0005 call	INITSYS
  207: 0006 call	INITUSART
```

## Instruction mix

| Mnemonic | Count | Programmer meaning |
|---|---:|---|
| `retlw` | 1121 | instruction |
| `movwf` | 560 | store W into register |
| `movlw` | 531 | load literal into W |
| `goto` | 287 | unconditional branch |
| `movf` | 178 | move/read file register, often setting flags |
| `fcall` | 166 | instruction |
| `btfss` | 144 | bit test, skip if set |
| `subwf` | 127 | instruction |
| `clrf` | 90 | clear register |
| `call` | 84 | instruction |
| `return` | 53 | instruction |
| `bsf` | 52 | set one bit |
| `bcf` | 39 | clear one bit |
| `btfsc` | 23 | bit test, skip if clear |
| `ljmp` | 18 | long jump |
| `addwf` | 16 | instruction |
| `incf` | 15 | instruction |
| `rlf` | 14 | rotate/shift left through carry |
| `comf` | 11 | instruction |
| `sublw` | 2 | instruction |
| `nop` | 2 | no operation/timing padding |
| `pagesel` | 1 | instruction |
| `retfie` | 1 | instruction |
| `sleep` | 1 | instruction |
| `iorwf` | 1 | instruction |

## Register/SFR interpretation

| Line | Numeric operand | Symbol meaning | Instruction |
|---:|---:|---|---|
| 2854 | 0 | `stk_offset/auto_size` | `movf	0,w` |
| 2872 | 0 | `stk_offset/auto_size` | `movf	0,w` |
| 2967 | 0 | `stk_offset/auto_size` | `movwf	0` |
| 3009 | 0 | `stk_offset/auto_size` | `addwf	0,w` |

## Source-line map

No C source references were found in the parsed instruction stream.

## Findings

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'RB_NCO_PRINTSTATUS' is called 13 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 229, 629, 636, 658, 666, 674, 682, 690, 698, 706.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'HSERPRINT422' is called 69 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 249, 267, 396, 415, 434, 453, 556, 575, 751, 773.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'HSERPRINTCRLF' is called 32 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 279, 401, 420, 439, 458, 561, 580, 761, 2204, 2245.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'DELAY_MS' is called 8 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 292, 298, 2209, 2214, 2219, 2224, 2229, 3456.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'RB_LED_STATUS_ON' is called 5 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 568, 2205, 2215, 2225, 3558.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'HSERPRINT424' is called 17 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 756, 2475, 2495, 2563, 2575, 2601, 2627, 2662, 2688, 2722.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 206: HOT_CALL_TARGET [INFO]
Address: `0005`

```asm
   200  0005  236F               	call	INITSYS
```
Parsed / interpreted as: `call INITSYS`

**Finding:** Function 'HSERSEND410' is called 10 times.

**Why it matters:** Frequent calls to tiny functions may cost more than the work they perform. Related lines: 833, 867, 899, 931, 2874, 2902, 2933, 3011, 3028, 3031.

**Suggested action:** Inspect whether this helper should be inline or simplified.

Local context:
```asm
   203: BASPROGRAMSTART:
=> 206: call	INITSYS
   207: call	INITUSART
```

### Line 277: REPEATED_MOVLW [WARN]
Address: `006B`

```asm
   271  006B  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 275.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   274: fcall	HSERPRINT425
   275: movlw	1
   276: movwf	45
=> 277: movlw	1
   278: movwf	44
   279: fcall	HSERPRINTCRLF
   280: incf	37,f
```

### Line 281: STATUS_Z_TEST [INFO]
Address: `0071`

```asm
   275  0071  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   278: movwf	44
   279: fcall	HSERPRINTCRLF
   280: incf	37,f
=> 281: btfsc	3,2
   282: incf	38,f
   283: btfsc	3,2
   284: incf	39,f
```

### Line 283: STATUS_Z_TEST [INFO]
Address: `0073`

```asm
   277  0073  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   280: incf	37,f
   281: btfsc	3,2
   282: incf	38,f
=> 283: btfsc	3,2
   284: incf	39,f
   285: btfsc	3,2
   286: incf	40,f
```

### Line 285: STATUS_Z_TEST [INFO]
Address: `0075`

```asm
   279  0075  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   282: incf	38,f
   283: btfsc	3,2
   284: incf	39,f
=> 285: btfsc	3,2
   286: incf	40,f
   287: fcall	RB_LED_STATUS_TOGGLE
   288: movlw	244
```

### Line 310: STATUS_Z_TEST [INFO]
Address: `008D`

```asm
   304  008D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   308: movlw	63
   309: subwf	36,w
=> 310: btfss	3,2
   311: goto	ELSE4_1
   312: fcall	CLI_PRINTHELP
   313: goto	ENDIF4
```

### Line 317: STATUS_Z_TEST [INFO]
Address: `0095`

```asm
   311  0095  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   314: ELSE4_1:
   315: movlw	72
   316: subwf	36,w
=> 317: btfss	3,2
   318: goto	ELSE4_2
   319: fcall	CLI_PRINTHELP
   320: goto	ENDIF4
```

### Line 324: STATUS_Z_TEST [INFO]
Address: `009D`

```asm
   318  009D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   321: ELSE4_2:
   322: movlw	104
   323: subwf	36,w
=> 324: btfss	3,2
   325: goto	ELSE4_3
   326: fcall	CLI_PRINTHELP
   327: goto	ENDIF4
```

### Line 331: STATUS_Z_TEST [INFO]
Address: `00A5`

```asm
   325  00A5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   328: ELSE4_3:
   329: movlw	73
   330: subwf	36,w
=> 331: btfss	3,2
   332: goto	ELSE4_4
   333: fcall	CLI_PRINTIDENTITY
   334: goto	ENDIF4
```

### Line 338: STATUS_Z_TEST [INFO]
Address: `00AD`

```asm
   332  00AD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   335: ELSE4_4:
   336: movlw	105
   337: subwf	36,w
=> 338: btfss	3,2
   339: goto	ELSE4_5
   340: fcall	CLI_PRINTIDENTITY
   341: goto	ENDIF4
```

### Line 345: STATUS_Z_TEST [INFO]
Address: `00B5`

```asm
   339  00B5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   342: ELSE4_5:
   343: movlw	83
   344: subwf	36,w
=> 345: btfss	3,2
   346: goto	ELSE4_6
   347: fcall	CLI_PRINTSTATUS
   348: goto	ENDIF4
```

### Line 352: STATUS_Z_TEST [INFO]
Address: `00BD`

```asm
   346  00BD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   349: ELSE4_6:
   350: movlw	115
   351: subwf	36,w
=> 352: btfss	3,2
   353: goto	ELSE4_7
   354: fcall	CLI_PRINTSTATUS
   355: goto	ENDIF4
```

### Line 359: STATUS_Z_TEST [INFO]
Address: `00C5`

```asm
   353  00C5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   356: ELSE4_7:
   357: movlw	80
   358: subwf	36,w
=> 359: btfss	3,2
   360: goto	ELSE4_8
   361: fcall	CLI_PRINTSWITCH
   362: goto	ENDIF4
```

### Line 366: STATUS_Z_TEST [INFO]
Address: `00CD`

```asm
   360  00CD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   363: ELSE4_8:
   364: movlw	112
   365: subwf	36,w
=> 366: btfss	3,2
   367: goto	ELSE4_9
   368: fcall	CLI_PRINTSWITCH
   369: goto	ENDIF4
```

### Line 373: STATUS_Z_TEST [INFO]
Address: `00D5`

```asm
   367  00D5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   370: ELSE4_9:
   371: movlw	65
   372: subwf	36,w
=> 373: btfss	3,2
   374: goto	ELSE4_10
   375: fcall	CLI_PRINTADC
   376: goto	ENDIF4
```

### Line 380: STATUS_Z_TEST [INFO]
Address: `00DD`

```asm
   374  00DD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   377: ELSE4_10:
   378: movlw	97
   379: subwf	36,w
=> 380: btfss	3,2
   381: goto	ELSE4_11
   382: fcall	CLI_PRINTADC
   383: goto	ENDIF4
```

### Line 387: STATUS_Z_TEST [INFO]
Address: `00E5`

```asm
   381  00E5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   384: ELSE4_11:
   385: movlw	82
   386: subwf	36,w
=> 387: btfss	3,2
   388: goto	ELSE4_12
   389: bsf	75,0
   390: movlw	low STRINGTABLE44
```

### Line 399: REPEATED_MOVLW [WARN]
Address: `00F3`

```asm
   393  00F3  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 397.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   396: fcall	HSERPRINT422
   397: movlw	1
   398: movwf	45
=> 399: movlw	1
   400: movwf	44
   401: fcall	HSERPRINTCRLF
   402: goto	ENDIF4
```

### Line 406: STATUS_Z_TEST [INFO]
Address: `00FB`

```asm
   400  00FB  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   403: ELSE4_12:
   404: movlw	114
   405: subwf	36,w
=> 406: btfss	3,2
   407: goto	ELSE4_13
   408: bsf	75,0
   409: movlw	low STRINGTABLE44
```

### Line 418: REPEATED_MOVLW [WARN]
Address: `0109`

```asm
   412  0109  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 416.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   415: fcall	HSERPRINT422
   416: movlw	1
   417: movwf	45
=> 418: movlw	1
   419: movwf	44
   420: fcall	HSERPRINTCRLF
   421: goto	ENDIF4
```

### Line 425: STATUS_Z_TEST [INFO]
Address: `0111`

```asm
   419  0111  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   422: ELSE4_13:
   423: movlw	84
   424: subwf	36,w
=> 425: btfss	3,2
   426: goto	ELSE4_14
   427: bcf	75,0
   428: movlw	low STRINGTABLE45
```

### Line 437: REPEATED_MOVLW [WARN]
Address: `011F`

```asm
   431  011F  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 435.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   434: fcall	HSERPRINT422
   435: movlw	1
   436: movwf	45
=> 437: movlw	1
   438: movwf	44
   439: fcall	HSERPRINTCRLF
   440: goto	ENDIF4
```

### Line 444: STATUS_Z_TEST [INFO]
Address: `0127`

```asm
   438  0127  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   441: ELSE4_14:
   442: movlw	116
   443: subwf	36,w
=> 444: btfss	3,2
   445: goto	ELSE4_15
   446: bcf	75,0
   447: movlw	low STRINGTABLE45
```

### Line 456: REPEATED_MOVLW [WARN]
Address: `0135`

```asm
   450  0135  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 454.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   453: fcall	HSERPRINT422
   454: movlw	1
   455: movwf	45
=> 456: movlw	1
   457: movwf	44
   458: fcall	HSERPRINTCRLF
   459: goto	ENDIF4
```

### Line 463: STATUS_Z_TEST [INFO]
Address: `013D`

```asm
   457  013D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   460: ELSE4_15:
   461: movlw	68
   462: subwf	36,w
=> 463: btfss	3,2
   464: goto	ELSE4_16
   465: fcall	CLI_DIAGNOSTICBLINK
   466: goto	ENDIF4
```

### Line 470: STATUS_Z_TEST [INFO]
Address: `0145`

```asm
   464  0145  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   467: ELSE4_16:
   468: movlw	100
   469: subwf	36,w
=> 470: btfss	3,2
   471: goto	ELSE4_17
   472: fcall	CLI_DIAGNOSTICBLINK
   473: goto	ENDIF4
```

### Line 477: STATUS_Z_TEST [INFO]
Address: `014D`

```asm
   471  014D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   474: ELSE4_17:
   475: movlw	88
   476: subwf	36,w
=> 477: btfss	3,2
   478: goto	ELSE4_18
   479: fcall	CLI_I2CSCANPLACEHOLDER
   480: goto	ENDIF4
```

### Line 484: STATUS_Z_TEST [INFO]
Address: `0155`

```asm
   478  0155  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   481: ELSE4_18:
   482: movlw	120
   483: subwf	36,w
=> 484: btfss	3,2
   485: goto	ELSE4_19
   486: fcall	CLI_I2CSCANPLACEHOLDER
   487: goto	ENDIF4
```

### Line 491: STATUS_Z_TEST [INFO]
Address: `015D`

```asm
   485  015D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   488: ELSE4_19:
   489: movlw	77
   490: subwf	36,w
=> 491: btfss	3,2
   492: goto	ELSE4_20
   493: fcall	RB_LEDBANK_PRINTMAP
   494: goto	ENDIF4
```

### Line 498: STATUS_Z_TEST [INFO]
Address: `0165`

```asm
   492  0165  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   495: ELSE4_20:
   496: movlw	109
   497: subwf	36,w
=> 498: btfss	3,2
   499: goto	ELSE4_21
   500: fcall	RB_LEDBANK_PRINTMAP
   501: goto	ENDIF4
```

### Line 505: STATUS_Z_TEST [INFO]
Address: `016D`

```asm
   499  016D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   502: ELSE4_21:
   503: movlw	78
   504: subwf	36,w
=> 505: btfss	3,2
   506: goto	ELSE4_22
   507: fcall	CLI_NEXTLED
   508: goto	ENDIF4
```

### Line 512: STATUS_Z_TEST [INFO]
Address: `0175`

```asm
   506  0175  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   509: ELSE4_22:
   510: movlw	110
   511: subwf	36,w
=> 512: btfss	3,2
   513: goto	ELSE4_23
   514: fcall	CLI_NEXTLED
   515: goto	ENDIF4
```

### Line 519: STATUS_Z_TEST [INFO]
Address: `017D`

```asm
   513  017D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   516: ELSE4_23:
   517: movlw	43
   518: subwf	36,w
=> 519: btfss	3,2
   520: goto	ELSE4_24
   521: fcall	CLI_SELECTEDLEDON
   522: goto	ENDIF4
```

### Line 526: STATUS_Z_TEST [INFO]
Address: `0185`

```asm
   520  0185  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   523: ELSE4_24:
   524: movlw	45
   525: subwf	36,w
=> 526: btfss	3,2
   527: goto	ELSE4_25
   528: fcall	CLI_SELECTEDLEDOFF
   529: goto	ENDIF4
```

### Line 533: STATUS_Z_TEST [INFO]
Address: `018D`

```asm
   527  018D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   530: ELSE4_25:
   531: movlw	76
   532: subwf	36,w
=> 533: btfss	3,2
   534: goto	ELSE4_26
   535: fcall	CLI_SELECTEDLEDTOGGLE
   536: goto	ENDIF4
```

### Line 540: STATUS_Z_TEST [INFO]
Address: `0195`

```asm
   534  0195  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   537: ELSE4_26:
   538: movlw	108
   539: subwf	36,w
=> 540: btfss	3,2
   541: goto	ELSE4_27
   542: fcall	CLI_SELECTEDLEDTOGGLE
   543: goto	ENDIF4
```

### Line 547: STATUS_Z_TEST [INFO]
Address: `019D`

```asm
   541  019D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   544: ELSE4_27:
   545: movlw	48
   546: subwf	36,w
=> 547: btfss	3,2
   548: goto	ELSE4_28
   549: fcall	RB_LED_STATUS_OFF
   550: movlw	low STRINGTABLE46
```

### Line 559: REPEATED_MOVLW [WARN]
Address: `01AD`

```asm
   553  01AD  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 557.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   556: fcall	HSERPRINT422
   557: movlw	1
   558: movwf	45
=> 559: movlw	1
   560: movwf	44
   561: fcall	HSERPRINTCRLF
   562: goto	ENDIF4
```

### Line 566: STATUS_Z_TEST [INFO]
Address: `01B5`

```asm
   560  01B5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   563: ELSE4_28:
   564: movlw	49
   565: subwf	36,w
=> 566: btfss	3,2
   567: goto	ELSE4_29
   568: fcall	RB_LED_STATUS_ON
   569: movlw	low STRINGTABLE47
```

### Line 578: REPEATED_MOVLW [WARN]
Address: `01C5`

```asm
   572  01C5  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 576.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   575: fcall	HSERPRINT422
   576: movlw	1
   577: movwf	45
=> 578: movlw	1
   579: movwf	44
   580: fcall	HSERPRINTCRLF
   581: goto	ENDIF4
```

### Line 585: STATUS_Z_TEST [INFO]
Address: `01CD`

```asm
   579  01CD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   582: ELSE4_29:
   583: movlw	89
   584: subwf	36,w
=> 585: btfss	3,2
   586: goto	ELSE4_30
   587: fcall	RB_7SEG_PRINTMAP
   588: goto	ENDIF4
```

### Line 592: STATUS_Z_TEST [INFO]
Address: `01D5`

```asm
   586  01D5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   589: ELSE4_30:
   590: movlw	121
   591: subwf	36,w
=> 592: btfss	3,2
   593: goto	ELSE4_31
   594: fcall	RB_7SEG_PRINTMAP
   595: goto	ENDIF4
```

### Line 599: STATUS_Z_TEST [INFO]
Address: `01DD`

```asm
   593  01DD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   596: ELSE4_31:
   597: movlw	71
   598: subwf	36,w
=> 599: btfss	3,2
   600: goto	ELSE4_32
   601: fcall	CLI_NEXTDIGIT
   602: goto	ENDIF4
```

### Line 606: STATUS_Z_TEST [INFO]
Address: `01E5`

```asm
   600  01E5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   603: ELSE4_32:
   604: movlw	103
   605: subwf	36,w
=> 606: btfss	3,2
   607: goto	ELSE4_33
   608: fcall	CLI_NEXTDIGIT
   609: goto	ENDIF4
```

### Line 613: STATUS_Z_TEST [INFO]
Address: `01ED`

```asm
   607  01ED  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   610: ELSE4_33:
   611: movlw	67
   612: subwf	36,w
=> 613: btfss	3,2
   614: goto	ELSE4_34
   615: fcall	CLI_SENDDEMOCHARTODIGIT
   616: goto	ENDIF4
```

### Line 620: STATUS_Z_TEST [INFO]
Address: `01F5`

```asm
   614  01F5  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   617: ELSE4_34:
   618: movlw	99
   619: subwf	36,w
=> 620: btfss	3,2
   621: goto	ELSE4_35
   622: fcall	CLI_SENDDEMOCHARTODIGIT
   623: goto	ENDIF4
```

### Line 627: STATUS_Z_TEST [INFO]
Address: `01FD`

```asm
   621  01FD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   624: ELSE4_35:
   625: movlw	79
   626: subwf	36,w
=> 627: btfss	3,2
   628: goto	ELSE4_36
   629: fcall	RB_NCO_PRINTSTATUS
   630: goto	ENDIF4
```

### Line 634: STATUS_Z_TEST [INFO]
Address: `0205`

```asm
   628  0205  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   631: ELSE4_36:
   632: movlw	111
   633: subwf	36,w
=> 634: btfss	3,2
   635: goto	ELSE4_37
   636: fcall	RB_NCO_PRINTSTATUS
   637: goto	ENDIF4
```

### Line 641: STATUS_Z_TEST [INFO]
Address: `020D`

```asm
   635  020D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   638: ELSE4_37:
   639: movlw	86
   640: subwf	36,w
=> 641: btfss	3,2
   642: goto	ELSE4_38
   643: fcall	RB_NCO_PRINTFORMULANOTE
   644: goto	ENDIF4
```

### Line 648: STATUS_Z_TEST [INFO]
Address: `0215`

```asm
   642  0215  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   645: ELSE4_38:
   646: movlw	118
   647: subwf	36,w
=> 648: btfss	3,2
   649: goto	ELSE4_39
   650: fcall	RB_NCO_PRINTFORMULANOTE
   651: goto	ENDIF4
```

### Line 655: STATUS_Z_TEST [INFO]
Address: `021D`

```asm
   649  021D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   652: ELSE4_39:
   653: movlw	74
   654: subwf	36,w
=> 655: btfss	3,2
   656: goto	ELSE4_40
   657: fcall	RB_NCO_SETDEMOSLOW
   658: fcall	RB_NCO_PRINTSTATUS
```

### Line 663: STATUS_Z_TEST [INFO]
Address: `0228`

```asm
   657  0228  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   660: ELSE4_40:
   661: movlw	106
   662: subwf	36,w
=> 663: btfss	3,2
   664: goto	ELSE4_41
   665: fcall	RB_NCO_SETDEMOSLOW
   666: fcall	RB_NCO_PRINTSTATUS
```

### Line 671: STATUS_Z_TEST [INFO]
Address: `0233`

```asm
   665  0233  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   668: ELSE4_41:
   669: movlw	75
   670: subwf	36,w
=> 671: btfss	3,2
   672: goto	ELSE4_42
   673: fcall	RB_NCO_SETDEMOMEDIUM
   674: fcall	RB_NCO_PRINTSTATUS
```

### Line 679: STATUS_Z_TEST [INFO]
Address: `023E`

```asm
   673  023E  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   676: ELSE4_42:
   677: movlw	107
   678: subwf	36,w
=> 679: btfss	3,2
   680: goto	ELSE4_43
   681: fcall	RB_NCO_SETDEMOMEDIUM
   682: fcall	RB_NCO_PRINTSTATUS
```

### Line 687: STATUS_Z_TEST [INFO]
Address: `0249`

```asm
   681  0249  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   684: ELSE4_43:
   685: movlw	81
   686: subwf	36,w
=> 687: btfss	3,2
   688: goto	ELSE4_44
   689: fcall	RB_NCO_SETDEMOFAST
   690: fcall	RB_NCO_PRINTSTATUS
```

### Line 695: STATUS_Z_TEST [INFO]
Address: `0254`

```asm
   689  0254  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   692: ELSE4_44:
   693: movlw	113
   694: subwf	36,w
=> 695: btfss	3,2
   696: goto	ELSE4_45
   697: fcall	RB_NCO_SETDEMOFAST
   698: fcall	RB_NCO_PRINTSTATUS
```

### Line 703: STATUS_Z_TEST [INFO]
Address: `025F`

```asm
   697  025F  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   700: ELSE4_45:
   701: movlw	69
   702: subwf	36,w
=> 703: btfss	3,2
   704: goto	ELSE4_46
   705: fcall	RB_NCO_ENABLESOFTWARESTATE
   706: fcall	RB_NCO_PRINTSTATUS
```

### Line 711: STATUS_Z_TEST [INFO]
Address: `026A`

```asm
   705  026A  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   708: ELSE4_46:
   709: movlw	101
   710: subwf	36,w
=> 711: btfss	3,2
   712: goto	ELSE4_47
   713: fcall	RB_NCO_ENABLESOFTWARESTATE
   714: fcall	RB_NCO_PRINTSTATUS
```

### Line 719: STATUS_Z_TEST [INFO]
Address: `0275`

```asm
   713  0275  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   716: ELSE4_47:
   717: movlw	87
   718: subwf	36,w
=> 719: btfss	3,2
   720: goto	ELSE4_48
   721: fcall	RB_NCO_DISABLESOFTWARESTATE
   722: fcall	RB_NCO_PRINTSTATUS
```

### Line 727: STATUS_Z_TEST [INFO]
Address: `0280`

```asm
   721  0280  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   724: ELSE4_48:
   725: movlw	119
   726: subwf	36,w
=> 727: btfss	3,2
   728: goto	ELSE4_49
   729: fcall	RB_NCO_DISABLESOFTWARESTATE
   730: fcall	RB_NCO_PRINTSTATUS
```

### Line 735: SKIP_WITH_DOUBLE_GOTO [INFO]
Address: `028B`

```asm
   729  028B  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Skip instruction feeds a two-GOTO decision pattern.

**Why it matters:** XC8 often implements if/else as skip + goto + goto. Correct, but not always compact. Related lines: 736, 737.

**Suggested action:** For tiny code, inspect whether source logic can be rearranged so the fall-through path is the common path.

Local context:
```asm
   732: ELSE4_49:
   733: movlw	13
   734: subwf	36,w
=> 735: btfss	3,2
   736: goto	ELSE4_50
   737: goto	ENDIF4
   738: ELSE4_50:
```

### Line 735: STATUS_Z_TEST [INFO]
Address: `028B`

```asm
   729  028B  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   732: ELSE4_49:
   733: movlw	13
   734: subwf	36,w
=> 735: btfss	3,2
   736: goto	ELSE4_50
   737: goto	ENDIF4
   738: ELSE4_50:
```

### Line 741: SKIP_WITH_DOUBLE_GOTO [INFO]
Address: `0290`

```asm
   735  0290  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Skip instruction feeds a two-GOTO decision pattern.

**Why it matters:** XC8 often implements if/else as skip + goto + goto. Correct, but not always compact. Related lines: 742, 743.

**Suggested action:** For tiny code, inspect whether source logic can be rearranged so the fall-through path is the common path.

Local context:
```asm
   738: ELSE4_50:
   739: movlw	10
   740: subwf	36,w
=> 741: btfss	3,2
   742: goto	ELSE4_51
   743: goto	ENDIF4
   744: ELSE4_51:
```

### Line 741: STATUS_Z_TEST [INFO]
Address: `0290`

```asm
   735  0290  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   738: ELSE4_50:
   739: movlw	10
   740: subwf	36,w
=> 741: btfss	3,2
   742: goto	ELSE4_51
   743: goto	ENDIF4
   744: ELSE4_51:
```

### Line 759: REPEATED_MOVLW [WARN]
Address: `02A5`

```asm
   753  02A5  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 757.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   756: fcall	HSERPRINT424
   757: movlw	1
   758: movwf	45
=> 759: movlw	1
   760: movwf	44
   761: fcall	HSERPRINTCRLF
   762: ENDIF4:
```

### Line 796: REPEATED_MOVLW [WARN]
Address: `02CE`

```asm
   790  02CE  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 794.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   793: ENDIF28:
   794: movlw	1
   795: movwf	45
=> 796: movlw	1
   797: movwf	44
   798: ljmp	HSERPRINTCRLF
   799: HSERPRINT425:
```

### Line 978: REPEATED_MOVLW [WARN]
Address: `0389`

```asm
   972  0389  3040               	movlw	64
```
Parsed / interpreted as: `movlw 64`

**Finding:** MOVLW reloads literal 64 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 976.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   975: movwf	284
   976: movlw	64
   977: movwf	283
=> 978: movlw	64
   979: movwf	283
   980: bsf	287,3
   981: bsf	286,2
```

### Line 1002: STATUS_Z_TEST [INFO]
Address: `039B`

```asm
   996  039B  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   999: movwf	10
   1000: movf	119,w
   1001: incf	119,f
=> 1002: btfsc	3,2
   1003: incf	120,f
   1004: movwf	2
   1005: STRINGTABLE9:
```

### Line 2202: REPEATED_MOVLW [WARN]
Address: `080B`

```asm
  2196  080B  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2200.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2199: fcall	HSERPRINT422
   2200: movlw	1
   2201: movwf	45
=> 2202: movlw	1
   2203: movwf	44
   2204: fcall	HSERPRINTCRLF
   2205: fcall	RB_LED_STATUS_ON
```

### Line 2243: REPEATED_MOVLW [WARN]
Address: `0849`

```asm
  2237  0849  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2241.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2240: call	HSERPRINT422
   2241: movlw	1
   2242: movwf	45
=> 2243: movlw	1
   2244: movwf	44
   2245: fcall	HSERPRINTCRLF
   2246: movlw	low STRINGTABLE31
```

### Line 2255: REPEATED_MOVLW [WARN]
Address: `0857`

```asm
  2249  0857  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2253.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2252: call	HSERPRINT422
   2253: movlw	1
   2254: movwf	45
=> 2255: movlw	1
   2256: movwf	44
   2257: ljmp	HSERPRINTCRLF
   2258: CLI_NEXTDIGIT:
```

### Line 2307: REPEATED_MOVLW [WARN]
Address: `0883`

```asm
  2301  0883  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2305.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2304: fcall	HSERPRINT425
   2305: movlw	1
   2306: movwf	45
=> 2307: movlw	1
   2308: movwf	44
   2309: ljmp	HSERPRINTCRLF
   2310: CLI_PRINTBANNER:
```

### Line 2322: REPEATED_MOVLW [WARN]
Address: `0893`

```asm
  2316  0893  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2320.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2319: fcall	HSERPRINT422
   2320: movlw	1
   2321: movwf	45
=> 2322: movlw	1
   2323: movwf	44
   2324: fcall	HSERPRINTCRLF
   2325: movlw	low STRINGTABLE10
```

### Line 2334: REPEATED_MOVLW [WARN]
Address: `08A3`

```asm
  2328  08A3  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2332.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2331: fcall	HSERPRINT422
   2332: movlw	1
   2333: movwf	45
=> 2334: movlw	1
   2335: movwf	44
   2336: fcall	HSERPRINTCRLF
   2337: movlw	low STRINGTABLE11
```

### Line 2346: REPEATED_MOVLW [WARN]
Address: `08B3`

```asm
  2340  08B3  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2344.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2343: fcall	HSERPRINT422
   2344: movlw	1
   2345: movwf	45
=> 2346: movlw	1
   2347: movwf	44
   2348: ljmp	HSERPRINTCRLF
   2349: CLI_PRINTHELP:
```

### Line 2354: REPEATED_MOVLW [WARN]
Address: `08BA`

```asm
  2348  08BA  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2352.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2352: movlw	1
   2353: movwf	45
=> 2354: movlw	1
   2355: movwf	44
   2356: fcall	HSERPRINTCRLF
   2357: movlw	low STRINGTABLE12
```

### Line 2366: REPEATED_MOVLW [WARN]
Address: `08C8`

```asm
  2360  08C8  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2364.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2363: call	HSERPRINT422
   2364: movlw	1
   2365: movwf	45
=> 2366: movlw	1
   2367: movwf	44
   2368: fcall	HSERPRINTCRLF
   2369: movlw	low STRINGTABLE13
```

### Line 2378: REPEATED_MOVLW [WARN]
Address: `08D6`

```asm
  2372  08D6  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2376.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2375: call	HSERPRINT422
   2376: movlw	1
   2377: movwf	45
=> 2378: movlw	1
   2379: movwf	44
   2380: fcall	HSERPRINTCRLF
   2381: movlw	low STRINGTABLE14
```

### Line 2390: REPEATED_MOVLW [WARN]
Address: `08E4`

```asm
  2384  08E4  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2388.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2387: call	HSERPRINT422
   2388: movlw	1
   2389: movwf	45
=> 2390: movlw	1
   2391: movwf	44
   2392: fcall	HSERPRINTCRLF
   2393: movlw	low STRINGTABLE15
```

### Line 2402: REPEATED_MOVLW [WARN]
Address: `08F2`

```asm
  2396  08F2  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2400.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2399: call	HSERPRINT422
   2400: movlw	1
   2401: movwf	45
=> 2402: movlw	1
   2403: movwf	44
   2404: fcall	HSERPRINTCRLF
   2405: movlw	low STRINGTABLE16
```

### Line 2414: REPEATED_MOVLW [WARN]
Address: `0900`

```asm
  2408  0900  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2412.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2411: call	HSERPRINT422
   2412: movlw	1
   2413: movwf	45
=> 2414: movlw	1
   2415: movwf	44
   2416: fcall	HSERPRINTCRLF
   2417: movlw	low STRINGTABLE17
```

### Line 2426: REPEATED_MOVLW [WARN]
Address: `090E`

```asm
  2420  090E  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2424.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2423: call	HSERPRINT422
   2424: movlw	1
   2425: movwf	45
=> 2426: movlw	1
   2427: movwf	44
   2428: fcall	HSERPRINTCRLF
   2429: movlw	low STRINGTABLE18
```

### Line 2438: REPEATED_MOVLW [WARN]
Address: `091C`

```asm
  2432  091C  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2436.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2435: call	HSERPRINT422
   2436: movlw	1
   2437: movwf	45
=> 2438: movlw	1
   2439: movwf	44
   2440: fcall	HSERPRINTCRLF
   2441: movlw	1
```

### Line 2443: REPEATED_MOVLW [WARN]
Address: `0923`

```asm
  2437  0923  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2441.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2440: fcall	HSERPRINTCRLF
   2441: movlw	1
   2442: movwf	45
=> 2443: movlw	1
   2444: movwf	44
   2445: ljmp	HSERPRINTCRLF
   2446: CLI_PRINTIDENTITY:
```

### Line 2458: REPEATED_MOVLW [WARN]
Address: `0931`

```asm
  2452  0931  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2456.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2455: call	HSERPRINT422
   2456: movlw	1
   2457: movwf	45
=> 2458: movlw	1
   2459: movwf	44
   2460: ljmp	HSERPRINTCRLF
   2461: CLI_PRINTSELECTEDDIGIT:
```

### Line 2478: REPEATED_MOVLW [WARN]
Address: `0944`

```asm
  2472  0944  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2476.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2475: call	HSERPRINT424
   2476: movlw	1
   2477: movwf	45
=> 2478: movlw	1
   2479: movwf	44
   2480: ljmp	HSERPRINTCRLF
   2481: CLI_PRINTSELECTEDLED:
```

### Line 2520: REPEATED_MOVLW [WARN]
Address: `0975`

```asm
  2514  0975  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2518.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2517: ENDIF3:
   2518: movlw	1
   2519: movwf	45
=> 2520: movlw	1
   2521: movwf	44
   2522: ljmp	HSERPRINTCRLF
   2523: CLI_PRINTSTATUS:
```

### Line 2578: REPEATED_MOVLW [WARN]
Address: `09AC`

```asm
  2572  09AC  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2576.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2575: call	HSERPRINT424
   2576: movlw	1
   2577: movwf	45
=> 2578: movlw	1
   2579: movwf	44
   2580: ljmp	HSERPRINTCRLF
   2581: CLI_SELECTEDLEDOFF:
```

### Line 2611: REPEATED_MOVLW [WARN]
Address: `09CC`

```asm
  2605  09CC  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2609.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2608: call	HSERPRINT422
   2609: movlw	1
   2610: movwf	45
=> 2611: movlw	1
   2612: movwf	44
   2613: fcall	HSERPRINTCRLF
   2614: goto	ENDIF31
```

### Line 2637: REPEATED_MOVLW [WARN]
Address: `09E7`

```asm
  2631  09E7  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2635.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2634: call	HSERPRINT422
   2635: movlw	1
   2636: movwf	45
=> 2637: movlw	1
   2638: movwf	44
   2639: fcall	HSERPRINTCRLF
   2640: ENDIF31:
```

### Line 2672: REPEATED_MOVLW [WARN]
Address: `0A08`

```asm
  2666  0A08  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2670.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2669: call	HSERPRINT422
   2670: movlw	1
   2671: movwf	45
=> 2672: movlw	1
   2673: movwf	44
   2674: fcall	HSERPRINTCRLF
   2675: goto	ENDIF30
```

### Line 2698: REPEATED_MOVLW [WARN]
Address: `0A23`

```asm
  2692  0A23  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2696.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2695: call	HSERPRINT422
   2696: movlw	1
   2697: movwf	45
=> 2698: movlw	1
   2699: movwf	44
   2700: fcall	HSERPRINTCRLF
   2701: ENDIF30:
```

### Line 2732: REPEATED_MOVLW [WARN]
Address: `0A43`

```asm
  2726  0A43  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2730.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2729: call	HSERPRINT422
   2730: movlw	1
   2731: movwf	45
=> 2732: movlw	1
   2733: movwf	44
   2734: fcall	HSERPRINTCRLF
   2735: goto	ENDIF32
```

### Line 2758: REPEATED_MOVLW [WARN]
Address: `0A5E`

```asm
  2752  0A5E  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2756.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2755: call	HSERPRINT422
   2756: movlw	1
   2757: movwf	45
=> 2758: movlw	1
   2759: movwf	44
   2760: fcall	HSERPRINTCRLF
   2761: ENDIF32:
```

### Line 2787: REPEATED_MOVLW [WARN]
Address: `0A79`

```asm
  2781  0A79  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2785.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2784: call	HSERPRINT422
   2785: movlw	1
   2786: movwf	45
=> 2787: movlw	1
   2788: movwf	44
   2789: fcall	HSERPRINTCRLF
   2790: goto	ENDIF34
```

### Line 2801: REPEATED_MOVLW [WARN]
Address: `0A88`

```asm
  2795  0A88  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 2799.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   2798: call	HSERPRINT422
   2799: movlw	1
   2800: movwf	45
=> 2801: movlw	1
   2802: movwf	44
   2803: fcall	HSERPRINTCRLF
   2804: ENDIF34:
```

### Line 2823: NOP_AFTER_CONTROL_TRANSFER [WARN]
Address: `0A99`

```asm
  2817  0A99  0000               	nop
```
Parsed / interpreted as: `nop`

**Finding:** NOP follows an unconditional control transfer.

**Why it matters:** Normal execution usually cannot fall through to this NOP. Related lines: 2822.

**Suggested action:** Inspect whether this is padding, delay-loop residue, or a branch target. Remove only if not timing-relevant.

Local context:
```asm
   2820: DELAYUS0:
   2822: goto	DELAYUS0
=> 2823: nop
   2825: goto	D10US_START
   2826: return
```

### Line 2857: STATUS_Z_TEST [INFO]
Address: `0AB2`

```asm
  2851  0AB2  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   2854: movf	0,w
   2855: movwf	47
   2856: movf	47,f
=> 2857: btfsc	3,2
   2858: goto	ENDIF16
   2859: clrf	93
   2860: movlw	1
```

### Line 3023: STATUS_Z_TEST [INFO]
Address: `0B4A`

```asm
  3017  0B4A  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3021: movf	45,w
   3022: movwf	94
=> 3023: btfsc	3,2
   3024: goto	SYSREPEATLOOPEND1
   3025: SYSREPEATLOOP1:
   3026: movlw	13
```

### Line 3054: STATUS_Z_TEST [INFO]
Address: `0B64`

```asm
  3048  0B64  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3051: clrf	48
   3052: movlw	48
   3053: subwf	51,w
=> 3054: btfss	3,2
   3055: goto	ELSE43_1
   3056: movlw	63
   3057: movwf	48
```

### Line 3062: STATUS_Z_TEST [INFO]
Address: `0B6B`

```asm
  3056  0B6B  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3059: ELSE43_1:
   3060: movlw	49
   3061: subwf	51,w
=> 3062: btfss	3,2
   3063: goto	ELSE43_2
   3064: movlw	6
   3065: movwf	48
```

### Line 3070: STATUS_Z_TEST [INFO]
Address: `0B72`

```asm
  3064  0B72  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3067: ELSE43_2:
   3068: movlw	50
   3069: subwf	51,w
=> 3070: btfss	3,2
   3071: goto	ELSE43_3
   3072: movlw	91
   3073: movwf	48
```

### Line 3078: STATUS_Z_TEST [INFO]
Address: `0B79`

```asm
  3072  0B79  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3075: ELSE43_3:
   3076: movlw	51
   3077: subwf	51,w
=> 3078: btfss	3,2
   3079: goto	ELSE43_4
   3080: movlw	79
   3081: movwf	48
```

### Line 3086: STATUS_Z_TEST [INFO]
Address: `0B80`

```asm
  3080  0B80  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3083: ELSE43_4:
   3084: movlw	52
   3085: subwf	51,w
=> 3086: btfss	3,2
   3087: goto	ELSE43_5
   3088: movlw	102
   3089: movwf	48
```

### Line 3094: STATUS_Z_TEST [INFO]
Address: `0B87`

```asm
  3088  0B87  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3091: ELSE43_5:
   3092: movlw	53
   3093: subwf	51,w
=> 3094: btfss	3,2
   3095: goto	ELSE43_6
   3096: movlw	109
   3097: movwf	48
```

### Line 3102: STATUS_Z_TEST [INFO]
Address: `0B8E`

```asm
  3096  0B8E  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3099: ELSE43_6:
   3100: movlw	54
   3101: subwf	51,w
=> 3102: btfss	3,2
   3103: goto	ELSE43_7
   3104: movlw	125
   3105: movwf	48
```

### Line 3110: STATUS_Z_TEST [INFO]
Address: `0B95`

```asm
  3104  0B95  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3107: ELSE43_7:
   3108: movlw	55
   3109: subwf	51,w
=> 3110: btfss	3,2
   3111: goto	ELSE43_8
   3112: movlw	7
   3113: movwf	48
```

### Line 3118: STATUS_Z_TEST [INFO]
Address: `0B9C`

```asm
  3112  0B9C  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3115: ELSE43_8:
   3116: movlw	56
   3117: subwf	51,w
=> 3118: btfss	3,2
   3119: goto	ELSE43_9
   3120: movlw	127
   3121: movwf	48
```

### Line 3126: STATUS_Z_TEST [INFO]
Address: `0BA3`

```asm
  3120  0BA3  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3123: ELSE43_9:
   3124: movlw	57
   3125: subwf	51,w
=> 3126: btfss	3,2
   3127: goto	ELSE43_10
   3128: movlw	111
   3129: movwf	48
```

### Line 3134: STATUS_Z_TEST [INFO]
Address: `0BAA`

```asm
  3128  0BAA  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3131: ELSE43_10:
   3132: movlw	65
   3133: subwf	51,w
=> 3134: btfss	3,2
   3135: goto	ELSE43_11
   3136: movlw	119
   3137: movwf	48
```

### Line 3142: STATUS_Z_TEST [INFO]
Address: `0BB1`

```asm
  3136  0BB1  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3139: ELSE43_11:
   3140: movlw	97
   3141: subwf	51,w
=> 3142: btfss	3,2
   3143: goto	ELSE43_12
   3144: movlw	119
   3145: movwf	48
```

### Line 3150: STATUS_Z_TEST [INFO]
Address: `0BB8`

```asm
  3144  0BB8  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3147: ELSE43_12:
   3148: movlw	66
   3149: subwf	51,w
=> 3150: btfss	3,2
   3151: goto	ELSE43_13
   3152: movlw	124
   3153: movwf	48
```

### Line 3158: STATUS_Z_TEST [INFO]
Address: `0BBF`

```asm
  3152  0BBF  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3155: ELSE43_13:
   3156: movlw	98
   3157: subwf	51,w
=> 3158: btfss	3,2
   3159: goto	ELSE43_14
   3160: movlw	124
   3161: movwf	48
```

### Line 3166: STATUS_Z_TEST [INFO]
Address: `0BC6`

```asm
  3160  0BC6  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3163: ELSE43_14:
   3164: movlw	67
   3165: subwf	51,w
=> 3166: btfss	3,2
   3167: goto	ELSE43_15
   3168: movlw	57
   3169: movwf	48
```

### Line 3174: STATUS_Z_TEST [INFO]
Address: `0BCD`

```asm
  3168  0BCD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3171: ELSE43_15:
   3172: movlw	99
   3173: subwf	51,w
=> 3174: btfss	3,2
   3175: goto	ELSE43_16
   3176: movlw	88
   3177: movwf	48
```

### Line 3182: STATUS_Z_TEST [INFO]
Address: `0BD4`

```asm
  3176  0BD4  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3179: ELSE43_16:
   3180: movlw	68
   3181: subwf	51,w
=> 3182: btfss	3,2
   3183: goto	ELSE43_17
   3184: movlw	94
   3185: movwf	48
```

### Line 3190: STATUS_Z_TEST [INFO]
Address: `0BDB`

```asm
  3184  0BDB  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3187: ELSE43_17:
   3188: movlw	100
   3189: subwf	51,w
=> 3190: btfss	3,2
   3191: goto	ELSE43_18
   3192: movlw	94
   3193: movwf	48
```

### Line 3198: STATUS_Z_TEST [INFO]
Address: `0BE2`

```asm
  3192  0BE2  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3195: ELSE43_18:
   3196: movlw	69
   3197: subwf	51,w
=> 3198: btfss	3,2
   3199: goto	ELSE43_19
   3200: movlw	121
   3201: movwf	48
```

### Line 3206: STATUS_Z_TEST [INFO]
Address: `0BE9`

```asm
  3200  0BE9  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3203: ELSE43_19:
   3204: movlw	101
   3205: subwf	51,w
=> 3206: btfss	3,2
   3207: goto	ELSE43_20
   3208: movlw	121
   3209: movwf	48
```

### Line 3214: STATUS_Z_TEST [INFO]
Address: `0BF0`

```asm
  3208  0BF0  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3211: ELSE43_20:
   3212: movlw	70
   3213: subwf	51,w
=> 3214: btfss	3,2
   3215: goto	ELSE43_21
   3216: movlw	113
   3217: movwf	48
```

### Line 3222: STATUS_Z_TEST [INFO]
Address: `0BF7`

```asm
  3216  0BF7  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3219: ELSE43_21:
   3220: movlw	102
   3221: subwf	51,w
=> 3222: btfss	3,2
   3223: goto	ELSE43_22
   3224: movlw	113
   3225: movwf	48
```

### Line 3230: STATUS_Z_TEST [INFO]
Address: `0BFE`

```asm
  3224  0BFE  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3227: ELSE43_22:
   3228: movlw	72
   3229: subwf	51,w
=> 3230: btfss	3,2
   3231: goto	ELSE43_23
   3232: movlw	118
   3233: movwf	48
```

### Line 3238: STATUS_Z_TEST [INFO]
Address: `0C05`

```asm
  3232  0C05  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3235: ELSE43_23:
   3236: movlw	104
   3237: subwf	51,w
=> 3238: btfss	3,2
   3239: goto	ELSE43_24
   3240: movlw	116
   3241: movwf	48
```

### Line 3246: STATUS_Z_TEST [INFO]
Address: `0C0C`

```asm
  3240  0C0C  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3243: ELSE43_24:
   3244: movlw	76
   3245: subwf	51,w
=> 3246: btfss	3,2
   3247: goto	ELSE43_25
   3248: movlw	56
   3249: movwf	48
```

### Line 3254: STATUS_Z_TEST [INFO]
Address: `0C13`

```asm
  3248  0C13  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3251: ELSE43_25:
   3252: movlw	108
   3253: subwf	51,w
=> 3254: btfss	3,2
   3255: goto	ELSE43_26
   3256: movlw	56
   3257: movwf	48
```

### Line 3262: STATUS_Z_TEST [INFO]
Address: `0C1A`

```asm
  3256  0C1A  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3259: ELSE43_26:
   3260: movlw	80
   3261: subwf	51,w
=> 3262: btfss	3,2
   3263: goto	ELSE43_27
   3264: movlw	115
   3265: movwf	48
```

### Line 3270: STATUS_Z_TEST [INFO]
Address: `0C21`

```asm
  3264  0C21  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3267: ELSE43_27:
   3268: movlw	112
   3269: subwf	51,w
=> 3270: btfss	3,2
   3271: goto	ELSE43_28
   3272: movlw	115
   3273: movwf	48
```

### Line 3278: STATUS_Z_TEST [INFO]
Address: `0C28`

```asm
  3272  0C28  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3275: ELSE43_28:
   3276: movlw	85
   3277: subwf	51,w
=> 3278: btfss	3,2
   3279: goto	ELSE43_29
   3280: movlw	62
   3281: movwf	48
```

### Line 3286: STATUS_Z_TEST [INFO]
Address: `0C2F`

```asm
  3280  0C2F  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3283: ELSE43_29:
   3284: movlw	117
   3285: subwf	51,w
=> 3286: btfss	3,2
   3287: goto	ELSE43_30
   3288: movlw	28
   3289: movwf	48
```

### Line 3294: STATUS_Z_TEST [INFO]
Address: `0C36`

```asm
  3288  0C36  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3291: ELSE43_30:
   3292: movlw	45
   3293: subwf	51,w
=> 3294: btfss	3,2
   3295: goto	ELSE43_31
   3296: movlw	64
   3297: movwf	48
```

### Line 3302: STATUS_Z_TEST [INFO]
Address: `0C3D`

```asm
  3296  0C3D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3299: ELSE43_31:
   3300: movlw	95
   3301: subwf	51,w
=> 3302: btfss	3,2
   3303: goto	ELSE43_32
   3304: movlw	8
   3305: movwf	48
```

### Line 3310: STATUS_Z_TEST [INFO]
Address: `0C44`

```asm
  3304  0C44  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3307: ELSE43_32:
   3308: movlw	32
   3309: subwf	51,w
=> 3310: btfsc	3,2
   3311: clrf	48
   3312: ENDIF43:
   3313: return
```

### Line 3362: REPEATED_MOVLW [WARN]
Address: `0C73`

```asm
  3356  0C73  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3360.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3359: call	HSERPRINT424
   3360: movlw	1
   3361: movwf	45
=> 3362: movlw	1
   3363: movwf	44
   3364: ljmp	HSERPRINTCRLF
   3365: RB_7SEG_PRINTMAP:
```

### Line 3377: REPEATED_MOVLW [WARN]
Address: `0C83`

```asm
  3371  0C83  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3375.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3374: fcall	HSERPRINT422
   3375: movlw	1
   3376: movwf	45
=> 3377: movlw	1
   3378: movwf	44
   3379: fcall	HSERPRINTCRLF
   3380: movlw	low STRINGTABLE86
```

### Line 3389: REPEATED_MOVLW [WARN]
Address: `0C93`

```asm
  3383  0C93  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3387.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3386: fcall	HSERPRINT422
   3387: movlw	1
   3388: movwf	45
=> 3389: movlw	1
   3390: movwf	44
   3391: fcall	HSERPRINTCRLF
   3392: movlw	low STRINGTABLE87
```

### Line 3401: REPEATED_MOVLW [WARN]
Address: `0CA3`

```asm
  3395  0CA3  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3399.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3398: fcall	HSERPRINT422
   3399: movlw	1
   3400: movwf	45
=> 3401: movlw	1
   3402: movwf	44
   3403: ljmp	HSERPRINTCRLF
   3404: FN_RB_7SEG_WRITECHAR:
```

### Line 3449: REPEATED_MOVLW [WARN]
Address: `0CCC`

```asm
  3443  0CCC  3000               	movlw	0
```
Parsed / interpreted as: `movlw 0`

**Finding:** MOVLW reloads literal 0 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3447.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3446: addwf	63,f
   3447: movlw	0
=> 3449: movlw	0
   3451: movlw	0
```

### Line 3451: REPEATED_MOVLW [WARN]
Address: `0CCE`

```asm
  3445  0CCE  3000               	movlw	0
```
Parsed / interpreted as: `movlw 0`

**Finding:** MOVLW reloads literal 0 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3449.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3449: movlw	0
=> 3451: movlw	0
   3453: movlw	2
   3454: movwf	114
```

### Line 3502: STATUS_Z_TEST [INFO]
Address: `0CFA`

```asm
  3496  0CFA  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3501: movf	56,f
=> 3502: btfss	3,2
   3503: goto	ELSE8_1
   3504: bsf	76,2
   3505: goto	ENDIF8
```

### Line 3522: REPEATED_MOVLW [WARN]
Address: `0D0B`

```asm
  3516  0D0B  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3520.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3519: fcall	HSERPRINT422
   3520: movlw	1
   3521: movwf	45
=> 3522: movlw	1
   3523: movwf	44
   3524: fcall	HSERPRINTCRLF
   3525: movlw	low STRINGTABLE80
```

### Line 3534: REPEATED_MOVLW [WARN]
Address: `0D1B`

```asm
  3528  0D1B  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3532.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3531: fcall	HSERPRINT422
   3532: movlw	1
   3533: movwf	45
=> 3534: movlw	1
   3535: movwf	44
   3536: fcall	HSERPRINTCRLF
   3537: movlw	low STRINGTABLE81
```

### Line 3546: REPEATED_MOVLW [WARN]
Address: `0D2B`

```asm
  3540  0D2B  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3544.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3543: fcall	HSERPRINT422
   3544: movlw	1
   3545: movwf	45
=> 3546: movlw	1
   3547: movwf	44
   3548: ljmp	HSERPRINTCRLF
   3549: FN_RB_LEDBANK_SET:
```

### Line 3554: STATUS_Z_TEST [INFO]
Address: `0D32`

```asm
  3548  0D32  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3552: bcf	76,3
   3553: movf	56,f
=> 3554: btfss	3,2
   3555: goto	ENDIF37
   3556: btfss	76,4
   3557: goto	ELSE38_1
```

### Line 3571: STATUS_Z_TEST [INFO]
Address: `0D3D`

```asm
  3565  0D3D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3569: bcf	76,5
   3570: movf	56,f
=> 3571: btfss	3,2
   3572: goto	ENDIF39
   3573: call	RB_LED_STATUS_TOGGLE
   3574: bsf	76,5
```

### Line 3639: REPEATED_MOVLW [WARN]
Address: `0D68`

```asm
  3633  0D68  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3637.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3636: call	HSERPRINT422
   3637: movlw	1
   3638: movwf	45
=> 3639: movlw	1
   3640: movwf	44
   3641: ljmp	HSERPRINTCRLF
   3642: RB_NCO_PRINTSTATUS:
```

### Line 3679: STATUS_Z_TEST [INFO]
Address: `0D8D`

```asm
  3673  0D8D  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3676: movwf	44
   3677: call	HSERPRINT422
=> 3679: btfss	3,2
   3680: goto	ELSE12_1
   3681: movlw	low STRINGTABLE92
   3682: movwf	91
```

### Line 3736: REPEATED_MOVLW [WARN]
Address: `0DC4`

```asm
  3730  0DC4  3001               	movlw	1
```
Parsed / interpreted as: `movlw 1`

**Finding:** MOVLW reloads literal 1 already loaded earlier.

**Why it matters:** Reloading W with the same literal may be redundant if W was not consumed/clobbered. Related lines: 3734.

**Suggested action:** Inspect intervening instructions. If W was still valid, source may be forcing repeated loads.

Local context:
```asm
   3733: call	HSERPRINT424
   3734: movlw	1
   3735: movwf	45
=> 3736: movlw	1
   3737: movwf	44
   3738: ljmp	HSERPRINTCRLF
   3739: RB_NCO_SETDEMOFAST:
```

### Line 3762: BRANCH_TO_NEXT_LABEL [STRONG]
Address: `0DD7`

```asm
  3756  0DD7  2DD8               	goto	RB_NCO_SETINCREMENTBYTES
```
Parsed / interpreted as: `goto RB_NCO_SETINCREMENTBYTES`

**Finding:** GOTO goes to the next label RB_NCO_SETINCREMENTBYTES.

**Why it matters:** A branch to the very next executable location usually wastes cycles and code space. Related lines: 3763.

**Suggested action:** Remove only if not needed for psect/debug/linker artifact.

Local context:
```asm
   3759: movwf	55
   3760: clrf	53
   3761: clrf	67
=> 3762: goto	RB_NCO_SETINCREMENTBYTES
   3763: RB_NCO_SETINCREMENTBYTES:
```

### Line 3809: STATUS_Z_TEST [INFO]
Address: `0DF7`

```asm
  3803  0DF7  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3806: SYSSELECT1CASE1:
   3808: movf	32,f
=> 3809: btfss	3,2
   3810: goto	SYSSELECT1CASE2
   3812: bsf	7992,0
```

### Line 3816: STATUS_Z_TEST [INFO]
Address: `0DFD`

```asm
  3810  0DFD  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3813: goto	SYSSELECTEND1
   3814: SYSSELECT1CASE2:
=> 3816: btfss	3,2
   3817: goto	SYSSELECT1CASE3
   3819: bsf	7992,1
```

### Line 3824: STATUS_Z_TEST [INFO]
Address: `0E04`

```asm
  3818  0E04  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3821: SYSSELECT1CASE3:
   3822: movlw	2
   3823: subwf	32,w
=> 3824: btfss	3,2
   3825: goto	SYSSELECT1CASE4
   3827: bsf	7992,2
```

### Line 3832: STATUS_Z_TEST [INFO]
Address: `0E0B`

```asm
  3826  0E0B  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3829: SYSSELECT1CASE4:
   3830: movlw	3
   3831: subwf	32,w
=> 3832: btfss	3,2
   3833: goto	SYSSELECT1CASE5
   3835: bsf	7992,3
```

### Line 3840: STATUS_Z_TEST [INFO]
Address: `0E12`

```asm
  3834  0E12  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3837: SYSSELECT1CASE5:
   3838: movlw	4
   3839: subwf	32,w
=> 3840: btfss	3,2
   3841: goto	SYSSELECT1CASE6
   3843: bsf	7992,4
```

### Line 3848: STATUS_Z_TEST [INFO]
Address: `0E19`

```asm
  3842  0E19  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3845: SYSSELECT1CASE6:
   3846: movlw	5
   3847: subwf	32,w
=> 3848: btfss	3,2
   3849: goto	SYSSELECT1CASE7
   3851: bsf	7992,5
```

### Line 3856: STATUS_Z_TEST [INFO]
Address: `0E20`

```asm
  3850  0E20  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3853: SYSSELECT1CASE7:
   3854: movlw	6
   3855: subwf	32,w
=> 3856: btfss	3,2
   3857: goto	SYSSELECT1CASE8
   3859: bsf	7992,6
```

### Line 3864: STATUS_Z_TEST [INFO]
Address: `0E27`

```asm
  3858  0E27  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3861: SYSSELECT1CASE8:
   3862: movlw	7
   3863: subwf	32,w
=> 3864: btfss	3,2
   3865: goto	SYSSELECT1CASE9
   3867: bsf	7992,7
```

### Line 3872: STATUS_Z_TEST [INFO]
Address: `0E2E`

```asm
  3866  0E2E  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3869: SYSSELECT1CASE9:
   3870: movlw	8
   3871: subwf	32,w
=> 3872: btfss	3,2
   3873: goto	SYSSELECT1CASE10
   3874: bsf	33,0
   3875: goto	SYSSELECTEND1
```

### Line 3879: STATUS_Z_TEST [INFO]
Address: `0E34`

```asm
  3873  0E34  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3876: SYSSELECT1CASE10:
   3877: movlw	9
   3878: subwf	32,w
=> 3879: btfss	3,2
   3880: goto	SYSSELECT1CASE11
   3881: bsf	33,1
   3882: goto	SYSSELECTEND1
```

### Line 3886: STATUS_Z_TEST [INFO]
Address: `0E3A`

```asm
  3880  0E3A  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3883: SYSSELECT1CASE11:
   3884: movlw	10
   3885: subwf	32,w
=> 3886: btfss	3,2
   3887: goto	SYSSELECT1CASE12
   3888: bsf	33,2
   3889: goto	SYSSELECTEND1
```

### Line 3893: STATUS_Z_TEST [INFO]
Address: `0E40`

```asm
  3887  0E40  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3890: SYSSELECT1CASE12:
   3891: movlw	11
   3892: subwf	32,w
=> 3893: btfss	3,2
   3894: goto	SYSSELECT1CASE13
   3895: bsf	33,3
   3896: goto	SYSSELECTEND1
```

### Line 3900: STATUS_Z_TEST [INFO]
Address: `0E46`

```asm
  3894  0E46  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3897: SYSSELECT1CASE13:
   3898: movlw	12
   3899: subwf	32,w
=> 3900: btfss	3,2
   3901: goto	SYSSELECT1CASE14
   3902: bsf	33,4
   3903: goto	SYSSELECTEND1
```

### Line 3907: STATUS_Z_TEST [INFO]
Address: `0E4C`

```asm
  3901  0E4C  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3904: SYSSELECT1CASE14:
   3905: movlw	13
   3906: subwf	32,w
=> 3907: btfss	3,2
   3908: goto	SYSSELECT1CASE15
   3909: bsf	33,5
   3910: goto	SYSSELECTEND1
```

### Line 3914: STATUS_Z_TEST [INFO]
Address: `0E52`

```asm
  3908  0E52  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3911: SYSSELECT1CASE15:
   3912: movlw	14
   3913: subwf	32,w
=> 3914: btfss	3,2
   3915: goto	SYSSELECT1CASE16
   3916: bsf	33,6
   3917: goto	SYSSELECTEND1
```

### Line 3921: STATUS_Z_TEST [INFO]
Address: `0E58`

```asm
  3915  0E58  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3918: SYSSELECT1CASE16:
   3919: movlw	15
   3920: subwf	32,w
=> 3921: btfss	3,2
   3922: goto	SYSSELECT1CASE17
   3923: bsf	33,7
   3924: goto	SYSSELECTEND1
```

### Line 3928: STATUS_Z_TEST [INFO]
Address: `0E5E`

```asm
  3922  0E5E  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3925: SYSSELECT1CASE17:
   3926: movlw	16
   3927: subwf	32,w
=> 3928: btfss	3,2
   3929: goto	SYSSELECT1CASE18
   3931: bsf	8014,0
```

### Line 3936: STATUS_Z_TEST [INFO]
Address: `0E65`

```asm
  3930  0E65  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3933: SYSSELECT1CASE18:
   3934: movlw	17
   3935: subwf	32,w
=> 3936: btfss	3,2
   3937: goto	SYSSELECT1CASE19
   3939: bsf	8014,1
```

### Line 3944: STATUS_Z_TEST [INFO]
Address: `0E6C`

```asm
  3938  0E6C  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3941: SYSSELECT1CASE19:
   3942: movlw	18
   3943: subwf	32,w
=> 3944: btfss	3,2
   3945: goto	SYSSELECT1CASE20
   3947: bsf	8014,2
```

### Line 3952: STATUS_Z_TEST [INFO]
Address: `0E73`

```asm
  3946  0E73  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3949: SYSSELECT1CASE20:
   3950: movlw	19
   3951: subwf	32,w
=> 3952: btfss	3,2
   3953: goto	SYSSELECT1CASE21
   3955: bsf	8014,3
```

### Line 3960: STATUS_Z_TEST [INFO]
Address: `0E7A`

```asm
  3954  0E7A  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3957: SYSSELECT1CASE21:
   3958: movlw	20
   3959: subwf	32,w
=> 3960: btfss	3,2
   3961: goto	SYSSELECT1CASE22
   3963: bsf	8014,4
```

### Line 3968: STATUS_Z_TEST [INFO]
Address: `0E81`

```asm
  3962  0E81  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3965: SYSSELECT1CASE22:
   3966: movlw	21
   3967: subwf	32,w
=> 3968: btfss	3,2
   3969: goto	SYSSELECT1CASE23
   3971: bsf	8014,5
```

### Line 3976: STATUS_Z_TEST [INFO]
Address: `0E88`

```asm
  3970  0E88  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3973: SYSSELECT1CASE23:
   3974: movlw	22
   3975: subwf	32,w
=> 3976: btfss	3,2
   3977: goto	SYSSELECT1CASE24
   3979: bsf	8014,6
```

### Line 3984: STATUS_Z_TEST [INFO]
Address: `0E8F`

```asm
  3978  0E8F  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   3981: SYSSELECT1CASE24:
   3982: movlw	23
   3983: subwf	32,w
=> 3984: btfss	3,2
   3985: goto	SYSSELECTEND1
   3987: bsf	8014,7
```

### Line 4010: NOP_GENERAL [INFO]
Address: `0EAA`

```asm
  4004  0EAA  0000               	nop
```
Parsed / interpreted as: `nop`

**Finding:** NOP instruction found.

**Why it matters:** May be timing padding, alignment, or compiler residue.

**Suggested action:** Review in context; do not remove blindly.

Local context:
```asm
   4007: fcall	DELAY_10US
   4009: bsf	273,0
=> 4010: nop
   4011: SYSWAITLOOP1:
   4012: btfsc	273,0
   4013: goto	SYSWAITLOOP1
```

### Line 4032: STATUS_Z_TEST [INFO]
Address: `0EBC`

```asm
  4026  0EBC  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4029: clrf	112
   4030: movf	117,w
   4031: subwf	121,w
=> 4032: btfss	3,2
   4033: return
   4034: movf	118,w
   4035: subwf	122,w
```

### Line 4036: STATUS_Z_TEST [INFO]
Address: `0EC0`

```asm
  4030  0EC0  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4033: return
   4034: movf	118,w
   4035: subwf	122,w
=> 4036: btfss	3,2
   4037: return
   4038: comf	112,f
   4039: return
```

### Line 4046: STATUS_Z_TEST [INFO]
Address: `0EC7`

```asm
  4040  0EC7  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4043: clrf	112
   4044: movf	117,w
   4045: subwf	121,w
=> 4046: btfss	3,2
   4047: return
   4048: movf	118,w
   4049: subwf	122,w
```

### Line 4050: STATUS_Z_TEST [INFO]
Address: `0ECB`

```asm
  4044  0ECB  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4047: return
   4048: movf	118,w
   4049: subwf	122,w
=> 4050: btfss	3,2
   4051: return
   4052: movf	119,w
   4053: subwf	123,w
```

### Line 4054: STATUS_Z_TEST [INFO]
Address: `0ECF`

```asm
  4048  0ECF  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4051: return
   4052: movf	119,w
   4053: subwf	123,w
=> 4054: btfss	3,2
   4055: return
   4056: movf	120,w
   4057: subwf	124,w
```

### Line 4058: STATUS_Z_TEST [INFO]
Address: `0ED3`

```asm
  4052  0ED3  1D03               	btfss	3,2
```
Parsed / interpreted as: `btfss 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4055: return
   4056: movf	120,w
   4057: subwf	124,w
=> 4058: btfss	3,2
   4059: return
   4060: comf	112,f
   4061: return
```

### Line 4095: STATUS_Z_TEST [INFO]
Address: `0EEE`

```asm
  4089  0EEE  1903               	btfsc	3,2
```
Parsed / interpreted as: `btfsc 3, 2`

**Finding:** Code tests STATUS,Z after arithmetic/logical work.

**Why it matters:** This is the normal PIC way to implement comparisons such as == 0.

**Suggested action:** Useful marker: inspect the previous one or two instructions to understand the C condition being implemented.

Local context:
```asm
   4094: movf	121,f
=> 4095: btfsc	3,2
   4096: return
   4097: clrf	112
   4098: movlw	8
```

## Programmer notes

- Treat `volatile` comments as a clue that the compiler is preserving exact SFR access semantics.
- `movlb` is not automatically bad; it is the price of banked memory/SFRs. Repeated `movlb` only matters when no possible entry path needs it.
- Delay loops are not automatically bad; they are often exactly what `__delay_ms()` requested. They are bad only when they block useful work or depend on an undocumented oscillator assumption.
- Skip + goto + goto patterns are common compiler output for tiny PIC conditionals. They are correct but sometimes source can be rearranged for a shorter fall-through path.
