#include <iostream>
#include <string>

struct SensorData {
    int id;
    float suhu;
    bool aktif;
};

void cetakSensor(SensorData s) {
    std::cout << "  ID: " << s.id << std::endl;
    std::cout << "  Suhu: " << s.suhu << "°C" << std::endl;
    std::cout << "  Aktif: " << s.aktif << std::endl;
}

void nonaktifkan(SensorData& s) {
    s.aktif = false;
    std::cout << "SENSOR DINONAKTIFKAN!" << std::endl;
}

int main() {
    SensorData sensor1 = {101, 36.5f, true};

    std::cout << "CETAK SENSOR PERTAMA" << std::endl;
    cetakSensor(sensor1);

    std::cout << std::endl;
    nonaktifkan(sensor1);

    std::cout << "\nCETAK SENSOR KEDUA" << std::endl;
    cetakSensor(sensor1);

    return 0;
}