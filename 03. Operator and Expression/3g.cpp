#include <iostream>
#include <string>

int main() {
    int a = 10, b = 4, c = 2;
    bool hasil1 = (a + b * c) > (a / c);
    bool hasil2 = b != c;
    bool hasil3 = hasil1 && hasil2;

    std::cout << "b x c: " << b * c << std::endl;
    std::cout << "a + (b x c): " << a + (b*c) << std::endl;
    std::cout << "a / c: " << a / c << std::endl;
    std::cout << "(a + b x c) > (a / c): " << hasil1 << std::endl;
    std::cout << "b != c: " << hasil2 << std::endl;
    std::cout << "hasil1 && hasil1: " << hasil3 << std::endl;

    return 0;
}

