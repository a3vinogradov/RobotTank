#include "CIRStrategy.h"

CIRStrategy::CIRStrategy(CSensorController* sensorController)
  : _Timer()
{
  _sensorController = sensorController;
}

void CIRStrategy::Setup()
{
  SetForward();  
}

void PrintSettings(String header, MoveSettings value)
{
  Serial.println();
  Serial.println(header);
  Serial.print("Power = "); Serial.println(value.Power);
  Serial.print("Mode = "); Serial.println(value.Mode);
}

MoveSettings CIRStrategy::GetSettings()
{
  Exec();
  return _CurrSettings; 
}

void CIRStrategy::Exec()
{
  switch (_CurrentState)
  {
    case ssForward:
      ExecForward();
      break;
    case ssCheckIR:
      ExecCheckIR();
      break;
    case ssMoveLeft:
      ExecMoveLeft();
      break;
    case ssMoveRight:
      ExecMoveRight();
      break;
    case ssStop1:
      ExecStop1();
      break;      
    case ssSelectDirect:
      ExecSelectDirect();
      break;      
    case ssMoveLeftBack:
      ExecMoveLeftBack();
      break;      
    case ssMoveRightBack:
      ExecMoveRightBack();
      break;      
    case ssStop2:
      ExecStop2();
      break;      
    default:
      ExecStop1();
      break;
  }   
}

void CIRStrategy::SetForward()
{
  _CurrSettings = GetDefaultMoveSettings();
  _CurrentState = StrategyState::ssForward;
  _Timer.SetDelay(200);
  _Timer.ReStart();    
}

void CIRStrategy::ExecForward()
{
  if (!_Timer.IsActive())
  {
    SetCheckIR();
  }
}

void CIRStrategy::SetCheckIR()
{
  _CurrentState = StrategyState::ssCheckIR;
}

void CIRStrategy::ExecCheckIR()
{
  bool isIRL = _sensorController->GetIRLeft();
  bool isIRR = _sensorController->GetIRRight();
  
  if (!isIRL && !isIRR)
  {    
    SetStop1();
  }
  else if (!isIRL)
  {
    SetMoveRight();
  }
  else if (!isIRR)
  {
    SetMoveLeft();
  }
  else
  {
    SetForward();
  }
}
  
void CIRStrategy::SetStop1()
{
  _CurrentState = StrategyState::ssStop1;
  _CurrSettings.Power = 0;
  _CurrSettings.Mode = cnstMoveStop;

  _Timer.SetDelay(500);
  _Timer.ReStart(); 
}

void CIRStrategy::ExecStop1()
{
  if (!_Timer.IsActive())
  {
    SetSelectDirect();
  }  
}

void CIRStrategy::SetMoveLeft()
{
  _CurrentState = StrategyState::ssMoveLeft;
  _Timer.SetDelay(300);
  _Timer.ReStart(); 

  _CurrSettings.Power = 180;
  _CurrSettings.Mode = cnstMoveLeft;  
}

void CIRStrategy::ExecMoveLeft()
{
  if (!_Timer.IsActive())
  {
    SetCheckIR();
  }
}

void CIRStrategy::SetMoveRight()
{
  _CurrentState = StrategyState::ssMoveRight;
  _Timer.SetDelay(300);
  _Timer.ReStart(); 

  _CurrSettings.Power = 180;
  _CurrSettings.Mode = cnstMoveRight;  
}

void CIRStrategy::ExecMoveRight()
{
  if (!_Timer.IsActive())
  {
    SetCheckIR();
  }
}

void CIRStrategy::SetSelectDirect()
{
  _CurrentState = StrategyState::ssSelectDirect;
} 

void CIRStrategy::ExecSelectDirect()
{
  if (random(1,10) < 6)
  { 
    SetMoveLeftBack();
  } 
  else
  {
    SetMoveRightBack();
  } 
} 

void CIRStrategy::SetMoveLeftBack()
{
  _CurrentState = StrategyState::ssMoveLeftBack;
  _Timer.SetDelay(1000);
  _Timer.ReStart(); 

  _CurrSettings.Power = 180;
  _CurrSettings.Mode = cnstMoveBackLeft;  
} 

void CIRStrategy::ExecMoveLeftBack()
{
  if (!_Timer.IsActive())
  {
    SetStop2();
  }
} 

void CIRStrategy::SetMoveRightBack()
{
  _CurrentState = StrategyState::ssMoveRightBack;
  _Timer.SetDelay(1000);
  _Timer.ReStart(); 

  _CurrSettings.Power = 180;
  _CurrSettings.Mode = cnstMoveBackRight;  
} 

void CIRStrategy::ExecMoveRightBack()
{
  if (!_Timer.IsActive())
  {
    SetStop2();
  }
} 

void CIRStrategy::SetStop2()
{
  _CurrentState = StrategyState::ssStop2;
  _CurrSettings.Power = 0;
  _CurrSettings.Mode = cnstMoveStop;

  _Timer.SetDelay(300);
  _Timer.ReStart(); 
} 

void CIRStrategy::ExecStop2()
{
  if (!_Timer.IsActive())
  {
    SetCheckIR();
  }
} 

MoveSettings CIRStrategy::GetDefaultMoveSettings()
{
  MoveSettings newSettings;
  newSettings.Power = 180;
  newSettings.Mode = cnstMoveForward;
  return newSettings;
}
