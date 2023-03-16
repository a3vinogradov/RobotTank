#include <string.h>

#include "FlySkyReceiver.h"
#include "CMoveController.h"
#include "CMainController.h"


FlySkyReceiver gReceiver(2, 13);
CMoveController gMoveController;
CMainController gMainController(&gMoveController, &gReceiver);
void setup() 
{
  Serial.begin(115200); 
  gReceiver.Setup();  
  gMoveController.Setup();
  gMainController.Setup();

  Serial.println("setup done!");
}

void loop() 
{
  gReceiver.Exec();
  gMainController.Exec();
  gMainController.Exec();
}