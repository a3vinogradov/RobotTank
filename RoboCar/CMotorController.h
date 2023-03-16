#ifndef file_CMotorController
#define file_CMotorController
#include <Arduino.h>
#include <AFMotor.h> 

class CMotorController
{
  private:
    int _motorNumber;
    AF_DCMotor _afMotor; 
    uint8_t _direct;
    bool _IsInverse;
    
  public:
  CMotorController(int motorNumber, bool isInverse);
  void Setup();
  void Forward(byte power);
  void Backward(byte power);
  void Run(int power);
  void Stop(); 
};

#endif 
