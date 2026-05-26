# XC8 ASM Revelator v3.6 Triage Report

**Listing input:** `/mnt/data/nugget_cli_monitor.lst`
**Physical listing lines:** 4462
**Executable instruction lines:** 3365
**Directive lines:** 38
**All parsed labels/symbols:** 311
**True code-label candidates:** 310
**Compiler temporaries/symbols detected:** 0
**SFR/equ definitions:** 0
**Other equ symbols:** 0
**Findings:** 1517

## Executable Address Orientation

- Lowest recognized executable address: `0x1`
- Highest recognized executable address: `0xF8E`
- Approximate executable address span: `3982` words
- Executable lines with addresses: `3365`

This is listing-derived orientation, not a complete linker memory-usage proof.

## First Recognized Executable Lines

```asm
  196 addr=  0001 cyc=2   :: goto	BASPROGRAMSTART
  198 addr=  0004 cyc=2   :: retfie
  206 addr=  0005 cyc=2   :: call	INITSYS
  207 addr=  0006 cyc=2   :: call	INITUSART
  216 addr=  0019 cyc=1   :: bcf	75,0
  217 addr=  001A cyc=1   :: clrf	37
  218 addr=  001B cyc=1   :: clrf	38
  219 addr=  001C cyc=1   :: clrf	39
  220 addr=  001D cyc=1   :: clrf	40
  221 addr=  001E cyc=1   :: clrf	43
  222 addr=  001F cyc=1   :: clrf	42
  223 addr=  0020 cyc=1   :: movlw	48
  224 addr=  0021 cyc=1   :: movwf	41
  232 addr=  0034 cyc=1/2 :: btfsc	75,1
  233 addr=  0035 cyc=2   :: call	CLI_DISPATCHCOMMAND
  234 addr=  0036 cyc=1/2 :: btfss	75,0
  235 addr=  0037 cyc=2   :: goto	ELSE2_1
  236 addr=  0038 cyc=1   :: movlw	8
  237 addr=  0039 cyc=1   :: movwf	62
  239 addr=  003D cyc=1   :: movf	49,w
  240 addr=  003E cyc=1   :: movwf	34
  241 addr=  003F cyc=1   :: movf	50,w
  242 addr=  0040 cyc=1   :: movwf	35
  243 addr=  0041 cyc=1   :: movlw	low STRINGTABLE49
  244 addr=  0042 cyc=1   :: movwf	91
  245 addr=  0043 cyc=1   :: movlw	(high STRINGTABLE49)| (0+128)
  246 addr=  0044 cyc=1   :: movwf	92
  247 addr=  0045 cyc=1   :: movlw	1
  248 addr=  0046 cyc=1   :: movwf	44
  250 addr=  004A cyc=1   :: movf	37,w
  251 addr=  004B cyc=1   :: movwf	70
  252 addr=  004C cyc=1   :: movf	38,w
  253 addr=  004D cyc=1   :: movwf	71
  254 addr=  004E cyc=1   :: movf	39,w
  255 addr=  004F cyc=1   :: movwf	72
  256 addr=  0050 cyc=1   :: movf	40,w
  257 addr=  0051 cyc=1   :: movwf	73
  258 addr=  0052 cyc=1   :: movlw	1
  259 addr=  0053 cyc=1   :: movwf	44
  261 addr=  0057 cyc=1   :: movlw	low STRINGTABLE50
  262 addr=  0058 cyc=1   :: movwf	91
  263 addr=  0059 cyc=1   :: movlw	(high STRINGTABLE50)| (0+128)
  264 addr=  005A cyc=1   :: movwf	92
  265 addr=  005B cyc=1   :: movlw	1
  266 addr=  005C cyc=1   :: movwf	44
  268 addr=  0060 cyc=1   :: movf	34,w
  269 addr=  0061 cyc=1   :: movwf	70
  270 addr=  0062 cyc=1   :: movf	35,w
  271 addr=  0063 cyc=1   :: movwf	71
  272 addr=  0064 cyc=1   :: movlw	1
... 3315 additional executable lines omitted ...
```

## Symbol Classification

### Code Labels / Executable Regions

| Label | Line | Start | End | Executable instructions | Psect |
|---|---:|---:|---:|---:|---|
| `RESETVEC` | 189 | 0x1 | 0x4 | 2 | `PROGMEM0` |
| `BASPROGRAMSTART` | 203 | 0x5 | 0x1F | 11 | `PROGMEM0` |
| `SYSDOLOOP_S1` | 230 | 0x22 | 0x7D | 54 | `PROGMEM0` |
| `ELSE2_1` | 294 | 0x52 | 0x54 | 3 | `PROGMEM0` |
| `ENDIF2` | 299 | 0x58 | 0x58 | 1 | `PROGMEM0` |
| `BASPROGRAMEND` | 302 | 0x59 | 0x8A | 2 | `PROGMEM0` |
| `CLI_DISPATCHCOMMAND` | 305 | 0x5C | 0x8E | 5 | `PROGMEM0` |
| `ELSE4_1` | 314 | 0x5D | 0x9A | 5 | `PROGMEM0` |
| `ELSE4_2` | 321 | 0x9B | 0xA2 | 5 | `PROGMEM0` |
| `ELSE4_3` | 328 | 0xA3 | 0xAA | 5 | `PROGMEM0` |
| `ELSE4_4` | 335 | 0xAB | 0xB2 | 5 | `PROGMEM0` |
| `ELSE4_5` | 342 | 0xB3 | 0xBA | 5 | `PROGMEM0` |
| `ELSE4_6` | 349 | 0xBB | 0xC2 | 5 | `PROGMEM0` |
| `ELSE4_7` | 356 | 0xC3 | 0xCA | 5 | `PROGMEM0` |
| `ELSE4_8` | 363 | 0xCB | 0xD2 | 5 | `PROGMEM0` |
| `ELSE4_9` | 370 | 0xD3 | 0xDA | 5 | `PROGMEM0` |
| `ELSE4_10` | 377 | 0xDB | 0xE2 | 5 | `PROGMEM0` |
| `ELSE4_11` | 384 | 0xE3 | 0xF8 | 16 | `PROGMEM0` |
| `ELSE4_12` | 403 | 0x64 | 0x10E | 16 | `PROGMEM0` |
| `ELSE4_13` | 422 | 0x6E | 0x11F | 16 | `PROGMEM0` |
| `ELSE4_14` | 441 | 0x7D | 0x13A | 16 | `PROGMEM0` |
| `ELSE4_15` | 460 | 0x8E | 0x13E | 5 | `PROGMEM0` |
| `ELSE4_16` | 467 | 0x8F | 0x14A | 5 | `PROGMEM0` |
| `ELSE4_17` | 474 | 0x98 | 0x14E | 5 | `PROGMEM0` |
| `ELSE4_18` | 481 | 0x99 | 0x15A | 5 | `PROGMEM0` |
| `ELSE4_19` | 488 | 0xA2 | 0x15E | 5 | `PROGMEM0` |
| `ELSE4_20` | 495 | 0xA3 | 0x16A | 5 | `PROGMEM0` |
| `ELSE4_21` | 502 | 0xAC | 0x16E | 5 | `PROGMEM0` |
| `ELSE4_22` | 509 | 0xAD | 0x17A | 5 | `PROGMEM0` |
| `ELSE4_23` | 516 | 0xB6 | 0x17E | 5 | `PROGMEM0` |
| `ELSE4_24` | 523 | 0xB7 | 0x18A | 5 | `PROGMEM0` |
| `ELSE4_25` | 530 | 0xC0 | 0x18E | 5 | `PROGMEM0` |
| `ELSE4_26` | 537 | 0xC1 | 0x19A | 5 | `PROGMEM0` |
| `ELSE4_27` | 544 | 0x19B | 0x1B2 | 15 | `PROGMEM0` |
| `ELSE4_28` | 563 | 0x1B3 | 0x1CA | 15 | `PROGMEM0` |
| `ELSE4_29` | 582 | 0x1CB | 0x1D2 | 5 | `PROGMEM0` |
| `ELSE4_30` | 589 | 0x1D3 | 0x1DA | 5 | `PROGMEM0` |
| `ELSE4_31` | 596 | 0x1DB | 0x1E2 | 5 | `PROGMEM0` |
| `ELSE4_32` | 603 | 0x1E3 | 0x1EA | 5 | `PROGMEM0` |
| `ELSE4_33` | 610 | 0x1EB | 0x1F2 | 5 | `PROGMEM0` |
| `ELSE4_34` | 617 | 0x1F3 | 0x1FA | 5 | `PROGMEM0` |
| `ELSE4_35` | 624 | 0xCA | 0x1FE | 5 | `PROGMEM0` |
| `ELSE4_36` | 631 | 0xCB | 0x20A | 5 | `PROGMEM0` |
| `ELSE4_37` | 638 | 0xD4 | 0x20E | 5 | `PROGMEM0` |
| `ELSE4_38` | 645 | 0xD5 | 0x21A | 5 | `PROGMEM0` |
| `ELSE4_39` | 652 | 0xE1 | 0x21E | 5 | `PROGMEM0` |
| `ELSE4_40` | 660 | 0xE2 | 0xE6 | 5 | `PROGMEM0` |
| `ELSE4_41` | 668 | 0xE7 | 0x23B | 5 | `PROGMEM0` |
| `ELSE4_42` | 676 | 0xF6 | 0x23F | 5 | `PROGMEM0` |
| `ELSE4_43` | 684 | 0xF7 | 0x24A | 5 | `PROGMEM0` |
| `ELSE4_44` | 692 | 0xFC | 0x25C | 5 | `PROGMEM0` |
| `ELSE4_45` | 700 | 0x104 | 0x25F | 5 | `PROGMEM0` |
| `ELSE4_46` | 708 | 0x10C | 0x26B | 5 | `PROGMEM0` |
| `ELSE4_47` | 716 | 0x111 | 0x27D | 5 | `PROGMEM0` |
| `ELSE4_48` | 724 | 0x118 | 0x27F | 5 | `PROGMEM0` |
| `ELSE4_49` | 732 | 0x121 | 0x28D | 5 | `PROGMEM0` |
| `ELSE4_50` | 738 | 0x122 | 0x28F | 5 | `PROGMEM0` |
| `ELSE4_51` | 744 | 0x125 | 0x2A6 | 14 | `PROGMEM0` |
| `ENDIF4` | 762 | 0x2AA | 0x2AA | 1 | `PROGMEM0` |
| `CLI_PRINTSWITCH` | 764 | 0x2AB | 0x2C2 | 15 | `PROGMEM0` |
| `ELSE28_1` | 785 | 0x2C3 | 0x2C8 | 6 | `PROGMEM0` |
| `ENDIF28` | 793 | 0x2CC | 0x2CF | 4 | `PROGMEM0` |
| `HSERPRINT425` | 799 | 0x2D3 | 0x2F9 | 30 | `PROGMEM0` |
| `ENDIF21` | 835 | 0x12C | 0x2FF | 11 | `PROGMEM0` |
| `HSERPRINTWORD1000` | 848 | 0x134 | 0x31F | 18 | `PROGMEM0` |
| `ENDIF22` | 869 | 0x140 | 0x32C | 10 | `PROGMEM0` |
| `HSERPRINTWORD100` | 881 | 0x14A | 0x33F | 17 | `PROGMEM0` |
| `ENDIF23` | 901 | 0x158 | 0x34F | 10 | `PROGMEM0` |
| `HSERPRINTWORD10` | 913 | 0x15F | 0x35F | 16 | `PROGMEM0` |
| `ENDIF24` | 932 | 0x16F | 0x36B | 5 | `PROGMEM0` |
| `INITSYS` | 939 | 0x173 | 0x37F | 16 | `PROGMEM0` |
| `INITUSART` | 970 | 0x180 | 0x38F | 14 | `PROGMEM0` |
| `RB_CORE_CLEARLATCHES` | 989 | 0x18A | 0x18C | 3 | `PROGMEM0` |
| `SYSSTRINGTABLES` | 995 | 0x18D | 0x39D | 7 | `PROGMEM0` |
| `STRINGTABLE9` | 1005 | 0x39E | 0x3B0 | 19 | `PROGMEM0` |
| `STRINGTABLE10` | 1025 | 0x3B1 | 0x3DB | 43 | `PROGMEM0` |
| `STRINGTABLE11` | 1069 | 0x3DC | 0x3F1 | 22 | `PROGMEM0` |
| `STRINGTABLE12` | 1092 | 0x190 | 0x3FF | 20 | `PROGMEM0` |
| `STRINGTABLE13` | 1113 | 0x196 | 0x40F | 14 | `PROGMEM0` |
| `STRINGTABLE14` | 1128 | 0x19E | 0x42F | 38 | `PROGMEM0` |
| `STRINGTABLE15` | 1167 | 0x1B8 | 0x46F | 57 | `PROGMEM0` |
| `STRINGTABLE16` | 1225 | 0x1D9 | 0x4A9 | 55 | `PROGMEM0` |
| `STRINGTABLE17` | 1281 | 0x4AA | 0x4D5 | 44 | `PROGMEM0` |
| `STRINGTABLE18` | 1326 | 0x1F4 | 0x51D | 72 | `PROGMEM0` |
| `STRINGTABLE19` | 1399 | 0x208 | 0x53F | 40 | `PROGMEM0` |
| `STRINGTABLE20` | 1440 | 0x222 | 0x54D | 8 | `PROGMEM0` |
| `STRINGTABLE21` | 1449 | 0x226 | 0x55B | 14 | `PROGMEM0` |
| `STRINGTABLE22` | 1464 | 0x230 | 0x55F | 6 | `PROGMEM0` |
| `STRINGTABLE23` | 1471 | 0x232 | 0x237 | 6 | `PROGMEM0` |
| `STRINGTABLE24` | 1478 | 0x238 | 0x56F | 8 | `PROGMEM0` |
| `STRINGTABLE25` | 1487 | 0x23A | 0x23E | 5 | `PROGMEM0` |
| `STRINGTABLE26` | 1493 | 0x23F | 0x57C | 8 | `PROGMEM0` |
| `STRINGTABLE27` | 1502 | 0x244 | 0x57F | 9 | `PROGMEM0` |
| `STRINGTABLE28` | 1512 | 0x24A | 0x58F | 10 | `PROGMEM0` |
| `STRINGTABLE29` | 1523 | 0x24E | 0x59D | 14 | `PROGMEM0` |
| `STRINGTABLE30` | 1538 | 0x59E | 0x5C0 | 35 | `PROGMEM0` |
| `STRINGTABLE31` | 1574 | 0x5C1 | 0x5EE | 46 | `PROGMEM0` |
| `STRINGTABLE32` | 1621 | 0x5EF | 0x5FC | 14 | `PROGMEM0` |
| `STRINGTABLE33` | 1636 | 0x258 | 0x5FF | 13 | `PROGMEM0` |
| `STRINGTABLE34` | 1650 | 0x262 | 0x60F | 10 | `PROGMEM0` |
| `STRINGTABLE35` | 1661 | 0x266 | 0x61B | 8 | `PROGMEM0` |
| `STRINGTABLE36` | 1670 | 0x61C | 0x61F | 4 | `PROGMEM0` |
| `STRINGTABLE37` | 1675 | 0x26C | 0x274 | 9 | `PROGMEM0` |
| `STRINGTABLE38` | 1685 | 0x275 | 0x62F | 17 | `PROGMEM0` |
| `STRINGTABLE39` | 1703 | 0x63A | 0x63E | 5 | `PROGMEM0` |
| `STRINGTABLE40` | 1709 | 0x280 | 0x63F | 8 | `PROGMEM0` |
| `STRINGTABLE41` | 1718 | 0x287 | 0x65B | 21 | `PROGMEM0` |
| `STRINGTABLE42` | 1740 | 0x294 | 0x65F | 14 | `PROGMEM0` |
| `STRINGTABLE43` | 1755 | 0x29E | 0x67F | 25 | `PROGMEM0` |
| `STRINGTABLE44` | 1781 | 0x2AB | 0x68F | 17 | `PROGMEM0` |
| `STRINGTABLE45` | 1799 | 0x2B6 | 0x6A5 | 18 | `PROGMEM0` |
| `STRINGTABLE46` | 1818 | 0x6A6 | 0x6B7 | 18 | `PROGMEM0` |
| `STRINGTABLE47` | 1837 | 0x6B8 | 0x6C8 | 17 | `PROGMEM0` |
| `STRINGTABLE48` | 1855 | 0x6C9 | 0x6DB | 19 | `PROGMEM0` |
| `STRINGTABLE49` | 1875 | 0x6DC | 0x6E8 | 13 | `PROGMEM0` |
| `STRINGTABLE50` | 1889 | 0x6E9 | 0x6EE | 6 | `PROGMEM0` |
| `STRINGTABLE79` | 1896 | 0x6EF | 0x6F6 | 8 | `PROGMEM0` |
| `STRINGTABLE80` | 1905 | 0x2BC | 0x70F | 31 | `PROGMEM0` |
| `STRINGTABLE81` | 1937 | 0x2CC | 0x73C | 39 | `PROGMEM0` |
| `STRINGTABLE82` | 1977 | 0x2E4 | 0x73F | 12 | `PROGMEM0` |

