#include "Common.h"
#include "CMotorController.h"
#include "CMoveController.h"
#include "CMoveStrategy.h"

CMotorController gRightMotor(MotorDirectionPinB, MotorPWMB, false);
CMotorController gLeftMotor(MotorDirectionPinA, MotorPWMA, true);
CMoveController gMoveController(&gLeftMotor, &gRightMotor);
CMoveStrategy gMoveStrategy;

MoveSettings gCurrentMove;

void setup()
{
  Serial.begin(9600);
  gRightMotor.Setup();
  gLeftMotor.Setup();
  gMoveController.Setup();
  gMoveStrategy.Setup();

  gCurrentMove = gMoveStrategy.GetSettings();
};

void loop()
{
  //delay(500);
  MoveSettings newSettings = gMoveStrategy.GetSettings();
  //PrintSettings("-----------------",newSettings);
  if (gCurrentMove != newSettings)
  {
    gCurrentMove = newSettings;
    
    //PrintSettings("============  new ==========", gCurrentMove);
    switch (gCurrentMove.Mode)
    {
      case MoveForward: 
        gMoveController.Forward(gCurrentMove.Power);
        break;
      case MoveBackward: 
        gMoveController.Backward(gCurrentMove.Power);
        break;
      case MoveLeft: 
        gMoveController.TurnLeft(gCurrentMove.Power);
        break;
      case MoveRight: 
        gMoveController.TurnRight(gCurrentMove.Power);
        break;
      default:
        gMoveController.Stop();
    }
  }
};

void PrintSettings(String header, MoveSettings value)
{
  Serial.println();
  Serial.println(header);
  Serial.print("Power = "); Serial.println(value.Power);
  Serial.print("Mode = "); Serial.println(value.Mode);

}
