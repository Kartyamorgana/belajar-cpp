const int PIN_LED = 8;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);
    Serial.println("Kirim 'LED ON', 'LED OFF' atau 'BLINK':");
}

void loop() {
    if (Serial.available() > 0) {                // (1) Ada data masuk?
        String perintah = Serial.readString();   // (2) Baca semua data sebagai String
        
        perintah.trim();                         // (3) Buang spasi/enter di awal/akhir
        
        if (perintah == "LED ON") {              // (4) Cocokkan persis
            digitalWrite(PIN_LED, HIGH);
            Serial.println("💡 LED NYALA");
        } 
        else if (perintah == "LED OFF") {
            digitalWrite(PIN_LED, LOW);
            Serial.println("🔌 LED MATI");
        } 
      	else if (perintah == "BLINK") {
            for (int i = 0; i < 5; i++) {
              digitalWrite(PIN_LED, HIGH);
              delay(300);
              digitalWrite(PIN_LED, LOW);
              delay(300);
            }
          	Serial.println("LED BLINK");
        }
        else {
            Serial.print("Perintah tidak dikenal: ");
            Serial.println(perintah);
        }
    }
}