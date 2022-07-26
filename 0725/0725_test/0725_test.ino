int i = 90;
int finish = i-4;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:

  while(i>finish){
    Serial.print("BIN : ");
    Serial.print(i, BIN);
    Serial.print(" DEC : ");
    Serial.print(i);
    Serial.print(" HEX : ");
    Serial.print(i, HEX);

    Serial.print(" Write : ");
    Serial.write(i);

    
    Serial.println();
    i--;
  }
  
}
