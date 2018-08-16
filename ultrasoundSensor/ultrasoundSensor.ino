const int trigpin1=5;
const int echopin1=6;
const int trigpin2=3;
const int echopin2=4;

long duration1, duration2;
int distance1, distance2;

void setup() {
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);
  
  pinMode(trigpin2,OUTPUT);
  pinMode(echopin2,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  
  duration1=pulseIn(echopin1,HIGH);
  distance1=(duration1/2)/29;

  Serial.print("Distance1: ");
  Serial.print(distance1);
  
  digitalWrite(trigpin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2,LOW);
  
  duration2=pulseIn(echopin2,HIGH);
  distance2=(duration2/2)/29;

  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println();
  delay(1000);
  }
