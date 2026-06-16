#include <iostream>

void kurangi(int* ptr) {
    if (ptr != nullptr) {
        --(*ptr);
    } else {
        std::cout << "Pointer kosong, tidak bisa mengurangi." << std::endl;
    }
}

int main() {
    int x = 10;
    
    std::cout << "Sebelum dikurangi: " << x << std::endl;
    kurangi(&x);
    std::cout << "Setelah dikurangi: " << x << std::endl;

    std::cout << "\n=== NullPtr ===" << std::endl;
    kurangi(nullptr);

    return 0;
}