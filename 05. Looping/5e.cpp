#include <iostream>
#include <string>

int main() {
    for (int i = 1; i < 21; i++) {
        if (i % 5 == 0) {
            break;
        } else if (i % 2 == 0) {
            continue;
        } else {
            std::cout << i << " ";
        }
    }

    return 0;
}

