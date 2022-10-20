#include "CRandomStrategy.h"

CRandomStrategy::CRandomStrategy()
  : _Timer()
{
  
}

void CRandomStrategy::Setup()
{
  _CurrSettings.Power = 180; 
  _CurrSettings.Mode = cnstMoveForward;
  _CurrSettings.Delay = 2000; 

  _Timer.SetDelay(2000);
  _Timer.Start(); 
}

MoveSettings CRandomStrategy::GetSettings()
{
  if (!_Timer.IsActive())
  {
    _CurrSettings = GenerateSettings();
    _Timer.SetDelay(random(1000, 3000)); 
    _Timer.ReStart();
  }

  return _CurrSettings;
}

MoveSettings CRandomStrategy::GenerateSettings()
{
   MoveSettings newSettings;
   newSettings.Power = random(100, 255);
   newSettings.Mode = random(0,cnstMoveTypeCount-1);
   return newSettings;
}
