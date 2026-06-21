#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream sensor("sensor.csv");

    if (!sensor.is_open()) {
        std::cout << "File tidak dapat dibuka!" << std::endl;
        return 1;
    }

    std::string baris;

    std::getline(sensor, baris);

    while (std::getline(sensor, baris)) {
        std::stringstream ss(baris);

        std::string ID;
        std::string Suhu;
        std::string Kelembapan;

        std::getline(ss, ID, ',');
        std::getline(ss, Suhu, ',');
        std::getline(ss, Kelembapan, ',');

        int id = std::stoi(ID);
        float suhu = std::stof(Suhu);
        float kelembapan = std::stof(Kelembapan);

        std::cout << "Sensor " << id << " -> Suhu: " << suhu << " C, Kelembapan: " << kelembapan << std::endl;
    }

    sensor.close();

    return 0;
}