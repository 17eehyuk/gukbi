#include <EEPROM.h>

int addr = 2;   //주소당 1바이트(0~255) 데이터 저장가능
int number_count = 10;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  int val = analogRead(A0) / 4;   //0~255 까지만 저장가능하기 때문

  if(number_count > 0)
  {
    number_count--;
    EEPROM.write(addr,val);
    String msg =
    "number_count = " + String(number_count) +
    ", addr = " + String(addr) +
    ", val = " + String(val);
    Serial.println(msg);    
  }
  EEPROM.write(0, 77);
  EEPROM.write(1, 33);
  

}
