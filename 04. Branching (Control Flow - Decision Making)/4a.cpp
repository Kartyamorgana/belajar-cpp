#include <iostream>
#include <string>

int main() {
    int bilangan;

    std::cout << "Masukkan bilangan: ";
    std::cin >> bilangan;

    if (bilangan % 2 == 0) {
        std::cout << "Bilangan yang dimasukkan adalah bilangan GENAP!" << std::endl;
    }
    std::cout << "Terima kasih" << std::endl;

    return 0;
}


