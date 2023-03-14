#include "CMotorController.h"

CMotorController::CMotorController(int motorNumber, bool isInverse):
  _afMotor(motorNumber)
{
  _motorNumber = motorNumber; 
  _direct = FORWARD;
  _IsInverse = isInverse;
}
void CMotorController::Setup()
{
  Stop();
}

void CMotorController::Forward(byte power)
{
  uint8_t dir = _IsInverse?BACKWARD:FORWARD;  
  _afMotor.run(dir);
  _afMotor.setSpeed(power);  
}

void CMotorController::Backward(byte power)
{
  uint8_t dir = _IsInverse?FORWARD:BACKWARD;  
  _afMotor.run(dir);
  _afMotor.setSpeed(power);  
}

void CMotorController::Stop()
{
  _afMotor.setSpeed(0);    // Начальная скорость вращения
  _afMotor.run(RELEASE);  
}
