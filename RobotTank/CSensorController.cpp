#include "CSensorController.h"

CSensorController::CSensorController(int irLeftPin, int irRightPin, int USEchoPin, int USTrigPin)
{
  _IRLeftPin = irLeftPin;
}

void CSensorController::Setup()
{
  pinMode(_IRLeftPin, INPUT);
  pinMode(_IRRightPin, INPUT);
}    

void CSensorController::Exec()
{
  
}

bool CSensorController::GetIRLeft()
{
  return digitalRead(cnstIRLeftPin) == 1;
}

bool CSensorController::GetIRRight()
{
  return digitalRead(cnstIRRightPin) == 1;
}