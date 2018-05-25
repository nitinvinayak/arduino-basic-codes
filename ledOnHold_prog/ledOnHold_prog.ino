//led On Hold program
int ledPin=13;
int switchPin=8;
void setup() {
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin)==HIGH)
  {
    digitalWrite(ledPin,HIGH);
    
  }
   else
   {
    digitalWrite(ledPin,LOW);
    
   }
}
