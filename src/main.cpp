#include <Arduino.h>
#include <SPI.h>

#define EEPROM_CS D8

void setup() {
  Serial.begin(115200);

  SPI.begin();

  pinMode(EEPROM_CS, OUTPUT);
  digitalWrite(EEPROM_CS, HIGH);

  Serial.println("EEPROM TEST");
}

byte readStatusRegister() {
  digitalWrite(EEPROM_CS, LOW);

  SPI.transfer(0x05); // RDSR
  byte status = SPI.transfer(0x00);

  digitalWrite(EEPROM_CS, HIGH);

  return status;
}

void loop() {
  byte status = readStatusRegister();

  Serial.print("STATUS: 0x");
  Serial.println(status, HEX);

  delay(1000);
}