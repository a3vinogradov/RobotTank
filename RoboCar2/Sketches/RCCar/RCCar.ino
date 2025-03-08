#include "CSN74HC595Controller.h"
#include "CGPOExt595.h"
#include "CMotorController.h"
#include "CMoveController.h"
#include "FlySkyReceiver.h"
#include "CMotorEncoder.h"

// FlySky
#define PIN_FS_RX 13
#define PIN_FS_TX 2

// Моторы PWM
#define PIN_MD_FR 3
#define PIN_MD_FL 9
#define PIN_MD_BL 10
#define PIN_MD_BR 11

//Енкодеры
#define PIN_ME_FR 4  
#define PIN_ME_FL 6 
#define PIN_ME_BL 12 
#define PIN_ME_BR 2 

// Регистр
#define PIN_EGPO_DS 5  
#define PIN_EGPO_ST 7
#define PIN_EGPO_SH 8

CSN74HC595Controller gExtGPO(PIN_EGPO_DS,PIN_EGPO_ST,PIN_EGPO_SH);

CGPOExt595 gGPO0(&gExtGPO, ExtQH);
CGPOExt595 gGPO1(&gExtGPO, ExtQG);
CGPOExt595 gGPO2(&gExtGPO, ExtQF);
CGPOExt595 gGPO3(&gExtGPO, ExtQE);

CArduinoGPO gGPIO3(PIN_MD_FR);
CArduinoGPO gGPIO9(PIN_MD_FL);
CArduinoGPO gGPIO10(PIN_MD_BL);
CArduinoGPO gGPIO11(PIN_MD_BR);

CMotorEncoder gEncoderFR(PIN_ME_FR);
CMotorEncoder gEncoderFL(PIN_ME_FL);
CMotorEncoder gEncoderBR(PIN_ME_BR);
CMotorEncoder gEncoderBL(PIN_ME_BL);

CMotorController gMotorFR(&gGPO2, &gGPIO9, false);
CMotorController gMotorFL(&gGPO3, &gGPIO3, false);
CMotorController gMotorBL(&gGPO0, &gGPIO10, false);
CMotorController gMotorBR(&gGPO1, &gGPIO11, false);

CMoveController gMoveController(&gMotorFL, &gMotorFR, &gMotorBL, &gMotorBR);
CMoveController* pMoveController = &gMoveController;

FlySkyReceiver gReceiver(PIN_FS_RX, PIN_FS_TX);

FlySkyData data;

unsigned long _tmr;

void setup() {
  Serial.begin(115200);
  gExtGPO.Setup();
  gExtGPO.registerWrite(0b00000000);

  gMoveController.Setup();
  gMoveController.Move(0,0,0);

  gEncoderFR.Setup();
  gEncoderFL.Setup();
  gEncoderBR.Setup();
  gEncoderBL.Setup();

  gReceiver.Setup();
  data = gReceiver.GetDefaultData();

  _tmr = 0;
}

void loop()
{
  gEncoderFR.Exec();
  gEncoderFL.Exec();
  gEncoderBR.Exec();
  gEncoderBL.Exec();
  
  gReceiver.Exec();
  if (!gReceiver.IsEqual(data))
  {
    data = gReceiver.GetCurData();
    int powMove = map(data.ch[1], 1000, 2000, 255, -255);
    int powTurn = map(data.ch[0], 1000, 2000, -128, 128);
    //Serial.print("Move = "); Serial.print(powMove); Serial.print("; Turn = "); Serial.println(powTurn); 
    gMoveController.Move(powMove, powTurn, 0);
  }

  if (millis() - _tmr >= 500) 
  {
    _tmr = millis();  // "сбросить"
    Serial.print("FR = "); Serial.print(gEncoderFR.GetCount()); Serial.print(", ");
    Serial.print("FL = "); Serial.print(gEncoderFL.GetCount()); Serial.print(", ");
    Serial.print("BR = "); Serial.print(gEncoderBR.GetCount()); Serial.print(", ");
    Serial.print("BL = "); Serial.print(gEncoderBL.GetCount()); Serial.println(";");
    //Serial.println(_count);
  } 
}
