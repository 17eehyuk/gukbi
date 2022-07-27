void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    byte data = Serial.read();

    if(data != '\n')    //엔터키 방지
    {
      Serial.print("Echo back : ");
      Serial.write(data);
      Serial.print(" ");
      Serial.println(data);
    }
  }
}
