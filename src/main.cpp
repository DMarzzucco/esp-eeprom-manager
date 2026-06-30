#include <Arduino.h>
#include <SPI.h>

#define EEPROM_CS D8

void setup()
{
    Serial.begin(115200);

    pinMode(EEPROM_CS, OUTPUT);
    digitalWrite(EEPROM_CS, HIGH);

    SPI.begin();

    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

    Serial.println("Leyendo Status Register...");
}

void loop()
{
    digitalWrite(EEPROM_CS, LOW);

    SPI.transfer(0x05);  
    uint8_t status = SPI.transfer(0x00);

    digitalWrite(EEPROM_CS, HIGH);

    Serial.print("Status: 0x");
    Serial.println(status, HEX);

    delay(1000);
}
