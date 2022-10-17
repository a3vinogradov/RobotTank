#include <Servo.h>

Servo myservo;

void setup(){
  myservo.attach(10);
}

void loop(){
  for (int POS = 0; POS <= 180; POS = POS + (1)) {
    myservo.write(POS);
    delay(15);
  }
  for (int POS = 180; POS >= 0; POS = POS -1) {
    myservo.write(POS);
    delay(15);
  }

}
