"""Minimal serial logger for nugget-fwlib GSA text devices.

Usage:
    pip install pyserial
    python nugget_serial_logger.py COM19 9600
"""
import sys, time
import serial

port = sys.argv[1] if len(sys.argv) > 1 else "COM19"
baud = int(sys.argv[2]) if len(sys.argv) > 2 else 9600

with serial.Serial(port, baud, timeout=1) as ser:
    print(f"Connected to {port} at {baud} baud")
    ser.write(b"HELLO
")
    while True:
        line = ser.readline().decode(errors="replace").strip()
        if line:
            print(time.strftime("%H:%M:%S"), line)
