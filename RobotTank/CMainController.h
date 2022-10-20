#ifndef file_CMainController
#define file_CMainController

#include "CMoveController.h"
#include "CBaseStrategy.h"

class CMainController
{
  private:
    CMoveController* _moveController;
    CBaseStrategy* _moveStrategy;
    MoveSettings _currentMove;

  public:
  CMainController(CMoveController* moveCtrl, CBaseStrategy* moveStrategy);
  void Setup();
  void Exec();
};

#endif