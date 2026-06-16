#include <iostream>
#include <string>

int main() {
    int counter = 10;

    std::cout << "Nilai awal: " << counter << std::endl;

    ++counter;
    std::cout << "Nilai prefix: " << counter << std::endl;

    counter++;
    std::cout << "Nilai postfix: " << counter << std::endl;

    std::cout << "Nilai pengurangan prefix: " << --counter << std::endl;

    std::cout << "Nilai pengurangan postfix: " << counter-- << std::endl;

    std::cout << "Nilai akhir: " << counter << std::endl;

    return 0;
}

