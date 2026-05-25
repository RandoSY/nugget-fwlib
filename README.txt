NUGGET-FWLIB v0.1.0
====================

A GCBASIC firmware library for REDBOARD, PIC Black Box, and GSA teaching instruments.

Purpose
-------
nugget-fwlib turns the PIC16F18424 into a readable, teachable, protocol-speaking embedded device.
It is organized like a small firmware framework rather than a bag of examples.

The goal is transparency:

    If the student cannot understand the magic, it does not help.

Core behavior classes
---------------------
    GPIO
    Switch input
    Timing and stopwatch behavior
    ADC measurement
    PWM / pseudo-DAC behavior
    UART serial I/O
    GSA tiny text protocol
    Diagnostics and blink codes
    Sensor/device wrappers
    Cooperative task service patterns

Primary target
--------------
PIC16F18424 using GCBASIC on the REDBOARD / PIC Black Box workflow.
Default configuration:

    #chip 16F18424
    #option Explicit
    #config LVP = ON
    #config MCLRE = ON

The LVP and MCLRE lines are important for the REDBOARD / SNAP-LVP workflow.

First-use examples
------------------
    examples/001_blink/001_blink.gcb
    examples/002_switch_pullup_led/002_switch_pullup_led.gcb
    examples/003_debounced_button_event/003_debounced_button_event.gcb
    examples/004_one_bit_latch/004_one_bit_latch.gcb
    examples/006_uart_hello/006_uart_hello.gcb
    examples/007_gsa_hello_status/007_gsa_hello_status.gcb

GSA command examples
--------------------
Open a serial terminal or Web Serial dashboard and send:

    HELLO
    STATUS
    START
    STOP
    RESET
    TARE
    READ
    DEMO ON
    DEMO OFF

Expected response style:

    ID NUGGET-REDBOARD PIC16F18424 FW=0.1.0
    OK STATUS READY
    OK START
    OK TARE
    DATA ADC 512
    ERR BAD_CMD

Important note
--------------
This is a v0.1.0 teaching release. GCBASIC syntax can vary slightly by version and chip header.
If a register or serial receive helper requires a local syntax correction, keep the behavior API stable and adjust the low-level routine only.
