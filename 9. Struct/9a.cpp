#include <iostream>
#include <string>

struct RobotStatus {
    int posisiX;
    int posisiY;
    std::string arah;
    float baterai;
};

int main() {
    RobotStatus robot1 = {10, 20, "TIMUR", 85.5};

    std::cout << "== DATA ROBOT ===" << std::endl;
    std::cout << "Posisi: (" << robot1.posisiX << ", " << robot1.posisiY << ")" << std::endl;
    std::cout << "Arah: " << robot1.arah << std::endl;
    std::cout << "Baterai: " << robot1.baterai << "%" << std::endl;

    return 0;
}