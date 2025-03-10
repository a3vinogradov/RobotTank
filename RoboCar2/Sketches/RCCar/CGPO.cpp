#include "Arduino.h"
#include "CGPO.h"

//================== CArduinoGPO =====================
CArduinoGPO::CArduinoGPO(const int pinNum)
{
  _pinNum = pinNum;
  pinMode(_pinNum, OUTPUT);
}

void CArduinoGPO::On()
{
  digitalWrite(_pinNum, HIGH);
}

void CArduinoGPO::Off() 
{
  digitalWrite(_pinNum, LOW);
}

void CArduinoGPO::PWM(uint8_t value)
{
  if (value < 1)
  {
    Off();
  } 
  else if (value > 254)
  {
    On();
  }
  else
  {
    analogWrite(_pinNum, value);
  }
}