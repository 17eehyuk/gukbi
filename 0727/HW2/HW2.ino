//문제
/*
LED1 100100
LED2 010010
LED3 001001
인데 SW 누르고있는 동안은 역순으로
*/

//풀이
/*
스위치 OFF
나머지
0 -> LED3
1 -> LED1
2 -> LED2

스위치 ON
나머지
0 -> LED1
1 -> LED3
2 -> LED2

즉 LED2 는 고정이므로 0<->1 을 바꿔주면됨

*/

const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int SWITCH = 10;
/**********LED**********/
unsigned long pre_millis = 0;
int state = 100;    //처음 1초의 경우 켜지는거 방지하기 위해서 0,1,2를 제외한 임의의값 설정
/*************************/

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
  unsigned long cur_millis = millis();

  // 1초마다 state값이 변함
  if(cur_millis - pre_millis >= 1000)
  {
    pre_millis = cur_millis; 
    state = pre_millis/1000%3;
    if(digitalRead(SWITCH)==LOW)
    {
      if(state != 2){state ^=1;}    // 0<->1 변환
    }
  }

  if(state == 0)
  {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  }
  else if(state == 1)
  {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  }
  else if(state == 2)
  {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  }

}
