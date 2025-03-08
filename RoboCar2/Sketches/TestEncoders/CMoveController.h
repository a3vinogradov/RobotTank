#pragma once

#include "CMotorController.h"

class CMoveController
{
  private:
    CMotorController* _motorFL;
    CMotorController* _motorFR;
    CMotorController* _motorBL;
    CMotorController* _motorBR;

  public:
  CMoveController(CMotorController* motorFL, CMotorController* motorFR, CMotorController* motorBL, CMotorController* motorBR);
  void Setup();
  void Exec();
  void Stop();

  void Move(const int chMove, const int chTurn, const int chShift);
};


