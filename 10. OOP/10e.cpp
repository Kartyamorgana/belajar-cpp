#include <iostream>

class Baterai {
private:
    float persen;

public:
    Baterai() {
        persen = 100.0f;
        std::cout << "Baterai di-set ke 100%!" << std::endl;
    }

    void pakai(float p) {
        if (p >= persen) {                // Jika pemakaian >= sisa
            persen = 0;
            std::cout << "Baterai di pakai sebanyak " << p 
                    << "%! BATERAI HABIS!" << std::endl;
        } else {                          // Jika pemakaian < sisa
            persen -= p;
            std::cout << "Baterai di pakai sebanyak " << p 
                    << "%! Sisa baterai: " << persen << "%" << std::endl;
        }
    }

    float getPersen() {
        return persen;
    }
};

int main() {
    Baterai bat;

    bat.pakai(30.0);
    bat.pakai(80.0);

    std::cout << "SISA BATERAI SEKARANG: " << bat.getPersen() << std::endl;

    return 0;
}