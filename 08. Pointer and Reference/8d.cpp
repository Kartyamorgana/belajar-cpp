#include <iostream>

void koreksi(float& nilai, float faktor) {
    nilai *= faktor;
}

int main() {
    float bacaan = 100.0f;

    std::cout << "Sebelum koreksi: " << bacaan << std::endl;
    koreksi(bacaan, 1.1f);
    std::cout << "Setelah koreksi: " << bacaan << std::endl;

    return 0;
}