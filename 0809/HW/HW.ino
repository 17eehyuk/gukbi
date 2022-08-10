/*
버튼 2개를 통해서 세그먼트에 번호 출력하는 회로
최대 9
*/
// A=13, B=12, C=11, D=10, E=9, F=8, G=7
const int seg_pin[] = {13, 12, 11, 10, 9, 8 , 7}; //segmet 할당
const int down_SW_pin = 6;
const int up_SW_pin = 5;

const String seg_num[]={
  "1111110",
  "0110000",  
  "1101101",
  "1111001",
  "0110011",
  "1011011",
  "1011111",
  "1110010",
  "1111111",
  "1111011"
};
int cur_num = 0;

// A~G 따라서 7개
// 1 = B,C
// 2 = ABDEG


void setup()
{
  for(int i=0; i<7; i++)
  {
    pinMode(seg_pin[i],OUTPUT);
  }
  pinMode(down_SW_pin, INPUT);
  pinMode(up_SW_pin, INPUT);
}


void loop()
{

  String seg_display = seg_num[cur_num];  // 현재 숫자 표시

  for(int i=0; i<7; i++)
  {
    digitalWrite(seg_pin[i],seg_display[i]-'0');  // char에서 int
  }
  int down_SW = digitalRead(down_SW_pin);
  int up_SW = digitalRead(up_SW_pin);

  // 풀업저항 사용 따라서 누르면 0
  if(down_SW == 0)
  {
    if(cur_num>0){cur_num--;}
    delay(300);   //무한 입력 방지
  }
  if(up_SW == 0)
  {
    if(cur_num<9){cur_num++;}
    delay(300);   //무한 입력 방지
  }

}
