#include <iostream>
#include <string>

int main() {
    int skor[5] = {85, 92, 78, 95, 88};
    int total = 0;

    std::cout << "Skor robot: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "  Skor ke-" << i+1 << ": " << skor[i] << std::endl;
        total += skor[i];
    }
    std::cout << "Rata-rata skor: " << total / 5.0f << std::endl;

    return 0;
}

