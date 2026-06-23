// Kaino Faiq Rudiyansyah (21-06-2026)

#include <LiquidCrystal.h>  // Library LCD parallel
#include <Servo.h>          // Library Servo

class SensorUltrasonik {
  private:
    byte pinTrig, pinEcho;
  public:
    SensorUltrasonik(byte trig, byte echo) {
        pinTrig = trig;
        pinEcho = echo;
        pinMode(pinTrig, OUTPUT);
        pinMode(pinEcho, INPUT);
    }
    float bacaJarak() {
        digitalWrite(pinTrig, LOW);
        delayMicroseconds(2);
        digitalWrite(pinTrig, HIGH);
        delayMicroseconds(10);
        digitalWrite(pinTrig, LOW);
        long durasi = pulseIn(pinEcho, HIGH, 30000); // timeout 30ms
        if (durasi == 0) return 999; // tidak ada pantulan = jauh
        return (durasi * 0.0343) / 2.0;
    }
};

class PalangParkir {
  private:
    Servo servo;
    byte pin;
    bool statusTerbuka; // true = terbuka, false = tertutup
  public:
    PalangParkir(byte p) {
        pin = p;
        statusTerbuka = false;
    }
    void begin() {
        servo.attach(pin);
        tutup(); // awal tertutup
    }
    void buka() {
      for (int sudut = 0; sudut <= 90; sudut++) {
          servo.write(sudut);
          delay(20);
      }
      statusTerbuka = true;
	}
    void tutup() {
        servo.write(0);  // sudut 0° (tertutup)
        statusTerbuka = false;
    }
    bool isTerbuka() {
        return statusTerbuka;
    }
};

SensorUltrasonik sensorMasuk(9, 10);
SensorUltrasonik sensorKeluar(11, 12);
PalangParkir palang(13);

// LCD: RS=6, E=5, DB4=2, DB5=3, DB6=4, DB7=7
LiquidCrystal lcd(6, 5, 2, 3, 4, 7);

const byte PIN_LED_HIJAU = A0;
const byte PIN_LED_MERAH = A1;

enum StateGerbang {
    STATE_IDLE,
    STATE_DETECTED,
    STATE_OPEN,
    STATE_CLOSE
};
StateGerbang stateGerbang = STATE_IDLE;
unsigned long timerGerbang = 0;

const int TOTAL_SLOT = 2;
int slotKosong = TOTAL_SLOT;
bool mobilDiGerbang = false; // mencegah deteksi berulang

void setup() {
    Serial.begin(9600);
    
    // Inisialisasi komponen
    palang.begin(); // servo siap, posisi tertutup
    lcd.begin(16, 2);
    pinMode(PIN_LED_HIJAU, OUTPUT);
    pinMode(PIN_LED_MERAH, OUTPUT);
    
    // Tampilan awal
    updateLCD();
    digitalWrite(PIN_LED_HIJAU, HIGH); // awalnya slot kosong
    digitalWrite(PIN_LED_MERAH, LOW);
    
    Serial.println("=== SMART PARKING SYSTEM ===");
}

void loop() {
    float jarakMasuk = sensorMasuk.bacaJarak();
    float jarakKeluar = sensorKeluar.bacaJarak();
    
    Serial.print("Masuk: "); Serial.print(jarakMasuk, 1);
    Serial.print(" cm | Keluar: "); Serial.print(jarakKeluar, 1);
    Serial.print(" cm | Slot: "); Serial.print(slotKosong);
    Serial.print(" | State: ");
  
    if (jarakKeluar < 15 && slotKosong < TOTAL_SLOT) {
        // Mobil keluar terdeteksi
        delay(500); // debounce sederhana
        slotKosong++;
      	lcd.clear();
      	lcd.print("TERIMA KASIH");
      	lcd.setCursor(0, 1);
        lcd.print("SILAHKAN DATANG KEMBALI :)");
      	delay(1500);
        updateLCD();
        Serial.println("MOBIL KELUAR -> Slot bertambah");
    }
    
    switch (stateGerbang) {
        case STATE_IDLE:
            Serial.println("IDLE");
            // Cek apakah ada mobil di depan gerbang
            if (jarakMasuk < 15 && !mobilDiGerbang) {
                mobilDiGerbang = true;
                if (slotKosong > 0) {
                    stateGerbang = STATE_OPEN;
                    Serial.println("  -> Mobil datang, slot tersedia. BUKA");
                } else {
                    stateGerbang = STATE_DETECTED;
                    Serial.println("  -> Mobil datang, tapi PENUH. Tolak.");
                }
            }
            // Reset flag mobilDiGerbang jika sudah jauh
            if (jarakMasuk > 30) {
                mobilDiGerbang = false;
            }
            break;
            
        case STATE_DETECTED:
            Serial.println("DETECTED (PENUH)");
            // Tampilkan pesan penuh di LCD (sudah diupdate saat transisi)
            digitalWrite(PIN_LED_HIJAU, LOW);
            digitalWrite(PIN_LED_MERAH, HIGH);
            // Setelah 2 detik, kembalikan ke IDLE jika mobil pergi
            if (jarakMasuk > 30) {
                stateGerbang = STATE_IDLE;
                mobilDiGerbang = false;
                updateLCD();
                digitalWrite(PIN_LED_MERAH, LOW);
                digitalWrite(PIN_LED_HIJAU, HIGH);
            }
            break;
            
        case STATE_OPEN:
            Serial.println("OPEN");
      		lcd.clear();
      		lcd.print("SILAKAN MASUK");
            palang.buka();
            digitalWrite(PIN_LED_MERAH, LOW);
            digitalWrite(PIN_LED_HIJAU, HIGH);
            timerGerbang = millis();
            stateGerbang = STATE_CLOSE; // langsung menuju penutupan setelah timer
            // Kurangi slot setelah palang terbuka
            slotKosong--;
            updateLCD();
            break;
            
        case STATE_CLOSE:
            Serial.println("CLOSE (menunggu mobil lewat)");
            // Biarkan palang terbuka selama 3 detik
            if (millis() - timerGerbang > 3000) {
                palang.tutup();
                mobilDiGerbang = false;
                stateGerbang = STATE_IDLE;
                // Update LED
                if (slotKosong == 0) {
                    digitalWrite(PIN_LED_HIJAU, LOW);
                    digitalWrite(PIN_LED_MERAH, HIGH);
                } else {
                    digitalWrite(PIN_LED_HIJAU, HIGH);
                    digitalWrite(PIN_LED_MERAH, LOW);
                }
            }
            break;
    }
    
    delay(50);
}

void updateLCD() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Parkir Smart");
    lcd.setCursor(0, 1);
    if (slotKosong > 0) {
        lcd.print("Slot: ");
        lcd.print(slotKosong);
        lcd.print("/");
        lcd.print(TOTAL_SLOT);
    } else {
        lcd.print("    MAAF, PENUH    ");
    }
}