class SensorUltrasonik {
  private: byte pinTrig, pinEcho;
  public:
    SensorUltrasonik(byte trig, byte echo) {
        pinTrig = trig; pinEcho = echo;
        pinMode(pinTrig, OUTPUT); pinMode(pinEcho, INPUT);
    }
    float bacaJarak() {
        digitalWrite(pinTrig, LOW); delayMicroseconds(2);
        digitalWrite(pinTrig, HIGH); delayMicroseconds(10);
        digitalWrite(pinTrig, LOW);
        long durasi = pulseIn(pinEcho, HIGH, 30000); // Timeout 30ms untuk mencegah hang
        if (durasi == 0) return 999; // Jika tidak ada pantulan, anggap jarak sangat jauh
        return (durasi * 0.0343) / 2.0;
    }
};

class MotorDC {
  private: byte in1, in2;
  public:
    MotorDC(byte a, byte b) { in1 = a; in2 = b; pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); }
    void maju() { digitalWrite(in1, HIGH); digitalWrite(in2, LOW); }
    void mundur() { digitalWrite(in1, LOW); digitalWrite(in2, HIGH); }
    void berhenti() { digitalWrite(in1, LOW); digitalWrite(in2, LOW); }
};

SensorUltrasonik usDepan(8, 9);
SensorUltrasonik usKiri(10, 11);
MotorDC motorKanan(2, 3);
MotorDC motorKiri(4, 5);

enum RobotState {
    STATE_MAJU,
    STATE_MUNDUR,
    STATE_BELOK_KIRI,
    STATE_BELOK_KANAN,
    STATE_BERHENTI
};
RobotState stateSekarang = STATE_MAJU;
unsigned long timerState = 0;

float jarakDepan, jarakKiri;

void setup() {
    Serial.begin(9600);
    Serial.println("=================================");
    Serial.println(" ROBOT PENGHINDAR RINTANGAN ");
    Serial.println("=================================");
    Serial.println("Depan | Kiri  | State");
    Serial.println("------|-------|----------");
}

void loop() {
    // 1. BACA SENSOR (dengan validasi timeout)
    jarakDepan = usDepan.bacaJarak();
    jarakKiri = usKiri.bacaJarak();
    
    // 2. DEBUGGING: Cetak data sensor
    Serial.print(jarakDepan, 1);
    Serial.print(" cm | ");
    Serial.print(jarakKiri, 1);
    Serial.print(" cm | ");
    
    // 3. STATE MACHINE (Algoritma Dua Zona)
    switch (stateSekarang) {
        case STATE_MAJU:
            Serial.println("MAJU");
            motorKanan.maju();
            motorKiri.maju();
            
            if (jarakDepan < 10) {
                Serial.println("  -> BAHAYA! Pindah ke BERHENTI");
                stateSekarang = STATE_BERHENTI;
                timerState = millis();
            } else if (jarakDepan < 30) {
                Serial.println("  -> HATI-HATI! Pindah ke MUNDUR");
                stateSekarang = STATE_MUNDUR;
                timerState = millis();
            }
            break;
            
        case STATE_BERHENTI:
            Serial.println("BERHENTI (Mundur Pelan)");
            motorKanan.mundur();
            motorKiri.mundur();
            if (millis() - timerState > 1500) {
                Serial.println("  -> Selesai. Lanjut ke MUNDUR");
                stateSekarang = STATE_MUNDUR;
                timerState = millis();
            }
            break;
            
        case STATE_MUNDUR:
            Serial.println("MUNDUR");
            motorKanan.mundur();
            motorKiri.mundur();
            if (millis() - timerState > 1000) {
                if (jarakKiri > 30) {
                    Serial.println("  -> Kiri aman, BELOK KIRI");
                    stateSekarang = STATE_BELOK_KIRI;
                } else {
                    Serial.println("  -> Kiri tidak aman, BELOK KANAN");
                    stateSekarang = STATE_BELOK_KANAN;
                }
                timerState = millis();
            }
            break;
            
        case STATE_BELOK_KIRI:
            Serial.println("BELOK KIRI");
            motorKanan.maju();
            motorKiri.mundur();
            if (millis() - timerState > 800) {
                Serial.println("  -> Selesai belok, kembali MAJU");
                stateSekarang = STATE_MAJU;
            }
            break;
            
        case STATE_BELOK_KANAN:
            Serial.println("BELOK KANAN");
            motorKanan.mundur();
            motorKiri.maju();
            if (millis() - timerState > 800) {
                Serial.println("  -> Selesai belok, kembali MAJU");
                stateSekarang = STATE_MAJU;
            }
            break;
    }
    
    delay(50);
}