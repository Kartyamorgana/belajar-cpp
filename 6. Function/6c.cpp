#include <iostream>
#include <string>

void tampilkanStatus(bool online, int baterai) {
    if (online) {
        std::cout << "Robot ONLINE" << std::endl;
    } else {
        std::cout << "Robot OFFLINE" << std::endl;
    }
    std::cout << "Baterai: " << baterai << "%" << std::endl;
}

int main() {
    tampilkanStatus(true, 80);
    tampilkanStatus(false, 15);

    return 0;
}

