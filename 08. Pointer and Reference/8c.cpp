#include <iostream>

int main() {
    float sensor[4] = {10.5f, 20.3f, 30.8f, 40.1f};
    float* ptr = sensor;

    std::cout << "=== AKSES DENGAN POINTER ===" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "*(ptr + " << i << ") = " << *(ptr + i) << std::endl;
    }

    std::cout << "\n=== LOOP DENGAN ptr++ ===" << std::endl;
    ptr = sensor;
    float* p = sensor;
    for (int i = 0; i < 4; i++) {
        std::cout << "*p = " << *p << std::endl;
        p++;
    }

    return 0;
}