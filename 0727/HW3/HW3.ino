//문제
/*
SW1 -> 온도를 시리얼 모니터로 출력
SW2 -> LED 3개를 순차적으로 점멸
SW3 -> 조도값을 시리얼 모니터로 출력
SW4 -> LED 3개를 반대로 점멸
*/

//delay 시간 조절
const int delay_time = 300;


//DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;
const int SW1 = 10;
const int SW2 = 11;
const int SW3 = 12;
const int SW4 = 13;


void setup() {
  sensors.begin();
  
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT); 
}

void loop() {

  if(digitalRead(SW1)==LOW)
  {
    float tempC = sensors.getTempCByIndex(0);
    sensors.requestTemperatures(); // Send the command to get temperatures
    if(tempC != DEVICE_DISCONNECTED_C) 
    {
      Serial.print("온도 ");
      Serial.println(tempC);
    } 
    else
    {
      Serial.println("Error");
    }
    delay(delay_time);
    
    
  }
  
  if(digitalRead(SW2)==LOW)
  {
    digitalWrite(LED1,HIGH);
    delay(delay_time);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    delay(delay_time);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
    delay(delay_time);
    digitalWrite(LED3,LOW);
  }

  if(digitalRead(SW3)==LOW)
  {
    int cds_val = analogRead(A5);
    Serial.print("조도 ");
    Serial.println(cds_val);
    delay(delay_time);
    
  }

  if(digitalRead(SW4)==LOW)
  {
    digitalWrite(LED3,HIGH);
    delay(delay_time);
    digitalWrite(LED3,LOW);
    digitalWrite(LED2,HIGH);
    delay(delay_time);
    digitalWrite(LED2,LOW);
    digitalWrite(LED1,HIGH);
    delay(delay_time);
    digitalWrite(LED1,LOW);
  }
  
}
