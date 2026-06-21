#include <Servo.h>  

Servo servoAku;   

const int pinServo = 9; 
const int PIN_POT = A0;

void setup() {
    servoAku.attach(pinServo); 
    Serial.begin(9600);
}

void loop() {
  	int bacaPot = analogRead(PIN_POT);
    int sudutPot = map(bacaPot, 0, 1023, 0, 180);
    servoAku.write(sudutPot);
}