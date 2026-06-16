#include <iostream>

class MotorDC {
public:
    int kecepatan;
    bool berputar;

    void mulai(int kec) {
        kecepatan = kec;
        berputar = true;
        std::cout << "Motor berputar dengan kecepatan " << kecepatan << std::endl;
    }

    void berhenti() {
        kecepatan = 0;
        berputar = false;
        std::cout << "MOTOR BERHENTI" << std::endl;
    }

    void status() {
        std::cout << "Kecepatan: " << kecepatan << std::endl;
        std::cout << "Berputar?: " << (berputar ? "Iya" : "Tidak") << std::endl;
    }
};

int main() {
    MotorDC motorKanan;
    MotorDC motorKiri;

    std::cout << "=== MOTOR KANAN ===" << std::endl;
    motorKanan.mulai(100);
    motorKanan.status();

    std::cout << "\n=== MOTOR KIRI ===" << std::endl;
    motorKiri.mulai(88);
    motorKiri.berhenti();
    motorKiri.status();

    return 0;
}