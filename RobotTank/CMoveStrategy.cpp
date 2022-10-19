#include "CMoveStrategy.h"

CMoveStrategy::CMoveStrategy()
  : _Timer()
{
  
}

void CMoveStrategy::Setup()
{
  _CurrSettings.Power = 180; 
  _CurrSettings.Mode = cnstMoveBackward;
  _CurrSettings.Delay = 2000; 

  _Timer.SetDelay(2000);
  _Timer.Start(); 
}

MoveSettings CMoveStrategy::GetSettings()
{
  if (!_Timer.IsActive())
  {
    _CurrSettings = GenerateSettings();
    _Timer.SetDelay(random(1000, 3000)); 
    _Timer.ReStart();
  }

  return _CurrSettings;
}

MoveSettings CMoveStrategy::GenerateSettings()
{
   MoveSettings newSettings;
   //newSettings.Power = _CurrSettings.Power + 64;
   //newSettings.Mode = (_CurrSettings.Mode+2)%5;
   newSettings.Power = random(100, 255);
   newSettings.Mode = random(0,6);
   return newSettings;
}
