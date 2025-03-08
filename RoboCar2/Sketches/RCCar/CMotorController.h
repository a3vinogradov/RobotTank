#ifndef file_CMotorController
#define file_CMotorController
#include <Arduino.h>
#include "CGPO.h"

class CMotorController
{
  private:
    bool _IsInverse;
    CGPO* _pinConst;
    CGPO_PWM* _pinPWM;
   
  public:
  CMotorController( CGPO* pin1, CGPO_PWM* pin2, bool isInverse = false);
  void Setup();
  void Forward(byte power);
  void Backward(byte power);
  void Run(int power);
  void Stop(); 
};

#endif 
