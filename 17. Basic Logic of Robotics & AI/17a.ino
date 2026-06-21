// PIN
const int SENSOR_KIRI = 2;
const int SENSOR_KANAN = 3;
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

void setup() {
  	pinMode(SENSOR_KIRI, INPUT);
  	pinMode(SENSOR_KANAN, INPUT);
  	pinMode(IN1, OUTPUT);
  	pinMode(IN2, OUTPUT);
  	pinMode(IN3, OUTPUT);
  	pinMode(IN4, OUTPUT);
  
  	Serial.begin(9600);
  
  	// Default
  	digitalWrite(IN1, LOW);
  	digitalWrite(IN2, LOW);
  	digitalWrite(IN3, LOW);
  	digitalWrite(IN4, LOW);
}

void maju() {
  	digitalWrite(IN1, HIGH);
  	digitalWrite(IN2, LOW);
  	digitalWrite(IN3, HIGH);
  	digitalWrite(IN4, LOW);
}

void belokKanan() {
  	digitalWrite(IN1, LOW);
  	digitalWrite(IN2, HIGH);
  	digitalWrite(IN3, HIGH);
  	digitalWrite(IN4, LOW);
}

void belokKiri() {
  	digitalWrite(IN1, HIGH);
  	digitalWrite(IN2, LOW);
  	digitalWrite(IN3, LOW);
  	digitalWrite(IN4, HIGH);
}

void berhenti() {
  	digitalWrite(IN1, LOW);
  	digitalWrite(IN2, LOW);
  	digitalWrite(IN3, LOW);
  	digitalWrite(IN4, LOW);
}

void loop() {
  	int kiri = digitalRead(SENSOR_KIRI);
  	int kanan = digitalRead(SENSOR_KANAN);
  	
  	if (kiri == LOW && kanan == HIGH) {
        // Hanya sensor kiri melihat hitam -> Robot terlalu ke kanan
        belokKanan();
        Serial.println("Koreksi KIRI");
    } 
    else if (kanan == LOW && kiri == HIGH) {
        // Hanya sensor kanan melihat hitam -> Robot terlalu ke kiri
        belokKiri();
        Serial.println("Koreksi KANAN");
    } 
    else if (kiri == HIGH && kanan == HIGH) {
        // Keduanya melihat putih -> Jalan lurus
        maju();
        Serial.println("MAJU");
    } 
    else {
        // Keduanya LOW (hitam) -> Persimpangan atau garis tebal
        berhenti();
        Serial.println("BERHENTI (Simpang)");
    }
    
    delay(10); // Jeda kecil untuk stabilitas
}