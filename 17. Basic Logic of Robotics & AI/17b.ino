// Class Ultrasonik (Pin 8, 9)
class SensorUltrasonik {
  private:
    byte pinTrig, pinEcho;
  public:
    SensorUltrasonik(byte trig, byte echo) {
        pinTrig = trig; pinEcho = echo;
        pinMode(pinTrig, OUTPUT); pinMode(pinEcho, INPUT);
    }
    float bacaJarak() {
        digitalWrite(pinTrig, LOW); delayMicroseconds(2);
        digitalWrite(pinTrig, HIGH); delayMicroseconds(10);
        digitalWrite(pinTrig, LOW);
        long durasi = pulseIn(pinEcho, HIGH);
        return (durasi * 0.0343) / 2.0;
    }
};

// Class Motor (Pin 2,3 untuk Kiri; Pin 4,5 untuk Kanan)
class MotorDC {
  private:
    byte in1, in2;
  public:
    MotorDC(byte a, byte b) { in1 = a; in2 = b; pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); }
    void maju() { digitalWrite(in1, HIGH); digitalWrite(in2, LOW); }
    void mundur() { digitalWrite(in1, LOW); digitalWrite(in2, HIGH); }
    void berhenti() { digitalWrite(in1, LOW); digitalWrite(in2, LOW); }
};

SensorUltrasonik usDepan(8, 9);
MotorDC motorKiri(2, 3);
MotorDC motorKanan(4, 5);

void setup() {
    Serial.begin(9600);
    Serial.println("Robot 1 Sensor Siap!");
}

void loop() {
    float jarak = usDepan.bacaJarak();
    
    Serial.print("Jarak: ");
    Serial.print(jarak);
    Serial.println(" cm");

    // ===== DECISION MAKING =====
    if (jarak < 20) {
        // BAHAYA!
        Serial.println("⚠️ BAHAYA! Mundur...");
        motorKiri.mundur();
        motorKanan.mundur();
        delay(500);
        
        // Belok kiri untuk menghindar
        Serial.println("↩️ Belok Kiri...");
        motorKiri.mundur();  // Kiri mundur
        motorKanan.maju();   // Kanan maju
        delay(800);
    } 
    else {
        // AMAN
        Serial.println("✅ Aman, Maju...");
        motorKiri.maju();
        motorKanan.maju();
    }
    
    delay(50);
}