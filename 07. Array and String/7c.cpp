#include <iostream>
#include <string>

int main() {
    float suhu[7] = {24.5f, 26.0f, 25.5f, 28.0f, 27.5f, 23.0f, 30.0f};
    float max = 0.0f;
    int indexMax = 0;
    int count = 0;

    std::cout << "=== ARRAY SUHU ===" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << "  Hari ke-" << i+1 << ": " << suhu[i] << " °C" << std::endl;

        if (suhu[i] > max) {
            max = suhu[i];
            indexMax = i;
        }

        if (suhu[i] > 26.0f) {
            count++;
        }
    }

    std::cout << "Suhu tertinggi: " << max << " (Hari ke-" << indexMax+1 << ")" << std::endl;

    std::cout << "Hari dengan suhu diatas 26°C: " << count << std::endl;
    
    return 0;
}

