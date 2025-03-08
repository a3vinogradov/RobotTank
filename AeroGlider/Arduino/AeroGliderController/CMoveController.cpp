#include "CMoveController.h"

CMoveController::CMoveController(CMotorController* lm, CMotorController* rm)
{
  _LMotor = lm;
  _RMotor = rm;
}

void CMoveController::Setup() {
  _LMotor->Setup();
  _RMotor->Setup();
}

void CMoveController::Exec(){
};

void CMoveController::Stop() {
  _LMotor->Stop();
  _RMotor->Stop();
}

 void CMoveController::Move(const uint_fast16_t chMove, const uint_fast16_t chTurn) {
  // Обработка канала газа
  int movePow = map(chMove, 1000, 2000, -255, 255);
  // Обработка канала поворота
  int turnPow = map(chTurn, 1000, 2000, 255, -255);

  _LMotor->Run( movePow + turnPow);
  _RMotor->Run( movePow - turnPow);
  Serial.print(chMove); Serial.print("; ");
  Serial.print(chTurn), Serial.print("; ");
  Serial.print(movePow + turnPow), Serial.print("; ");
  Serial.print(movePow - turnPow), Serial.println("; ");
}
