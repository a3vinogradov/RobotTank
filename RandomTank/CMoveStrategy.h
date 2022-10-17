#ifndef file_CMoveStrategy
#define file_CMoveStrategy

#include <Arduino.h>
#include "CTimer.h"
#include "Common.h"

struct MoveSettings
{
  byte Power; 
  int Mode;
  int Delay;
  bool operator==(const MoveSettings& other) const 
  {
    return Power == other.Power && Mode == other.Mode && Delay == other.Delay;
  }
  bool operator!=(const MoveSettings& other) const 
  {
    return !(*this == other);
  }
};

class CMoveStrategy
{
  private:
  CTimer _Timer;
  MoveSettings _CurrSettings;

  
  public:
  CMoveStrategy();
  void Setup();
  MoveSettings GetSettings();
  MoveSettings GenerateSettings();
};

#endif 
