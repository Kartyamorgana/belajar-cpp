const int PIN_SENSOR = A0;
const float TEGANGAN_OFFSET = 0.5;  
const float SKALA = 100.0;          

void setup() {
    pinMode(PIN_SENSOR, INPUT);
    Serial.begin(9600);
    
    Serial.println("=========================");
    Serial.println("   TERMOMETER DIGITAL   ");
    Serial.println("=========================");
}

void loop() {
    int bacaADC = analogRead(PIN_SENSOR);
    float tegangan = (bacaADC / 1023.0) * 5.0;
    float suhuC = (tegangan - TEGANGAN_OFFSET) * SKALA;
  	float suhuF = (suhuC * 9 / 5) + 32;
    
    String status;
  	if (suhuC > 40) {
  		status =  "🔥 KRITIS!";
    } else if (suhuC >= 30.0) {
        status = "🔴 PANAS!";
    } else if (suhuC >= 20.0) {
        status = "🟢 NORMAL";
    } else {
        status = "🔵 DINGIN";
    }
    
    Serial.println("-------------------------");
    Serial.print("| Suhu (C): ");
    Serial.print(suhuC, 1);  
    Serial.println(" C\t|");
  	Serial.print("| Suhu (F): ");
    Serial.print(suhuF, 1);  
    Serial.println(" F\t|");
    Serial.print("| Status: ");
    Serial.print(status);
    Serial.println("\t|");
    Serial.println("-------------------------");
    
    delay(1000); 
}