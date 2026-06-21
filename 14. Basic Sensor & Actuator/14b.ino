const int PIN_TRIG = 8;
const int PIN_ECHO = 9;

long durasi;
float jarak;

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  durasi = pulseIn(PIN_ECHO, HIGH);
  
  jarak = (durasi * 0.0343) / 2.0;
  
  if (jarak < 20) {
    Serial.println("BAHAYA!");
  } else {
    Serial.println("AMAN");
  }
  
  delay(500);
}
  