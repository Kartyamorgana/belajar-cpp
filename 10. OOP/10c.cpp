#include <iostream>

class LED {
private:
    bool status;

public:
    void nyalakan() {
        status = true;
        std::cout << "Lampu dinyalakan." << std::endl;
    }

    void matikan() {
        status = false;
        std::cout << "Lampu dimatikan." << std::endl;
    }

    bool isNyala() {
        return status;
    }
};

int main() {
    LED led1;

    led1.nyalakan();
    std::cout << "Status: " << (led1.isNyala() ? "Nyala" : "Mati") << std::endl;
    led1.matikan();

    return 0;
}