### Compiler Temporaries / Generated Symbols

No compiler temporary symbols were detected.

### SFR / EQU Definitions

0 SFR/equ definitions detected. These are intentionally not counted as executable code labels.

## Developer-Facing Grouped Insights

These collapse repeated low-level assembly findings into source-level GCBASIC patterns.

| Category | Count | Actionability | Interpretation | Fix strategy | Representative lines |
|---|---:|---|---|---|---|
| `GCBASIC_LINEAR_COMPARE_CHAIN` | 109 | **High** | Linear GCBASIC command comparison chain (109 blocks). | Normalize command input to one case once; remove duplicate upper/lower tests; consider grouped/table dispatch. | 308, 315, 322, 329, 336, 343, 350, 357, 364, 371, 378, 385 |
| `GCBASIC_STRUCTURED_GOTO_FLOW` | 1217 | **Medium** | GCBASIC structured GOTO/label flow (1217 findings). | Do not remove generated GOTOs directly; simplify repeated source-level branches. | 197, 202, 236, 313, 320, 327, 334, 341, 348, 355, 362, 369 |
| `MOVF_FILE_TO_SELF` | 6 | **Review** | MOVF_FILE_TO_SELF (6 occurrences). | Keep if followed by a STATUS/Z test or skip instruction. | 2856, 3501, 3553, 3570, 3808, 4094 |
| `PIC_SKIP_CONTROL_FLOW` | 177 | **Low** | PIC_SKIP_CONTROL_FLOW (177 occurrences). | Do not optimize individual skip instructions. Reduce repeated source-level condition patterns. | 232, 234, 281, 283, 285, 310, 317, 324, 331, 338, 345, 352 |
| `DELAY_OR_TIMING` | 6 | **Low** | DELAY_OR_TIMING (6 occurrences). | In this CLI, strings and dispatch are higher-value targets than delay code. | 2817, 2820, 2831, 2834, 2837, 3025 |

## Severity Summary

- **STRONG:** 0
- **WARN:** 1218
- **INFO:** 299

## Category Summary

- **POSSIBLY_UNREACHABLE_CODE:** 1216
- **PIC_SKIP_PATTERN:** 177
- **GCBASIC_LINEAR_IF_CHAR_COMPARE:** 109
- **COUNTER_DELAY_LOOP:** 6
- **MOVF_FILE_TO_SELF:** 6
- **NOP_AFTER_BRANCH_OR_RETURN:** 1
- **BRANCH_TO_NEXT_LABEL:** 1
- **NOP_GENERAL:** 1

## Instruction Mix

| Mnemonic | Count | Rough cycle note |
|---|---:|---|
| `retlw` | 1121 | `2` |
| `movwf` | 560 | `1` |
| `movlw` | 531 | `1` |
| `goto` | 287 | `2` |
| `movf` | 178 | `1` |
| `btfss` | 144 | `1/2` |
| `subwf` | 127 | `?` |
| `clrf` | 90 | `1` |
| `call` | 84 | `2` |
| `return` | 53 | `2` |
| `bsf` | 52 | `1` |
| `bcf` | 39 | `1` |
| `btfsc` | 23 | `1/2` |
| `addwf` | 16 | `?` |
| `incf` | 15 | `?` |
| `rlf` | 14 | `?` |
| `comf` | 11 | `?` |
| `decfsz` | 10 | `1/2` |
| `decf` | 3 | `?` |
| `sublw` | 2 | `?` |
| `nop` | 2 | `1` |
| `retfie` | 1 | `2` |
| `sleep` | 1 | `?` |
| `iorwf` | 1 | `?` |

## Linker Map Summary

**Map file:** `/mnt/data/nugget_cli_monitor.map`
**Map physical lines:** 289

### Detected Map Sections

- `data_memory`: 8 hint(s)
- `program_memory`: 1 hint(s)
- `psect`: 2 hint(s)
- `symbol`: 1 hint(s)

### Psect / Section Candidates

| Name | Start | End | Size | Notes |
|---|---:|---:|---:|---|
| `ABANK2` | - | - | - | -ABANK2=0120h-016Fh -ABANK3=01A0h-01EFh -ABANK4=0220h-026Fh \ |
| `ABANK5` | - | - | - | -ABANK5=02A0h-02EFh -ABANK6=0320h-032Fh -ABIGRAM=02000h-021EFh \ |
| `ABS1` | - | - | - | CLASS   ABS1 |
| `ACOMMON` | - | - | - | -ACOMMON=070h-07Fh -ABANK0=020h-06Fh -ABANK1=0A0h-0EFh \ |
| `ACONFIG` | - | - | - | -ACONFIG=08007h-0800Bh -DCONFIG=2 -AIDLOC=08000h-08003h -DIDLOC=2 \ |
| `AEEDATA` | - | - | - | -AEEDATA=00h-0FFh/0F000h -DEEDATA=2 -DCODE=2 -DSTRCODE=2 -DSTRING=2 \ |
| `BANK0` | 0x14 | 0x82 | 111 | CLASS   BANK0 / BANK0            00020-0006F              50           1 |
| `BANK1` | 0xA0 | 0x18E | 239 | CLASS   BANK1 / BANK1            000A0-000EF              50           1 |
| `BANK2` | 0x78 | 0x1E6 | 367 | CLASS   BANK2 / BANK2            00120-0016F              50           1 |
| `BANK3` | 0x1A0 | 0x38E | 495 | CLASS   BANK3 / BANK3            001A0-001EF              50           1 |
| `BANK4` | 0xDC | 0x34A | 623 | CLASS   BANK4 / BANK4            00220-0026F              50           1 |
| `BANK5` | 0x2A0 | 0x58E | 751 | CLASS   BANK5 / BANK5            002A0-002EF              50           1 |
| `BANK6` | 0x140 | 0x46E | 815 | CLASS   BANK6 / BANK6            00320-0032F              10           1 |
| `BIGRAM` | - | - | - | CLASS   BIGRAM |
| `COMMON` | 0x46 | 0xC4 | 127 | CLASS   COMMON / COMMON           00070-0007F              10           1 |
| `CONFIG` | - | - | - | CLASS   CONFIG |
| `CONST` | - | - | - | CLASS   CONST |
| `E1` | 0x5D5 | - | - | -E1 --acfsm=1493 -ACODE=00h-07FFhx2 -ASTRCODE=00h-0FFFh \ |
| `EEDATA` | - | - | - | CLASS   EEDATA |
| `ENTRY` | - | - | - | CLASS   ENTRY |
| `IDLOC` | - | - | - | CLASS   IDLOC |
| `Object` | - | - | - | Object code version is 3.11 |
| `RAM` | - | - | - | CLASS   RAM |
| `SEGMENTS` | - | - | - | SEGMENTS        Name                           Load    Length   Top    Selector  |
| `SFR0` | - | - | - | CLASS   SFR0 |
| `SFR1` | - | - | - | CLASS   SFR1 |
| `SFR10` | - | - | - | CLASS   SFR10 |
| `SFR11` | - | - | - | CLASS   SFR11 |
| `SFR12` | - | - | - | CLASS   SFR12 |
| `SFR13` | - | - | - | CLASS   SFR13 |
| `SFR14` | - | - | - | CLASS   SFR14 |
| `SFR15` | - | - | - | CLASS   SFR15 |
| `SFR16` | - | - | - | CLASS   SFR16 |
| `SFR17` | - | - | - | CLASS   SFR17 |
| `SFR18` | - | - | - | CLASS   SFR18 |
| `SFR19` | - | - | - | CLASS   SFR19 |
| `SFR2` | - | - | - | CLASS   SFR2 |
| `SFR20` | - | - | - | CLASS   SFR20 |
| `SFR21` | - | - | - | CLASS   SFR21 |
| `SFR22` | - | - | - | CLASS   SFR22 |
| `SFR23` | - | - | - | CLASS   SFR23 |
| `SFR24` | - | - | - | CLASS   SFR24 |
| `SFR25` | - | - | - | CLASS   SFR25 |
| `SFR26` | - | - | - | CLASS   SFR26 |
| `SFR27` | - | - | - | CLASS   SFR27 |
| `SFR28` | - | - | - | CLASS   SFR28 |
| `SFR29` | - | - | - | CLASS   SFR29 |
| `SFR3` | - | - | - | CLASS   SFR3 |
| `SFR30` | - | - | - | CLASS   SFR30 |
| `SFR31` | - | - | - | CLASS   SFR31 |
| `SFR32` | - | - | - | CLASS   SFR32 |
| `SFR33` | - | - | - | CLASS   SFR33 |
| `SFR34` | - | - | - | CLASS   SFR34 |
| `SFR35` | - | - | - | CLASS   SFR35 |
| `SFR36` | - | - | - | CLASS   SFR36 |
| `SFR37` | - | - | - | CLASS   SFR37 |
| `SFR38` | - | - | - | CLASS   SFR38 |
| `SFR39` | - | - | - | CLASS   SFR39 |
| `SFR4` | - | - | - | CLASS   SFR4 |
| `SFR40` | - | - | - | CLASS   SFR40 |
| `SFR41` | - | - | - | CLASS   SFR41 |
| `SFR42` | - | - | - | CLASS   SFR42 |
| `SFR43` | - | - | - | CLASS   SFR43 |
| `SFR44` | - | - | - | CLASS   SFR44 |
| `SFR45` | - | - | - | CLASS   SFR45 |
| `SFR46` | - | - | - | CLASS   SFR46 |
| `SFR47` | - | - | - | CLASS   SFR47 |
| `SFR48` | - | - | - | CLASS   SFR48 |
| `SFR49` | - | - | - | CLASS   SFR49 |
| `SFR5` | - | - | - | CLASS   SFR5 |
| `SFR50` | - | - | - | CLASS   SFR50 |
| `SFR51` | - | - | - | CLASS   SFR51 |
| `SFR52` | - | - | - | CLASS   SFR52 |
| `SFR53` | - | - | - | CLASS   SFR53 |
| `SFR54` | - | - | - | CLASS   SFR54 |
| `SFR55` | - | - | - | CLASS   SFR55 |
| `SFR56` | - | - | - | CLASS   SFR56 |
| `SFR57` | - | - | - | CLASS   SFR57 |
| `SFR58` | - | - | - | CLASS   SFR58 |
| `SFR59` | - | - | - | CLASS   SFR59 |
| `SFR6` | - | - | - | CLASS   SFR6 |
| `SFR60` | - | - | - | CLASS   SFR60 |
| `SFR61` | - | - | - | CLASS   SFR61 |
| `SFR62` | - | - | - | CLASS   SFR62 |
| `SFR63` | - | - | - | CLASS   SFR63 |
| `SFR7` | - | - | - | CLASS   SFR7 |
| `SFR8` | - | - | - | CLASS   SFR8 |
| `SFR9` | - | - | - | CLASS   SFR9 |
| `STRCODE` | 0x7FF | 0xFFD | 2047 | CLASS   STRCODE / STRCODE          007FF-007FF               1           2 |
| `STRING` | - | - | - | CLASS   STRING |
| `UNCLASSED` | - | - | - | CLASS   UNCLASSED |
| `__Hcode` | 0x0 | 0x800B | 32780 | __Hcode        code        00000  __Hconfig      config      0800C |
| `__Hudata` | 0x0 | 0x-1 | 0 | __Hudata       udata       00000  __Hudata_bank0 udata_bank0 00000 |
| `__Hudata_bank1` | 0x0 | 0x-1 | 0 | __Hudata_bank1 udata_bank1 00000  __Hudata_bank2 udata_bank2 00000 |
| `__Hudata_bank3` | 0x0 | 0x-1 | 0 | __Hudata_bank3 udata_bank3 00000  __Hudata_bank4 udata_bank4 00000 |
| `__Hudata_bank5` | 0x0 | 0x-1 | 0 | __Hudata_bank5 udata_bank5 00000  __Hudata_bank6 udata_bank6 00000 |
| `__LPROGMEM1` | 0x0 | 0x-1 | 0 | __LPROGMEM1    PROGMEM1    00000  __Lcode        code        00000 |
| `__Lconfig` | 0x0 | 0x-1 | 0 | __Lconfig      config      00000  __Ldata        data        00000 |
| `__Ludata_bank0` | 0x0 | 0x-1 | 0 | __Ludata_bank0 udata_bank0 00000  __Ludata_bank1 udata_bank1 00000 |
| `__Ludata_bank2` | 0x0 | 0x-1 | 0 | __Ludata_bank2 udata_bank2 00000  __Ludata_bank3 udata_bank3 00000 |
| `__Ludata_bank4` | 0x0 | 0x-1 | 0 | __Ludata_bank4 udata_bank4 00000  __Ludata_bank5 udata_bank5 00000 |
| `__Ludata_bank6` | 0x0 | 0x-1 | 0 | __Ludata_bank6 udata_bank6 00000  __Ludata_shr   udata_shr   00000 |
| `config` | 0x1F47 | 0x3E8D | 8007 | config                             8007     8007        5        0       4 / config                             8007     8007        5         4 |

### Symbol Candidates

