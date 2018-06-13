int motorpin = 2;
int motorpin1 = 4;
void setup() {
 pinMode(motorpin,OUTPUT); 
 pinMode(motorpin1,OUTPUT); 
 Serial.begin(9600);
}

void loop() {
  digitalWrite(motorpin,LOW);
  digitalWrite(motorpin1,HIGH);

}
