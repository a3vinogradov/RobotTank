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
  
    // управление камерой
    static int lastCamPosition;
    if ((lastCamPosition+50 < _curFlySkyData.ch[5]) || (lastCamPosition-50 > _curFlySkyData.ch[5]))
    {
      Serial.print(lastCamPosition); Serial.print(", "); Serial.println(_curFlySkyData.ch[5]);
      lastCamPosition = _curFlySkyData.ch[5];
      _camServo.write(map(lastCamPosition, 1000, 2000, 180, 0));
      _camServo2.write(map(lastCamPosition, 1000, 2000, 180, 0));
    }
  }
}

void CMainController::Setup()
{
  _camServo.attach(9);
  _camServo2.attach(10);
  _curFlySkyData = _FlySkyReseiver->GetDefaultData();  
  //_curFlySkyData.ch[1] = 1700;
  //_moveController->Move(1700, _curFlySkyData.ch[0], _curFlySkyData.ch[3]);
}  
