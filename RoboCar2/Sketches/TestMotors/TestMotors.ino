#include "CSN74HC595Controller.h"
#include "CGPOExt595.h"
#include "CMotorController.h"

#define PIN_EGPO_DS 5  
#define PIN_EGPO_ST 7
#define PIN_EGPO_SH 8

CSN74HC595Controller gExtGPO(PIN_EGPO_DS,PIN_EGPO_ST,PIN_EGPO_SH);
CSN74HC595Controller *pExtGPO = &gExtGPO; 

CGPOExt595 gGPO0(pExtGPO, 0);
CGPOExt595 *pGPO0 = &gGPO0;
CGPOExt595 gGPO1(pExtGPO, 1);
CGPOExt595 *pGPO1 = &gGPO1;
CGPOExt595 gGPO2(pExtGPO, 2);
CGPOExt595 *pGPO2 = &gGPO2;
CGPOExt595 gGPO3(pExtGPO, 3);
CGPOExt595 *pGPO3 = &gGPO3;

CArduinoGPO gGPIO3(3);
CArduinoGPO *pGPIO3 = &gGPIO3;
CArduinoGPO gGPIO9(9);
CArduinoGPO *pGPIO9 = &gGPIO9;
CArduinoGPO gGPIO10(10);
CArduinoGPO *pGPIO10 = &gGPIO10;
CArduinoGPO gGPIO11(11);
CArduinoGPO *pGPIO11 = &gGPIO11;

CMotorController gMotorFR(pGPO3, pGPIO3, true);
CMotorController gMotorFL(pGPO2, pGPIO9, false);
CMotorController gMotorBL(pGPO0, pGPIO10, true);
CMotorController gMotorBR(pGPO1, pGPIO11, false);


void setup() {
  Serial.begin(115200);
  gExtGPO.Setup();
}

void loop() {
  gExtGPO.Exec();
  if (Serial.available())
  {
    uint8_t val = Serial.read();
    if (val == 'w')
    {
      Serial.println("Forward!");
      gMotorFR.Forward(256);
      gMotorFL.Forward(256);
      gMotorBR.Forward(256);
      gMotorBL.Forward(256);
    }
    else if (val == 'x')
    {
      Serial.println("Stop!");
      gMotorFR.Stop();
      gMotorFL.Stop();
      gMotorBR.Stop();
      gMotorBL.Stop();
    }
    else if (val == 's')
    {
      Serial.println("Backward!");
      gMotorFR.Backward(255);
      gMotorFL.Backward(255);
      gMotorBR.Backward(255);
      gMotorBL.Backward(255);
    }    
    else if (val == 'a')
    {
      Serial.println("Left!");
      gMotorFR.Forward(255);
      gMotorFL.Backward(255);
      gMotorBR.Forward(255);
      gMotorBL.Backward(255);
    }   
        else if (val == 'd')
    {
      Serial.println("Right!");
      gMotorFR.Backward(255);
      gMotorFL.Forward(255);
      gMotorBR.Backward(255);
      gMotorBL.Forward(255);
    }  
    else if (val == 'q')
    {
      Serial.println("registerWrite(0b11111111)");
      gExtGPO.registerWrite(0b11111111);
    }    
    else if (val == 'e')
    {
      Serial.println("registerWrite(0b00000000)");
      gExtGPO.registerWrite(0b00000000);
    }    
  }  

}
