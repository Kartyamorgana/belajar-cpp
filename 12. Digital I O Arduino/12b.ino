int pinLED8 = 8;
int pinLED2 = 2;

void setup() {
    pinMode(pinLED8, OUTPUT);
    pinMode(pinLED8, OUTPUT);
}

void loop() {
    digitalWrite(pinLED8, HIGH); 
    digitalWrite(pinLED2, LOW);
    delay(1000);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED8, LOW);   
    delay(1000);
}