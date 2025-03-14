#include "Arduino.h"
#include "CMotorController.h"

CMotorController::CMotorController(CGPO* pin1, CGPO_PWM* pin2, bool isInverse = false)
{
    _IsInverse = isInverse;
    _pinConst = pin1;
    _pinPWM = pin2;
}
void CMotorController::Setup()
{
  Stop();
}

void CMotorController::Forward(byte power)
{
  if (_IsInverse)
  {
    _pinConst->On();
    _pinPWM->PWM(255-power);
  } else {
    _pinConst->Off();
    _pinPWM->PWM(power);
  }
}

void CMotorController::Backward(byte power)
{
  if (_IsInverse)
  {
    _pinConst->Off();
    _pinPWM->PWM(power);
  } else {
    _pinConst->On();
    _pinPWM->PWM(255-power);
  }
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
  _pinConst->Off();
  _pinPWM->Off();
}
