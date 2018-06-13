const int trigpin=5;
const int echopin=6;

long duration;
int distance;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  duration=pulseIn(echopin,HIGH);
  distance=duration*.03412/6;

  Serial.print("Distance: ");
  Serial.println(distance);
  //Serial.println(duration);
}
