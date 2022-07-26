void setup()
{
  //Switch
  pinMode(10, OUTPUT);
  //LED
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{

  for (int i = 7; i >= 5; i--)
  {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    delay(500);
  }

}
