int pinPot = A0;

void setup() {
    pinMode(pinPot, INPUT); // Atur sebagai input (opsional untuk analog, tapi baik untuk kejelasan)
    Serial.begin(9600);
}

void loop() {
    int bacaPot = analogRead(A0);

    float tegangan = (bacaPot / 1023.0) * 5.0; // Konversi ke Volt
    int persentase = map(bacaPot, 0, 1023, 0, 100); // Konversi ke %

    Serial.print("Tegangan: ");
    Serial.print(tegangan);
    Serial.print(" V | Persentase: ");
    Serial.print(persentase);
    Serial.println(" %");
}