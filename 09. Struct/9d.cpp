#include <iostream>
#include <string>

struct Sensor {
    int pin;
    float nilai;
};

struct Station {
    std::string nama;
    Sensor suhu;
    Sensor kelembapan;
};

int main() {
    Station station1 = {
        "Lab Utama",
        {0, 28.7f},   // Sensor suhu: pin A0, nilai 28.7°C
        {1, 65.2f}    // Sensor kelembaban: pin A1, nilai 65.2%
    };

    std::cout << "=== Data Stasiun " << station1.nama << " ===" << std::endl;
    std::cout << "Suhu: " << std::endl;
    std::cout << "  PIN: A" << station1.suhu.pin << std::endl;
    std::cout << "  Nilai: " << station1.suhu.nilai << "°C" << std::endl;
    std::cout << "Kelembapan: " << std::endl;
    std::cout << "  PIN: A" << station1.kelembapan.pin << std::endl;
    std::cout << "  Nilai: " << station1.kelembapan.nilai << "°C" << std::endl;

    return 0;
}