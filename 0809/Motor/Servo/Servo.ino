#include <Servo.h>

Servo servo;
int servoPin = 5;

void setup() {
  servo.attach(servoPin);
}
 
void loop() {

  for(int angle=0; angle<180; angle++)
  {
    servo.write(angle);
    delay(5);
  }
  for(int angle=180; angle>0; angle--)
  {
    servo.write(angle);
    delay(5);
  }

}
