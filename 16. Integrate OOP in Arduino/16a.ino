class LED {
  private:
  	byte pin;
  	
  public:
    LED(byte p) {
      pin = p;
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }
  
  	void nyalakan() {
    	digitalWrite(pin, HIGH);
      	Serial.println("LAMPU NYALA");
    }
  
    void matikan() {
      digitalWrite(pin, LOW);
      Serial.println("LAMPU MATI");
    }
  
    bool apakahNyala() {
      return digitalRead(pin);
    }
};

LED ledmerah(8);
LED ledbiru(9);

void setup() {
  	Serial.begin(9600);
  	Serial.println("CLASS LED SIAP!");
}

void loop() {
  	ledmerah.nyalakan();
  	ledbiru.matikan();
  	delay(1000);
  	ledmerah.matikan();
  	ledbiru.nyalakan();
  	delay(1000);
}