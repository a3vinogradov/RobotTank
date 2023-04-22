#include "CMotorEncoder.h"

int pinIn = A5;
int gPotValue;
int gSetPoint;
int gPIDPoint;

int kP = 0;

unsigned long tmr1;
unsigned long tmrPeriod = 100;

CMotorEncoder gEncoder(4);

void setup() {
  tmr1 = millis();
  Serial.begin(115200);
  gPotValue = 0;
  gSetPoint = 0;
  gPIDPoint = 0;
  gEncoder.Setup();
  Serial.println("goal, real, power, kP");
}

void loop() {
  gEncoder.Exec();
  // опрос потенциометра
  int newPotVal = analogRead(A5);
  if (newPotVal != gPotValue) {
    gPotValue = newPotVal;
    gSetPoint = map(gPotValue, 0, 1023, 0, 18);
    //gSetPoint = map(gPotValue, 0, 1023, 0, 255);

    gPIDPoint = computePID(gEncoder.GetCount(), gSetPoint, kP, 0, 0, 0.1, 15, 255);
  }

  // вывод в плоттер
  if (millis() - tmr1 >= tmrPeriod) {  // ищем разницу
    tmr1 = millis();                   // сброс таймера
    Serial.print("goal:");
    Serial.print(gSetPoint);
    Serial.print(",");
    Serial.print("real:");
    Serial.print(gEncoder.GetCount());
    Serial.print(",");
    Serial.print("pow:");
    Serial.print(gPIDPoint);
    Serial.print(",");
    Serial.print("kP:");
    Serial.print(kP);
    Serial.println();
  }

  // управление мотором
  MotorRun(gPIDPoint);
  //MotorRun(gSetPoint);

  // установка коэффициента через сом
  if (Serial.available()) {
    kP = Serial.parseInt();
  }
}

void MotorRun(int pow) {
  digitalWrite(2, 0);
  analogWrite(3, pow);
}

int computePID(float input, float setpoint, float kp, float ki, float kd, float dt, int minOut, int maxOut) {
  float err = setpoint - input;
  static float integral = 0, prevErr = 0;
  integral = constrain(integral + (float)err * dt * ki, minOut, maxOut);
  float D = (err - prevErr) / dt;
  prevErr = err;
  return constrain(err * kp + integral + D * kd, minOut, maxOut);
}
