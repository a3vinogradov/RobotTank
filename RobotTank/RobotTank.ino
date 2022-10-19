#include "Common.h"
#include "CMotorController.h"
#include "CMoveController.h"
#include "CMoveStrategy.h"
#include "CMainController.h"

CMotorController gRightMotor(MotorDirectionPinB, MotorPWMB, false);
CMotorController gLeftMotor(MotorDirectionPinA, MotorPWMA, true);
CMoveController gMoveController(&gLeftMotor, &gRightMotor);
CMoveStrategy gMoveStrategy;
CMainController gMainController(&gMoveController, &gMoveStrategy);



//MoveSettings gCurrentMove;

void setup()
{
  Serial.begin(9600);
  gRightMotor.Setup();
  gLeftMotor.Setup();
  gMoveController.Setup();
  gMoveStrategy.Setup();
  gMainController.Setup();

  //gCurrentMove = gMoveStrategy.GetSettings();
};

void loop()
{
  delay(500);
  gMainController.Exec();
};

void PrintSettings(String header, MoveSettings value)
{
  Serial.println();
  Serial.println(header);
  Serial.print("Power = "); Serial.println(value.Power);
  Serial.print("Mode = "); Serial.println(value.Mode);
}
