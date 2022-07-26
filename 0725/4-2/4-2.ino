void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  Serial.println(123, DEC);
  Serial.println(123, HEX);
  Serial.println(123, BIN);

  Serial.print(3.14195,2);  // 소수점 2개만 출력
  
  Serial.println();
  delay(500);
}
