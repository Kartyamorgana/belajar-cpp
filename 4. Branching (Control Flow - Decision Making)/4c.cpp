#include <iostream>
#include <string>

int main() {
    int jarak;

    std::cout << "Masukkan jarak (cm): ";
    std::cin >> jarak;

    if (jarak < 10) {
        std::cout << "BAHAYA! Menabrak." << std::endl;
    } else if (jarak < 30) {
        std::cout << "HATI-HATI. Terlalu dekat." << std::endl;
    } else if (jarak < 60) {
        std::cout << "Aman, maju perlahan." << std::endl;
    } else {
        std::cout << "Jarak sangat aman, maju cepat." << std::endl;
    }
    std::cout << "Pemindaian selesai." << std::endl;

    return 0;
}

