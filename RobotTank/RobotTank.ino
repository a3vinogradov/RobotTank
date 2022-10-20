#include "Common.h"
#include "CMotorController.h"
#include "CMoveController.h"
#include "CRandomStrategy.h"
#include "CIRStrategy.h"
#include "CMainController.h"
#include "CSensorController.h"

CSensorController gSensorController(cnstIRLeftPin, cnstIRRightPin, cnstUSEchoPin, cnstUSTrigPin);
CMotorController gRightMotor(MotorDirectionPinB, MotorPWMB, false);
CMotorController gLeftMotor(MotorDirectionPinA, MotorPWMA, true);
CMoveController gMoveController(&gLeftMotor, &gRightMotor);
CRandomStrategy gRandomStrategy;
CIRStrategy gIRStrategy(&gSensorController);
//CMainController gMainController(&gMoveController, &gRandomStrategy);
CMainController gMainController(&gMoveController, &gIRStrategy);

void setup()
{
  Serial.begin(9600);
  LogMsg("");  
  LogMsg("Setup..."); 

  gSensorController.Setup();  
  gRightMotor.Setup();
  gLeftMotor.Setup();
  gMoveController.Setup();
  gRandomStrategy.Setup();
  gIRStrategy.Setup();
  gMainController.Setup();
  LogMsg("Setup successfull");    
};

void loop()
{
  gSensorController.Exec();
  gMainController.Exec();
};


