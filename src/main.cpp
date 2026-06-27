#include <Arduino.h>
#include <SPI.h>

#define EEPROM_CS D8

void setup()
{
  Serial.begin(115200);

  SPI.begin();

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  pinMode(EEPROM_CS, OUTPUT);
  digitalWrite(EEPROM_CS, HIGH);

  Serial.println("CS en HIGH");
}

void loop()
{
  digitalWrite(EEPROM_CS, LOW);

  SPI.transfer(0x9F);

  byte a = SPI.transfer(0x00);
  byte b = SPI.transfer(0x00);
  byte c = SPI.transfer(0x00);

  digitalWrite(EEPROM_CS, HIGH);

  Serial.printf("%02X %02X %02X\n", a, b, c);

  delay(2000);
}
