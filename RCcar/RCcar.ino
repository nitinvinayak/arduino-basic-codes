/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  Note: This only works on Android!
        iOS does not support Bluetooth 2.0 Serial Port Profile
        You may need to pair the module with your smartphone
        via Bluetooth settings. Default pairing password is 1234

  Feel free to apply it to any other example. It's simple!

  NOTE: Bluetooth support is in beta!

  You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - Arduino Uno board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "400190a9c4da48d9bce72478b695bb85";

SoftwareSerial SerialBLE(10, 11); // RX, TX
int motorL1= 5, motorL2=3 , motorR1=9 , motorR2=6;


void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

BLYNK_WRITE(V1) {                               //joystick controls{same as analog stick}
  int x = param[0].asInt();
  int y = param[1].asInt();

  // Do something with x and y
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);
int a;                                          //a variable to make test cases
if(0<=y && y<=37)
a=0;
else if(219<=y && y<=255)
a=1;
if(0<=x && x<=37)
a=2;
else if(219<=x && x<=255)
a=3;
else if(x==128 && y==128)
a=4;
switch(a)
{
  case 0: //turn back
    analogWrite(motorR1, 255-y);
    analogWrite(motorL1, 255-y);
    analogWrite(motorR2, 0);
    analogWrite(motorL2, 0);
    break;
 case 1: //go straight
    analogWrite(motorR2, y);
    analogWrite(motorL2, y);
    analogWrite(motorR1, 0);
    analogWrite(motorL1, 0);
    break;

 case 2: // turn left x(0-37)
    analogWrite(motorL1, 0);
    analogWrite(motorL2, 255-x);
    analogWrite(motorR1, 255-x);
    analogWrite(motorR2, 0);
    break;
 
 case 3: // turn right x(219-255)
    analogWrite(motorR1, 0);
    analogWrite(motorR2, x);
    analogWrite(motorL1, x);
    analogWrite(motorL2, 0);
    break;
case 4:
    analogWrite(motorL1, 0);
    analogWrite(motorL2, 0);
    analogWrite(motorR1, 0);
    analogWrite(motorR2, 0);
    break;
default:
    analogWrite(motorL1, 0);
    analogWrite(motorL2, 0);
    analogWrite(motorR1, 0);
    analogWrite(motorR2, 0);
    break;

}
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

