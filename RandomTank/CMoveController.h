#ifndef file_CMoveController
#define file_CMoveController

#include "CMotorController.h"

class CMoveController
{
  private:
  CMotorController* _LeftMotor;
  CMotorController* _RightMotor;

  public:  
  CMoveController( CMotorController* leftMotor, CMotorController* rightMotor);
  void Setup();
  void TurnLeft(byte power);
  void TurnRight(byte power);
  void Forward(byte power);
  void Backward(byte power);
  void Stop();
};


#endif 