| Symbol | Address | Raw map line |
|---|---:|---|
| `BANK0` | 0x14 | BANK0            00020-0006F              50           1 |
| `BANK1` | 0xA0 | BANK1            000A0-000EF              50           1 |
| `BANK2` | 0x78 | BANK2            00120-0016F              50           1 |
| `BANK3` | 0x1A0 | BANK3            001A0-001EF              50           1 |
| `BANK4` | 0xDC | BANK4            00220-0026F              50           1 |
| `BANK5` | 0x2A0 | BANK5            002A0-002EF              50           1 |
| `BANK6` | 0x140 | BANK6            00320-0032F              10           1 |
| `BIGRAM` | 0x7D0 | BIGRAM           02000-021EF             1F0           1 |
| `CODE` | 0x7FF | CODE             007FF-007FF               1           2 |
| `COMMON` | 0x46 | COMMON           00070-0007F              10           1 |
| `CONST` | 0x7FF | CONST            007FF-007FF               1           2 |
| `EEDATA` | 0xF000 | EEDATA           0F000-0F0FF             100           2 |
| `ENTRY` | 0x7FF | ENTRY            007FF-007FF               1           2 |
| `IDLOC` | 0x1F40 | IDLOC            08000-08003               4           2 |
| `RAM` | 0x14 | RAM              00020-0006F              50           1 |
| `SFR62` | 0x1F1E | SFR62            01F1E-01F6F              52           1 |
| `SFR63` | 0x1F80 | SFR63            01F80-01FEF              70           1 |
| `STRCODE` | 0x7FF | STRCODE          007FF-007FF               1           2 |
| `STRING` | 0x7FF | STRING           007FF-007FF               1           2 |

### Program-Memory Related Lines

```text
        CLASS   CODE           
                PROGMEM1                            800      800      78F         0
        CLASS   STRCODE        
        CLASS   STRING         
        CLASS   CONST          
        CLASS   ENTRY          
```

### Data-Memory Related Lines

```text
        CLASS   COMMON         
        CLASS   BANK0          
        CLASS   BANK1          
        CLASS   BANK2          
        CLASS   BANK3          
        CLASS   BANK4          
        CLASS   BANK5          
        CLASS   BANK6          
        CLASS   BIGRAM         
        CLASS   RAM            
        CLASS   ABS1           
        CLASS   SFR0           
        CLASS   SFR1           
        CLASS   SFR2           
        CLASS   SFR3           
        CLASS   SFR4           
        CLASS   SFR5           
        CLASS   SFR6           
        CLASS   SFR7           
        CLASS   SFR8           
        CLASS   SFR9           
        CLASS   SFR10          
        CLASS   SFR11          
        CLASS   SFR12          
        CLASS   SFR13          
        CLASS   SFR14          
        CLASS   SFR15          
        CLASS   SFR16          
        CLASS   SFR17          
        CLASS   SFR18          
        CLASS   SFR19          
        CLASS   SFR20          
        CLASS   SFR21          
        CLASS   SFR22          
        CLASS   SFR23          
        CLASS   SFR24          
        CLASS   SFR25          
        CLASS   SFR26          
        CLASS   SFR27          
        CLASS   SFR28          
        CLASS   SFR29          
        CLASS   SFR30          
        CLASS   SFR31          
        CLASS   SFR32          
        CLASS   SFR33          
        CLASS   SFR34          
        CLASS   SFR35          
        CLASS   SFR36          
        CLASS   SFR37          
        CLASS   SFR38          
        CLASS   SFR39          
        CLASS   SFR40          
        CLASS   SFR41          
        CLASS   SFR42          
        CLASS   SFR43          
        CLASS   SFR44          
        CLASS   SFR45          
        CLASS   SFR46          
        CLASS   SFR47          
        CLASS   SFR48          
        CLASS   SFR49          
        CLASS   SFR50          
        CLASS   SFR51          
        CLASS   SFR52          
        CLASS   SFR53          
        CLASS   SFR54          
        CLASS   SFR55          
        CLASS   SFR56          
        CLASS   SFR57          
        CLASS   SFR58          
        CLASS   SFR59          
        CLASS   SFR60          
        CLASS   SFR61          
        CLASS   SFR62          
        CLASS   SFR63          
        CLASS   CONFIG         
                config                             8007     8007        5         4
        CLASS   IDLOC          
        CLASS   EEDATA         
        CLASS   UNCLASSED
                PROGMEM0                              0        0      7FF         0
SEGMENTS        Name                           Load    Length   Top    Selector   Space  Class     Delta
UNUSED ADDRESS RANGES
        Name                Unused          Largest block    Delta
        BANK0            00020-0006F              50           1
        BANK1            000A0-000EF              50           1
        BANK2            00120-0016F              50           1
        BANK3            001A0-001EF              50           1
        BANK4            00220-0026F              50           1
        BANK5            002A0-002EF              50           1
        BANK6            00320-0032F              10           1
        BIGRAM           02000-021EF             1F0           1
        CODE             007FF-007FF               1           2
                         00F8F-00FFF              71
        COMMON           00070-0007F              10           1
        CONST            007FF-007FF               1           2
                         00F8F-00FFF              71
        EEDATA           0F000-0F0FF             100           2
        ENTRY            007FF-007FF               1           2
                         00F8F-00FFF              71
... 14 more lines omitted ...
```

## Programmer Findings

Showing the first 250 line-level findings out of 1517.
The JSON report preserves the complete finding set for audit/dashboard use.
For machine-level auditing, rerun with `--profile raw` or `--show-structural`.

### Line 197 addr=0004: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
org	4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0004 appears within map psect `__Hcode` (0000-800B).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
193: ;;'VECTORS
194 addr=0000: org	0
195 addr=0000: pagesel	BASPROGRAMSTART
196 addr=0001: goto	BASPROGRAMSTART
197 addr=0004: org	4
198 addr=0004: retfie
199:    193                           
200: ;;'********************************************************************************
201: ;;'PROGRAM_MEMORY_PAGE: 0
```

### Line 202 addr=0005: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
org	5
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0005 appears within map psect `__Hcode` (0000-800B).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
198 addr=0004: retfie
199:    193                           
200: ;;'********************************************************************************
201: ;;'PROGRAM_MEMORY_PAGE: 0
202 addr=0005: org	5
203 addr=0005: BASPROGRAMSTART:
204:    198                           
205: ;;'CALL INITIALISATION ROUTINES
206 addr=0005: call	INITSYS
```

### Line 232 addr=0034: PIC_SKIP_PATTERN [INFO]

```asm
btfsc	75,1
```
**Meaning:** BTFSC conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `call	CLI_DISPATCHCOMMAND`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0034 appears within map psect `BANK0` (0014-0082).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
228 addr=002B: ;2136 3180     	fcall	CLI_PRINTSELECTEDDIGIT
229 addr=002E: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
230 addr=0031: SYSDOLOOP_S1:
231 addr=0031: ;2068 3180     	fcall	FN_CLI_POLLSERIAL
232 addr=0034: btfsc	75,1
233 addr=0035: call	CLI_DISPATCHCOMMAND
234 addr=0036: btfss	75,0
235 addr=0037: goto	ELSE2_1
236 addr=0038: movlw	8
```

### Line 234 addr=0036: PIC_SKIP_PATTERN [INFO]

```asm
btfss	75,0
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE2_1`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0036 appears within map psect `BANK0` (0014-0082).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
230 addr=0031: SYSDOLOOP_S1:
231 addr=0031: ;2068 3180     	fcall	FN_CLI_POLLSERIAL
232 addr=0034: btfsc	75,1
233 addr=0035: call	CLI_DISPATCHCOMMAND
234 addr=0036: btfss	75,0
235 addr=0037: goto	ELSE2_1
236 addr=0038: movlw	8
237 addr=0039: movwf	62
238 addr=003A: ;24B9 3180     	fcall	FN_RB_ADC_READAVERAGE_AN2
```

### Line 236 addr=0038: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
movlw	8
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0038 appears within map psect `BANK0` (0014-0082).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
232 addr=0034: btfsc	75,1
233 addr=0035: call	CLI_DISPATCHCOMMAND
234 addr=0036: btfss	75,0
235 addr=0037: goto	ELSE2_1
236 addr=0038: movlw	8
237 addr=0039: movwf	62
238 addr=003A: ;24B9 3180     	fcall	FN_RB_ADC_READAVERAGE_AN2
239 addr=003D: movf	49,w
240 addr=003E: movwf	34
```

### Line 281 addr=0071: PIC_SKIP_PATTERN [INFO]

```asm
btfsc	3,2
```
**Meaning:** BTFSC conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `incf	38,f`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0071 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
277 addr=006B: movlw	1
278 addr=006C: movwf	44
279 addr=006D: ;2348 3180     	fcall	HSERPRINTCRLF
280 addr=0070: incf	37,f
281 addr=0071: btfsc	3,2
282 addr=0072: incf	38,f
283 addr=0073: btfsc	3,2
284 addr=0074: incf	39,f
285 addr=0075: btfsc	3,2
```

### Line 283 addr=0073: PIC_SKIP_PATTERN [INFO]

```asm
btfsc	3,2
```
**Meaning:** BTFSC conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `incf	39,f`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0073 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
279 addr=006D: ;2348 3180     	fcall	HSERPRINTCRLF
280 addr=0070: incf	37,f
281 addr=0071: btfsc	3,2
282 addr=0072: incf	38,f
283 addr=0073: btfsc	3,2
284 addr=0074: incf	39,f
285 addr=0075: btfsc	3,2
286 addr=0076: incf	40,f
287 addr=0077: ;254C 3180     	fcall	RB_LED_STATUS_TOGGLE
```

### Line 285 addr=0075: PIC_SKIP_PATTERN [INFO]

```asm
btfsc	3,2
```
**Meaning:** BTFSC conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `incf	40,f`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0075 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
281 addr=0071: btfsc	3,2
282 addr=0072: incf	38,f
283 addr=0073: btfsc	3,2
284 addr=0074: incf	39,f
285 addr=0075: btfsc	3,2
286 addr=0076: incf	40,f
287 addr=0077: ;254C 3180     	fcall	RB_LED_STATUS_TOGGLE
288 addr=007A: movlw	244
289 addr=007B: movwf	114
```

### Line 310 addr=008D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_1`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 008D appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
306: ;;'********************************************************************************
307:    301                           
308 addr=008B: movlw	63
309 addr=008C: subwf	36,w
310 addr=008D: btfss	3,2
311 addr=008E: goto	ELSE4_1
312 addr=008F: ;20B8 3180     	fcall	CLI_PRINTHELP
313 addr=0092: goto	ENDIF4
314 addr=0093: ELSE4_1:
```

### Line 313 addr=0092: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0092 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
309 addr=008C: subwf	36,w
310 addr=008D: btfss	3,2
311 addr=008E: goto	ELSE4_1
312 addr=008F: ;20B8 3180     	fcall	CLI_PRINTHELP
313 addr=0092: goto	ENDIF4
314 addr=0093: ELSE4_1:
315 addr=0093: movlw	72
316 addr=0094: subwf	36,w
317 addr=0095: btfss	3,2
```

### Line 317 addr=0095: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_2`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0095 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
313 addr=0092: goto	ENDIF4
314 addr=0093: ELSE4_1:
315 addr=0093: movlw	72
316 addr=0094: subwf	36,w
317 addr=0095: btfss	3,2
318 addr=0096: goto	ELSE4_2
319 addr=0097: ;20B8 3180     	fcall	CLI_PRINTHELP
320 addr=009A: goto	ENDIF4
321 addr=009B: ELSE4_2:
```

### Line 320 addr=009A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 009A appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
316 addr=0094: subwf	36,w
317 addr=0095: btfss	3,2
318 addr=0096: goto	ELSE4_2
319 addr=0097: ;20B8 3180     	fcall	CLI_PRINTHELP
320 addr=009A: goto	ENDIF4
321 addr=009B: ELSE4_2:
322 addr=009B: movlw	104
323 addr=009C: subwf	36,w
324 addr=009D: btfss	3,2
```

### Line 324 addr=009D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_3`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 009D appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
320 addr=009A: goto	ENDIF4
321 addr=009B: ELSE4_2:
322 addr=009B: movlw	104
323 addr=009C: subwf	36,w
324 addr=009D: btfss	3,2
325 addr=009E: goto	ELSE4_3
326 addr=009F: ;20B8 3180     	fcall	CLI_PRINTHELP
327 addr=00A2: goto	ENDIF4
328 addr=00A3: ELSE4_3:
```

### Line 327 addr=00A2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00A2 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
323 addr=009C: subwf	36,w
324 addr=009D: btfss	3,2
325 addr=009E: goto	ELSE4_3
326 addr=009F: ;20B8 3180     	fcall	CLI_PRINTHELP
327 addr=00A2: goto	ENDIF4
328 addr=00A3: ELSE4_3:
329 addr=00A3: movlw	73
330 addr=00A4: subwf	36,w
331 addr=00A5: btfss	3,2
```

### Line 331 addr=00A5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_4`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00A5 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
327 addr=00A2: goto	ENDIF4
328 addr=00A3: ELSE4_3:
329 addr=00A3: movlw	73
330 addr=00A4: subwf	36,w
331 addr=00A5: btfss	3,2
332 addr=00A6: goto	ELSE4_4
333 addr=00A7: ;2128 3180     	fcall	CLI_PRINTIDENTITY
334 addr=00AA: goto	ENDIF4
335 addr=00AB: ELSE4_4:
```

### Line 334 addr=00AA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00AA appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
330 addr=00A4: subwf	36,w
331 addr=00A5: btfss	3,2
332 addr=00A6: goto	ELSE4_4
333 addr=00A7: ;2128 3180     	fcall	CLI_PRINTIDENTITY
334 addr=00AA: goto	ENDIF4
335 addr=00AB: ELSE4_4:
336 addr=00AB: movlw	105
337 addr=00AC: subwf	36,w
338 addr=00AD: btfss	3,2
```

### Line 338 addr=00AD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_5`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00AD appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
334 addr=00AA: goto	ENDIF4
335 addr=00AB: ELSE4_4:
336 addr=00AB: movlw	105
337 addr=00AC: subwf	36,w
338 addr=00AD: btfss	3,2
339 addr=00AE: goto	ELSE4_5
340 addr=00AF: ;2128 3180     	fcall	CLI_PRINTIDENTITY
341 addr=00B2: goto	ENDIF4
342 addr=00B3: ELSE4_5:
```

### Line 341 addr=00B2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00B2 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
337 addr=00AC: subwf	36,w
338 addr=00AD: btfss	3,2
339 addr=00AE: goto	ELSE4_5
340 addr=00AF: ;2128 3180     	fcall	CLI_PRINTIDENTITY
341 addr=00B2: goto	ENDIF4
342 addr=00B3: ELSE4_5:
343 addr=00B3: movlw	83
344 addr=00B4: subwf	36,w
345 addr=00B5: btfss	3,2
```

