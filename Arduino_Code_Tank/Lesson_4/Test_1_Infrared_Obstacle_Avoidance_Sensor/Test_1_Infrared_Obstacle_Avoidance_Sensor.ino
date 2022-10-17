volatile int left_IR_Sensor;
volatile int right_IR_Sensor;

void setup(){
  Serial.begin(9600);
  left_IR_Sensor = 0;
  right_IR_Sensor = 0;
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop(){
  left_IR_Sensor = digitalRead(A1);
  right_IR_Sensor = digitalRead(A2);
  Serial.print("left_light_value = ");
  Serial.println(left_IR_Sensor);
  Serial.print("right_light_value = ");
  Serial.println(right_IR_Sensor);
  Serial.println("");
  delay(500);

}
