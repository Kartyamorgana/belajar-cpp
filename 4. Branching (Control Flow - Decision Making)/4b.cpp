#include <iostream>
#include <string>

int main() {
    float suhu;

    std::cout << "Masukkan suhu: ";
    std::cin >> suhu;

    if (suhu > 35.0f) {
        std::cout << "Bahaya! Suhu terlalu panas, nyalakan kipas." << std::endl;
    } else {
        std::cout << "Suhu normal, kipas tidak perlu dinyalakan." << std::endl;
    }
    std::cout << "Pengecekan suhu selesai." << std::endl;

    return 0;
}

