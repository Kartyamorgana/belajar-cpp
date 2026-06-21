// ==========================================
// (1) DEFINISI CLASS MOTORDC ("Library")
// ==========================================
class MotorDC {
  private:
    byte pinIN1;  // Pin kontrol arah 1
    byte pinIN2;  // Pin kontrol arah 2
    byte pinPWM;  // Pin kecepatan (PWM) - optional
    
  public:
    // Constructor untuk motor tanpa kontrol kecepatan (hanya ON/OFF)
    MotorDC(byte in1, byte in2) {
        pinIN1 = in1;
        pinIN2 = in2;
        pinPWM = 255; // Default tidak dipakai
        pinMode(pinIN1, OUTPUT);
        pinMode(pinIN2, OUTPUT);
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, LOW);
    }
    
    // Constructor untuk motor DENGAN kontrol kecepatan
    MotorDC(byte in1, byte in2, byte pwm) {
        pinIN1 = in1;
        pinIN2 = in2;
        pinPWM = pwm;
        pinMode(pinIN1, OUTPUT);
        pinMode(pinIN2, OUTPUT);
        pinMode(pinPWM, OUTPUT);
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, LOW);
    }
    
    // Method: Maju
    void maju(int kecepatan) {
        digitalWrite(pinIN1, HIGH);
        digitalWrite(pinIN2, LOW);
        if (pinPWM != 255) {  // Jika pin PWM diset
            analogWrite(pinPWM, kecepatan);
        }
        Serial.println("Motor MAJU");
    }
    
    // Method: Mundur
    void mundur(int kecepatan) {
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, HIGH);
        if (pinPWM != 255) {
            analogWrite(pinPWM, kecepatan);
        }
        Serial.println("Motor MUNDUR");
    }
    
    // Method: Berhenti
    void berhenti() {
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, LOW);
        if (pinPWM != 255) {
            analogWrite(pinPWM, 0);
        }
        Serial.println("Motor BERHENTI");
    }
};

// ==========================================
// (2) MEMBUAT OBJEK MOTOR
// ==========================================
MotorDC motorKanan(8, 9);    // IN1=8, IN2=9 (tanpa PWM)
MotorDC motorKiri(10, 11);   // IN1=10, IN2=11 (tanpa PWM)

void setup() {
    Serial.begin(9600);
    Serial.println("Library MotorDC Siap!");
}

void loop() {
    // (3) Demo: Robot zig-zag
    Serial.println(">>> MAJU <<<");
    motorKanan.maju(255);
    motorKiri.maju(255);
    delay(2000);
    
    Serial.println(">>> BELOK KANAN (Motor Kiri saja) <<<");
    motorKanan.berhenti();  // Motor kanan diam
    // Motor kiri tetap maju
    delay(1000);
    
    Serial.println(">>> MUNDUR <<<");
    motorKanan.mundur(200);
    motorKiri.mundur(200);
    delay(2000);
    
    Serial.println(">>> BERHENTI <<<");
    motorKanan.berhenti();
    motorKiri.berhenti();
    delay(3000);
}