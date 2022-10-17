#include <Servo.h>

volatile int DL;
volatile int DM;
volatile int DR;

float checkdistance() {
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(13, HIGH) / 58.00;
  delay(10);
  return distance;
}

Servo myservo;
void Detect_obstacle_distance() {
  myservo.write(160);
  for (int i = 1; i <= 3; i = i + (1)) {
    DL = checkdistance();
    delay(100);
  }
  myservo.write(20);
  for (int i = 1; i <= 3; i = i + (1)) {
    DR = checkdistance();
    delay(100);
  }
}

void setup(){
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  myservo.attach(10);
  DL = 0;
  DM = 0;
  DR = 0;
  myservo.write(90);
}

void loop(){
  DM = checkdistance();
  if (DM < 30) {
    stopp();
    delay(1000);
    Detect_obstacle_distance();
    if (DL < 50 || DR < 50) {
      if (DL > DR) {
        myservo.write(90);
        rotate_left();
        delay(500);
        forward();


      } else {
        myservo.write(90);
        rotate_right();
        delay(500);
        forward();

      }

    } else {
      if (random(1, 10) > 5) {
        myservo.write(90);
        rotate_left();
        delay(500);
        forward();

      } else {
        myservo.write(90);
        rotate_right();
        delay(500);
        forward();

      }

    }

  } else {
    forward();

  }

}




void forward()
{digitalWrite(2,LOW);
 analogWrite(5,200);
 digitalWrite(4,HIGH);
 analogWrite(6,200);
  }

  void backward()
{digitalWrite(2,HIGH);
 analogWrite(5,255);
 digitalWrite(4,LOW);
 analogWrite(6,255);
  }

void rotate_left()
{digitalWrite(2,HIGH);
 analogWrite(5,255);
 digitalWrite(4,HIGH);
 analogWrite(6,255);
  }


  void rotate_right()
{digitalWrite(2,LOW);
 analogWrite(5,255);
 digitalWrite(4,LOW);
 analogWrite(6,255);
  }



    void stopp()
{digitalWrite(2,HIGH);
 analogWrite(5,0);
 digitalWrite(4,LOW);
 analogWrite(6,0);
  }
