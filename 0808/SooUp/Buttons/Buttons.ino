#include <MultiFuncShield.h>

/*

For more information and help, please visit https://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-1/

*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  MFS.initialize();    // initialize multi-function shield library
}


void loop() {
  // put your main code here, to run repeatedly:

  byte btn = MFS.getButton(); // Normally it is sufficient to compare the return
                              // value to predefined macros, e.g. BUTTON_1_PRESSED,
                              // BUTTON_1_LONG_PRESSED etc.
  byte buttonAction = btn & B11000000;

  Serial.println(buttonAction);
  delay(100);
//  if (btn)
//  {
//    byte buttonNumber = btn & B00111111;
//    byte buttonAction = btn & B11000000;
//    
//    Serial.print("BUTTON_");
//    Serial.write(buttonNumber + '0');
//    Serial.print("_");
//    
//    if (buttonAction == BUTTON_PRESSED_IND)   //BUTTON_PRESSED_IND : 0x00
//    {
//      Serial.println("PRESSED");
//    }
//    else if (buttonAction == BUTTON_SHORT_RELEASE_IND)    // BUTTON_SHORT_RELEASE_IND : 0x40
//    {
//      Serial.println("SHORT_RELEASE");
//    }
//    else if (buttonAction == BUTTON_LONG_PRESSED_IND)     // BUTTON_LONG_PRESSED_IND : 0x80
//    {
//      Serial.println("LONG_PRESSED");
//    }
//    else if (buttonAction == BUTTON_LONG_RELEASE_IND)     // BUTTON_LONG_RELEASE_IND : 0xC0
//    {
//      Serial.println("LONG_RELEASE");
//    }
//  }
}
