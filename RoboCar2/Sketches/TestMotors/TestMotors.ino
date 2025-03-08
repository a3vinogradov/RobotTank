#include "CSN74HC595Controller.h"
#include "CGPOExt595.h"
#include "CMotorController.h"
#include "CMoveController.h"

#define PIN_EGPO_DS 5  
#define PIN_EGPO_ST 7
#define PIN_EGPO_SH 8

CSN74HC595Controller gExtGPO(PIN_EGPO_DS,PIN_EGPO_ST,PIN_EGPO_SH);
CSN74HC595Controller *pExtGPO = &gExtGPO; 

CGPOExt595 gGPO0(pExtGPO, ExtQH);
CGPOExt595 *pGPO0 = &gGPO0;
CGPOExt595 gGPO1(pExtGPO, ExtQG);
CGPOExt595 *pGPO1 = &gGPO1;
CGPOExt595 gGPO2(pExtGPO, ExtQF);
CGPOExt595 *pGPO2 = &gGPO2;
CGPOExt595 gGPO3(pExtGPO, ExtQE);
CGPOExt595 *pGPO3 = &gGPO3;

CArduinoGPO gGPIO3(3);
CArduinoGPO *pGPIO3 = &gGPIO3;
CArduinoGPO gGPIO9(9);
CArduinoGPO *pGPIO9 = &gGPIO9;
CArduinoGPO gGPIO10(10);
CArduinoGPO *pGPIO10 = &gGPIO10;
CArduinoGPO gGPIO11(11);
CArduinoGPO *pGPIO11 = &gGPIO11;

CMotorController gMotorFR(pGPO3, pGPIO3, false);
CMotorController gMotorFL(pGPO2, pGPIO9, false);
CMotorController gMotorBL(pGPO0, pGPIO10, false);
CMotorController gMotorBR(pGPO1, pGPIO11, false);


int gear = 0;
//CMotorController* pCurrentMotor;
CMoveController gMoveController(&gMotorFL, &gMotorFR, &gMotorBL, &gMotorBR);
CMoveController* pMoveController = &gMoveController;

void setup() {
  Serial.begin(115200);
  gExtGPO.Setup();
  //pCurrentMotor = &gMotorBR;
  //Serial.print("CurrentMotor : gMotorBR");

}

void loop() {


  // if (Serial.available())
  // {
  //   byte val = Serial.read();
  //   switch (val)
  //   {
  //     case 'w': {
  //       gear++;
  //       gear = gear>10?10:gear;
  //       int pow = map(gear, -10, 10, -255, 255);
  //       Serial.print("pow = "); Serial.println(pow);
  //       //pCurrentMotor->Run(pow); 
  //       pMoveController-> Move(pow, 0, 0);
  //       break;
  //     }
  //     case 's': gear = 0; pMoveController->Move(0, 0, 0); break;
  //     case 'x':{
  //       gear--;
  //       gear = gear<-10?-10:gear;
  //       int pow = map(gear, -10, 10, -255, 255);
  //       Serial.print("pow = "); Serial.println(pow);
  //       //pCurrentMotor->Run(pow); 
  //       pMoveController->Move(pow, 0, 0);
  //       break;
  //     }
  //     // case '1':{
  //     //   gear = 0;
  //     //   pMoveController->Move(0, 0, 0);
  //     //   // pCurrentMotor->Stop();
  //     //   // pCurrentMotor = &gMotorBR;
  //     //   // Serial.print("CurrentMotor : gMotorBR");
  //     //   // pCurrentMotor->Stop();
  //     //   break;
  //     // }
  //     // case '2':{
  //     //   gear = 0;
  //     //   pMoveController->Move(0, 0, 0);
  //     //   // pCurrentMotor->Stop();
  //     //   // pCurrentMotor = &gMotorBL;
  //     //   // Serial.print("CurrentMotor : gMotorBL");
  //     //   // pCurrentMotor->Stop();
  //     //   break;
  //     // }
  //     // case '3':{
  //     //   gear = 0;
  //     //   pMoveController->Move(0, 0, 0);
  //     //   // pCurrentMotor->Stop();
  //     //   // pCurrentMotor = &gMotorFR;
  //     //   // Serial.print("CurrentMotor : gMotorFR");
  //     //   // pCurrentMotor->Stop();
  //     //   break;
  //     // }
  //     // case '4':{
  //     //   gear = 0;
  //     //   pMoveController->Move(0, 0, 0);
  //     //   // pCurrentMotor->Stop();
  //     //   // pCurrentMotor = &gMotorFL;
  //     //   // Serial.print("CurrentMotor : gMotorFL");
  //     //   // pCurrentMotor->Stop();
  //     //   break;
  //     // }
  //   }
  // }
  //gExtGPO.Exec();
  //gMoveController.Exec();
   //gMoveController.Stop();
   for (int i = -255; i<256; i++)
   {
      delay(100);
      gMoveController.Move(i, 0, 0);   
   }
   for (int i = 255; i>-256; i--)
   {
      delay(100);
      gMoveController.Move(i, 0, 0);   
   }


  // gMoveController.Stop();
  // delay(1000);
  // gMoveController.Move(-64, 0, 0);
  // delay(1000);
  // gMoveController.Move(-128, 0, 0);
  // delay(1000);
  // gMoveController.Move(-192, 0, 0);
  // delay(1000);
  // gMoveController.Move(-255, 0, 0);
  // delay(1000);
  
  // gMoveController.Stop();
  // delay(1000);
  // gMoveController.Move(0, 64, 0);
  // delay(1000);
  // gMoveController.Move(0, 128, 0);
  // delay(1000);
  // gMoveController.Move(0, 192, 0);
  // delay(1000);
  // gMoveController.Move(0, 255, 0);
  // delay(1000);

  // gMoveController.Stop();
  // delay(1000);
  // gMoveController.Move(0, -64, 0);
  // delay(1000);
  // gMoveController.Move(0, -128, 0);
  // delay(1000);
  // gMoveController.Move(0, -192, 0);
  // delay(1000);
  // gMoveController.Move(0, -255, 0);
  // delay(1000);
}
