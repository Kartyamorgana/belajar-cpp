int pinLED9 = 9;
int pinLED10 = 10;
int pinPot = A0;


void setup() {
  pinMode(pinLED9, OUTPUT);
  pinMode(pinLED10, OUTPUT);
  pinMode(pinPot, INPUT);
  Serial.begin(9600);
}

void loop() {
  int bacaPot = analogRead(A0);
  
  int kecerahan1 = map(bacaPot, 0, 1023, 255, 0);
  int kecerahan2 = 255 - kecerahan1;
  
  analogWrite(pinLED9, kecerahan1);
  analogWrite(pinLED10, kecerahan2);
  
  delay(50);
}
