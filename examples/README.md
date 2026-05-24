# nugget-fwlib Example Suite

The examples are intentionally verbose. They are not code golf. They are teaching artifacts.

| # | Example | Main idea |
|---|---|---|
| 001 | blink | GPIO output |
| 002 | switch_pullup_led | switch-to-ground + weak pull-up |
| 003 | debounced_button_event | clean press event |
| 004 | one_bit_latch | one-bit memory |
| 005 | reaction_timer_blocking | elapsed time |
| 006 | uart_hello | serial text output |
| 007 | gsa_hello_status | tiny command protocol |
| 008 | adc_read_serial_csv | ADC + CSV |
| 009 | adc_threshold_rg_show | threshold classification |
| 010 | softdac_pwm_brightness | number to duty cycle |
| 011 | blink_codes_faults | visible diagnostics |
| 012 | cooperative_tick_demo | service-style multitasking |
| 013 | state_machine_reaction | explicit states |
| 014 | hx711_ready_fault_demo | sensor ready/fault pattern |
| 015 | gsa_adc_instrument | ADC as GSA telemetry |
| 016 | tare_button_pattern | local control behavior |
| 017 | button_modes | one-button UI |
| 018 | serial_csv_reaction_trials | CSV statistics source |
| 019 | hcsr04_tapeless_ruler_skeleton | distance instrument skeleton |
| 020 | full_tiny_gsa_node | integrated endpoint pattern |

Build note: examples assume they are two folders below the repository root and use:

```gcb
#include "../../nugget_fwlib_all.inc"
```
