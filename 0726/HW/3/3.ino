/*
3개 LED를 1초 간격으로 다음과 같이 점멸하도록 프로그램

LED1  OOXOOX...
LED2  XOOXOOX...
LED3  XXOOXOOX...

*/

//즉 2개씩 켜지도록 설계

int LED1 = 7;
int LED2 = 6;
int LED3 = 5;
unsigned long i = 1;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
  
}

void potentiometer()
{
  int val = analogRead(A0);
  
  int delay_time = 1000/(1+9*val/1023);   //0이면 1000, 1023이면 100
  Serial.print("val : ");
  Serial.print(val);
  Serial.print(", delay_time : ");
  Serial.println(delay_time);
  delay(delay_time); 
}

void loop()
{
  if(i==1){
    
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    potentiometer();
    i++;
  }
  else{
    while(1)
    {
      if(i%3==0)
      {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        potentiometer();
        i++;
      }
      else if(i%3==1)
      {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        potentiometer();
        i++;
      }
      else if(i%3==2)
      {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        potentiometer();
        i++;
      }
      
    }  
    
  }
  


  
}
