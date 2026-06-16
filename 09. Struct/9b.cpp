#include <iostream>
#include <string>

struct MotorConfig {
    int pinDepan;
    int pinBelakang;
    int kecepatanMaks;
};

int main() {
    MotorConfig motorKanan = {1, 2, 3};
    MotorConfig motorKiri = {4, 5, 6};

    std::cout << "=== DATA MOTOR ===" << std::endl;
    std::cout << "PIN motor kanan: " << motorKanan.pinDepan << "-" << motorKanan.pinBelakang << std::endl;
    std::cout << "Kecepatan maks: " << motorKanan.kecepatanMaks << " m/s" << std::endl;

    std::cout << "\nPIN motor kiri: " << motorKiri.pinDepan << "-" << motorKiri.pinBelakang << std::endl;
    std::cout << "Kecepatan maks: " << motorKiri.kecepatanMaks << " m/s" << std::endl;

    MotorConfig motorCadangan = motorKanan;
    motorCadangan.pinDepan = 99;

    std::cout << "\nPIN depan motor cadangan: " << motorCadangan.pinDepan << std::endl;
    std::cout << "PIN motor kanan: " << motorKanan.pinDepan << std::endl;

    return 0;
}