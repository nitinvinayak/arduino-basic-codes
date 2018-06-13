int motorpin1=2;
int motorpin2=8;
void setup() {
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
}

void loop() {
  digitalWrite(motorpin1,HIGH);
  digitalWrite(motorpin2,LOW);

}
