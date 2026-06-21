#include <iostream>
#include <fstream>  
#include <string>
#include <cstdlib>
#include <ctime>    

int main() {
    // 1. Inisialisasi seed
    std::srand(std::time(nullptr));

    // 2. Format nama file baru
    std::time_t sekarang = std::time(nullptr);
    std::tm* info_waktu = std::localtime(&sekarang);
    
    char buffer_tanggal[9];
    std::strftime(buffer_tanggal, sizeof(buffer_tanggal), "%Y%m%d", info_waktu);
    std::string nama_file_baru = "log_suhu_" + std::string(buffer_tanggal) + ".txt";

    // 3. Buka file BARU untuk ditulis
    std::ofstream file_baru(nama_file_baru);

    if (!file_baru.is_open()) {
        std::cout << "Gagal membuat file baru!" << std::endl;
        return 1;
    }

    // 4. Tulis header
    file_baru << "===== LOG SUHU HARIAN =====" << std::endl;
    file_baru << "Waktu\t\tSuhu (C)" << std::endl;
    file_baru << "---------------------------" << std::endl;

    // 5. Tulis 10 data suhu acak
    for (int i = 8; i <= 17; i++) {
        float suhu = 25.0f + (rand() % 100) / 10.0f;
        file_baru << i << ":00\t\t" << suhu << std::endl;
    }

    // 6. Tutup dan cetak pesan sukses
    file_baru.close();
    std::cout << "File '" << nama_file_baru << "' berhasil dibuat dengan data acak!" << std::endl;

    return 0;
}