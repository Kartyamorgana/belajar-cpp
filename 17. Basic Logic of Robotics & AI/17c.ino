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
  	MotorDC(byte a, byte b) { in1 = a; in2 = b; pinMode(in1, OUTPUT);
                             pinMode(in2, OUTPUT); }
    void maju() { digitalWrite(in1, HIGH); digitalWrite(in2, LOW); }
    void mundur() { digitalWrite(in1, LOW); digitalWrite(in2, HIGH); }
    void berhenti() { digitalWrite(in1, LOW); digitalWrite(in2, LOW); }
};

SensorUltrasonik usDepan(8, 9);
MotorDC motorKiri(2, 3);
MotorDC motorKanan(4, 5);

enum RobotState {
  STATE_MAJU,
  STATE_MUNDUR,
  STATE_BELOK,
  STATE_BERHENTI
};

RobotState stateSekarang = STATE_MAJU;
unsigned long timerState = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("State Machine Siap! State: MAJU");
}

void loop() {
  float jarak = usDepan.bacaJarak();
  
  switch (stateSekarang) {
    
    case STATE_MAJU:
    	motorKiri.maju();
    	motorKanan.maju();
    
    	if (jarak < 10) {
          	Serial.println("BAHAYA! TERLALU DEKAT! STATE: BERHENTI");
          	stateSekarang = STATE_BERHENTI;
          	timerState = millis();
        } else if (jarak < 20) {
            Serial.println("ADA RINTANGAN! STATE: MUNDUR");
            stateSekarang = STATE_MUNDUR;
            timerState = millis();
        } 
        break;
    
    case STATE_MUNDUR:
    	motorKiri.mundur();
    	motorKanan.mundur();
    
        if (millis() - timerState > 1000) {
            Serial.println("Selesai mundur. Pindah ke BELOK");
            stateSekarang = STATE_BELOK;
            timerState = millis();
        }
        break;
    
    case STATE_BELOK:
    	motorKiri.mundur();
    	motorKanan.maju();
    
        if (millis() - timerState > 1000) {
            Serial.println("Selesai belok. Kembali ke MAJU");
            stateSekarang = STATE_MAJU;
        }
        break;
    
    case STATE_BERHENTI:
    	motorKiri.berhenti();
    	motorKanan.berhenti();
    	
    	if (millis() - timerState > 2000) {
            Serial.println("Selesai berhenti. Kembali ke MAJU");
            stateSekarang = STATE_MAJU;
        }
        break;
  }
  
  delay(50);
}
    