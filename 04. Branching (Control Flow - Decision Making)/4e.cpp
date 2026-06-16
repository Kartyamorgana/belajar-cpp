#include <iostream>
#include <string>

int main() {
    int pilihan;

    std::cout << "MENU ROBOT: \n1. Maju\n2. Mundur\n3. Putar\n4. Diam\nMasukkan pilihan (1-4): ";
    std::cin >> pilihan;

    switch (pilihan) {
        case 1:
            std::cout << "Robot MAJU" << std::endl;
            break;
        case 2:
            std::cout << "Robot MUNDUR" << std::endl;
            break;
        case 3:
            std::cout << "Robot PUTAR" << std::endl;
            break;
        case 4:
            std::cout << "Robot DIAM" << std::endl;
            break;
        default:
            std::cout << "Input tidak valid!" << std::endl;
            break;
    }

    return 0;
}

