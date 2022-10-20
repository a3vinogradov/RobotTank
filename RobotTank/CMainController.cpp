#include "CMainController.h"

CMainController::CMainController(CMoveController* moveCtrl, CBaseStrategy* moveStrtegy)
{
  _moveController = moveCtrl;
  _moveStrategy = moveStrtegy;
} 

void CMainController::Exec()
{
  LogMsg("Main Exec ...");  
  MoveSettings newSettings = _moveStrategy->GetSettings();

  if (_currentMove != newSettings)
  {
    LogMsg("NewSettingd + Move");    
    _currentMove = newSettings;
    _moveController->Move(_currentMove.Mode, _currentMove.Power);
  }  
  LogMsg("Main Exec end");  

}

void CMainController::Setup()
{
  _currentMove.Mode = cnstMoveStop;
  _currentMove.Delay = 10000;
  _currentMove.Power = 0;    
  _moveController->Move(_currentMove.Mode, _currentMove.Power);
}  
