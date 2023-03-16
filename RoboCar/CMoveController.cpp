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
   _FLMotor.Stop();
   _FRMotor.Stop();
   _BLMotor.Stop();
   _BRMotor.Stop();
}

void CMoveController::Move(const uint_fast16_t chMove, const uint_fast16_t chTurn, const uint_fast16_t chShift)
{
  // Serial.print("MoveRequest: {");
  // Serial.print(chMove); Serial.print(", ");
  // Serial.print(chTurn); Serial.print(", ");
  // Serial.print(chShift); Serial.print(", ");
  // Serial.println("}");

  // Обработка канала газа  
  int movePow = map(chMove, 1000, 2000, -255, 255);
  // Обработка канала поворота  
  int turnPow = map(chTurn, 1000, 2000, -255, 255);
  // Обработка канала слайда  
  int shiftPow = map(chShift, 1000, 2000, -255, 255);

  // программная блокировка каналов   
  //movePow = 0;    
  //turnPow = 0;    
  //shiftPow = 0;    

  _FLMotor.Run(movePow-turnPow+shiftPow);   
  _FRMotor.Run(movePow+turnPow-shiftPow);
  _BLMotor.Run(movePow-turnPow-shiftPow);
  _BRMotor.Run(movePow+turnPow+shiftPow);        
}
 

