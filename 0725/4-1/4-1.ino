void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  
  byte data = 65;
  
  Serial.print("With print:");
  Serial.println(data);

  Serial.print("With write:");
  Serial.write(data);
  Serial.println();
  Serial.println();

  delay(500);
}
