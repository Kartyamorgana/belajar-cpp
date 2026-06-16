#include <iostream>
#include <string>

int tambah(int a, int b) {
    return a + b;
}

float tambah(float a, float b) {
    return a + b;
}

std::string tambah(std::string a, std::string b) {
    return a + b;
}

int main() {
    std::cout << "Integer: " << tambah(6, 7) << std::endl;
    std::cout << "Float: " << tambah(6.0f, 7.0f) << std::endl;
    std::cout << "String: " << tambah("6", "7") << std::endl;

    return 0;
}

