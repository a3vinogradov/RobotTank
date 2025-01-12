#include <Arduino.h>
#include "CMotorController.h"

CMotorController::CMotorController(const int PWSPin, const int dirPin, bool isInverse)
{
  _PWSPin = PWSPin; 
  _directPin = dirPin;
  _IsInverse = isInverse;
}

void CMotorController::Setup()
{
  pinMode(_directPin, OUTPUT);
  pinMode(_PWSPin, OUTPUT);
  Stop();
}

void CMotorController::Forward(byte power)
{
  if (_IsInverse)
  {
    digitalWrite(_directPin, HIGH);
    analogWrite(_PWSPin, 255-power);
  }
  else
  {
    digitalWrite(_directPin, LOW);
    analogWrite(_PWSPin, power);
  }
}

void CMotorController::Backward(byte power)
{
  if (_IsInverse)
  {
    digitalWrite(_directPin, LOW);
    analogWrite(_PWSPin, power);
  }
  else
  {
    digitalWrite(_directPin, HIGH);
    analogWrite(_PWSPin, 255-power);
  }
}

void CMotorController::Run(int power)
{
  if (!(power < 0))
  {
    Forward(min(power, 255));
  } 
  else
  {
    Backward(min(-power, 255));
  }
}

void CMotorController::Stop()
{
  Forward(0);
}


