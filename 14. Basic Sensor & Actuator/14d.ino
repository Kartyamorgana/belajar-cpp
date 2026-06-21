// Deklarasi pin kontrol
const int IN1 = 8; // Input 1 L293D
const int IN2 = 9; // Input 2 L293D

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Putar searah jarum jam
    Serial.println("Maju (CW)");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(2000); // Berputar 2 detik

    // Berhenti
    Serial.println("Berhenti");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    delay(1000);

    // Putar berlawanan arah jarum jam
    Serial.println("Mundur (CCW)");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(2000);

    // Berhenti
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.println("Berhenti");
    delay(1000);
}