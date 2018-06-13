int motorpin = 3;
int i=0;
int a=0;
void setup() {
 pinMode(motorpin,OUTPUT); 
 Serial.begin(9600);
}

void loop() {
  a=Serial.read();
  i+=a;
  analogWrite(motorpin,i);
  Serial.print(i);
  delay(1000);
}
