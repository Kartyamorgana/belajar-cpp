#include <iostream>
#include <string>

int main() {
    std::string kata1 = "Robot";
    std::string kata2 = "Cerdas";

    std::string gabungan = kata1 + " " + kata2;
    int panjangKata = gabungan.length();

    std::cout << gabungan << std::endl;
    std::cout << "Panjang karakter: " << panjangKata << std::endl;

    std::cout << "Karakter pertama: " << gabungan[0] << std::endl;
    std::cout << "Karakter terakhir: " << gabungan[panjangKata - 1] << std::endl;

    return 0;
}

