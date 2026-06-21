#include <Servo.h>  

Servo servoAku;   

const int pinServo = 9; 

void setup() {
    servoAku.attach(pinServo); 
    Serial.begin(9600);
    Serial.println("Masukkan derajat: ");
}

void loop() {
  	if (Serial.available() > 0) {
    	int sudut = Serial.parseInt();
      
      	if (sudut >= 0 && sudut <= 180) {
        	servoAku.write(sudut);
          	Serial.print("Servo bergerak ke sudut: ");
          	Serial.println(sudut);
        } else {
          	Serial.println("Sudut tidak valid!");
          
        }
    }
}