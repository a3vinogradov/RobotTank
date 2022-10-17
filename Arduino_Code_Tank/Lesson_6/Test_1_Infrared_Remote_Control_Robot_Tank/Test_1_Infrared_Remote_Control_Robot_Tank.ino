#include <IRremote.h>

long ir_rec;

IRrecv irrecv(3);
decode_results results;

void setup(){
  irrecv.enableIRIn();
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)) {
    ir_rec=results.value;
    irrecv.resume();
  } else {
  }
  if (ir_rec == 0xFF629D) {
    forward();

  }
  if (ir_rec == 0xFFA857) {
    backward();

  }
  if (ir_rec == 0xFF22DD) {
    rotate_left();
    delay(50);
    stopp();

  }
  if (ir_rec == 0xFFC23D) {
    rotate_right();
    delay(50);
    stopp();

  }
  if (ir_rec == 0xFF30CF) {
    rotate_left();

  }
  if (ir_rec == 0xFF7A85) {
   rotate_right();

  }
  if (ir_rec == 0xFF02FD) {
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

void turn_left()
{digitalWrite(2,LOW);
 analogWrite(5,100);
 digitalWrite(4,HIGH);
 analogWrite(6,255);
  }

void turn_right()
{digitalWrite(2,LOW);
 analogWrite(5,255);
 digitalWrite(4,HIGH);
 analogWrite(6,100);
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
