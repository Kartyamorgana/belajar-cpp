#include <iostream>
#include <string>

int main() {
    int kecepatan = 50;

    std::cout << "Kecepatan awal: " << kecepatan << std::endl;

    kecepatan += 30;
    kecepatan -= 20;
    kecepatan *= 2;
    kecepatan %= 45;

    std::cout << "Sisa bagi 45: " << kecepatan << std::endl;

    return 0;
}

