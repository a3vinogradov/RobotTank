char bluetooth_val;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if (Serial.available())
  {
    bluetooth_val = Serial.read();
    Serial.println(bluetooth_val);
  }

}
