#ifndef file_CMoveController
#define file_CMoveController

#include <Arduino.h>
#include "CMotorController.h"
#include "Common.h"

class CMoveController
{
  private:
  CMotorController* _LeftMotor;
  CMotorController* _RightMotor;
  byte _TurnKoeff = 2; 
  
  public:  
  CMoveController( CMotorController* leftMotor, CMotorController* rightMotor);
  void Setup();
  void TurnLeft(byte power);
  void TurnRight(byte power);
  void MoveLeft(byte power);
  void MoveRight(byte power);
  void Forward(byte power);
  void Backward(byte power);
  void Move(byte moveType, byte power);  
  void Stop();
};


#endif 
