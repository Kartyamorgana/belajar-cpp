#include <iostream>
#include <string>

int main() {
    int skor;

    std::cout << "Masukkan skor (0-100): ";
    std::cin >> skor;

    std::string status = (skor >= 75) ? "Lulus" : "Coba lagi";

    std::cout << status << std::endl;

    return 0;
}

