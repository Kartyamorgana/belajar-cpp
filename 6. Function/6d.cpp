#include <iostream>
#include <string>

void cobaUbah(float suhu) {
    suhu = 99.9f;
    std::cout << "  Suhu saat fungsi: " << suhu << std::endl;
}

int main() {
    float suhuRUang = 27.5f;
    std::cout << "Suhu sebelum fungsi: " << suhuRUang << std::endl;

    cobaUbah(suhuRUang);

    std::cout << "Suhu setelah fungsi: " << suhuRUang << std::endl;

    return 0;
}

