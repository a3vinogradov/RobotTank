#include "CMoveController.h"

CMoveController::CMoveController( CMotorController* leftMotor, CMotorController* rightMotor)
{
  _LeftMotor = leftMotor;
  _RightMotor = rightMotor;
}

void CMoveController::Setup()
{
  
}

void CMoveController::TurnLeft(byte power)
{
  _RightMotor->Forward(power);
  _LeftMotor->Backward(power);
}

void CMoveController::TurnRight(byte power)
{
  _RightMotor->Backward(power);
  _LeftMotor->Forward(power);
}

void CMoveController::MoveLeft(byte power)
{
  _RightMotor->Forward(power);
  _LeftMotor->Forward(power/_TurnKoeff);
  
};

void CMoveController::MoveRight(byte power)
{
  _RightMotor->Forward(power/_TurnKoeff);
  _LeftMotor->Forward(power);
};

void CMoveController::Forward(byte power)
{
  _RightMotor->Forward(power);
  _LeftMotor->Forward(power);
}
  
void CMoveController::Backward(byte power)
{
  _RightMotor->Backward(power);
  _LeftMotor->Backward(power);
}

void CMoveController::Stop()
{
  _RightMotor->Stop();
  _LeftMotor->Stop();
}

void CMoveController::Move(byte moveType, byte power)
{
  switch (moveType)
  {
    case cnstMoveForward: 
      Forward(power);
      break;
    case cnstMoveBackward: 
      Backward(power);
      break;
    case cnstMoveLeft: 
      MoveLeft(power);
      break;
    case cnstMoveRight: 
      MoveRight(power);
      break;
    case cnstTurnLeft: 
      TurnLeft(power);
      break;
    case cnstTurnRight: 
      TurnRight(power);
      break;
    default:
      Stop();
  }    
};  
