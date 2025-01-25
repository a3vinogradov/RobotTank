#include "FlySkyReceiver.h"
FlySkyReceiver gReceiver(13, 2);
FlySkyData data;
FlySkyData newData;
void setup()
{
  Serial.begin(115200);
  gReceiver.Setup();
  data = gReceiver.GetDefaultData();
}

void loop()
{
  gReceiver.Exec();
  if (!gReceiver.IsEqual(data))
  {
    data = gReceiver.GetCurData();
    Serial.print("ch01 = "); Serial.print(data.ch[0]); Serial.print(";") ;
    Serial.print("ch02 = "); Serial.print(data.ch[1]); Serial.print(";") ;
    Serial.print("ch03 = "); Serial.print(data.ch[2]); Serial.print(";") ;
    Serial.print("ch04 = "); Serial.print(data.ch[3]); Serial.print(";") ;
    Serial.print("ch05 = "); Serial.print(data.ch[4]); Serial.print(";") ;
    Serial.print("ch06 = "); Serial.print(data.ch[5]); Serial.print(";") ;
    Serial.print("ch07 = "); Serial.print(data.ch[6]); Serial.print(";") ;
    Serial.print("ch08 = "); Serial.print(data.ch[7]); Serial.print(";") ;
    Serial.print("ch09 = "); Serial.print(data.ch[8]); Serial.print(";") ;
    Serial.print("ch10 = "); Serial.print(data.ch[9]); Serial.print(";") ;
    Serial.print("ch11 = "); Serial.print(data.ch[10]); Serial.print(";") ;
    Serial.print("ch12 = "); Serial.print(data.ch[11]); Serial.print(";") ;
    Serial.print("ch13 = "); Serial.print(data.ch[12]); Serial.print(";") ;
    Serial.print("ch14 = "); Serial.print(data.ch[13]); Serial.println(";") ;
  }


}