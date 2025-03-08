#include "FlySkyReceiver.h"
#include "CMotorController.h"
#include "CMoveController.h"

#define MOTOR_DRIVER_D0 10
#define MOTOR_DRIVER_D1 7
#define MOTOR_DRIVER_D2 9
#define MOTOR_DRIVER_D3 8

#define FS_RX 2
#define FS_TX 13

CMotorController gMotor1(MOTOR_DRIVER_D0, MOTOR_DRIVER_D1, 0);
CMotorController gMotor2(MOTOR_DRIVER_D2, MOTOR_DRIVER_D3, 0);
CMoveController gMoveController(&gMotor1, &gMotor2);
FlySkyReceiver gFSReseiver(FS_RX, FS_TX);

FlySkyData gCurFSData;

void setup() {
  // раскомментировать в финальной версии Это пины D9 и D10 - 31.4 кГц
  TCCR2B = 0b00000001;  // x1
  TCCR2A = 0b00000001;  // phase correct

  // Пины D9 и D10 - 62.5 кГц
  //TCCR1A = 0b00000001;  // 8bit
  //TCCR1B = 0b00001001;  // x1 fast pwm

  gMoveController.Setup();
  gFSReseiver.Setup();

  gCurFSData = gFSReseiver.GetDefaultData();

  Serial.begin(9600);
}

void loop() {

  gFSReseiver.Exec();
  gMoveController.Exec();

  if (!gFSReseiver.IsEqual(gCurFSData)) {
    gCurFSData = gFSReseiver.GetCurData();
    //Serial.println("New data expected!");
    // Serial.print(gCurFSData.ch[0]); Serial.print(", ");
    // Serial.print(gCurFSData.ch[1]); Serial.print(", ");
    // Serial.print(gCurFSData.ch[2]); Serial.print(", ");
    // Serial.print(gCurFSData.ch[3]); Serial.print("; ");
    // Serial.print(gCurFSData.ch[4]); Serial.print("; ");
    // Serial.print(gCurFSData.ch[5]); Serial.print("; ");
 
    gMoveController.Move(gCurFSData.ch[1], gCurFSData.ch[0]);
  }
}