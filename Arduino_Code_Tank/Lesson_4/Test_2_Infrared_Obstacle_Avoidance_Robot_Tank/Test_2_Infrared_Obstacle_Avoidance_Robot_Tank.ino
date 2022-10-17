volatile int left_light;
volatile int right_light;

void setup(){
  Serial.begin(9600);
  left_light = 0;
  right_light = 0;
  pinMode(3, INPUT);
  pinMode(10, INPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  left_light = digitalRead(A1);
  right_light = digitalRead(A2);
//  Serial.print("left_light_value = ");
//  Serial.println(left_light);
//  Serial.print("right_light_value = ");
//  Serial.println(right_light);
  if (left_light==0&& right_light==0) {
    stopp();
    delay(500);
    backward();
    delay(500);
    if (random(1, 10) > 5) 
    {
     rotate_left();
    } 
    else 
    {
    rotate_right();
    }
    delay(500);
  } else if (left_light==0&& right_light==1) {
    backward();
    delay(500);
    rotate_right();
    delay(500);
  } else if (left_light==1&& right_light==0) {
     backward();
    delay(500);
    rotate_left();
    delay(500);
  } else {
    forward();
  }

}


void forward()
{digitalWrite(2,LOW);
 analogWrite(5,180);
    digitalWrite(4,HIGH);
    analogWrite(6,180);
  }


void rotate_left()
{digitalWrite(2,HIGH);
 analogWrite(5,220);
    digitalWrite(4,HIGH);
    analogWrite(6,220);
  }


  void rotate_right()
{digitalWrite(2,LOW);
 analogWrite(5,220);
    digitalWrite(4,LOW);
    analogWrite(6,220);
  }


  void backward()
{digitalWrite(2,HIGH);
 analogWrite(5,220);
    digitalWrite(4,LOW);
    analogWrite(6,220);
  }

    void stopp()
{digitalWrite(2,HIGH);
 analogWrite(5,0);
    digitalWrite(4,LOW);
    analogWrite(6,0);
  }
