#include "CSN74HC595Controller.h"
// #include "CGPOExt595.h"
// #include "CMotorController.h"
// #include "CMoveController.h"
#include "CMotorEncoder.h"

#define PIN_MD_FR 3
#define PIN_MD_FL 9
#define PIN_MD_BL 10
#define PIN_MD_BR 11

#define PIN_ME_FR 4 //2 
#define PIN_ME_FL 6 //4
#define PIN_ME_BL 12 //6
#define PIN_ME_BR 2 //12

#define PIN_EGPO_DS 5  
#define PIN_EGPO_ST 7
#define PIN_EGPO_SH 8

CSN74HC595Controller gExtGPO(PIN_EGPO_DS,PIN_EGPO_ST,PIN_EGPO_SH);

// CGPOExt595 gGPO0(&gExtGPO, ExtQH);
// CGPOExt595 gGPO1(&gExtGPO, ExtQG);
// CGPOExt595 gGPO2(&gExtGPO, ExtQF);
// CGPOExt595 gGPO3(&gExtGPO, ExtQE);

// CArduinoGPO gGPIO3(PIN_MD_FR);
// CArduinoGPO gGPIO9(PIN_MD_FL);
// CArduinoGPO gGPIO10(PIN_MD_BL);
// CArduinoGPO gGPIO11(PIN_MD_BR);

// CMotorController gMotorFR(&gGPO2, &gGPIO9, false);
// CMotorController gMotorFL(&gGPO3, &gGPIO3, false);
// CMotorController gMotorBL(&gGPO0, &gGPIO10, false);
// CMotorController gMotorBR(&gGPO1, &gGPIO11, false);

// CMoveController gMoveController(&gMotorFL, &gMotorFR, &gMotorBL, &gMotorBR);
// CMoveController* pMoveController = &gMoveController;

CMotorEncoder gEncoderFR(PIN_ME_FR);
CMotorEncoder gEncoderFL(PIN_ME_FL);
CMotorEncoder gEncoderBR(PIN_ME_BR);
CMotorEncoder gEncoderBL(PIN_ME_BL);

unsigned long _tmr;

void setup() {
  Serial.begin(115200);
  gExtGPO.Setup();
  gExtGPO.registerWrite(0b00000000);

  gEncoderFR.Setup();
  gEncoderFL.Setup();
  gEncoderBR.Setup();
  gEncoderBL.Setup();


  // gMoveController.Setup();
  // gMoveController.Move(0,0,0);

  _tmr = 0;
}

void loop()
{
  gEncoderFR.Exec();
  gEncoderFL.Exec();
  gEncoderBR.Exec();
  gEncoderBL.Exec();

  if (millis() - _tmr >= 500) {
    _tmr = millis();  // "сбросить"
    Serial.print("FR = "); Serial.print(gEncoderFR.GetCount()); Serial.print(", ");
    Serial.print("FL = "); Serial.print(gEncoderFL.GetCount()); Serial.print(", ");
    Serial.print("BR = "); Serial.print(gEncoderBR.GetCount()); Serial.print(", ");
    Serial.print("BL = "); Serial.print(gEncoderBL.GetCount()); Serial.println(";");
    //Serial.println(_count);
  }

}