### Line 345 addr=00B5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_6`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00B5 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
341 addr=00B2: goto	ENDIF4
342 addr=00B3: ELSE4_5:
343 addr=00B3: movlw	83
344 addr=00B4: subwf	36,w
345 addr=00B5: btfss	3,2
346 addr=00B6: goto	ELSE4_6
347 addr=00B7: ;217A 3180     	fcall	CLI_PRINTSTATUS
348 addr=00BA: goto	ENDIF4
349 addr=00BB: ELSE4_6:
```

### Line 348 addr=00BA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00BA appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
344 addr=00B4: subwf	36,w
345 addr=00B5: btfss	3,2
346 addr=00B6: goto	ELSE4_6
347 addr=00B7: ;217A 3180     	fcall	CLI_PRINTSTATUS
348 addr=00BA: goto	ENDIF4
349 addr=00BB: ELSE4_6:
350 addr=00BB: movlw	115
351 addr=00BC: subwf	36,w
352 addr=00BD: btfss	3,2
```

### Line 352 addr=00BD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_7`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00BD appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
348 addr=00BA: goto	ENDIF4
349 addr=00BB: ELSE4_6:
350 addr=00BB: movlw	115
351 addr=00BC: subwf	36,w
352 addr=00BD: btfss	3,2
353 addr=00BE: goto	ELSE4_7
354 addr=00BF: ;217A 3180     	fcall	CLI_PRINTSTATUS
355 addr=00C2: goto	ENDIF4
356 addr=00C3: ELSE4_7:
```

### Line 355 addr=00C2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00C2 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
351 addr=00BC: subwf	36,w
352 addr=00BD: btfss	3,2
353 addr=00BE: goto	ELSE4_7
354 addr=00BF: ;217A 3180     	fcall	CLI_PRINTSTATUS
355 addr=00C2: goto	ENDIF4
356 addr=00C3: ELSE4_7:
357 addr=00C3: movlw	80
358 addr=00C4: subwf	36,w
359 addr=00C5: btfss	3,2
```

### Line 359 addr=00C5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_8`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00C5 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
355 addr=00C2: goto	ENDIF4
356 addr=00C3: ELSE4_7:
357 addr=00C3: movlw	80
358 addr=00C4: subwf	36,w
359 addr=00C5: btfss	3,2
360 addr=00C6: goto	ELSE4_8
361 addr=00C7: ;22AB  3180   	fcall	CLI_PRINTSWITCH
362 addr=00CA: goto	ENDIF4
363 addr=00CB: ELSE4_8:
```

### Line 362 addr=00CA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00CA appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
358 addr=00C4: subwf	36,w
359 addr=00C5: btfss	3,2
360 addr=00C6: goto	ELSE4_8
361 addr=00C7: ;22AB  3180   	fcall	CLI_PRINTSWITCH
362 addr=00CA: goto	ENDIF4
363 addr=00CB: ELSE4_8:
364 addr=00CB: movlw	112
365 addr=00CC: subwf	36,w
366 addr=00CD: btfss	3,2
```

### Line 366 addr=00CD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_9`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00CD appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
362 addr=00CA: goto	ENDIF4
363 addr=00CB: ELSE4_8:
364 addr=00CB: movlw	112
365 addr=00CC: subwf	36,w
366 addr=00CD: btfss	3,2
367 addr=00CE: goto	ELSE4_9
368 addr=00CF: ;22AB  3180   	fcall	CLI_PRINTSWITCH
369 addr=00D2: goto	ENDIF4
370 addr=00D3: ELSE4_9:
```

### Line 369 addr=00D2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00D2 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
365 addr=00CC: subwf	36,w
366 addr=00CD: btfss	3,2
367 addr=00CE: goto	ELSE4_9
368 addr=00CF: ;22AB  3180   	fcall	CLI_PRINTSWITCH
369 addr=00D2: goto	ENDIF4
370 addr=00D3: ELSE4_9:
371 addr=00D3: movlw	65
372 addr=00D4: subwf	36,w
373 addr=00D5: btfss	3,2
```

### Line 373 addr=00D5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_10`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00D5 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
369 addr=00D2: goto	ENDIF4
370 addr=00D3: ELSE4_9:
371 addr=00D3: movlw	65
372 addr=00D4: subwf	36,w
373 addr=00D5: btfss	3,2
374 addr=00D6: goto	ELSE4_10
375 addr=00D7: ;206A 3180     	fcall	CLI_PRINTADC
376 addr=00DA: goto	ENDIF4
377 addr=00DB: ELSE4_10:
```

### Line 376 addr=00DA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00DA appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
372 addr=00D4: subwf	36,w
373 addr=00D5: btfss	3,2
374 addr=00D6: goto	ELSE4_10
375 addr=00D7: ;206A 3180     	fcall	CLI_PRINTADC
376 addr=00DA: goto	ENDIF4
377 addr=00DB: ELSE4_10:
378 addr=00DB: movlw	97
379 addr=00DC: subwf	36,w
380 addr=00DD: btfss	3,2
```

### Line 380 addr=00DD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_11`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00DD appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
376 addr=00DA: goto	ENDIF4
377 addr=00DB: ELSE4_10:
378 addr=00DB: movlw	97
379 addr=00DC: subwf	36,w
380 addr=00DD: btfss	3,2
381 addr=00DE: goto	ELSE4_11
382 addr=00DF: ;206A 3180     	fcall	CLI_PRINTADC
383 addr=00E2: goto	ENDIF4
384 addr=00E3: ELSE4_11:
```

### Line 383 addr=00E2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00E2 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
379 addr=00DC: subwf	36,w
380 addr=00DD: btfss	3,2
381 addr=00DE: goto	ELSE4_11
382 addr=00DF: ;206A 3180     	fcall	CLI_PRINTADC
383 addr=00E2: goto	ENDIF4
384 addr=00E3: ELSE4_11:
385 addr=00E3: movlw	82
386 addr=00E4: subwf	36,w
387 addr=00E5: btfss	3,2
```

### Line 387 addr=00E5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_12`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00E5 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
383 addr=00E2: goto	ENDIF4
384 addr=00E3: ELSE4_11:
385 addr=00E3: movlw	82
386 addr=00E4: subwf	36,w
387 addr=00E5: btfss	3,2
388 addr=00E6: goto	ELSE4_12
389 addr=00E7: bsf	75,0
390 addr=00E8: movlw	low STRINGTABLE44
391 addr=00E9: movwf	91
```

### Line 389 addr=00E7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
bsf	75,0
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00E7 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
385 addr=00E3: movlw	82
386 addr=00E4: subwf	36,w
387 addr=00E5: btfss	3,2
388 addr=00E6: goto	ELSE4_12
389 addr=00E7: bsf	75,0
390 addr=00E8: movlw	low STRINGTABLE44
391 addr=00E9: movwf	91
392 addr=00EA: movlw	(high STRINGTABLE44)| (0+128)
393 addr=00EB: movwf	92
```

### Line 406 addr=00FB: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_13`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 00FB appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
402 addr=00F8: goto	ENDIF4
403 addr=00F9: ELSE4_12:
404 addr=00F9: movlw	114
405 addr=00FA: subwf	36,w
406 addr=00FB: btfss	3,2
407 addr=00FC: goto	ELSE4_13
408 addr=00FD: bsf	75,0
409 addr=00FE: movlw	low STRINGTABLE44
410 addr=00FF: movwf	91
```

### Line 408 addr=00FD: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
bsf	75,0
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 00FD appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
404 addr=00F9: movlw	114
405 addr=00FA: subwf	36,w
406 addr=00FB: btfss	3,2
407 addr=00FC: goto	ELSE4_13
408 addr=00FD: bsf	75,0
409 addr=00FE: movlw	low STRINGTABLE44
410 addr=00FF: movwf	91
411 addr=0100: movlw	(high STRINGTABLE44)| (0+128)
412 addr=0101: movwf	92
```

### Line 425 addr=0111: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_14`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0111 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
421 addr=010E: goto	ENDIF4
422 addr=010F: ELSE4_13:
423 addr=010F: movlw	84
424 addr=0110: subwf	36,w
425 addr=0111: btfss	3,2
426 addr=0112: goto	ELSE4_14
427 addr=0113: bcf	75,0
428 addr=0114: movlw	low STRINGTABLE45
429 addr=0115: movwf	91
```

### Line 427 addr=0113: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
bcf	75,0
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0113 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
423 addr=010F: movlw	84
424 addr=0110: subwf	36,w
425 addr=0111: btfss	3,2
426 addr=0112: goto	ELSE4_14
427 addr=0113: bcf	75,0
428 addr=0114: movlw	low STRINGTABLE45
429 addr=0115: movwf	91
430 addr=0116: movlw	(high STRINGTABLE45)| (0+128)
431 addr=0117: movwf	92
```

### Line 444 addr=0127: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_15`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0127 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
440 addr=0124: goto	ENDIF4
441 addr=0125: ELSE4_14:
442 addr=0125: movlw	116
443 addr=0126: subwf	36,w
444 addr=0127: btfss	3,2
445 addr=0128: goto	ELSE4_15
446 addr=0129: bcf	75,0
447 addr=012A: movlw	low STRINGTABLE45
448 addr=012B: movwf	91
```

### Line 446 addr=0129: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
bcf	75,0
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0129 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
442 addr=0125: movlw	116
443 addr=0126: subwf	36,w
444 addr=0127: btfss	3,2
445 addr=0128: goto	ELSE4_15
446 addr=0129: bcf	75,0
447 addr=012A: movlw	low STRINGTABLE45
448 addr=012B: movwf	91
449 addr=012C: movlw	(high STRINGTABLE45)| (0+128)
450 addr=012D: movwf	92
```

### Line 463 addr=013D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_16`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 013D appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
459 addr=013A: goto	ENDIF4
460 addr=013B: ELSE4_15:
461 addr=013B: movlw	68
462 addr=013C: subwf	36,w
463 addr=013D: btfss	3,2
464 addr=013E: goto	ELSE4_16
465 addr=013F: ;2000 3180     	fcall	CLI_DIAGNOSTICBLINK
466 addr=0142: goto	ENDIF4
467 addr=0143: ELSE4_16:
```

### Line 466 addr=0142: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0142 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
462 addr=013C: subwf	36,w
463 addr=013D: btfss	3,2
464 addr=013E: goto	ELSE4_16
465 addr=013F: ;2000 3180     	fcall	CLI_DIAGNOSTICBLINK
466 addr=0142: goto	ENDIF4
467 addr=0143: ELSE4_16:
468 addr=0143: movlw	100
469 addr=0144: subwf	36,w
470 addr=0145: btfss	3,2
```

### Line 470 addr=0145: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_17`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0145 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
466 addr=0142: goto	ENDIF4
467 addr=0143: ELSE4_16:
468 addr=0143: movlw	100
469 addr=0144: subwf	36,w
470 addr=0145: btfss	3,2
471 addr=0146: goto	ELSE4_17
472 addr=0147: ;2000 3180     	fcall	CLI_DIAGNOSTICBLINK
473 addr=014A: goto	ENDIF4
474 addr=014B: ELSE4_17:
```

### Line 473 addr=014A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 014A appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
469 addr=0144: subwf	36,w
470 addr=0145: btfss	3,2
471 addr=0146: goto	ELSE4_17
472 addr=0147: ;2000 3180     	fcall	CLI_DIAGNOSTICBLINK
473 addr=014A: goto	ENDIF4
474 addr=014B: ELSE4_17:
475 addr=014B: movlw	88
476 addr=014C: subwf	36,w
477 addr=014D: btfss	3,2
```

### Line 477 addr=014D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_18`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 014D appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
473 addr=014A: goto	ENDIF4
474 addr=014B: ELSE4_17:
475 addr=014B: movlw	88
476 addr=014C: subwf	36,w
477 addr=014D: btfss	3,2
478 addr=014E: goto	ELSE4_18
479 addr=014F: ;2040 3180     	fcall	CLI_I2CSCANPLACEHOLDER
480 addr=0152: goto	ENDIF4
481 addr=0153: ELSE4_18:
```

### Line 480 addr=0152: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0152 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
476 addr=014C: subwf	36,w
477 addr=014D: btfss	3,2
478 addr=014E: goto	ELSE4_18
479 addr=014F: ;2040 3180     	fcall	CLI_I2CSCANPLACEHOLDER
480 addr=0152: goto	ENDIF4
481 addr=0153: ELSE4_18:
482 addr=0153: movlw	120
483 addr=0154: subwf	36,w
484 addr=0155: btfss	3,2
```

### Line 484 addr=0155: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_19`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0155 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
480 addr=0152: goto	ENDIF4
481 addr=0153: ELSE4_18:
482 addr=0153: movlw	120
483 addr=0154: subwf	36,w
484 addr=0155: btfss	3,2
485 addr=0156: goto	ELSE4_19
486 addr=0157: ;2040 3180     	fcall	CLI_I2CSCANPLACEHOLDER
487 addr=015A: goto	ENDIF4
488 addr=015B: ELSE4_19:
```

### Line 487 addr=015A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 015A appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
483 addr=0154: subwf	36,w
484 addr=0155: btfss	3,2
485 addr=0156: goto	ELSE4_19
486 addr=0157: ;2040 3180     	fcall	CLI_I2CSCANPLACEHOLDER
487 addr=015A: goto	ENDIF4
488 addr=015B: ELSE4_19:
489 addr=015B: movlw	77
490 addr=015C: subwf	36,w
491 addr=015D: btfss	3,2
```

### Line 491 addr=015D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_20`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 015D appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
487 addr=015A: goto	ENDIF4
488 addr=015B: ELSE4_19:
489 addr=015B: movlw	77
490 addr=015C: subwf	36,w
491 addr=015D: btfss	3,2
492 addr=015E: goto	ELSE4_20
493 addr=015F: ;2500 3180     	fcall	RB_LEDBANK_PRINTMAP
494 addr=0162: goto	ENDIF4
495 addr=0163: ELSE4_20:
```

### Line 494 addr=0162: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0162 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
490 addr=015C: subwf	36,w
491 addr=015D: btfss	3,2
492 addr=015E: goto	ELSE4_20
493 addr=015F: ;2500 3180     	fcall	RB_LEDBANK_PRINTMAP
494 addr=0162: goto	ENDIF4
495 addr=0163: ELSE4_20:
496 addr=0163: movlw	109
497 addr=0164: subwf	36,w
498 addr=0165: btfss	3,2
```

### Line 498 addr=0165: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_21`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0165 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
494 addr=0162: goto	ENDIF4
495 addr=0163: ELSE4_20:
496 addr=0163: movlw	109
497 addr=0164: subwf	36,w
498 addr=0165: btfss	3,2
499 addr=0166: goto	ELSE4_21
500 addr=0167: ;2500 3180     	fcall	RB_LEDBANK_PRINTMAP
501 addr=016A: goto	ENDIF4
502 addr=016B: ELSE4_21:
```

### Line 501 addr=016A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 016A appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
497 addr=0164: subwf	36,w
498 addr=0165: btfss	3,2
499 addr=0166: goto	ELSE4_21
500 addr=0167: ;2500 3180     	fcall	RB_LEDBANK_PRINTMAP
501 addr=016A: goto	ENDIF4
502 addr=016B: ELSE4_21:
503 addr=016B: movlw	78
504 addr=016C: subwf	36,w
505 addr=016D: btfss	3,2
```

