#include "FlySkyReceiver.h"

#define D0 4
#define D1 3
#define D2 5
#define D3 11

FlySkyReceiver gFSReseiver(2, 13);
FlySkyData gCurFSData;

void setup() {
// Пины D3 и D11 - 62.5 кГц
//TCCR2B = 0b00000001;  // x1
//TCCR2A = 0b00000011;  // fast pwm
// Пины D3 и D11 - 31.4 кГц
TCCR2B = 0b00000001;  // x1
TCCR2A = 0b00000001;  // phase correct
// Пины D3 и D11 - 8 кГц
//TCCR2B = 0b00000010;  // x8
//TCCR2A = 0b00000011;  // fast pwm
// Пины D3 и D11 - 4 кГц
//TCCR2B = 0b00000010;  // x8
//TCCR2A = 0b00000001;  // phase correct
// Пины D3 и D11 - 2 кГц
//TCCR2B = 0b00000011;  // x32
//TCCR2A = 0b00000011;  // fast pwm


  gFSReseiver.Setup();
  gCurFSData = gFSReseiver.GetDefaultData();

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600);
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
}

void loop() {
  gFSReseiver.Exec();

  if (!gFSReseiver.IsEqual(gCurFSData)) {
    gCurFSData = gFSReseiver.GetCurData();
    Serial.println("New data expected!");
    Serial.print(gCurFSData.ch[0]); Serial.print(", ");
    Serial.print(gCurFSData.ch[1]); Serial.print(", ");
    Serial.print(gCurFSData.ch[2]); Serial.print(", ");
    Serial.print(gCurFSData.ch[3]); Serial.print("; ");
    int pow = map(gCurFSData.ch[2], 1000, 2000, 0, 255);
    Serial.print(pow); Serial.println("; ");
    

    //_moveController->Move(_curFlySkyData.ch[1], _curFlySkyData.ch[0], _curFlySkyData.ch[3]);
    
    digitalWrite(D0, 0);
    analogWrite(D1, pow);
    digitalWrite(D2, 0);
    analogWrite(D3, pow);
  }



}