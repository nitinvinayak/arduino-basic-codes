int n=13;
void setup() {
  // put your setup code here, to run once:
pinMode(n,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(n,HIGH);
delay(1000);
digitalWrite(n,LOW);
delay(1000);
}
