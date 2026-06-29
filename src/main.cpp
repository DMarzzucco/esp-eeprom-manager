#include <Arduino.h>
#include <SPI.h>

#define EEPROM_CS D8

void setup()
{
    SPI.begin();

    SPI.beginTransaction(
        SPISettings(1000000, MSBFIRST, SPI_MODE0)
    );

    pinMode(EEPROM_CS, OUTPUT);
    digitalWrite(EEPROM_CS, HIGH);
}

void loop()
{
    digitalWrite(EEPROM_CS, LOW);

    for (int i = 0; i < 100; i++)
    {
        SPI.transfer(0xAA);
        SPI.transfer(0x55);
    }

    digitalWrite(EEPROM_CS, HIGH);

    delay(1000);
}