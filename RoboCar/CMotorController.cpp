#include "Arduino.h"
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
  //Stop();
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

void CMotorController::Run(int power)
{
  int pow = constrain(power, -255, 255);
  
  // Serial.print("Motor Run: ");
  // Serial.print(power);
  // Serial.print(" - ");
  // Serial.println(pow);
  
  if (pow > 0)
  {
    Forward(pow);
  } 
  else
  {
    Backward(-pow);
  }   
}

void CMotorController::Stop()
{
  _afMotor.setSpeed(0);    // Начальная скорость вращения
  _afMotor.run(RELEASE);  
}