### Line 505 addr=016D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_22`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 016D appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
501 addr=016A: goto	ENDIF4
502 addr=016B: ELSE4_21:
503 addr=016B: movlw	78
504 addr=016C: subwf	36,w
505 addr=016D: btfss	3,2
506 addr=016E: goto	ELSE4_22
507 addr=016F: ;2062 3180     	fcall	CLI_NEXTLED
508 addr=0172: goto	ENDIF4
509 addr=0173: ELSE4_22:
```

### Line 508 addr=0172: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0172 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
504 addr=016C: subwf	36,w
505 addr=016D: btfss	3,2
506 addr=016E: goto	ELSE4_22
507 addr=016F: ;2062 3180     	fcall	CLI_NEXTLED
508 addr=0172: goto	ENDIF4
509 addr=0173: ELSE4_22:
510 addr=0173: movlw	110
511 addr=0174: subwf	36,w
512 addr=0175: btfss	3,2
```

### Line 512 addr=0175: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_23`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0175 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
508 addr=0172: goto	ENDIF4
509 addr=0173: ELSE4_22:
510 addr=0173: movlw	110
511 addr=0174: subwf	36,w
512 addr=0175: btfss	3,2
513 addr=0176: goto	ELSE4_23
514 addr=0177: ;2062 3180     	fcall	CLI_NEXTLED
515 addr=017A: goto	ENDIF4
516 addr=017B: ELSE4_23:
```

### Line 515 addr=017A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 017A appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
511 addr=0174: subwf	36,w
512 addr=0175: btfss	3,2
513 addr=0176: goto	ELSE4_23
514 addr=0177: ;2062 3180     	fcall	CLI_NEXTLED
515 addr=017A: goto	ENDIF4
516 addr=017B: ELSE4_23:
517 addr=017B: movlw	43
518 addr=017C: subwf	36,w
519 addr=017D: btfss	3,2
```

### Line 519 addr=017D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_24`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 017D appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
515 addr=017A: goto	ENDIF4
516 addr=017B: ELSE4_23:
517 addr=017B: movlw	43
518 addr=017C: subwf	36,w
519 addr=017D: btfss	3,2
520 addr=017E: goto	ELSE4_24
521 addr=017F: ;21ED 3180     	fcall	CLI_SELECTEDLEDON
522 addr=0182: goto	ENDIF4
523 addr=0183: ELSE4_24:
```

### Line 522 addr=0182: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0182 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
518 addr=017C: subwf	36,w
519 addr=017D: btfss	3,2
520 addr=017E: goto	ELSE4_24
521 addr=017F: ;21ED 3180     	fcall	CLI_SELECTEDLEDON
522 addr=0182: goto	ENDIF4
523 addr=0183: ELSE4_24:
524 addr=0183: movlw	45
525 addr=0184: subwf	36,w
526 addr=0185: btfss	3,2
```

### Line 526 addr=0185: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_25`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0185 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
522 addr=0182: goto	ENDIF4
523 addr=0183: ELSE4_24:
524 addr=0183: movlw	45
525 addr=0184: subwf	36,w
526 addr=0185: btfss	3,2
527 addr=0186: goto	ELSE4_25
528 addr=0187: ;21B1 3180     	fcall	CLI_SELECTEDLEDOFF
529 addr=018A: goto	ENDIF4
530 addr=018B: ELSE4_25:
```

### Line 529 addr=018A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 018A appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
525 addr=0184: subwf	36,w
526 addr=0185: btfss	3,2
527 addr=0186: goto	ELSE4_25
528 addr=0187: ;21B1 3180     	fcall	CLI_SELECTEDLEDOFF
529 addr=018A: goto	ENDIF4
530 addr=018B: ELSE4_25:
531 addr=018B: movlw	76
532 addr=018C: subwf	36,w
533 addr=018D: btfss	3,2
```

### Line 533 addr=018D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_26`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 018D appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
529 addr=018A: goto	ENDIF4
530 addr=018B: ELSE4_25:
531 addr=018B: movlw	76
532 addr=018C: subwf	36,w
533 addr=018D: btfss	3,2
534 addr=018E: goto	ELSE4_26
535 addr=018F: ;2229 3180     	fcall	CLI_SELECTEDLEDTOGGLE
536 addr=0192: goto	ENDIF4
537 addr=0193: ELSE4_26:
```

### Line 536 addr=0192: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0192 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
532 addr=018C: subwf	36,w
533 addr=018D: btfss	3,2
534 addr=018E: goto	ELSE4_26
535 addr=018F: ;2229 3180     	fcall	CLI_SELECTEDLEDTOGGLE
536 addr=0192: goto	ENDIF4
537 addr=0193: ELSE4_26:
538 addr=0193: movlw	108
539 addr=0194: subwf	36,w
540 addr=0195: btfss	3,2
```

### Line 540 addr=0195: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_27`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0195 appears within map psect `COMMON` (0046-00C4).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
536 addr=0192: goto	ENDIF4
537 addr=0193: ELSE4_26:
538 addr=0193: movlw	108
539 addr=0194: subwf	36,w
540 addr=0195: btfss	3,2
541 addr=0196: goto	ELSE4_27
542 addr=0197: ;2229 3180     	fcall	CLI_SELECTEDLEDTOGGLE
543 addr=019A: goto	ENDIF4
544 addr=019B: ELSE4_27:
```

### Line 543 addr=019A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 019A appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
539 addr=0194: subwf	36,w
540 addr=0195: btfss	3,2
541 addr=0196: goto	ELSE4_27
542 addr=0197: ;2229 3180     	fcall	CLI_SELECTEDLEDTOGGLE
543 addr=019A: goto	ENDIF4
544 addr=019B: ELSE4_27:
545 addr=019B: movlw	48
546 addr=019C: subwf	36,w
547 addr=019D: btfss	3,2
```

### Line 547 addr=019D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_28`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 019D appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
543 addr=019A: goto	ENDIF4
544 addr=019B: ELSE4_27:
545 addr=019B: movlw	48
546 addr=019C: subwf	36,w
547 addr=019D: btfss	3,2
548 addr=019E: goto	ELSE4_28
549 addr=019F: ;2548 3180     	fcall	RB_LED_STATUS_OFF
550 addr=01A2: movlw	low STRINGTABLE46
551 addr=01A3: movwf	91
```

### Line 550 addr=01A2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
movlw	low STRINGTABLE46
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01A2 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
546 addr=019C: subwf	36,w
547 addr=019D: btfss	3,2
548 addr=019E: goto	ELSE4_28
549 addr=019F: ;2548 3180     	fcall	RB_LED_STATUS_OFF
550 addr=01A2: movlw	low STRINGTABLE46
551 addr=01A3: movwf	91
552 addr=01A4: movlw	(high STRINGTABLE46)| (0+128)
553 addr=01A5: movwf	92
554 addr=01A6: movlw	1
```

### Line 566 addr=01B5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_29`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01B5 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
562 addr=01B2: goto	ENDIF4
563 addr=01B3: ELSE4_28:
564 addr=01B3: movlw	49
565 addr=01B4: subwf	36,w
566 addr=01B5: btfss	3,2
567 addr=01B6: goto	ELSE4_29
568 addr=01B7: ;254A 3180     	fcall	RB_LED_STATUS_ON
569 addr=01BA: movlw	low STRINGTABLE47
570 addr=01BB: movwf	91
```

### Line 569 addr=01BA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
movlw	low STRINGTABLE47
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01BA appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
565 addr=01B4: subwf	36,w
566 addr=01B5: btfss	3,2
567 addr=01B6: goto	ELSE4_29
568 addr=01B7: ;254A 3180     	fcall	RB_LED_STATUS_ON
569 addr=01BA: movlw	low STRINGTABLE47
570 addr=01BB: movwf	91
571 addr=01BC: movlw	(high STRINGTABLE47)| (0+128)
572 addr=01BD: movwf	92
573 addr=01BE: movlw	1
```

### Line 585 addr=01CD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_30`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01CD appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
581 addr=01CA: goto	ENDIF4
582 addr=01CB: ELSE4_29:
583 addr=01CB: movlw	89
584 addr=01CC: subwf	36,w
585 addr=01CD: btfss	3,2
586 addr=01CE: goto	ELSE4_30
587 addr=01CF: ;2478 3180     	fcall	RB_7SEG_PRINTMAP
588 addr=01D2: goto	ENDIF4
589 addr=01D3: ELSE4_30:
```

### Line 588 addr=01D2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01D2 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
584 addr=01CC: subwf	36,w
585 addr=01CD: btfss	3,2
586 addr=01CE: goto	ELSE4_30
587 addr=01CF: ;2478 3180     	fcall	RB_7SEG_PRINTMAP
588 addr=01D2: goto	ENDIF4
589 addr=01D3: ELSE4_30:
590 addr=01D3: movlw	121
591 addr=01D4: subwf	36,w
592 addr=01D5: btfss	3,2
```

### Line 592 addr=01D5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_31`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01D5 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
588 addr=01D2: goto	ENDIF4
589 addr=01D3: ELSE4_30:
590 addr=01D3: movlw	121
591 addr=01D4: subwf	36,w
592 addr=01D5: btfss	3,2
593 addr=01D6: goto	ELSE4_31
594 addr=01D7: ;2478 3180     	fcall	RB_7SEG_PRINTMAP
595 addr=01DA: goto	ENDIF4
596 addr=01DB: ELSE4_31:
```

### Line 595 addr=01DA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01DA appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
591 addr=01D4: subwf	36,w
592 addr=01D5: btfss	3,2
593 addr=01D6: goto	ELSE4_31
594 addr=01D7: ;2478 3180     	fcall	RB_7SEG_PRINTMAP
595 addr=01DA: goto	ENDIF4
596 addr=01DB: ELSE4_31:
597 addr=01DB: movlw	71
598 addr=01DC: subwf	36,w
599 addr=01DD: btfss	3,2
```

### Line 599 addr=01DD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_32`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01DD appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
595 addr=01DA: goto	ENDIF4
596 addr=01DB: ELSE4_31:
597 addr=01DB: movlw	71
598 addr=01DC: subwf	36,w
599 addr=01DD: btfss	3,2
600 addr=01DE: goto	ELSE4_32
601 addr=01DF: ;205C 3180     	fcall	CLI_NEXTDIGIT
602 addr=01E2: goto	ENDIF4
603 addr=01E3: ELSE4_32:
```

### Line 602 addr=01E2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01E2 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
598 addr=01DC: subwf	36,w
599 addr=01DD: btfss	3,2
600 addr=01DE: goto	ELSE4_32
601 addr=01DF: ;205C 3180     	fcall	CLI_NEXTDIGIT
602 addr=01E2: goto	ENDIF4
603 addr=01E3: ELSE4_32:
604 addr=01E3: movlw	103
605 addr=01E4: subwf	36,w
606 addr=01E5: btfss	3,2
```

### Line 606 addr=01E5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_33`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01E5 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
602 addr=01E2: goto	ENDIF4
603 addr=01E3: ELSE4_32:
604 addr=01E3: movlw	103
605 addr=01E4: subwf	36,w
606 addr=01E5: btfss	3,2
607 addr=01E6: goto	ELSE4_33
608 addr=01E7: ;205C 3180     	fcall	CLI_NEXTDIGIT
609 addr=01EA: goto	ENDIF4
610 addr=01EB: ELSE4_33:
```

### Line 609 addr=01EA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01EA appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
605 addr=01E4: subwf	36,w
606 addr=01E5: btfss	3,2
607 addr=01E6: goto	ELSE4_33
608 addr=01E7: ;205C 3180     	fcall	CLI_NEXTDIGIT
609 addr=01EA: goto	ENDIF4
610 addr=01EB: ELSE4_33:
611 addr=01EB: movlw	67
612 addr=01EC: subwf	36,w
613 addr=01ED: btfss	3,2
```

### Line 613 addr=01ED: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_34`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01ED appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
609 addr=01EA: goto	ENDIF4
610 addr=01EB: ELSE4_33:
611 addr=01EB: movlw	67
612 addr=01EC: subwf	36,w
613 addr=01ED: btfss	3,2
614 addr=01EE: goto	ELSE4_34
615 addr=01EF: ;2264 3180     	fcall	CLI_SENDDEMOCHARTODIGIT
616 addr=01F2: goto	ENDIF4
617 addr=01F3: ELSE4_34:
```

### Line 616 addr=01F2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01F2 appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
612 addr=01EC: subwf	36,w
613 addr=01ED: btfss	3,2
614 addr=01EE: goto	ELSE4_34
615 addr=01EF: ;2264 3180     	fcall	CLI_SENDDEMOCHARTODIGIT
616 addr=01F2: goto	ENDIF4
617 addr=01F3: ELSE4_34:
618 addr=01F3: movlw	99
619 addr=01F4: subwf	36,w
620 addr=01F5: btfss	3,2
```

### Line 620 addr=01F5: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_35`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01F5 appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
616 addr=01F2: goto	ENDIF4
617 addr=01F3: ELSE4_34:
618 addr=01F3: movlw	99
619 addr=01F4: subwf	36,w
620 addr=01F5: btfss	3,2
621 addr=01F6: goto	ELSE4_35
622 addr=01F7: ;2264 3180     	fcall	CLI_SENDDEMOCHARTODIGIT
623 addr=01FA: goto	ENDIF4
624 addr=01FB: ELSE4_35:
```

### Line 623 addr=01FA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 01FA appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
619 addr=01F4: subwf	36,w
620 addr=01F5: btfss	3,2
621 addr=01F6: goto	ELSE4_35
622 addr=01F7: ;2264 3180     	fcall	CLI_SENDDEMOCHARTODIGIT
623 addr=01FA: goto	ENDIF4
624 addr=01FB: ELSE4_35:
625 addr=01FB: movlw	79
626 addr=01FC: subwf	36,w
627 addr=01FD: btfss	3,2
```

### Line 627 addr=01FD: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_36`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 01FD appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
623 addr=01FA: goto	ENDIF4
624 addr=01FB: ELSE4_35:
625 addr=01FB: movlw	79
626 addr=01FC: subwf	36,w
627 addr=01FD: btfss	3,2
628 addr=01FE: goto	ELSE4_36
629 addr=01FF: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
630 addr=0202: goto	ENDIF4
631 addr=0203: ELSE4_36:
```

### Line 630 addr=0202: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0202 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
626 addr=01FC: subwf	36,w
627 addr=01FD: btfss	3,2
628 addr=01FE: goto	ELSE4_36
629 addr=01FF: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
630 addr=0202: goto	ENDIF4
631 addr=0203: ELSE4_36:
632 addr=0203: movlw	111
633 addr=0204: subwf	36,w
634 addr=0205: btfss	3,2
```

### Line 634 addr=0205: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_37`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0205 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
630 addr=0202: goto	ENDIF4
631 addr=0203: ELSE4_36:
632 addr=0203: movlw	111
633 addr=0204: subwf	36,w
634 addr=0205: btfss	3,2
635 addr=0206: goto	ELSE4_37
636 addr=0207: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
637 addr=020A: goto	ENDIF4
638 addr=020B: ELSE4_37:
```

### Line 637 addr=020A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 020A appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
633 addr=0204: subwf	36,w
634 addr=0205: btfss	3,2
635 addr=0206: goto	ELSE4_37
636 addr=0207: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
637 addr=020A: goto	ENDIF4
638 addr=020B: ELSE4_37:
639 addr=020B: movlw	86
640 addr=020C: subwf	36,w
641 addr=020D: btfss	3,2
```

