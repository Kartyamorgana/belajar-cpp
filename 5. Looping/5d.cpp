#include <iostream>
#include <string>

int main() {
    const int PIN_BENAR = 1234;
    int pinInput;

    do {
        std::cout << "Masukkan PIN: ";
        std::cin >> pinInput;

        if (pinInput != PIN_BENAR) {
            std::cout << "PIN salah, coba lagi." << std::endl;
        }
    } while (pinInput != PIN_BENAR);
    std::cout << "Login berhasil!" << std::endl;

    return 0;
}

