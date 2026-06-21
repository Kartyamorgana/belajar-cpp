// (1) Definisi class SensorUltrasonik
class SensorUltrasonik {
  private:
    byte pinTrig;  // Pin TRIG (mulut)
    byte pinEcho;  // Pin ECHO (telinga)

  public:
    // (2) Constructor: Menerima pin TRIG dan ECHO
    SensorUltrasonik(byte trig, byte echo) {
        pinTrig = trig;
        pinEcho = echo;
        pinMode(pinTrig, OUTPUT);
        pinMode(pinEcho, INPUT);
        Serial.println("Sensor Ultrasonik siap!");
    }

    // (3) Method utama: Membaca jarak dalam cm
    float bacaJarak() {
        // Kirim pulsa 10 mikrodetik ke TRIG
        digitalWrite(pinTrig, LOW);
        delayMicroseconds(2);
        digitalWrite(pinTrig, HIGH);
        delayMicroseconds(10);
        digitalWrite(pinTrig, LOW);

        // Baca durasi pantulan di ECHO
        long durasi = pulseIn(pinEcho, HIGH);

        // Konversi durasi ke jarak (cm)
        float jarak = (durasi * 0.0343) / 2.0;
        return jarak;
    }
};

// (4) Membuat objek sensor
SensorUltrasonik sensorKiri(8, 9);
SensorUltrasonik sensorKanan(10, 11);

void setup() {
    Serial.begin(9600);
}

void loop() {
    // (5) Gunakan method bacaJarak() dengan mudah!
    float jarak1 = sensorKiri.bacaJarak();
  	float jarak2 = sensorKanan.bacaJarak();
    
    Serial.print("Jarak sensor kanan: ");
    Serial.print(jarak2);
    Serial.println(" cm");
  	Serial.print("Jarak sensor kiri: ");
    Serial.print(jarak1);
    Serial.println(" cm");
    
    delay(500);
}