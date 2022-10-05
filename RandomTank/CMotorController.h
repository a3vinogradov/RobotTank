#ifndef file_CMotorController
#define file_CMotorController
#include <Arduino.h>

class CMotorController
{
  private:
    int _DirectPin;
    int _PWMPin;
    bool _IsInverse;
    
  public:
  CMotorController(int directPin, int PWMPin, bool isInverse);
  void Setup();
  void Forward(byte power);
  void Backward(byte power);
  void Stop(); 
};

#endif 
