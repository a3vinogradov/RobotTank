#include "FlySkyReceiver.h"
#include "CSN74HC595Controller.h"

// пины для организации SoftSerial
#define FS_RX 13
#define FS_TX 2

// пины дл яуправления сдвиговым регистром
#define PIN_EGPO_DS 5  
#define PIN_EGPO_ST 7
#define PIN_EGPO_SH 8

FlySkyReceiver gReceiver(FS_RX, FS_TX);
CSN74HC595Controller gExtGPO(PIN_EGPO_DS,PIN_EGPO_ST,PIN_EGPO_SH);

void setup()
{
  Serial.begin(115200);
  gReceiver.Setup();
  gExtGPO.Setup();
  gExtGPO.registerWrite(0b00000000); // Установка низкого уровня на всех выходах регистра

  


}

void loop()
{

} 