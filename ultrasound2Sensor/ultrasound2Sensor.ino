const int trigpin=3;
const int echopin=A0;

long duration;
int distance;

const int trigpin1=9;
const int echopin1=A1;

long duration1;
int distance1;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  duration=pulseIn(echopin,HIGH);
  
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  
  duration1=pulseIn(echopin1,HIGH);
  
  distance=duration*.034/2;
  distance1=duration1*.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Distance1: ");
  Serial.println(distance1);
}
