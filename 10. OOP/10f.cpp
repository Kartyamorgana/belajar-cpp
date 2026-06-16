#include <iostream>

class LED {
private:
    int pin;
    bool status;

public:
    LED(int p) {
        pin = p;
        status = false; 
        std::cout << "LED di pin " << pin << " siap digunakan. (Status: Mati)" << std::endl;
    }

    void nyalakan() {
        status = true;
        std::cout << "LED di pin " << pin << " dinyalakan." << std::endl;
    }

    void matikan() {
        status = false;
        std::cout << "LED di pin " << pin << " dimatikan." << std::endl;
    }

    ~LED() {
        matikan();
        std::cout << "LED di pin " << pin << " dihancurkan." << std::endl;
    }

    bool isNyala() {
        return status;
    }
};

int main() {
    LED led1(1);
    LED led2(2);

    std::cout << std::endl;
    led1.nyalakan();
    std::cout << "Status: " << (led1.isNyala() ? "Nyala" : "Mati") << std::endl;
    led1.matikan();

    {
        std::cout << std::endl;
        led2.nyalakan();
        std::cout << "Status: " << (led2.isNyala() ? "Nyala" : "Mati") << std::endl;
    }
    std::cout << std::endl;

    return 0;
}

