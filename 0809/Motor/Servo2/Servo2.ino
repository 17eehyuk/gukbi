#include <MultiFuncShield.h>
#include <Servo.h>


Servo servo;
int servoPin = 5;
int motor_speed = 5;


void setup() {
  servo.attach(servoPin);
  MFS.initialize();    // MFS 초기화
}
 
void loop() {
  MFS.write(motor_speed);   //스피드 표현
  byte btn = MFS.getButton();
  byte btn_num = btn & B00111111;
  byte btn_action = btn & B11000000;

  if(btn_action == BUTTON_PRESSED_IND || btn_action == BUTTON_LONG_PRESSED_IND)
  {
    if(btn_num == 1){motor_speed=5;}
    else if(btn_num == 2){motor_speed=3;}
    else if(btn_num == 3){motor_speed=1;}
  }

  
  for(int angle=0; angle<180; angle++)
  {
    servo.write(angle);
    delay(motor_speed);
  }
  for(int angle=180; angle>0; angle--)
  {
    servo.write(angle);
    delay(motor_speed);
  }

}
