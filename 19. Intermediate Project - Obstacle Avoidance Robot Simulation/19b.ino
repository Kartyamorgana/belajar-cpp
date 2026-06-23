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
        long durasi = pulseIn(pinEcho, HIGH);
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
    Serial.println("Robot Penghindar Rintangan Siap!");
}

void loop() {
    // 1. BACA SENSOR
    jarakDepan = usDepan.bacaJarak();
    jarakKiri = usKiri.bacaJarak();

    // 2. DEBUGGING
    Serial.print("Depan: "); Serial.print(jarakDepan);
    Serial.print(" cm | Kiri: "); Serial.print(jarakKiri);
    Serial.print(" cm | State: ");
    
    // 3. STATE MACHINE
    switch (stateSekarang) {
        case STATE_MAJU:
            Serial.println("MAJU");
            motorKanan.maju();
            motorKiri.maju();
            
            if (jarakDepan < 10) {
                stateSekarang = STATE_BERHENTI;
                timerState = millis();
            } else if (jarakDepan < 30) {
              	stateSekarang = STATE_MUNDUR;
              	timerState = millis();
            }
            break;
      
      	case STATE_BERHENTI:
            Serial.println("BERHENTI");
            motorKanan.berhenti();
            motorKiri.berhenti();
      
      		if (millis() - timerState < 1500) {
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
                    stateSekarang = STATE_BELOK_KIRI;
                } else {
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
                stateSekarang = STATE_MAJU;
            }
            break;
            
        case STATE_BELOK_KANAN:
            Serial.println("BELOK KANAN");
            motorKanan.mundur();
            motorKiri.maju();
            if (millis() - timerState > 800) {
                stateSekarang = STATE_MAJU;
            }
            break;
    }
    
    delay(50);
}