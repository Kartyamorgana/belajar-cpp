#include <iostream>
#include <string>

int hitungan = 0;

void tambahHitungan() {
    hitungan++;
}

int main() {
    tambahHitungan();
    tambahHitungan();
    tambahHitungan();

    std::cout << "Hitungan saat ini: " << hitungan << std::endl;

    return 0;
}

