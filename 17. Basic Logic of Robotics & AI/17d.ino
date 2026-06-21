// ========== CLASS MOTOR ==========
class MotorDC {
  private: byte in1, in2;
  public:
    MotorDC(byte a, byte b) { in1 = a; in2 = b; pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); }
    void maju() { digitalWrite(in1, HIGH); digitalWrite(in2, LOW); }
    void mundur() { digitalWrite(in1, LOW); digitalWrite(in2, HIGH); }
    void berhenti() { digitalWrite(in1, LOW); digitalWrite(in2, LOW); }
};

MotorDC motorKiri(4, 5);
MotorDC motorKanan(6, 7);

// ========== PIN SENSOR GARIS (TOMBOL) ==========
const int SENSOR_KIRI = 2;
const int SENSOR_KANAN = 3;

// ========== STATE MACHINE ==========
enum RobotState {
    STATE_MAJU,
    STATE_BELOK_KIRI,
    STATE_BELOK_KANAN,
    STATE_BERHENTI
};

RobotState stateSekarang = STATE_MAJU;
unsigned long timerState = 0;

void setup() {
    pinMode(SENSOR_KIRI, INPUT_PULLUP);
    pinMode(SENSOR_KANAN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    int kiri = digitalRead(SENSOR_KIRI);  // LOW jika ditekan (garis hitam)
    int kanan = digitalRead(SENSOR_KANAN);
    
    switch (stateSekarang) {
        case STATE_MAJU:
            motorKiri.maju();
            motorKanan.maju();
            
            if (kiri == LOW && kanan == HIGH) {
                stateSekarang = STATE_BELOK_KANAN;
                timerState = millis();
            } else if (kanan == LOW && kiri == HIGH) {
                stateSekarang = STATE_BELOK_KIRI;
                timerState = millis();
            } else if (kiri == LOW && kanan == LOW) {
                stateSekarang = STATE_BERHENTI;
                timerState = millis();
            }
            break;
            
        case STATE_BELOK_KANAN:
            motorKiri.maju();
            motorKanan.mundur();  // Belok kanan
            if (millis() - timerState > 300) {
                stateSekarang = STATE_MAJU;
            }
            break;
            
        case STATE_BELOK_KIRI:
            motorKiri.mundur();  // Belok kiri
            motorKanan.maju();
            if (millis() - timerState > 300) {
                stateSekarang = STATE_MAJU;
            }
            break;
            
        case STATE_BERHENTI:
            motorKiri.berhenti();
            motorKanan.berhenti();
            if (kiri == HIGH && kanan == HIGH) {
                stateSekarang = STATE_MAJU;
            }
            break;
    }
    
    delay(50);
}