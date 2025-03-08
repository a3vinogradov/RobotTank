#ifndef file_CMotorController
#define file_CMotorController

#include <Arduino.h>

class CMotorController
{
  private:
    int _PWSPin; 
    int _directPin;
    //uint8_t _direct;
    bool _IsInverse;
    
  public:
  CMotorController(const int PWSPin, const int dirPin, bool isInverse);
  void Setup();
  void Forward(byte power);
  void Backward(byte power);
  void Run(int power);
  void Stop(); 
  
};

#endif 
