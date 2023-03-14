#ifndef file_CMoveController
#define file_CMoveController

#include <Arduino.h>
#include "CMotorController.h"

class CMoveController
{
  private:
    CMotorController _FLMotor;
    CMotorController _FRMotor;
    CMotorController _BLMotor;
    CMotorController _BRMotor;

    byte FlySkyValueToByte(uint16_t value);  

  public:  
  CMoveController();
  void Setup();
  void Exec();
  void Stop();

  void Move(const uint_fast16_t chMove, const uint_fast16_t chTurn, const uint_fast16_t chShift);
};


#endif 
