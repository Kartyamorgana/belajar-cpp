#include <iostream>
#include <string>

struct DataSuhu {
    std::string lokasi;
    float suhu;
};

int main() {
    DataSuhu stasiun[4] = {
        {"Dapur",        29.5f},
        {"Ruang Tengah", 27.0f},
        {"Kamar Tidur",  25.5f},
        {"Teras",        32.0f}
    };
    float suhuMax = stasiun[0].suhu;
    std::string locationMax = stasiun[0].lokasi;
    float totalSuhu = 0;


    for (int i = 0; i < 4; i++) {
        std::cout << "Data #" << i+1 << std::endl;
        std::cout << "  Lokasi: " << stasiun[i].lokasi << std::endl;
        std::cout << "  Suhu: " << stasiun[i].suhu << " C" << std::endl;

        totalSuhu += stasiun[i].suhu;

        if (stasiun[i].suhu > suhuMax) {
            suhuMax = stasiun[i].suhu;
            locationMax = stasiun[i].lokasi;
        }
    }

    std::cout << "\nSuhu tertinggi: " << suhuMax << " C (" << locationMax << ")" << std::endl;
    std::cout << "Rata-rata suhu: " << totalSuhu / 4 << " C" << std::endl;

    return 0;
}