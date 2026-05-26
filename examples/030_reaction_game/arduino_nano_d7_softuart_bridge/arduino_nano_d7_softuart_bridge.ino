/*
  arduino_nano_d7_softuart_bridge.ino

  Nugget FWLIB Reaction Game serial bridge

  Purpose:
    Use an Arduino Nano as a USB-serial bridge for the PIC16F18424
    REDBOARD Reaction Game software UART output.

  Wiring:
    PIC RC4 software UART TX  -> Arduino Nano D7
    PIC GND                   -> Arduino Nano GND

  Serial settings:
    PIC software UART:  9600 baud, 8N1, TX-only
    Nano USB serial:    115200 baud to Serial Monitor / dashboard

  Notes:
    - This bridge only listens to the PIC. It does not transmit commands back.
    - D7 is used as the Nano SoftwareSerial RX pin, matching the previous
      D7 data-in bridge pattern.
    - Open Arduino Serial Monitor at 115200 baud.
*/

#include <SoftwareSerial.h>

const uint8_t PIC_RX_PIN = 7;   // Nano receives PIC TX on D7
const uint8_t UNUSED_TX_PIN = 8; // Required by SoftwareSerial, not connected

SoftwareSerial picSerial(PIC_RX_PIN, UNUSED_TX_PIN); // RX, TX

void printBanner() {
  Serial.println(F("============================================================"));
  Serial.println(F(" Nugget Reaction Game Nano D7 SoftUART Bridge"));
  Serial.println(F("============================================================"));
  Serial.println(F("Nano D7  <- PIC RC4 software UART TX"));
  Serial.println(F("Nano GND <-> PIC GND"));
  Serial.println(F("PIC UART:  9600 baud, 8N1, TX-only"));
  Serial.println(F("USB UART:  115200 baud"));
  Serial.println(F("============================================================"));
  Serial.println();
}

void setup() {
  pinMode(PIC_RX_PIN, INPUT);
  pinMode(UNUSED_TX_PIN, OUTPUT);
  digitalWrite(UNUSED_TX_PIN, HIGH);

  Serial.begin(115200);
  while (!Serial) {
    ; // harmless on Nano; useful on native-USB boards
  }

  picSerial.begin(9600);
  printBanner();

  Serial.println(F("STATUS BRIDGE_READY"));
  Serial.println(F("Waiting for PIC reaction-game telemetry..."));
  Serial.println();
}

void loop() {
  while (picSerial.available() > 0) {
    char c = (char)picSerial.read();
    Serial.write(c);
  }
}
