#include "CMoveController.h"

CMoveController::CMoveController(CMotorController* motorFL, CMotorController* motorFR, CMotorController* motorBL, CMotorController* motorBR)
{
    _motorFL = motorFL;
    _motorFR = motorFR;
    _motorBL = motorBL;
    _motorBR = motorBR;

}

void CMoveController::Setup() {
}

void CMoveController::Exec(){
};

void CMoveController::Stop() {
  _motorFL->Stop();
  _motorFR->Stop();
  _motorBL->Stop();
  _motorBR->Stop();
}

void CMoveController::Move(const int chMove, const int chTurn, const int chShift) {
  _motorFL->Run(chMove - chTurn + chShift);
  _motorFR->Run(chMove + chTurn - chShift);
  _motorBL->Run(chMove - chTurn - chShift);
  _motorBR->Run(chMove + chTurn + chShift);
}