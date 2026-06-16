#include <iostream>
#include <string>

int main() {
    int nilaiTeori = 85; int nilaiPraktek = 90; int jumlahUjian = 2;

    float hasil = (nilaiTeori + nilaiPraktek) / static_cast<float>(jumlahUjian);

    std::cout << "Rata-rata (float): " << hasil << std::endl;

    int hasilint = static_cast<int>(hasil);

    std::cout << "Rata-rata (int): " << hasilint << std::endl;

    return 0;
}

