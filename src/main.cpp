#include <Arduino.h>
#include <SPI.h>

#define EEPROM_CS D8

void writeEnable()
{
  digitalWrite(EEPROM_CS, LOW);

  SPI.transfer(0x06); // WREN

  digitalWrite(EEPROM_CS, HIGH);
}
byte readStatus()
{
  digitalWrite(EEPROM_CS, LOW);

  SPI.transfer(0x05); // RDSR

  Serial.print("RX: ");
  for (int i = 0; i < 8; i++)
  {
    Serial.printf("%02X ", SPI.transfer(0x00));
  }
  // byte status = SPI.transfer(0x00);

  Serial.println();
  digitalWrite(EEPROM_CS, HIGH);

  return 0;
}

void waitWriteComplete()
{
  while (readStatus() & 0x01)
  {
    delay(10);
  }
}

void writeByte(uint32_t address, byte value)
{
  writeEnable();

  digitalWrite(EEPROM_CS, LOW);

  SPI.transfer(0x02); // WRITE

  SPI.transfer((address >> 16) & 0xFF);
  SPI.transfer((address >> 8) & 0xFF);
  SPI.transfer(address & 0xFF);

  SPI.transfer(value);

  digitalWrite(EEPROM_CS, HIGH);

  delay(20);
  // waitWriteComplete();
}

byte readByte(uint32_t address)
{
  digitalWrite(EEPROM_CS, LOW);

  SPI.transfer(0x03); // READ

  SPI.transfer((address >> 16) & 0xFF);
  SPI.transfer((address >> 8) & 0xFF);
  SPI.transfer(address & 0xFF);

  byte value = SPI.transfer(0x00);

  digitalWrite(EEPROM_CS, HIGH);

  return value;
}

void setup()
{
  Serial.begin(115200);
  SPI.begin();

  pinMode(EEPROM_CS, OUTPUT);
  digitalWrite(EEPROM_CS, HIGH);

  Serial.println("Inicio");
}

void loop()
{
  readStatus();
  delay(3000);
}