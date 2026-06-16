#include <iostream>
#include <string>

int main() {
    int a = 7;
    int b = 11;

    bool kasus1 = a == b;
    bool kasus2 = a != b;
    bool kasus3 = a > b;
    bool kasus4 = a < b;
    bool kasus5 = a >= b;
    bool kasus6 = a <= b;

    std::cout << "a == b? " << kasus1 << std::endl;
    std::cout << "a != b? " << kasus2 << std::endl;
    std::cout << "a > b? " << kasus3 << std::endl;
    std::cout << "a < b? " << kasus4 << std::endl;
    std::cout << "a >= b? " << kasus5 << std::endl;
    std::cout << "a <= b? " << kasus6 << std::endl;

    return 0;
}

