# XC8 ASM Revelator Triage Report

This report condenses noisy line-by-line findings into ranked memory-reduction suspects.

## Ranked suspects

| Rank | Category | Score | Suspect | Evidence | Recommendation |
|---:|---|---:|---|---|---|
| 1 | `STRING_TABLE_BURDEN` | 1458 | String tables and serial text are a large footprint suspect. | Detected 60 unique STRINGTABLE symbols and 258 references. | Shorten text, remove long help from the PIC, use terse tokens, or compile help/banner text only in FULL/DEBUG builds. |
| 2 | `REPEATED_COMPARE_CHAIN` | 1308 | Dispatcher uses many repeated compare/skip/goto command tests. | Detected 109 movlw/subwf/btfss/goto compare patterns. | This is readable but expensive. First remove duplicate lower/upper tests by case-normalizing input; then consider a table-driven or grouped dispatch. |
| 3 | `BUILD_PROFILES` | 999 | This monitor should be split into build profiles. | Active feature families detected: CLI, ADC, LED, 7SEG, USART/HSER, DELAY. | Define CORE, LED, 7SEG, NCO, ADC, and FULL profiles. Make FULL the demonstration build, not the default memory-tight build. |
| 4 | `FLASH_PRESSURE` | 972 | Program memory is critically full: about 97.2% used. | Estimated used=3982 words, free=114 words from linker map. | Treat this as a code-footprint emergency. Use feature profiles and remove nonessential monitor features from the default build. |
| 5 | `SERIAL_PRINT_BURDEN` | 600 | Serial print scaffolding is heavily used. | Detected 60 print-like calls; top print targets: [('HSERPRINT422', 44), ('HSERPRINT424', 15), ('RB_7SEG_PRINTCHARINFO', 1)]. | Replace verbose repeated print sequences with shorter shared helpers and compact status tokens. |
| 6 | `COMMAND_DISPATCHER` | 587 | CLI_DISPATCHCOMMAND is a major code-size structure. | Approx span=587 words, instructions=333, compares=51, skips=51, gotos=102, calls=0. | Normalize input case once, reduce duplicate upper/lower command tests, and consider a compact command table or smaller command vocabulary. |
| 7 | `FEATURE_FAMILY` | 512 | USART/HSER feature family contributes significant call traffic. | Detected 64 calls involving USART/HSER. | Create a build flag for USART/HSER; keep it in FULL monitor builds but remove it from CORE memory-tight builds. |
| 8 | `FEATURE_FAMILY` | 48 | LED feature family contributes significant call traffic. | Detected 6 calls involving LED. | Create a build flag for LED; keep it in FULL monitor builds but remove it from CORE memory-tight builds. |
| 9 | `DELAY_USAGE` | 5 | Delay calls are present but probably not the primary memory problem. | Detected 1 delay calls: [('DELAY_MS', 1)]. | Do not start here unless timing code is very large. The dispatcher, strings, and print text are likely higher-value targets. |

## Details

```json
{
  "program_usage": {
    "used_words": 3982,
    "free_words": 114,
    "total_words": 4096,
    "percent_used": 97.216796875,
    "evidence": [
      "PROGMEM1                            800      800      78F        0       0",
      "PROGMEM0                              0        0      7FF        0       0",
      "CODE             007FF-007FF               1           2",
      "00F8F-00FFF              71"
    ]
  },
  "dispatcher": {
    "found": true,
    "start_line": 305,
    "end_line": 761,
    "start_address": 92,
    "end_address": 678,
    "instruction_count": 333,
    "call_count": 0,
    "goto_count": 102,
    "compare_count": 51,
    "skip_count": 51,
    "span_words": 587
  },
  "strings": {
    "unique_tables": 60,
    "references": 258,
    "definition_like": 60,
    "top_refs": [
      [
        "STRINGTABLE35",
        8
      ],
      [
        "STRINGTABLE37",
        8
      ],
      [
        "STRINGTABLE38",
        8
      ],
      [
        "STRINGTABLE44",
        6
      ],
      [
        "STRINGTABLE45",
        6
      ],
      [
        "STRINGTABLE95",
        6
      ],
      [
        "STRINGTABLE49",
        4
      ],
      [
        "STRINGTABLE50",
        4
      ],
      [
        "STRINGTABLE46",
        4
      ],
      [
        "STRINGTABLE47",
        4
      ],
      [
        "STRINGTABLE48",
        4
      ],
      [
        "STRINGTABLE25",
        4
      ]
    ],
    "data_like_lines": 217
  },
  "calls": {
    "total_calls": 84,
    "unique_targets": 20,
    "top_calls": [
      [
        "HSERPRINT422",
        44
      ],
      [
        "HSERPRINT424",
        15
      ],
      [
        "HSERSEND410",
        4
      ],
      [
        "FN_RB_LEDBANK_SET",
        2
      ],
      [
        "SYSCOMPLESSTHAN",
        2
      ],
      [
        "SYSDIVSUB32",
        2
      ],
      [
        "SYSCOMPEQUAL32",
        2
      ],
      [
        "INITSYS",
        1
      ],
      [
        "INITUSART",
        1
      ],
      [
        "CLI_DISPATCHCOMMAND",
        1
      ],
      [
        "FN_RB_ADC_READAVERAGE_AN2",
        1
      ],
      [
        "FN_RB_LEDBANK_TOGGLE",
        1
      ],
      [
        "RB_7SEG_PRINTCHARINFO",
        1
      ],
      [
        "FN_RB_7SEG_WRITECHAR",
        1
      ],
      [
        "FN_RB_7SEG_WRITEPATTERN",
        1
      ],
      [
        "DELAY_MS",
        1
      ],
      [
        "RB_LED_STATUS_ON",
        1
      ],
      [
        "RB_LED_STATUS_OFF",
        1
      ],
      [
        "RB_LED_STATUS_TOGGLE",
        1
      ],
      [
        "SYSCOMPEQUAL16",
        1
      ]
    ],
    "print_calls": [
      [
        "HSERPRINT422",
        44
      ],
      [
        "HSERPRINT424",
        15
      ],
      [
        "RB_7SEG_PRINTCHARINFO",
        1
      ]
    ],
    "feature_calls": {
      "CLI": 1,
      "ADC": 1,
      "LED": 6,
      "7SEG": 3,
      "NCO": 0,
      "USART/HSER": 64,
      "DELAY": 1
    }
  },
  "branches": {
    "command_compare_pattern_count": 109,
    "literal_samples": [
      "63",
      "72",
      "104",
      "73",
      "105",
      "83",
      "115",
      "80",
      "112",
      "65",
      "97",
      "82",
      "114",
      "84",
      "116",
      "68",
      "100",
      "88",
      "120",
      "77",
      "109",
      "78",
      "110",
      "43",
      "45",
      "76",
      "108",
      "48",
      "49",
      "89",
      "121",
      "71",
      "103",
      "67",
      "99",
      "79",
      "111",
      "86",
      "118",
      "74"
    ]
  },
  "delays": {
    "delay_calls": 1,
    "delay_targets": [
      [
        "DELAY_MS",
        1
      ]
    ],
    "delay_label_count": 3,
    "delay_labels": [
      "DELAY_10US",
      "DELAYUS0",
      "DELAY_MS"
    ]
  }
}
```
