int motorpin1=4;
int motorpin2=7;
int motorpin3=8;
int motorpin4=12;

void setup() {
 pinMode(motorpin1,OUTPUT);
 pinMode(motorpin2,OUTPUT);
 pinMode(motorpin3,OUTPUT);
 pinMode(motorpin4,OUTPUT); 
}

void loop() {
 digitalWrite(motorpin1,HIGH);
 digitalWrite(motorpin2,LOW);
 //digitalWrite(motorpin3,HIGH);
//digitalWrite(motorpin4,LOW);
 //delay(1000);

}
