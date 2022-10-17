#include "CMotorController.h"

CMotorController::CMotorController(int directPin, int PWMPin, bool isInverse)
{
 _DirectPin = directPin;
 _PWMPin = PWMPin;
 _IsInverse = isInverse;
}
void CMotorController::Setup()
{
  pinMode(_DirectPin, OUTPUT);
  pinMode(_PWMPin, OUTPUT);
}

void CMotorController::Forward(byte power)
{
  digitalWrite(_DirectPin,_IsInverse?LOW:HIGH);
  analogWrite(_PWMPin,power);
}

void CMotorController::Backward(byte power)
{
  digitalWrite(_DirectPin,_IsInverse?HIGH:LOW);
  analogWrite(_PWMPin,power);
}

void CMotorController::Stop()
{
  digitalWrite(_DirectPin,_IsInverse?LOW:HIGH);
  analogWrite(_PWMPin,0);   
}
