int LED_PIN = 8;
String input = "";

void nyalakan() {
  	digitalWrite(LED_PIN, HIGH);
  	Serial.println("LAMPU NYALA");
}

void matikan() {
  	digitalWrite(LED_PIN, LOW);
  	Serial.println("LAMPU MATI");
}

void blink() {
  	Serial.println("LAMPU BLINK");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(300);
      digitalWrite(LED_PIN, LOW);
      delay(300);
    }
}

void status() {
  	int status = digitalRead(LED_PIN);
  	Serial.print("STATUS: ");
    if (status == HIGH) {
      Serial.println("NYALA");
    } else {
      Serial.println("MATI");
    }
}

void sos() {
    Serial.println("SOS! Mengirim sinyal darurat...");
    // Tiga titik (S)
    for (int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(300);
        digitalWrite(LED_PIN, LOW);
        delay(300);
    }
    delay(600); // Jeda antar huruf
    
    // Tiga garis (O)
    for (int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(900);
        digitalWrite(LED_PIN, LOW);
        delay(300);
    }
    delay(600);
    
    // Tiga titik lagi (S)
    for (int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(300);
        digitalWrite(LED_PIN, LOW);
        delay(300);
    }
    Serial.println("Sinyal SOS selesai.");
}

void help() {
  	Serial.println("MASUKKAN ON, OFF, BLINK, STATUS, SOS, atau HELP.");
}


void perintah(String p) {
  	p.trim();
  	p.toUpperCase();
  	
    if (p == "ON") {
      nyalakan();
    } else if (p == "OFF") {
      	matikan();
    } else if (p == "BLINK") {
      	blink();
    } else if (p == "STATUS") {
      	status();
    } else if (p == "SOS") {
      	sos();
    } else if (p == "HELP") {
      	help();
    } else {
      	Serial.println("INPUT TIDAK DIKETAHUI!");
      	Serial.println("MOHON INPUT 'HELP' UNTUK BANTUAN");
    }
}

void setup() {
  	pinMode(LED_PIN, OUTPUT);
  	digitalWrite(LED_PIN, LOW);
  	Serial.begin(9600);
  	Serial.println("=================================");
    Serial.println("   SISTEM KONTROL LED SIAP!");
    Serial.println("   Ketik 'HELP' untuk panduan.");
    Serial.println("=================================");
}

void loop() {
  	if (Serial.available() > 0) {
    	input = Serial.readString();
    	perintah(input);
    }
}
    	

