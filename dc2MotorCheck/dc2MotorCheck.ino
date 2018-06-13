int motorpin = 3;
int motorpin1 = 11;
void setup() {
 pinMode(motorpin,OUTPUT);
 pinMode(motorpin1,OUTPUT); 
 Serial.begin(9600);
}

void loop() {
  analogWrite(motorpin,255);
  delay(10);
  analogWrite(motorpin1,255);
  delay(10);
}
