#include <iostream>
#include <string>

int main() {
    float suhuGrid[2][3] = {
        {28.5f, 29.0f, 30.2f},
        {27.8f, 26.5f, 25.0f}
    };
    float total = 0.0f;

    std::cout << "=== Grid Suhu ===" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << suhuGrid[i][j] << " ";
            total += suhuGrid[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "Rata-rata suhu: " << total / 6.0f << std::endl;
    
    return 0;
}

