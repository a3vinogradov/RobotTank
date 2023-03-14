#ifndef file_CMainController
#define file_CMainController

#include "CMoveController.h"
#include "FlySkyReceiver.h"

class CMainController
{
  private:
    CMoveController* _moveController;
    //MoveSettings _currentMove;
    FlySkyReceiver* _FlySkyReseiver;
    FlySkyData _curFlySkyData;

  public:
  CMainController(CMoveController* moveCtrl, FlySkyReceiver* flySkyReceiver);
  void Setup();
  void Exec();
};

#endif