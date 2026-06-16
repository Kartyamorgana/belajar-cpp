#include <iostream>
#include <string>

int main() {
    const float PI = 3.14159f;
    const float jariJari = 10.0f;
    float keliling = 2 * PI * jariJari;

    std::cout << "Keliling lingkaran: " << keliling << std::endl;

    // PI = 5.0f; -> Error karena const tidak bisa diubah

    return 0;
}


