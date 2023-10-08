#include "CMotorEncoder.h"
#include "CMotor.h"

int pinIn = A5;
int gPotValue;
int gSetPoint;
int gPIDPoint;
int gInputPoint;

float kP = 0;
float kI = 0;
float kD = 0;

unsigned long tmr1;
unsigned long tmrPeriod = 100;

CMotorEncoder gEncoder(4);
//CAvgFilter gFilter(3);

void setup() {
  tmr1 = millis();
  Serial.begin(115200);
  gPotValue = 0;
  gSetPoint = 0;
  gPIDPoint = 0;
  gInputPoint = 0;
  gEncoder.Setup();
  Serial.println("goal, real, power, kP, kI, kD");
}

void loop() {
  gEncoder.Exec();
  // опрос потенциометра
  // int newPotVal = analogRead(A5);
  // if (newPotVal != gPotValue) {
  //   gPotValue = newPotVal;
  //   //gSetPoint = map(gPotValue, 0, 1023, 0, 18);
  //   //gSetPoint = map(gPotValue, 0, 1023, 0, 255);
  //   //gPIDPoint = computePID(gEncoder.GetCount(), gSetPoint, kP, kI, kD, 0.1, 0, 255);
  // }


  if (millis() - tmr1 >= tmrPeriod) {  // ищем разницу
    tmr1 = millis();                   // сброс таймера
    gInputPoint = gEncoder.GetCount();
    //gSetPoint = map(gPotValue, 0, 1023, 0, 18);
    //gPIDPoint = gSetPoint;
    gPIDPoint = computePID(gInputPoint, gSetPoint, kP, kI, kD, 0.1, 0, 255);
    // управление мотором
    MotorRun(gPIDPoint);
    //MotorRun(gSetPoint);
  
    // вывод в плоттер
    Serial.print("goal:");
    Serial.print(gSetPoint);
    Serial.print(",");
    Serial.print("real:");
    Serial.print(gInputPoint);
    Serial.print(",");
    Serial.print("pow:");
    Serial.print(gPIDPoint);
    Serial.print(",");
    Serial.print("kP:");
    Serial.print(kP);
    Serial.print(",");
    Serial.print("kI:");
    Serial.print(kI);
    Serial.print(",");
    Serial.print("kD:");
    Serial.print(kD);
    Serial.println();
  }

  // управление мотором
  //MotorRun(gPIDPoint);
  //MotorRun(gSetPoint);

  // установка коэффициента через сом
  if (Serial.available()) {
    String inp = Serial.readString();
    if (inp[0]=='p')
    {
      kP = inp.substring(1).toFloat();
    } 
    else
    if (inp[0]=='i')
    {
      kI = inp.substring(1).toFloat();
    } 
    else
    if (inp[0]=='d')
    {
      kD = inp.substring(1).toFloat();
    } 
    else
    if (inp[0]=='g')
    {
      gSetPoint = inp.substring(1).toInt();
    } else
    if (inp[0]=='a')
    {
      
      switch(gInputPoint)
      {
        case 0:
          if (gSetPoint == 0){kP = kI = kD = 0;};
          break; 
        case 1:  
        case 2:  
        case 3:  
        case 4:  
        case 5:  
          kP = 0;
          kI = 10;
          kD = 0; 
          break;
        default:
          kP = 0;
          kI = 35;
          kD = 0; 
      }
    }     
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
  // принудительное обнуление интегральной ошибки когда скорость = 0
  // if (input == 0 and setpoint == 0 and prevErr == err)
  // {
  //   integral = 0;
  // }

  // принудительное увеличение ошибки для старта мотора троганья
  // if (setpoint > 0 and input == 0) 
  // {
  //   integral += 40;
  // } 

  prevErr = err;

  return constrain(err * kp + integral + D * kd, minOut, maxOut);
}
