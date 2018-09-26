void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i<255; i++){
    analogWrite(5, i);
    analogWrite(6, 0);
    delay(5);
  }
  
  for(int i = 0; i<255; i++){
    analogWrite(5, 255-i);
    analogWrite(6, 0);
    delay(5);
  }
  
  for(int i = 0; i<255; i++){
    analogWrite(5, 0);
    analogWrite(6, i);
    delay(5);
  }
  
  for(int i = 0; i<255; i++){
    analogWrite(5, 0);
    analogWrite(6, 255-i);
    delay(5);
  }

}
