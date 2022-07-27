/*
LED1 010101
LED2 101010
이런식으로 서로 교차되게 켜지고
스위치를 누르면 LED3가 켜지게 설계하기
*/


const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int SWITCH = 10;

/**********LED1, LED2**********/
int pre_millis = 0;
int LED_state = 1; 
/*************************/

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(SWITCH, INPUT);
  digitalWrite(LED2, HIGH); // 처음 1초용
}

void loop() {
  //LED1, LED2
  int cur_millis = millis();
  if(cur_millis - pre_millis >= 1000)
  {
    pre_millis = cur_millis; 
    digitalWrite(LED1, LED_state);
    digitalWrite(LED2, LED_state^1);
    LED_state ^= 1;      // XOR 이용해서 토글
  }
  
  //LED3    //풀업저항 따라서 누르면 LOW
  (digitalRead(SWITCH)==LOW)?(digitalWrite(LED3, HIGH)):(digitalWrite(LED3, LOW)); 

}
