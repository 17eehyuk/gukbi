const int LED1 = 7;
const int LED2 = 5;
const int SWITCH = 10;

/**********LED1**********/
int pre_millis = 0;
int LED1_state = 0; 
/*************************/

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
  //LED1
  int cur_millis = millis();
  if(cur_millis - pre_millis >= 1000)
  {
    pre_millis = cur_millis; 
    digitalWrite(LED1, LED1_state);
    LED1_state ^= 1;      // XOR 이용해서 토글
  }
  
  //LED2    //풀업저항 따라서 누르면 LOW
  (digitalRead(SWITCH)==LOW)?(digitalWrite(LED2, HIGH)):(digitalWrite(LED2, LOW)); 

}
