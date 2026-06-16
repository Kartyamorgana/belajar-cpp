#include <iostream>
#include <string>

int main() {
    for (int x = 0; x <= 2; x++) {
        for (int y = 0; y <= 2; y++) {
            std::cout << "(" << x << "," << y << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}

