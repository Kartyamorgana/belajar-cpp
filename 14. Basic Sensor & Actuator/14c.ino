int pinSensor = A0; 

void setup() {
    pinMode(pinSensor, INPUT);
    Serial.begin(9600);
}

void loop() {
    int bacaAnalog = analogRead(pinSensor);
    float tegangan = (bacaAnalog / 1023.0) * 5.0;
    float suhuC = (tegangan - 0.5) * 100.0;
    
  	if (suhuC > 30.0) {
    	Serial.println("PANAS");
    } else if (suhuC >= 20.0 && suhuC <= 30.0) {
      	Serial.println("NORMAL");
    } else {
      	Serial.println("DINGIN");
    }
  
    delay(500);
}