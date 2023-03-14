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

/*
void readRx()
{
  rxFrameDone = false;
  
  if (mySerial.available())
  {
    uint8_t val = mySerial.read();
    // Look for 0x2040 as start of packet
    if (ibusIndex == 0 && val != 0x20)
    {
      ibusIndex = 0;
      return;
    }
    if (ibusIndex == 1 && val != 0x40) 
    {
      ibusIndex = 0;
      return;
    }

    if (ibusIndex == IBUS_BUFFSIZE)
    {
      ibusIndex = 0;
      int high=3;
      int low=2;
      for(int i=0;i<IBUS_MAXCHANNELS; i++)
      {
        //left shift away the first 8 bits of the first byte and add the whole value of the previous one
        rcValue[i] = (ibus[high] << 8) + ibus[low];
        high += 2;
        low += 2;
      }
      ch1 = map(rcValue[2], 1000, 2000, 0, 255);
      Serial.print("ch3:");
      Serial.print(ch1);
      Serial.print("     ");
      ch2 = map(rcValue[3], 2000, 1000, 0, 255);
      Serial.print("ch4:");
      Serial.print(ch2);
      Serial.print("     ");
      ch3 = map(rcValue[1], 2000, 1000, 0, 255);
      Serial.print("ch2:");
      Serial.print(ch3);
      Serial.print("     ");
      ch4 = map(rcValue[7], 2000, 1000, 0, 255);
      Serial.print("ch1:");
      Serial.print(ch4);
      Serial.print("     ");
      Serial.println();
      
      rxFrameDone = true;


      uint_fast16_t chs1 = GetCheckSum();
      uint_fast16_t chs2 = CalcCheckSum();
      if(chs1-chs2)
      {
        //Serial.print("!!! checksum faild ");
      }     
      else
      { 
        Serial.print("checksum : ");
        Serial.print(chs1-chs2); Serial.print(" == ");
        Serial.print(chs1); Serial.print(" - "); Serial.print(chs2);
 
        Serial.print("rcValues: {");
        for (int i = 0; i < IBUS_MAXCHANNELS; i++)
        {
          Serial.print(rcValue[i]); 
          Serial.print("; ");
        }
        Serial.print("}");
      }
      Serial.println(); 
      
      return;
    }
    else
    {
      ibus[ibusIndex] = val;
      ibusIndex++;
    }
  }
}
*/