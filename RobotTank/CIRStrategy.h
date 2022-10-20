#ifndef file_CIRSrategy
#define file_CIRSrategy

#include <Arduino.h>
#include "CTimer.h"
#include "Common.h"
#include "CBaseStrategy.h"
#include "CSensorController.h"

enum StrategyState{ssForward, ssCheckIR, ssStop1, ssMoveRight, ssMoveLeft, ssSelectDirect, ssMoveLeftBack, ssMoveRightBack, ssStop2};

class CIRStrategy : public CBaseStrategy
{
  private:
  CSensorController* _sensorController;
  StrategyState _CurrentState = StrategyState::ssForward;
  MoveSettings _CurrSettings;
  CTimer _Timer;

  MoveSettings GetDefaultMoveSettings();
  void SetForward() ;
  void ExecForward();
  void SetCheckIR();  
  void ExecCheckIR();  
  void SetStop1();
  void ExecStop1();
  void SetMoveLeft();
  void ExecMoveLeft();
  void SetMoveRight();
  void ExecMoveRight();
  void SetSelectDirect(); 
  void ExecSelectDirect(); 
  void SetMoveLeftBack(); 
  void ExecMoveLeftBack(); 
  void SetMoveRightBack(); 
  void ExecMoveRightBack(); 
  void SetStop2();  
  void ExecStop2();

  public:
  CIRStrategy(CSensorController* sensorController);
  void Setup();
  virtual MoveSettings GetSettings();
  void Exec();   
};

#endif 