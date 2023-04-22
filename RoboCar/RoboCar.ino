#include <string.h>

#include "FlySkyReceiver.h"
#include "CMoveController.h"
#include "CMainController.h"
#include "CMotorEncoder.h"


FlySkyReceiver gReceiver(2, 13);
CMoveController gMoveController;
CMainController gMainController(&gMoveController, &gReceiver);

CMotorEncoder gMotorEncoder(A5);

void setup() {
  Serial.begin(115200);
  gReceiver.Setup();
  gMoveController.Setup();
  gMainController.Setup();

  gMotorEncoder.Setup();
  //Serial.println("setup done!");
}

void loop() {
  gReceiver.Exec();
  gMainController.Exec();
  gMoveController.Exec();

  gMotorEncoder.Exec();
}