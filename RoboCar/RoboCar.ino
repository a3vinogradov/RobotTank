#include <string.h>

#include "FlySkyReceiver.h"
#include "CMoveController.h"
#include "CMainController.h"
#include "CMotorEncoder.h"
#include "CTestRoutins.h"


FlySkyReceiver gReceiver(2, 13);
CMoveController gMoveController;
CMainController gMainController(&gMoveController, &gReceiver);

CMotorEncoder gMotorEncoder(A5);

CTestRoutins gTestRoutins;

void setup() {
  Serial.begin(115200);
  gReceiver.Setup();
  gMoveController.Setup();
  gMainController.Setup();

  gMotorEncoder.Setup();
  //Serial.println("setup done!");
  gTestRoutins.Setup();
}

void loop() {
  gReceiver.Exec();
  gMainController.Exec();
  gMoveController.Exec();

  gMotorEncoder.Exec();
  gTestRoutins.Exec();
}