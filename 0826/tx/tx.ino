void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("12345");
  Serial.println("67890");
  delay(500);
}
