#include<Servo.h>

Servo myservo;
volatile int distance;


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




void setup(){
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  myservo.attach(10);
  distance = 0;
  myservo.write(90);
}

void loop(){
  distance = checkdistance();
   if (distance >= 20 && distance <= 60)
   {
    forward();
  } else if (distance > 10 && distance < 20) {
    stopp();
  } else if (distance <= 10) {
   backward();
  } else {
    stopp();
  }
}




void forward()
{digitalWrite(2,LOW);
 analogWrite(5,255);
 digitalWrite(4,HIGH);
 analogWrite(6,255);
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
