int pinLED = 9;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int kecerahan = 0; kecerahan <= 255; kecerahan++) {
    analogWrite(pinLED, kecerahan);
    delay(30);
  }
  
  for (int kecerahan = 255; kecerahan >= 0; kecerahan--) {
    analogWrite(pinLED, kecerahan);
    delay(5);
  }
  
}