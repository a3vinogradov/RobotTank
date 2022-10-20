#ifndef file_CRandomSrategy
#define file_CRandomSrategy

#include <Arduino.h>
#include "CTimer.h"
#include "Common.h"
#include "CBaseStrategy.h"

class CRandomStrategy : public CBaseStrategy
{
  private:
  CTimer _Timer;
  MoveSettings _CurrSettings;

  
  public:
  CRandomStrategy();
  void Setup();
  MoveSettings GetSettings();
  MoveSettings GenerateSettings();
};

#endif 
