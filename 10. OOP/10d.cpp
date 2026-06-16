#include <iostream>

class ServoMotor {
private:
    int pin;
    int sudut;

public:
    ServoMotor(int p) {
        pin = p;
        sudut = 0;
        std::cout << "Servo di pin " << pin << " siap di sudut 0 derajat." << std::endl;
    }

    void setSudut(int s) {
        if (s >= 0 && s <= 180) {
            sudut = s;
            std::cout << "Servo pin " << pin << " bergerak ke " << s << " derajat." << std::endl;
        } else {
            std::cout << "Servo di pin " << pin << ". Sudut tidak valid! Harus 0-180." << std::endl;
        }
    }

    int getSudut() {
        return sudut;
    }
};

int main() {
    ServoMotor servo1(1);
    ServoMotor servo2(2);

    servo1.setSudut(100);
    servo2.setSudut(999);

    std::cout << "Sudut Servo 1: " << servo1.getSudut() << std::endl;
    std::cout << "Sudut Servo 2: " << servo2.getSudut() << std::endl;

    return 0;
}