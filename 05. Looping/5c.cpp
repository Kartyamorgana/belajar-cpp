#include <iostream>
#include <string>

int main() {
    int tabungan = 0;
    int target = 100;
    int koinHarian;

    while (tabungan < target) {
        std::cout << "Masukkan koin hari ini: ";
        std::cin >> koinHarian;

        tabungan += koinHarian;
        std::cout << "Total tabungan: " << tabungan << std::endl;
    }
    std::cout << "Target tercapai! Robot bisa membeli suku cadang." << std::endl;

    return 0;
}

