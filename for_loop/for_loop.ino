int ledPin=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  for(int i=0;i<10;i++)
    {
      digitalWrite(ledPin,HIGH);
      delay(1000);
      digitalWrite(ledPin,LOW);
      delay(1000);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
