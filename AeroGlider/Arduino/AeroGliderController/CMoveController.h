#ifndef file_CMoveController
#define file_CMoveController

#include "CMotorController.h"
#include <Arduino.h>
class CMoveController
{
  private:
    CMotorController* _LMotor;
    CMotorController* _RMotor;

  public:  
  CMoveController(CMotorController* lm, CMotorController* rm);
  void Setup();
  void Exec();
  void Stop();

  void Move(const uint_fast16_t chMove, const uint_fast16_t chTurn);
};

#endif 
