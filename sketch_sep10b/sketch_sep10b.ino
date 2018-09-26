int in1 = 5;
int ena = 9;
int in2 = 6;
int in3 = 3;
int in4 = 4;
int enb = 10;
int t = 11;
int e = 12;long d;int di;
void setup() {
  // put your setup code here, to run once:
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(ena,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(enb,OUTPUT);
pinMode(e,INPUT);pinMode(t,OUTPUT);Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(ena,100);
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);

analogWrite(enb,100);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
digitalWrite(t,LOW);
delayMicroseconds(2);
digitalWrite(t,HIGH);
delayMicroseconds(10);
digitalWrite(t,LOW);
d=pulseIn(e,HIGH);
di=d*0.034/2;
Serial.print("DISTANCE=  ");
Serial.println(di);
}
