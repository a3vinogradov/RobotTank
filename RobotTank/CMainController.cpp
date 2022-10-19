#include "CMainController.h"

CMainController::CMainController(CMoveController* moveCtrl, CMoveStrategy* moveStrtegy)
{
  _moveController = moveCtrl;
  _moveStrategy = moveStrtegy;
} 

void CMainController::Exec()
{
  MoveSettings newSettings = _moveStrategy->GetSettings();

  if (_currentMove != newSettings)
  {
    _currentMove = newSettings;
    _moveController->Move(_currentMove.Mode, _currentMove.Power);
  }  
}

void CMainController::Setup()
{
  _currentMove = _moveStrategy->GetSettings();  
}  
