#include "CSN74HC595Controller.h"
#include "CGPOExt595.h"

#define PIN_EGPO_DS 5  
#define PIN_EGPO_ST 7
#define PIN_EGPO_SH 8

CSN74HC595Controller gExtGPO(PIN_EGPO_DS,PIN_EGPO_ST,PIN_EGPO_SH);
CSN74HC595Controller *pExtGPO = &gExtGPO; 

// CGPOExt595 gGPO0(pExtGPO, 0);
// CGPOExt595 gGPO1(pExtGPO, 1);
// CGPOExt595 gGPO2(pExtGPO, 2);
// CGPOExt595 gGPO3(pExtGPO, 3);
CGPOExt595 gGPO4(pExtGPO, 4);
CGPOExt595 gGPO5(pExtGPO, 5);
CGPOExt595 gGPO6(pExtGPO, 6);
CGPOExt595 gGPO7(pExtGPO, 7);
CArduinoGPO gGPIO3(3);
CArduinoGPO gGPIO9(9);
CArduinoGPO gGPIO3(10);
CArduinoGPO gGPIO9(11);



void setup() {
  Serial.begin(115200);
  gExtGPO.Setup();
}

void loop() {
  gExtGPO.Exec();
  

}
