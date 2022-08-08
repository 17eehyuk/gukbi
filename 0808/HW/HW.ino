#include <MultiFuncShield.h>

int count = 0;

void setup() {
  Serial.begin(9600);
  MFS.initialize();    // MFS 초기화
  
}


void loop() {
  MFS.write(count);   // 세븐세그먼트 출력
  byte btn = MFS.getButton();
  byte btn_num = btn & B00111111;
  byte btn_action = btn & B11000000;


  if(btn_action == BUTTON_PRESSED_IND || btn_action == BUTTON_LONG_PRESSED_IND)
  {
    if(btn_num == 1){if(count<9999){count++;}}
    else if(btn_num == 2){if(count>0){count--;}}
    else if(btn_num == 3){count = 0;}
  }

}
