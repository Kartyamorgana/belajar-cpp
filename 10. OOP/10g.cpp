#include <iostream>
#include <string>

class RobotDasar {
protected:                     // Bisa diakses oleh class turunan
    std::string nama;
    int posisiX;
    int posisiY;

public:
    RobotDasar(std::string n) {
        nama = n;
        posisiX = 0;
        posisiY = 0;
        std::cout << "Robot " << nama << " dibuat di (0,0)." << std::endl;
    }

    void maju() {
        posisiX++;
        std::cout << nama << " maju ke X=" << posisiX << std::endl;
    }
};

class RobotTerbang : public RobotDasar {
public:
    RobotTerbang(std::string n) : RobotDasar(n) {}

    void terbang(int ketinggian) {
        posisiY += ketinggian;
        std::cout << nama << " terbang ke Y=" << posisiY << std::endl;
    }

    void info() {
        std::cout << "Robot " << nama << " | Posisi: (" << posisiX << "," << posisiY << ")" << std::endl;
    }
};

int main() {
    RobotTerbang r1("Superman");

    r1.info();
    r1.maju();
    r1.terbang(10);
    r1.info();

    return 0;
}