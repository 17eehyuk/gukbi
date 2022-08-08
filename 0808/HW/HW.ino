#include <MultiFuncShield.h>

int count = 0;
int btn_flag = 0;

void setup() {
  Serial.begin(9600);
  MFS.initialize();    // MFS 초기화
  
}


void loop() {
  MFS.write(count);   // 세븐세그먼트 출력
  byte btn = MFS.getButton();
  byte btn_num = btn & B00111111;
  byte btn_action = btn & B11000000;

  if(btn_num == 1 && btn_flag == 0)
  {
    btn_flag = 1;
    if(count<9999){count++;}     
  }
  else if(btn_num == 2 && btn_flag == 0)
  {
    btn_flag = 1;
    if(count>0){count--;}
  }
  else if(btn_num == 3 && btn_flag == 0)
  {
    btn_flag = 1;
    count = 0; 
  }

  if(btn_action == BUTTON_SHORT_RELEASE_IND || btn_action == BUTTON_LONG_RELEASE_IND)
  {
    btn_flag = 0;   // 때는 순간 flag 초기화
  }

  if (btn_action == BUTTON_LONG_PRESSED_IND)      // 꾹 눌렀을 때
  {
    if(btn_num ==1)
    {
      count++;
    }
    else if(btn_num ==2)
    {
      count--;
    }
  }
  
}
