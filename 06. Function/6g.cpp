#include <iostream>
#include <string>

void hitungMundur(int n) {
    std::cout << n << " ";
    if (n == 0) {
        return;
    } else {
        hitungMundur(n-1);
    }
}

int main() {
    hitungMundur(5);

    return 0;
}

