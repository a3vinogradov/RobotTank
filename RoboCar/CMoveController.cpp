#include "CMoveController.h"

CMoveController::CMoveController():
  _FLMotor(2,true), _FRMotor(1,true), _BLMotor(3,true), _BRMotor(4,true)
{
}

void CMoveController::Setup()
{
  
}

void CMoveController::Stop()
{
  // _RightMotor->Stop();
  // _LeftMotor->Stop();
}

void CMoveController::Move(const uint_fast16_t chMove, const uint_fast16_t chTurn, const uint_fast16_t chShift)
{
    Serial.print("MoveRequest: {");
    Serial.print(chMove); Serial.print(", ");
    Serial.print(chTurn); Serial.print(", ");
    Serial.print(chShift); Serial.print(", ");
    Serial.println("}");

    // Обработка канала газа  
    int pow = 0;
    if (chMove > 1500)
    {
      pow = map(chMove, 1500, 2000, 0, 255);
      _FLMotor.Forward(pow);   
      _FRMotor.Forward(pow);
      _BLMotor.Forward(pow);
      _BRMotor.Forward(pow);        
    }
    else    
    {
      pow = map(chMove, 1000, 1500, 255, 0);
      _FLMotor.Backward(pow); 
      _FRMotor.Backward(pow);
      _BLMotor.Backward(pow);
      _BRMotor.Backward(pow);            
    }
}

byte CMoveController::FlySkyValueToByte(uint16_t value)
{
    
};  

