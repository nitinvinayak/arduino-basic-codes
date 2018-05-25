//led On Hold program
int ledPin=13;
int switchPin=8;
boolean lastButton=LOW;
boolean ledOn=false;
boolean currentButton =LOW;

void setup() {
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
  
  // put your setup code here, to run once:

}

boolean debounce(boolean last)
{
 boolean current=digitalRead(switchPin);
 if (last!=current)
 {
  delay(5);
  current=digitalRead(switchPin);
 }
 return current; 
}  
void loop() {

  currentButton=debounce(lastButton);
  if (lastButton==LOW && currentButton==HIGH)
  {
    ledOn=!ledOn;
  }
    lastButton=currentButton;
    digitalWrite(ledPin,ledOn);
    
  }

