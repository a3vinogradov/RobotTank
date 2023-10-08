#include "CMotorEncoder.h"
#include <Arduino.h>

CMotorEncoder::CMotorEncoder(int signalPin) {
  _signalPin = signalPin;
}

void CMotorEncoder::Setup() {
  _tmr = millis();
  _tmrSet = 100;
  _count = 0;
  _state = digitalRead(_signalPin);
}

void CMotorEncoder::Exec() {
  if (millis() - _tmr >= _tmrSet) {
    _tmr = millis();  // "сбросить"
    //Serial.print("Encoder tic/500ms = ");
    //Serial.println(_count);
    _count = 0;
  }

  if (_state != digitalRead(_signalPin)) {
    _state = _state == HIGH ? LOW : HIGH;
    _count++;
  }
};
