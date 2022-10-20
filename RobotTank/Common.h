#ifndef file_Common
#define file_Common
#include <Arduino.h>

// Пины моторов
#define MotorDirectionPinA 2 
#define MotorDirectionPinB 4
#define MotorPWMA 5
#define MotorPWMB 6

// Пины сенсоров
#define cnstIRLeftPin A1
#define cnstIRRightPin A2
#define cnstUSTrigPin 12
#define cnstUSEchoPin 13

// константы для типов движения
#define cnstMoveTypeCount 9 
#define cnstMoveStop 0
#define cnstMoveForward 1
#define cnstMoveBackward 2
#define cnstTurnLeft 3
#define cnstTurnRight 4
#define cnstMoveLeft 5
#define cnstMoveRight 6
#define cnstMoveBackLeft 7
#define cnstMoveBackRight 8

// константы для типов поведения
#define cnstRandomStrategy 0
#define cnstIRStrategy 0

#define LogMsg(msg) 
//Serial.println(msg)

void LogMessage(String msg);

#endif 
 
