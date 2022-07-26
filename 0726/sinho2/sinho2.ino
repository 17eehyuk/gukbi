void setup()
{
  //Switch
  pinMode(10, INPUT_PULLUP);
  //LED
  pinMode(7, OUTPUT);
}

void loop()
{
  if (digitalRead(10) == LOW)
  {
    digitalWrite(7, HIGH);  
  }
  else
  {
    digitalWrite(7, LOW);
  }
}
