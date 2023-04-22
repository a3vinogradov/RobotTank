#include "CMainController.h"

CMainController::CMainController(CMoveController* moveCtrl, FlySkyReceiver* flySkyReceiver)
{
  _moveController = moveCtrl;
  _FlySkyReseiver = flySkyReceiver;
} 

void CMainController::Exec()
{
  if (!_FlySkyReseiver->IsEqual(_curFlySkyData))
  {
    _curFlySkyData = _FlySkyReseiver->GetCurData();
    //Serial.println("New data expected!");  
    _moveController->Move(_curFlySkyData.ch[1], _curFlySkyData.ch[0], _curFlySkyData.ch[3]);
  }
}

void CMainController::Setup()
{
  _curFlySkyData = _FlySkyReseiver->GetDefaultData();  
  //_curFlySkyData.ch[1] = 1700;
  //_moveController->Move(1700, _curFlySkyData.ch[0], _curFlySkyData.ch[3]);
}  
