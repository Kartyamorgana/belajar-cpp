#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>  // Untuk rand()
#include <ctime>    // Untuk time()

class SensorSuhu {
public:
    float bacaSuhu() {
        // Simulasi suhu antara 20.0 - 35.0 derajat
        return 20.0f + (std::rand() % 150) / 10.0f;
    }
};

class SensorKelembapan {
public:
    float bacaKelembapan() {
        // 40.0 - 90.0
        return 40.0f + (std::rand() % 500) / 10.0f;
    }
};

void tulisCSV(const std::string& namaFile, float dataSuhu[], float dataKelembapan[], int jumlah) {
    std::ofstream file(namaFile);
    if (!file.is_open()) {
        std::cout << "Gagal menulis file!" << std::endl;
        return;
    }
    
    file << "ID,Suhu,Kelembapan" << std::endl;  // Header
    for (int i = 0; i < jumlah; i++) {
        file << (i+1) << "," << dataSuhu[i] << ","<< dataKelembapan[i] << std::endl;
    }
    file.close();
    std::cout << "Data disimpan ke " << namaFile << std::endl;
}

void bacaDanAnalisis(const std::string& namaFile) {
    std::ifstream file(namaFile);
    if (!file.is_open()) {
        std::cout << "File tidak ditemukan!" << std::endl;
        return;
    }
    
    std::string baris;
    std::getline(file, baris); // Lewati header
    
    float totalSuhu = 0.0f; float totalKelembapan = 0.0f;
    float maksSuhu = -100.0f;
    float minSuhu = 100.0f;
    int countSuhu = 0; int countKelembapan = 0;
    
    while (std::getline(file, baris)) {
        std::stringstream ss(baris);
        std::string idStr, suhuStr, kelembapanStr;
        
        std::getline(ss, idStr, ',');
        std::getline(ss, suhuStr, ',');
        std::getline(ss, kelembapanStr, ',');
        
        float suhu = std::stof(suhuStr);
        float kelembapan = std::stof(kelembapanStr);
        totalSuhu += suhu;
        totalKelembapan += kelembapan;
        if (suhu > maksSuhu) maksSuhu = suhu;
        if (suhu < minSuhu) minSuhu = suhu;
        countSuhu++;
        countKelembapan++;
        
        std::cout << "Data ke-" << idStr << ": " << suhu << " C, Kelembapan: " << kelembapan << std::endl;
    }
    file.close();
    
    std::cout << "\n===== ANALISIS =====" << std::endl;
    std::cout << "Suhu Tertinggi      : " << maksSuhu << " C" << std::endl;
    std::cout << "Suhu Terendah       : " << minSuhu << " C" << std::endl;
    std::cout << "Rata-rata Suhu      : " << (totalSuhu/countSuhu) << " C" << std::endl;
    std::cout << "Rata-rata Kelembapan: " << (totalKelembapan/countKelembapan) << std::endl;
}

int main() {
    std::srand(std::time(nullptr));
    
    const int JUMLAH_DATA = 10;
    float dataSuhu[JUMLAH_DATA];
    float dataKelembapan[JUMLAH_DATA]; // Array terpisah
    
    SensorSuhu sensorSuhu;
    SensorKelembapan sensorKelembapan;
    
    std::cout << ">>> Robot mulai mengambil data...\n" << std::endl;
    for (int i = 0; i < JUMLAH_DATA; i++) {
        dataSuhu[i] = sensorSuhu.bacaSuhu();
        dataKelembapan[i] = sensorKelembapan.bacaKelembapan();
        std::cout << "Data ke-" << (i+1) << ": Suhu " << dataSuhu[i] 
          << " C, Kelembapan " << dataKelembapan[i] << "%" << std::endl; // Mencetak float

    }
    
    std::cout << "\n>>> Menyimpan ke CSV...\n" << std::endl;
    tulisCSV("data_suhu.csv", dataSuhu, dataKelembapan, JUMLAH_DATA);
    
    std::cout << "\n>>> Membaca dan menganalisis file...\n" << std::endl;
    bacaDanAnalisis("data_suhu.csv");
    
    return 0;
}