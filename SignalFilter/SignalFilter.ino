#include "CAvgFilter.h"

CAvgFilter filter(3);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available()) {
    String inp = Serial.readString();
    float val = inp.toFloat();

    //Serial.print("Input    value: "); 
    //Serial.println(val);
    //Serial.print("Filtered value: "); 
    //Serial.println(filter.GetValue(val));
    Serial.print(val);
    Serial.print(", "); 
    Serial.println(filter.GetValue(val));
    
     
  }  

}


