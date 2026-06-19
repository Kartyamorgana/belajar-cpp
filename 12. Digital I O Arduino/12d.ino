const int PIN_LED = 8;
const int PIN_TOMBOL = 2;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_TOMBOL, INPUT_PULLUP);
   
    Serial.begin(9600);
    Serial.println("Sistem Kendali Tombol Siap!");
}

void loop() {
    bool tombolDitekan = digitalRead(PIN_TOMBOL);

    digitalWrite(PIN_LED, tombolDitekan);
    
    delay(50);
}