#ifndef file_CBaseSrategy
#define file_CBaseSrategy
#include <Arduino.h>

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

class CBaseStrategy
{
  public:
  virtual MoveSettings GetSettings() = 0;
};

#endif