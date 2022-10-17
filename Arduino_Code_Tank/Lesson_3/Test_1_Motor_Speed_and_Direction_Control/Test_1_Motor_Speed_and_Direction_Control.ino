void setup() {
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() 
{
forward();
delay(1000);
backward();
delay(1000);
rotate_left();
delay(1000);
rotate_right();
delay(1000);
stopp();
delay(1000);

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
