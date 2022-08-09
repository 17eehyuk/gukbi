#include <EEPROM.h>

int address = 0;
byte value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(address <= 10)
  {
    value = EEPROM.read(address);
    String msg = String(address) + "\t" + String(value);
    Serial.println(msg);
    address = address + 1;
    delay(500);
  }
}
