#pragma once

#include <Arduino.h>

class CGPO
{
  public:
  virtual void On() = 0;
  virtual void Off() = 0;
};

class CGPO_PWM: CGPO
{
  public:
  virtual void On() = 0;
  virtual void Off() = 0;  
  virtual void PWM(uint8_t value) = 0;  
};

class CArduinoGPO : public CGPO_PWM
{
  private: 
  int _pinNum;

  public:
  CArduinoGPO(const int pinNum);
  virtual void On();
  virtual void Off();  
  virtual void PWM(uint8_t value);  
}; 