### Line 641 addr=020D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_38`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 020D appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
637 addr=020A: goto	ENDIF4
638 addr=020B: ELSE4_37:
639 addr=020B: movlw	86
640 addr=020C: subwf	36,w
641 addr=020D: btfss	3,2
642 addr=020E: goto	ELSE4_38
643 addr=020F: ;255F 3180     	fcall	RB_NCO_PRINTFORMULANOTE
644 addr=0212: goto	ENDIF4
645 addr=0213: ELSE4_38:
```

### Line 644 addr=0212: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0212 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
640 addr=020C: subwf	36,w
641 addr=020D: btfss	3,2
642 addr=020E: goto	ELSE4_38
643 addr=020F: ;255F 3180     	fcall	RB_NCO_PRINTFORMULANOTE
644 addr=0212: goto	ENDIF4
645 addr=0213: ELSE4_38:
646 addr=0213: movlw	118
647 addr=0214: subwf	36,w
648 addr=0215: btfss	3,2
```

### Line 648 addr=0215: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_39`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0215 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
644 addr=0212: goto	ENDIF4
645 addr=0213: ELSE4_38:
646 addr=0213: movlw	118
647 addr=0214: subwf	36,w
648 addr=0215: btfss	3,2
649 addr=0216: goto	ELSE4_39
650 addr=0217: ;255F 3180     	fcall	RB_NCO_PRINTFORMULANOTE
651 addr=021A: goto	ENDIF4
652 addr=021B: ELSE4_39:
```

### Line 651 addr=021A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 021A appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
647 addr=0214: subwf	36,w
648 addr=0215: btfss	3,2
649 addr=0216: goto	ELSE4_39
650 addr=0217: ;255F 3180     	fcall	RB_NCO_PRINTFORMULANOTE
651 addr=021A: goto	ENDIF4
652 addr=021B: ELSE4_39:
653 addr=021B: movlw	74
654 addr=021C: subwf	36,w
655 addr=021D: btfss	3,2
```

### Line 655 addr=021D: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_40`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 021D appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
651 addr=021A: goto	ENDIF4
652 addr=021B: ELSE4_39:
653 addr=021B: movlw	74
654 addr=021C: subwf	36,w
655 addr=021D: btfss	3,2
656 addr=021E: goto	ELSE4_40
657 addr=021F: ;25D3 3180     	fcall	RB_NCO_SETDEMOSLOW
658 addr=0222: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
659 addr=0225: goto	ENDIF4
```

### Line 659 addr=0225: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0225 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
655 addr=021D: btfss	3,2
656 addr=021E: goto	ELSE4_40
657 addr=021F: ;25D3 3180     	fcall	RB_NCO_SETDEMOSLOW
658 addr=0222: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
659 addr=0225: goto	ENDIF4
660 addr=0226: ELSE4_40:
661 addr=0226: movlw	106
662 addr=0227: subwf	36,w
663 addr=0228: btfss	3,2
```

### Line 663 addr=0228: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_41`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0228 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
659 addr=0225: goto	ENDIF4
660 addr=0226: ELSE4_40:
661 addr=0226: movlw	106
662 addr=0227: subwf	36,w
663 addr=0228: btfss	3,2
664 addr=0229: goto	ELSE4_41
665 addr=022A: ;25D3 3180     	fcall	RB_NCO_SETDEMOSLOW
666 addr=022D: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
667 addr=0230: goto	ENDIF4
```

### Line 667 addr=0230: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0230 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
663 addr=0228: btfss	3,2
664 addr=0229: goto	ELSE4_41
665 addr=022A: ;25D3 3180     	fcall	RB_NCO_SETDEMOSLOW
666 addr=022D: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
667 addr=0230: goto	ENDIF4
668 addr=0231: ELSE4_41:
669 addr=0231: movlw	75
670 addr=0232: subwf	36,w
671 addr=0233: btfss	3,2
```

### Line 671 addr=0233: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_42`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0233 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
667 addr=0230: goto	ENDIF4
668 addr=0231: ELSE4_41:
669 addr=0231: movlw	75
670 addr=0232: subwf	36,w
671 addr=0233: btfss	3,2
672 addr=0234: goto	ELSE4_42
673 addr=0235: ;25CE 3180     	fcall	RB_NCO_SETDEMOMEDIUM
674 addr=0238: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
675 addr=023B: goto	ENDIF4
```

### Line 675 addr=023B: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 023B appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
671 addr=0233: btfss	3,2
672 addr=0234: goto	ELSE4_42
673 addr=0235: ;25CE 3180     	fcall	RB_NCO_SETDEMOMEDIUM
674 addr=0238: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
675 addr=023B: goto	ENDIF4
676 addr=023C: ELSE4_42:
677 addr=023C: movlw	107
678 addr=023D: subwf	36,w
679 addr=023E: btfss	3,2
```

### Line 679 addr=023E: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_43`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 023E appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
675 addr=023B: goto	ENDIF4
676 addr=023C: ELSE4_42:
677 addr=023C: movlw	107
678 addr=023D: subwf	36,w
679 addr=023E: btfss	3,2
680 addr=023F: goto	ELSE4_43
681 addr=0240: ;25CE 3180     	fcall	RB_NCO_SETDEMOMEDIUM
682 addr=0243: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
683 addr=0246: goto	ENDIF4
```

### Line 683 addr=0246: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0246 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
679 addr=023E: btfss	3,2
680 addr=023F: goto	ELSE4_43
681 addr=0240: ;25CE 3180     	fcall	RB_NCO_SETDEMOMEDIUM
682 addr=0243: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
683 addr=0246: goto	ENDIF4
684 addr=0247: ELSE4_43:
685 addr=0247: movlw	81
686 addr=0248: subwf	36,w
687 addr=0249: btfss	3,2
```

### Line 687 addr=0249: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_44`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0249 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
683 addr=0246: goto	ENDIF4
684 addr=0247: ELSE4_43:
685 addr=0247: movlw	81
686 addr=0248: subwf	36,w
687 addr=0249: btfss	3,2
688 addr=024A: goto	ELSE4_44
689 addr=024B: ;25C9 3180     	fcall	RB_NCO_SETDEMOFAST
690 addr=024E: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
691 addr=0251: goto	ENDIF4
```

### Line 691 addr=0251: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0251 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
687 addr=0249: btfss	3,2
688 addr=024A: goto	ELSE4_44
689 addr=024B: ;25C9 3180     	fcall	RB_NCO_SETDEMOFAST
690 addr=024E: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
691 addr=0251: goto	ENDIF4
692 addr=0252: ELSE4_44:
693 addr=0252: movlw	113
694 addr=0253: subwf	36,w
695 addr=0254: btfss	3,2
```

### Line 695 addr=0254: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_45`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0254 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
691 addr=0251: goto	ENDIF4
692 addr=0252: ELSE4_44:
693 addr=0252: movlw	113
694 addr=0253: subwf	36,w
695 addr=0254: btfss	3,2
696 addr=0255: goto	ELSE4_45
697 addr=0256: ;25C9 3180     	fcall	RB_NCO_SETDEMOFAST
698 addr=0259: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
699 addr=025C: goto	ENDIF4
```

### Line 699 addr=025C: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 025C appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
695 addr=0254: btfss	3,2
696 addr=0255: goto	ELSE4_45
697 addr=0256: ;25C9 3180     	fcall	RB_NCO_SETDEMOFAST
698 addr=0259: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
699 addr=025C: goto	ENDIF4
700 addr=025D: ELSE4_45:
701 addr=025D: movlw	69
702 addr=025E: subwf	36,w
703 addr=025F: btfss	3,2
```

### Line 703 addr=025F: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_46`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 025F appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
699 addr=025C: goto	ENDIF4
700 addr=025D: ELSE4_45:
701 addr=025D: movlw	69
702 addr=025E: subwf	36,w
703 addr=025F: btfss	3,2
704 addr=0260: goto	ELSE4_46
705 addr=0261: ;2556 3180     	fcall	RB_NCO_ENABLESOFTWARESTATE
706 addr=0264: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
707 addr=0267: goto	ENDIF4
```

### Line 707 addr=0267: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0267 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
703 addr=025F: btfss	3,2
704 addr=0260: goto	ELSE4_46
705 addr=0261: ;2556 3180     	fcall	RB_NCO_ENABLESOFTWARESTATE
706 addr=0264: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
707 addr=0267: goto	ENDIF4
708 addr=0268: ELSE4_46:
709 addr=0268: movlw	101
710 addr=0269: subwf	36,w
711 addr=026A: btfss	3,2
```

### Line 711 addr=026A: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_47`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 026A appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
707 addr=0267: goto	ENDIF4
708 addr=0268: ELSE4_46:
709 addr=0268: movlw	101
710 addr=0269: subwf	36,w
711 addr=026A: btfss	3,2
712 addr=026B: goto	ELSE4_47
713 addr=026C: ;2556 3180     	fcall	RB_NCO_ENABLESOFTWARESTATE
714 addr=026F: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
715 addr=0272: goto	ENDIF4
```

### Line 715 addr=0272: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0272 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
711 addr=026A: btfss	3,2
712 addr=026B: goto	ELSE4_47
713 addr=026C: ;2556 3180     	fcall	RB_NCO_ENABLESOFTWARESTATE
714 addr=026F: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
715 addr=0272: goto	ENDIF4
716 addr=0273: ELSE4_47:
717 addr=0273: movlw	87
718 addr=0274: subwf	36,w
719 addr=0275: btfss	3,2
```

### Line 719 addr=0275: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_48`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0275 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
715 addr=0272: goto	ENDIF4
716 addr=0273: ELSE4_47:
717 addr=0273: movlw	87
718 addr=0274: subwf	36,w
719 addr=0275: btfss	3,2
720 addr=0276: goto	ELSE4_48
721 addr=0277: ;2554 3180     	fcall	RB_NCO_DISABLESOFTWARESTATE
722 addr=027A: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
723 addr=027D: goto	ENDIF4
```

### Line 723 addr=027D: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 027D appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
719 addr=0275: btfss	3,2
720 addr=0276: goto	ELSE4_48
721 addr=0277: ;2554 3180     	fcall	RB_NCO_DISABLESOFTWARESTATE
722 addr=027A: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
723 addr=027D: goto	ENDIF4
724 addr=027E: ELSE4_48:
725 addr=027E: movlw	119
726 addr=027F: subwf	36,w
727 addr=0280: btfss	3,2
```

### Line 727 addr=0280: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_49`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0280 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
723 addr=027D: goto	ENDIF4
724 addr=027E: ELSE4_48:
725 addr=027E: movlw	119
726 addr=027F: subwf	36,w
727 addr=0280: btfss	3,2
728 addr=0281: goto	ELSE4_49
729 addr=0282: ;2554 3180     	fcall	RB_NCO_DISABLESOFTWARESTATE
730 addr=0285: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
731 addr=0288: goto	ENDIF4
```

### Line 731 addr=0288: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0288 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
727 addr=0280: btfss	3,2
728 addr=0281: goto	ELSE4_49
729 addr=0282: ;2554 3180     	fcall	RB_NCO_DISABLESOFTWARESTATE
730 addr=0285: ;256D 3180     	fcall	RB_NCO_PRINTSTATUS
731 addr=0288: goto	ENDIF4
732 addr=0289: ELSE4_49:
733 addr=0289: movlw	13
734 addr=028A: subwf	36,w
735 addr=028B: btfss	3,2
```

### Line 735 addr=028B: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_50`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 028B appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
731 addr=0288: goto	ENDIF4
732 addr=0289: ELSE4_49:
733 addr=0289: movlw	13
734 addr=028A: subwf	36,w
735 addr=028B: btfss	3,2
736 addr=028C: goto	ELSE4_50
737 addr=028D: goto	ENDIF4
738 addr=028E: ELSE4_50:
739 addr=028E: movlw	10
```

### Line 737 addr=028D: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 028D appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
733 addr=0289: movlw	13
734 addr=028A: subwf	36,w
735 addr=028B: btfss	3,2
736 addr=028C: goto	ELSE4_50
737 addr=028D: goto	ENDIF4
738 addr=028E: ELSE4_50:
739 addr=028E: movlw	10
740 addr=028F: subwf	36,w
741 addr=0290: btfss	3,2
```

### Line 741 addr=0290: PIC_SKIP_PATTERN [INFO]

```asm
btfss	3,2
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE4_51`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0290 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
737 addr=028D: goto	ENDIF4
738 addr=028E: ELSE4_50:
739 addr=028E: movlw	10
740 addr=028F: subwf	36,w
741 addr=0290: btfss	3,2
742 addr=0291: goto	ELSE4_51
743 addr=0292: goto	ENDIF4
744 addr=0293: ELSE4_51:
745 addr=0293: movlw	low STRINGTABLE48
```

### Line 743 addr=0292: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
goto	ENDIF4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0292 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
739 addr=028E: movlw	10
740 addr=028F: subwf	36,w
741 addr=0290: btfss	3,2
742 addr=0291: goto	ELSE4_51
743 addr=0292: goto	ENDIF4
744 addr=0293: ELSE4_51:
745 addr=0293: movlw	low STRINGTABLE48
746 addr=0294: movwf	91
747 addr=0295: movlw	(high STRINGTABLE48)| (0+128)
```

### Line 775 addr=02B7: PIC_SKIP_PATTERN [INFO]

```asm
btfss	75,4
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ELSE28_1`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 02B7 appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
771 addr=02AF: movlw	1
772 addr=02B0: movwf	44
773 addr=02B1: ;22AB 3180     	fcall	HSERPRINT422
774 addr=02B4: ;25E9 3180     	fcall	FN_RB_SW1_ISPRESSED
775 addr=02B7: btfss	75,4
776 addr=02B8: goto	ELSE28_1
777 addr=02B9: movlw	low STRINGTABLE26
778 addr=02BA: movwf	91
779 addr=02BB: movlw	(high STRINGTABLE26)| (0+128)
```

### Line 777 addr=02B9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
movlw	low STRINGTABLE26
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 02B9 appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
773 addr=02B1: ;22AB 3180     	fcall	HSERPRINT422
774 addr=02B4: ;25E9 3180     	fcall	FN_RB_SW1_ISPRESSED
775 addr=02B7: btfss	75,4
776 addr=02B8: goto	ELSE28_1
777 addr=02B9: movlw	low STRINGTABLE26
778 addr=02BA: movwf	91
779 addr=02BB: movlw	(high STRINGTABLE26)| (0+128)
780 addr=02BC: movwf	92
781 addr=02BD: movlw	1
```

### Line 813 addr=02E0: PIC_SKIP_PATTERN [INFO]

