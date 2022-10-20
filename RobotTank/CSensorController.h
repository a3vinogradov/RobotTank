#ifndef file_CSensorController
#define file_CSensorController
#include <Arduino.h>
#include "Common.h"

class CSensorController
{
  private:
    int _IRLeftPin;
    int _IRRightPin;
    int _USEchoPin;
    int _USTrigPin;

  public:
  CSensorController(int irLeftPin, int irRightPin, int USEchoPin, int USTrigPin);
  void Setup();   
  void Exec();
  bool GetIRLeft();
  bool GetIRRight();
};

#endif