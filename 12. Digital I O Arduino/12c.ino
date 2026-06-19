int pinTombol = 2;
int pinLED = 8;

void setup() {
    pinMode(pinLED, OUTPUT);
    pinMode(pinTombol, INPUT_PULLUP);  
    Serial.begin(9600);
}

void loop() {
    int bacaTombol = digitalRead(pinTombol); 

    if (bacaTombol == LOW) {                 
        digitalWrite(pinLED, HIGH);          
        Serial.println("Tombol DITEKAN -> LED ON");
    } else {                                 
        digitalWrite(pinLED, LOW);           
        Serial.println("Tombol Lepas -> LED OFF");
    }

    delay(50); 
}