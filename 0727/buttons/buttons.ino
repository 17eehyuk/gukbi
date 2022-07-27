const int buttons[] = {4, 5, 6, 7};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++)
  {
    pinMode(buttons[i],INPUT);
  }

}

void loop() {

  for(int i=0; i<4; i++)
  {
    Serial.print(digitalRead(buttons[i]));
    Serial.print(" ");
  }
  Serial.println();
  delay(100);

}
