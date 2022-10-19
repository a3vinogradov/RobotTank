#ifndef file_CMainController
#define file_CMainController

#include "CMoveController.h"
#include "CMoveStrategy.h"

class CMainController
{
  private:
    CMoveController* _moveController;
    CMoveStrategy* _moveStrategy;
    MoveSettings _currentMove;

  public:
  CMainController(CMoveController* moveCtrl, CMoveStrategy* moveStrtegy);
  void Setup();
  void Exec();
};

#endif