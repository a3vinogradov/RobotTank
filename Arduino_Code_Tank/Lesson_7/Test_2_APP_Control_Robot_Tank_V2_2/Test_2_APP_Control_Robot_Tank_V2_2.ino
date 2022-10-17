#include <Servo.h>

#include <IRremote.h>

volatile int DL;
volatile int DM;
volatile int DR;
volatile int flag;
volatile int left_IR_Sensor;
volatile int right_IR_Sensor;
long ir_rec;

Servo myservo;
char bluetooth_data;

void Infrared_Obstacle_Avoidance() {
  flag = 0;
  while (flag == 0) {
    left_IR_Sensor = digitalRead(A1);
    right_IR_Sensor = digitalRead(A2);
    if (left_IR_Sensor == 0 && right_IR_Sensor == 0) {
      stopp();
      delay(500);
      backward(220,220);
      delay(500);
      if (random(1, 10) > 5) {
        rotate_left(220,220);;

      } else {
        rotate_right(220,220);

      }
      delay(500);

    } else if (left_IR_Sensor == 0 && right_IR_Sensor == 1) {
      backward(220,220);
      delay(500);
      rotate_right(220,220);
      delay(500);
    } else if (left_IR_Sensor == 1 && right_IR_Sensor == 0) {
      backward(220,220);
      delay(500);
      rotate_left(255,255);
      delay(500);
    } else {
     forward(150,150);

    }
    if (Serial.available())
    {
      bluetooth_data = Serial.read();
      if (bluetooth_data == 'S') {
        flag = 1;

      }
    }
  }
}

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

void Ultrasonic_Obstacle_Avoidance() {
  flag = 0;
  while (flag == 0) {
    DM = checkdistance();
    if (DM < 30) {
      stopp();
      delay(1000);
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
      if (DL < 50 || DR < 50) {
        if (DL > DR) {
          myservo.write(90);
          rotate_left(255,255);
          delay(500);
          forward(200,200);

        } else {
          myservo.write(90);
          rotate_right(255,255);
          delay(500);
          forward(200,200);

        }

      } else {
        if (random(1, 10) > 5) {
          myservo.write(90);
          rotate_left(255,255);
          delay(500);
          forward(200,200);

        } else {
          myservo.write(90);
          rotate_right(255,255);
          delay(500);
         forward(200,200);

        }

      }

    } else {
      forward(200,200);

    }
    if (Serial.available())
    {
      bluetooth_data = Serial.read();
      if (bluetooth_data == 'S') {
        flag = 1;

      }
    }
  }
}

IRrecv irrecv(3);
decode_results results;

void Infrared_Remote_Control() {
  flag = 0;
  while (flag == 0) {
    if (irrecv.decode(&results)) {
      ir_rec=results.value;
      irrecv.resume();
      }
      
    
    if (ir_rec == 0xFF629D) {
      forward(240,240);

    }
    if (ir_rec == 0xFFA857) {
      backward(240,240);

    }
    if (ir_rec == 0xFF22DD) {
      rotate_left(240,240);
      delay(50);
      stopp();

    }
    if (ir_rec == 0xFFC23D) {
      rotate_right(240,240);
      delay(50);
      stopp();


    }
    if (ir_rec == 0xFF30CF) {
     rotate_left(240,240);

    }
    if (ir_rec == 0xFF7A85) {
      rotate_right(240,240);

    }
    if (ir_rec == 0xFF02FD) {
     stopp();
    }
    if (Serial.available())
    {
      bluetooth_data = Serial.read();
      if (bluetooth_data == 'S') {
        flag = 1;

      }
    }
   }
 }


void setup(){
  DL = 0;
  DM = 0;
  DR = 0;
  flag = 0;
  left_IR_Sensor = 0;
  right_IR_Sensor = 0;
  myservo.attach(10);
  Serial.begin(9600);
  myservo.write(90);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  irrecv.enableIRIn();
}

void loop(){
  if (Serial.available())
  {
    bluetooth_data = Serial.read();
    Serial.println(bluetooth_data);
  }
  switch (bluetooth_data) {
   case 'F':
    forward(255,255);
    break;
   case 'G':
    backward(255,255);
    break;
   case 'H':
    rotate_left(255,255);
    delay(50);
    stopp();
    bluetooth_data = 'S';
    break;
   case 'I':
    rotate_right(255,255);
    delay(50);
    stopp();
    bluetooth_data = 'S';
    break;
   case 'J':
    rotate_left(255,255);
    break;
   case 'K':
    rotate_right(255,255);
    break;
   case 'S':
    stopp();
    break;
   case 'E':
    Infrared_Obstacle_Avoidance();
    break;
   case 'C':
    Ultrasonic_Obstacle_Avoidance();
    break;
   case 'D':
    Infrared_Remote_Control();
    break;
  }

}










void forward(int a,int b)
{digitalWrite(2,LOW);
 analogWrite(5,a);
 digitalWrite(4,HIGH);
 analogWrite(6,b);
  }

  void backward(int a,int b)
{digitalWrite(2,HIGH);
 analogWrite(5,a);
 digitalWrite(4,LOW);
 analogWrite(6,b);
  }

void turn_left(int a,int b)
{digitalWrite(2,LOW);
 analogWrite(5,a);
 digitalWrite(4,HIGH);
 analogWrite(6,b);
  }

void turn_right(int a,int b)
{digitalWrite(2,LOW);
 analogWrite(5,a);
 digitalWrite(4,HIGH);
 analogWrite(6,b);
  }
void rotate_left(int a,int b)
{digitalWrite(2,HIGH);
 analogWrite(5,a);
 digitalWrite(4,HIGH);
 analogWrite(6,b);
  }


  void rotate_right(int a,int b)
{digitalWrite(2,LOW);
 analogWrite(5,a);
 digitalWrite(4,LOW);
 analogWrite(6,b);
  }



    void stopp()
{digitalWrite(2,HIGH);
 analogWrite(5,0);
 digitalWrite(4,LOW);
 analogWrite(6,0);
  }
