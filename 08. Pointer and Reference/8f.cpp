#include <iostream>

int main() {
    int n;

    std::cout << "Jumlah jarak: ";
    std::cin >> n;

    if (n != 0) {
        float* jarak = new float[n];

        for (int i = 0; i < n; i++) {
            std::cout << "Isi jarak ke-" << i+1 << ": ";
            std::cin >> jarak[i];
        }

        float max = jarak[0];
        int idMax = 0;
        std::cout << "\nData yang tersimpan: " << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "  Jarak ke-" << i+1 << ": " << jarak[i] << std::endl;

            if (jarak[i] > max) {
                max = jarak[i];
                idMax = i;
            }
        }
        std::cout << "Jarak terjauh: " << max << " (Data ke-" << idMax + 1 << ")" << std::endl;

        delete[] jarak;
        jarak = nullptr;
    } else {
        std::cout << "Jumlah jarak 0! Tidak ada yang bisa dijalankan." << std::endl;
    }

    return 0;
}