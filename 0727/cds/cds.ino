void setup() {
  Serial.begin(9600);
}

void loop() {
  int cds_val = analogRead(A1);
  Serial.println(cds_val);
  delay(300);
}