```asm
btfss	112,0
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ENDIF21`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 02E0 appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
809 addr=02DA: movlw	39
810 addr=02DB: movwf	122
811 addr=02DC: ;26DE 3180     	fcall	SYSCOMPLESSTHAN16
812 addr=02DF: comf	112,f
813 addr=02E0: btfss	112,0
814 addr=02E1: goto	ENDIF21
815 addr=02E2: movf	70,w
816 addr=02E3: movwf	117
817 addr=02E4: movf	71,w
```

### Line 815 addr=02E2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
movf	70,w
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 02E2 appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
811 addr=02DC: ;26DE 3180     	fcall	SYSCOMPLESSTHAN16
812 addr=02DF: comf	112,f
813 addr=02E0: btfss	112,0
814 addr=02E1: goto	ENDIF21
815 addr=02E2: movf	70,w
816 addr=02E3: movwf	117
817 addr=02E4: movf	71,w
818 addr=02E5: movwf	118
819 addr=02E6: movlw	16
```

### Line 846 addr=0306: PIC_SKIP_PATTERN [INFO]

```asm
btfss	112,0
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ENDIF22`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 0306 appears within map psect `BANK1` (00A0-018E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
842 addr=0300: movlw	3
843 addr=0301: movwf	122
844 addr=0302: ;26DE 3180     	fcall	SYSCOMPLESSTHAN16
845 addr=0305: comf	112,f
846 addr=0306: btfss	112,0
847 addr=0307: goto	ENDIF22
848 addr=0308: HSERPRINTWORD1000:
849 addr=0308: movf	70,w
850 addr=0309: movwf	117
```

### Line 879 addr=032B: PIC_SKIP_PATTERN [INFO]

```asm
btfss	112,0
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ENDIF23`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 032B appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
875 addr=0325: movwf	121
876 addr=0326: clrf	122
877 addr=0327: ;26DE 3180     	fcall	SYSCOMPLESSTHAN16
878 addr=032A: comf	112,f
879 addr=032B: btfss	112,0
880 addr=032C: goto	ENDIF23
881 addr=032D: HSERPRINTWORD100:
882 addr=032D: movf	70,w
883 addr=032E: movwf	117
```

### Line 911 addr=034F: PIC_SKIP_PATTERN [INFO]

```asm
btfss	112,0
```
**Meaning:** BTFSS conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `goto	ENDIF24`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 034F appears within map psect `BANK3` (01A0-038E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
907 addr=0349: movwf	121
908 addr=034A: clrf	122
909 addr=034B: ;26DE 3180     	fcall	SYSCOMPLESSTHAN16
910 addr=034E: comf	112,f
911 addr=034F: btfss	112,0
912 addr=0350: goto	ENDIF24
913 addr=0351: HSERPRINTWORD10:
914 addr=0351: movf	70,w
915 addr=0352: movwf	117
```

### Line 1002 addr=039B: PIC_SKIP_PATTERN [INFO]

```asm
btfsc	3,2
```
**Meaning:** BTFSC conditionally skips the next instruction.

**Why it matters:** PIC skip instructions implement C if/loop logic by conditionally discarding exactly one following instruction. Next instruction: `incf	120,f`.

**Compiler/GCBASIC reason:** GCBASIC/PIC-AS commonly emits BTFSS/BTFSC-style skip tests for IF/THEN and loop logic.

**Likely programmer intent:** Implement a source-level conditional or loop test.

**Actionability:** `Low`

**Fix strategy:** Do not optimize individual skip instructions. Reduce repeated source-level condition patterns.

**Map cross-reference:** Address 039B appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Read this instruction together with the next line to understand branch polarity.

Local context:
```asm
998 addr=0397: movf	120,w
999 addr=0398: movwf	10
1000 addr=0399: movf	119,w
1001 addr=039A: incf	119,f
1002 addr=039B: btfsc	3,2
1003 addr=039C: incf	120,f
1004 addr=039D: movwf	2
1005 addr=039E: STRINGTABLE9:
1006 addr=039E: retlw	18
```

### Line 1007 addr=039F: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	78	;N
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 039F appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1003 addr=039C: incf	120,f
1004 addr=039D: movwf	2
1005 addr=039E: STRINGTABLE9:
1006 addr=039E: retlw	18
1007 addr=039F: retlw	78	;N
1008 addr=03A0: retlw	85	;U
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
```

### Line 1008 addr=03A0: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	85	;U
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A0 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1004 addr=039D: movwf	2
1005 addr=039E: STRINGTABLE9:
1006 addr=039E: retlw	18
1007 addr=039F: retlw	78	;N
1008 addr=03A0: retlw	85	;U
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
```

### Line 1009 addr=03A1: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	71	;G
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A1 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1005 addr=039E: STRINGTABLE9:
1006 addr=039E: retlw	18
1007 addr=039F: retlw	78	;N
1008 addr=03A0: retlw	85	;U
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
```

### Line 1010 addr=03A2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	71	;G
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A2 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1006 addr=039E: retlw	18
1007 addr=039F: retlw	78	;N
1008 addr=03A0: retlw	85	;U
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
```

### Line 1011 addr=03A3: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	69	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A3 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1007 addr=039F: retlw	78	;N
1008 addr=03A0: retlw	85	;U
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
```

### Line 1012 addr=03A4: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	84	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A4 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1008 addr=03A0: retlw	85	;U
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
```

### Line 1013 addr=03A5: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A5 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1009 addr=03A1: retlw	71	;G
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
```

### Line 1014 addr=03A6: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	67	;C
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A6 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1010 addr=03A2: retlw	71	;G
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
```

### Line 1015 addr=03A7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	76	;L
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A7 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1011 addr=03A3: retlw	69	;E
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
```

### Line 1016 addr=03A8: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	73	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A8 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1012 addr=03A4: retlw	84	;T
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
```

### Line 1017 addr=03A9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03A9 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1013 addr=03A5: retlw	32	;
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
```

### Line 1018 addr=03AA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	77	;M
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03AA appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1014 addr=03A6: retlw	67	;C
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
```

### Line 1019 addr=03AB: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	79	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03AB appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1015 addr=03A7: retlw	76	;L
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
1023 addr=03AF: retlw	79	;O
```

### Line 1020 addr=03AC: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	78	;N
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03AC appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1016 addr=03A8: retlw	73	;I
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
1023 addr=03AF: retlw	79	;O
1024 addr=03B0: retlw	82	;R
```

### Line 1021 addr=03AD: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	73	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03AD appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1017 addr=03A9: retlw	32	;
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
1023 addr=03AF: retlw	79	;O
1024 addr=03B0: retlw	82	;R
1025 addr=03B1: STRINGTABLE10:
```

### Line 1022 addr=03AE: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	84	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03AE appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1018 addr=03AA: retlw	77	;M
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
1023 addr=03AF: retlw	79	;O
1024 addr=03B0: retlw	82	;R
1025 addr=03B1: STRINGTABLE10:
1026 addr=03B1: retlw	42
```

### Line 1023 addr=03AF: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	79	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03AF appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1019 addr=03AB: retlw	79	;O
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
1023 addr=03AF: retlw	79	;O
1024 addr=03B0: retlw	82	;R
1025 addr=03B1: STRINGTABLE10:
1026 addr=03B1: retlw	42
1027 addr=03B2: retlw	66	;B
```

### Line 1024 addr=03B0: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	82	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B0 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1020 addr=03AC: retlw	78	;N
1021 addr=03AD: retlw	73	;I
1022 addr=03AE: retlw	84	;T
1023 addr=03AF: retlw	79	;O
1024 addr=03B0: retlw	82	;R
1025 addr=03B1: STRINGTABLE10:
1026 addr=03B1: retlw	42
1027 addr=03B2: retlw	66	;B
1028 addr=03B3: retlw	79	;O
```

### Line 1027 addr=03B2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	66	;B
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B2 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1023 addr=03AF: retlw	79	;O
1024 addr=03B0: retlw	82	;R
1025 addr=03B1: STRINGTABLE10:
1026 addr=03B1: retlw	42
1027 addr=03B2: retlw	66	;B
1028 addr=03B3: retlw	79	;O
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
```

### Line 1028 addr=03B3: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	79	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B3 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1024 addr=03B0: retlw	82	;R
1025 addr=03B1: STRINGTABLE10:
1026 addr=03B1: retlw	42
1027 addr=03B2: retlw	66	;B
1028 addr=03B3: retlw	79	;O
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
```

### Line 1029 addr=03B4: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	65	;A
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B4 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1025 addr=03B1: STRINGTABLE10:
1026 addr=03B1: retlw	42
1027 addr=03B2: retlw	66	;B
1028 addr=03B3: retlw	79	;O
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
```

### Line 1030 addr=03B5: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	82	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B5 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1026 addr=03B1: retlw	42
1027 addr=03B2: retlw	66	;B
1028 addr=03B3: retlw	79	;O
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
```

### Line 1031 addr=03B6: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	68	;D
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B6 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1027 addr=03B2: retlw	66	;B
1028 addr=03B3: retlw	79	;O
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
```

### Line 1032 addr=03B7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B7 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1028 addr=03B3: retlw	79	;O
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
```

### Line 1033 addr=03B8: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	78	;N
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B8 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1029 addr=03B4: retlw	65	;A
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
```

### Line 1034 addr=03B9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	85	;U
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03B9 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1030 addr=03B5: retlw	82	;R
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
```

### Line 1035 addr=03BA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	71	;G
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03BA appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1031 addr=03B6: retlw	68	;D
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
```

### Line 1036 addr=03BB: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	71	;G
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03BB appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1032 addr=03B7: retlw	32	;
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
```

### Line 1037 addr=03BC: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	69	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03BC appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1033 addr=03B8: retlw	78	;N
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
```

### Line 1038 addr=03BD: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	84	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03BD appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1034 addr=03B9: retlw	85	;U
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
```

### Line 1039 addr=03BE: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	45	;-
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03BE appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1035 addr=03BA: retlw	71	;G
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
```

### Line 1040 addr=03BF: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	82	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03BF appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1036 addr=03BB: retlw	71	;G
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
```

### Line 1041 addr=03C0: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	69	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C0 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1037 addr=03BC: retlw	69	;E
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
```

### Line 1042 addr=03C1: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	68	;D
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C1 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1038 addr=03BD: retlw	84	;T
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
```

### Line 1043 addr=03C2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	66	;B
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C2 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1039 addr=03BE: retlw	45	;-
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
```

### Line 1044 addr=03C3: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	79	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C3 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1040 addr=03BF: retlw	82	;R
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
```

### Line 1045 addr=03C4: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	65	;A
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C4 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1041 addr=03C0: retlw	69	;E
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
```

### Line 1046 addr=03C5: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	82	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C5 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1042 addr=03C1: retlw	68	;D
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
```

### Line 1047 addr=03C6: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	68	;D
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C6 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1043 addr=03C2: retlw	66	;B
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
```

### Line 1048 addr=03C7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C7 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1044 addr=03C3: retlw	79	;O
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
```

### Line 1049 addr=03C8: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	80	;P
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C8 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1045 addr=03C4: retlw	65	;A
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
```

### Line 1050 addr=03C9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	73	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03C9 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1046 addr=03C5: retlw	82	;R
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
```

### Line 1051 addr=03CA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	67	;C
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03CA appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1047 addr=03C6: retlw	68	;D
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
```

### Line 1052 addr=03CB: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	49	;1
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03CB appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1048 addr=03C7: retlw	32	;
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
```

### Line 1053 addr=03CC: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	54	;6
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03CC appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1049 addr=03C8: retlw	80	;P
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
```

### Line 1054 addr=03CD: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	70	;F
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03CD appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1050 addr=03C9: retlw	73	;I
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
```

### Line 1055 addr=03CE: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	49	;1
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03CE appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1051 addr=03CA: retlw	67	;C
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
```

### Line 1056 addr=03CF: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	56	;8
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03CF appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1052 addr=03CB: retlw	49	;1
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
```

### Line 1057 addr=03D0: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	52	;4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D0 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1053 addr=03CC: retlw	54	;6
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
```

### Line 1058 addr=03D1: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	50	;2
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D1 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1054 addr=03CD: retlw	70	;F
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
```

### Line 1059 addr=03D2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	52	;4
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D2 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1055 addr=03CE: retlw	49	;1
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
```

### Line 1060 addr=03D3: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D3 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1056 addr=03CF: retlw	56	;8
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
```

### Line 1061 addr=03D4: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	70	;F
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D4 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1057 addr=03D0: retlw	52	;4
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
```

### Line 1062 addr=03D5: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	87	;W
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D5 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1058 addr=03D1: retlw	50	;2
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
```

### Line 1063 addr=03D6: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	61	; (EQUALS)
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D6 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1059 addr=03D2: retlw	52	;4
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
1067 addr=03DA: retlw	46	;.
```

### Line 1064 addr=03D7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	48	;0
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D7 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1060 addr=03D3: retlw	32	;
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
1067 addr=03DA: retlw	46	;.
1068 addr=03DB: retlw	49	;1
```

### Line 1065 addr=03D8: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	46	;.
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D8 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1061 addr=03D4: retlw	70	;F
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
1067 addr=03DA: retlw	46	;.
1068 addr=03DB: retlw	49	;1
1069 addr=03DC: STRINGTABLE11:
```

### Line 1066 addr=03D9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	49	;1
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03D9 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1062 addr=03D5: retlw	87	;W
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
1067 addr=03DA: retlw	46	;.
1068 addr=03DB: retlw	49	;1
1069 addr=03DC: STRINGTABLE11:
1070 addr=03DC: retlw	21
```

### Line 1067 addr=03DA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	46	;.
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03DA appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1063 addr=03D6: retlw	61	; (EQUALS)
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
1067 addr=03DA: retlw	46	;.
1068 addr=03DB: retlw	49	;1
1069 addr=03DC: STRINGTABLE11:
1070 addr=03DC: retlw	21
1071 addr=03DD: retlw	84	;T
```

### Line 1068 addr=03DB: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	49	;1
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03DB appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1064 addr=03D7: retlw	48	;0
1065 addr=03D8: retlw	46	;.
1066 addr=03D9: retlw	49	;1
1067 addr=03DA: retlw	46	;.
1068 addr=03DB: retlw	49	;1
1069 addr=03DC: STRINGTABLE11:
1070 addr=03DC: retlw	21
1071 addr=03DD: retlw	84	;T
1072 addr=03DE: retlw	121	;Y
```

### Line 1071 addr=03DD: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	84	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03DD appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1067 addr=03DA: retlw	46	;.
1068 addr=03DB: retlw	49	;1
1069 addr=03DC: STRINGTABLE11:
1070 addr=03DC: retlw	21
1071 addr=03DD: retlw	84	;T
1072 addr=03DE: retlw	121	;Y
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
```

### Line 1072 addr=03DE: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	121	;Y
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03DE appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1068 addr=03DB: retlw	49	;1
1069 addr=03DC: STRINGTABLE11:
1070 addr=03DC: retlw	21
1071 addr=03DD: retlw	84	;T
1072 addr=03DE: retlw	121	;Y
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
```

### Line 1073 addr=03DF: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	112	;P
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03DF appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1069 addr=03DC: STRINGTABLE11:
1070 addr=03DC: retlw	21
1071 addr=03DD: retlw	84	;T
1072 addr=03DE: retlw	121	;Y
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
```

### Line 1074 addr=03E0: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	101	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E0 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1070 addr=03DC: retlw	21
1071 addr=03DD: retlw	84	;T
1072 addr=03DE: retlw	121	;Y
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
```

### Line 1075 addr=03E1: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E1 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1071 addr=03DD: retlw	84	;T
1072 addr=03DE: retlw	121	;Y
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
```

### Line 1076 addr=03E2: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	72	;H
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E2 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1072 addr=03DE: retlw	121	;Y
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
```

### Line 1077 addr=03E3: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E3 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1073 addr=03DF: retlw	112	;P
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
```

### Line 1078 addr=03E4: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	111	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E4 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1074 addr=03E0: retlw	101	;E
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
```

### Line 1079 addr=03E5: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	114	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E5 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1075 addr=03E1: retlw	32	;
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
```

### Line 1080 addr=03E6: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E6 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1076 addr=03E2: retlw	72	;H
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
```

### Line 1081 addr=03E7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	63	;?
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E7 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1077 addr=03E3: retlw	32	;
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
```

### Line 1082 addr=03E8: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E8 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1078 addr=03E4: retlw	111	;O
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
```

### Line 1083 addr=03E9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	102	;F
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03E9 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1079 addr=03E5: retlw	114	;R
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
```

### Line 1084 addr=03EA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	111	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03EA appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1080 addr=03E6: retlw	32	;
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
```

### Line 1085 addr=03EB: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	114	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03EB appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1081 addr=03E7: retlw	63	;?
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
```

### Line 1086 addr=03EC: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03EC appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1082 addr=03E8: retlw	32	;
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
1090 addr=03F0: retlw	112	;P
```

### Line 1087 addr=03ED: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	104	;H
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03ED appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1083 addr=03E9: retlw	102	;F
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
1090 addr=03F0: retlw	112	;P
1091 addr=03F1: retlw	46	;.
```

### Line 1088 addr=03EE: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	101	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03EE appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1084 addr=03EA: retlw	111	;O
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
1090 addr=03F0: retlw	112	;P
1091 addr=03F1: retlw	46	;.
1092 addr=03F2: STRINGTABLE12:
```

### Line 1089 addr=03EF: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	108	;L
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03EF appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1085 addr=03EB: retlw	114	;R
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
1090 addr=03F0: retlw	112	;P
1091 addr=03F1: retlw	46	;.
1092 addr=03F2: STRINGTABLE12:
1093 addr=03F2: retlw	19
```

### Line 1090 addr=03F0: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	112	;P
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F0 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1086 addr=03EC: retlw	32	;
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
1090 addr=03F0: retlw	112	;P
1091 addr=03F1: retlw	46	;.
1092 addr=03F2: STRINGTABLE12:
1093 addr=03F2: retlw	19
1094 addr=03F3: retlw	78	;N
```

### Line 1091 addr=03F1: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	46	;.
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F1 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1087 addr=03ED: retlw	104	;H
1088 addr=03EE: retlw	101	;E
1089 addr=03EF: retlw	108	;L
1090 addr=03F0: retlw	112	;P
1091 addr=03F1: retlw	46	;.
1092 addr=03F2: STRINGTABLE12:
1093 addr=03F2: retlw	19
1094 addr=03F3: retlw	78	;N
1095 addr=03F4: retlw	85	;U
```

### Line 1094 addr=03F3: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	78	;N
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F3 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1090 addr=03F0: retlw	112	;P
1091 addr=03F1: retlw	46	;.
1092 addr=03F2: STRINGTABLE12:
1093 addr=03F2: retlw	19
1094 addr=03F3: retlw	78	;N
1095 addr=03F4: retlw	85	;U
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
```

### Line 1095 addr=03F4: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	85	;U
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F4 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1091 addr=03F1: retlw	46	;.
1092 addr=03F2: STRINGTABLE12:
1093 addr=03F2: retlw	19
1094 addr=03F3: retlw	78	;N
1095 addr=03F4: retlw	85	;U
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
```

### Line 1096 addr=03F5: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	71	;G
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F5 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1092 addr=03F2: STRINGTABLE12:
1093 addr=03F2: retlw	19
1094 addr=03F3: retlw	78	;N
1095 addr=03F4: retlw	85	;U
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
```

### Line 1097 addr=03F6: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	71	;G
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F6 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1093 addr=03F2: retlw	19
1094 addr=03F3: retlw	78	;N
1095 addr=03F4: retlw	85	;U
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
```

### Line 1098 addr=03F7: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	69	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F7 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1094 addr=03F3: retlw	78	;N
1095 addr=03F4: retlw	85	;U
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
```

### Line 1099 addr=03F8: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	84	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F8 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1095 addr=03F4: retlw	85	;U
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
```

### Line 1100 addr=03F9: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03F9 appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1096 addr=03F5: retlw	71	;G
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
```

### Line 1101 addr=03FA: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	67	;C
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03FA appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1097 addr=03F6: retlw	71	;G
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
```

### Line 1102 addr=03FB: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	76	;L
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03FB appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1098 addr=03F7: retlw	69	;E
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
```

### Line 1103 addr=03FC: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	73	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03FC appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1099 addr=03F8: retlw	84	;T
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
```

### Line 1104 addr=03FD: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03FD appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1100 addr=03F9: retlw	32	;
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
```

### Line 1105 addr=03FE: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	67	;C
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03FE appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1101 addr=03FA: retlw	67	;C
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
```

### Line 1106 addr=03FF: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	79	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 03FF appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1102 addr=03FB: retlw	76	;L
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
```

### Line 1107 addr=0400: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	77	;M
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0400 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1103 addr=03FC: retlw	73	;I
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
1111 addr=0404: retlw	68	;D
```

### Line 1108 addr=0401: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	77	;M
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0401 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1104 addr=03FD: retlw	32	;
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
1111 addr=0404: retlw	68	;D
1112 addr=0405: retlw	83	;S
```

### Line 1109 addr=0402: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	65	;A
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0402 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1105 addr=03FE: retlw	67	;C
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
1111 addr=0404: retlw	68	;D
1112 addr=0405: retlw	83	;S
1113 addr=0406: STRINGTABLE13:
```

### Line 1110 addr=0403: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	78	;N
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0403 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1106 addr=03FF: retlw	79	;O
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
1111 addr=0404: retlw	68	;D
1112 addr=0405: retlw	83	;S
1113 addr=0406: STRINGTABLE13:
1114 addr=0406: retlw	13
```

### Line 1111 addr=0404: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	68	;D
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0404 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1107 addr=0400: retlw	77	;M
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
1111 addr=0404: retlw	68	;D
1112 addr=0405: retlw	83	;S
1113 addr=0406: STRINGTABLE13:
1114 addr=0406: retlw	13
1115 addr=0407: retlw	63	;?
```

### Line 1112 addr=0405: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	83	;S
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0405 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1108 addr=0401: retlw	77	;M
1109 addr=0402: retlw	65	;A
1110 addr=0403: retlw	78	;N
1111 addr=0404: retlw	68	;D
1112 addr=0405: retlw	83	;S
1113 addr=0406: STRINGTABLE13:
1114 addr=0406: retlw	13
1115 addr=0407: retlw	63	;?
1116 addr=0408: retlw	32	;
```

### Line 1115 addr=0407: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	63	;?
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0407 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1111 addr=0404: retlw	68	;D
1112 addr=0405: retlw	83	;S
1113 addr=0406: STRINGTABLE13:
1114 addr=0406: retlw	13
1115 addr=0407: retlw	63	;?
1116 addr=0408: retlw	32	;
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
```

### Line 1116 addr=0408: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0408 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1112 addr=0405: retlw	83	;S
1113 addr=0406: STRINGTABLE13:
1114 addr=0406: retlw	13
1115 addr=0407: retlw	63	;?
1116 addr=0408: retlw	32	;
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
```

### Line 1117 addr=0409: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	111	;O
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0409 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1113 addr=0406: STRINGTABLE13:
1114 addr=0406: retlw	13
1115 addr=0407: retlw	63	;?
1116 addr=0408: retlw	32	;
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
```

### Line 1118 addr=040A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	114	;R
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 040A appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1114 addr=0406: retlw	13
1115 addr=0407: retlw	63	;?
1116 addr=0408: retlw	32	;
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
```

### Line 1119 addr=040B: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 040B appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1115 addr=0407: retlw	63	;?
1116 addr=0408: retlw	32	;
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
```

### Line 1120 addr=040C: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	72	;H
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 040C appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1116 addr=0408: retlw	32	;
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
```

### Line 1121 addr=040D: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 040D appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1117 addr=0409: retlw	111	;O
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
```

### Line 1122 addr=040E: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	61	; (EQUALS)
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 040E appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1118 addr=040A: retlw	114	;R
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
1126 addr=0412: retlw	108	;L
```

### Line 1123 addr=040F: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 040F appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1119 addr=040B: retlw	32	;
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
1126 addr=0412: retlw	108	;L
1127 addr=0413: retlw	112	;P
```

### Line 1124 addr=0410: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	104	;H
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0410 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1120 addr=040C: retlw	72	;H
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
1126 addr=0412: retlw	108	;L
1127 addr=0413: retlw	112	;P
1128 addr=0414: STRINGTABLE14:
```

### Line 1125 addr=0411: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	101	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0411 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1121 addr=040D: retlw	32	;
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
1126 addr=0412: retlw	108	;L
1127 addr=0413: retlw	112	;P
1128 addr=0414: STRINGTABLE14:
1129 addr=0414: retlw	37
```

### Line 1126 addr=0412: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	108	;L
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0412 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1122 addr=040E: retlw	61	; (EQUALS)
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
1126 addr=0412: retlw	108	;L
1127 addr=0413: retlw	112	;P
1128 addr=0414: STRINGTABLE14:
1129 addr=0414: retlw	37
1130 addr=0415: retlw	73	;I
```

### Line 1127 addr=0413: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	112	;P
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0413 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1123 addr=040F: retlw	32	;
1124 addr=0410: retlw	104	;H
1125 addr=0411: retlw	101	;E
1126 addr=0412: retlw	108	;L
1127 addr=0413: retlw	112	;P
1128 addr=0414: STRINGTABLE14:
1129 addr=0414: retlw	37
1130 addr=0415: retlw	73	;I
1131 addr=0416: retlw	32	;
```

### Line 1130 addr=0415: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	73	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0415 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1126 addr=0412: retlw	108	;L
1127 addr=0413: retlw	112	;P
1128 addr=0414: STRINGTABLE14:
1129 addr=0414: retlw	37
1130 addr=0415: retlw	73	;I
1131 addr=0416: retlw	32	;
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
```

### Line 1131 addr=0416: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0416 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1127 addr=0413: retlw	112	;P
1128 addr=0414: STRINGTABLE14:
1129 addr=0414: retlw	37
1130 addr=0415: retlw	73	;I
1131 addr=0416: retlw	32	;
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
```

### Line 1132 addr=0417: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	105	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0417 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1128 addr=0414: STRINGTABLE14:
1129 addr=0414: retlw	37
1130 addr=0415: retlw	73	;I
1131 addr=0416: retlw	32	;
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
```

### Line 1133 addr=0418: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	100	;D
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0418 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1129 addr=0414: retlw	37
1130 addr=0415: retlw	73	;I
1131 addr=0416: retlw	32	;
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
```

### Line 1134 addr=0419: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	101	;E
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0419 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1130 addr=0415: retlw	73	;I
1131 addr=0416: retlw	32	;
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
```

### Line 1135 addr=041A: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	110	;N
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 041A appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1131 addr=0416: retlw	32	;
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
```

### Line 1136 addr=041B: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	116	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 041B appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1132 addr=0417: retlw	105	;I
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
```

### Line 1137 addr=041C: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	105	;I
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 041C appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1133 addr=0418: retlw	100	;D
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
```

### Line 1138 addr=041D: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	116	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 041D appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1134 addr=0419: retlw	101	;E
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
```

### Line 1139 addr=041E: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	121	;Y
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 041E appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1135 addr=041A: retlw	110	;N
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
```

### Line 1140 addr=041F: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	44	;,
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 041F appears within map psect `BANK5` (02A0-058E).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1136 addr=041B: retlw	116	;T
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
```

### Line 1141 addr=0420: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0420 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1137 addr=041C: retlw	105	;I
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
```

### Line 1142 addr=0421: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	83	;S
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0421 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1138 addr=041D: retlw	116	;T
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
```

### Line 1143 addr=0422: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	32	;
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0422 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1139 addr=041E: retlw	121	;Y
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
1147 addr=0426: retlw	116	;T
```

### Line 1144 addr=0423: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	115	;S
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0423 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1140 addr=041F: retlw	44	;,
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
1147 addr=0426: retlw	116	;T
1148 addr=0427: retlw	117	;U
```

### Line 1145 addr=0424: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	116	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0424 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1141 addr=0420: retlw	32	;
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
1147 addr=0426: retlw	116	;T
1148 addr=0427: retlw	117	;U
1149 addr=0428: retlw	115	;S
```

### Line 1146 addr=0425: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	97	;A
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0425 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1142 addr=0421: retlw	83	;S
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
1147 addr=0426: retlw	116	;T
1148 addr=0427: retlw	117	;U
1149 addr=0428: retlw	115	;S
1150 addr=0429: retlw	44	;,
```

### Line 1147 addr=0426: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	116	;T
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0426 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1143 addr=0422: retlw	32	;
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
1147 addr=0426: retlw	116	;T
1148 addr=0427: retlw	117	;U
1149 addr=0428: retlw	115	;S
1150 addr=0429: retlw	44	;,
1151 addr=042A: retlw	32	;
```

### Line 1148 addr=0427: POSSIBLY_UNREACHABLE_CODE [WARN]

```asm
retlw	117	;U
```
**Meaning:** Instruction follows unconditional branch/return without an intervening label.

**Why it matters:** If execution cannot fall through, this may be unreachable.

**Compiler/GCBASIC reason:** GCBASIC emits explicit labels and GOTOs for structured IF/ELSE/ENDIF flow.

**Likely programmer intent:** Represent structured BASIC control flow in PIC assembly.

**Actionability:** `Medium`

**Fix strategy:** Simplify repeated source-level branches; do not hand-edit generated GOTOs.

**Map cross-reference:** Address 0427 appears within map psect `BANK2` (0078-01E6).

**Suggested action:** Confirm no listing/psect/debug artifact explains it before changing source.

Local context:
```asm
1144 addr=0423: retlw	115	;S
1145 addr=0424: retlw	116	;T
1146 addr=0425: retlw	97	;A
1147 addr=0426: retlw	116	;T
1148 addr=0427: retlw	117	;U
1149 addr=0428: retlw	115	;S
1150 addr=0429: retlw	44	;,
1151 addr=042A: retlw	32	;
1152 addr=042B: retlw	80	;P
```

## Operator Notes

- The listing file reveals instruction-level behavior.
- The map file reveals linker-level placement and memory distribution.
- SFR/equ definitions are now separated from true code labels.
- Compiler temporaries are separately identified instead of being treated as ordinary labels.
- A suspicious instruction is not automatically wrong.
- Optimize source first. Hand-edit assembly only when purpose and timing are fully understood.
