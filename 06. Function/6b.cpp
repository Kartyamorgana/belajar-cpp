#include <iostream>
#include <string>

int kali(int x, int y);

int main() {
    int hasilKali = kali(4, 5);
    std::cout << "Hasil: " << hasilKali << std::endl;

    return 0;
}

int kali(int x, int y) {
    return x * y;
}

