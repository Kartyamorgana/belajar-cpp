#include <iostream>
#include <string>

int main() {
    bool bateraiRendah = false;
    bool sensorOk = true;
    bool modeLatihan = true;

    if (!bateraiRendah && (sensorOk || modeLatihan)) {
        std::cout << "Robot boleh masuk arena." << std::endl;
    } else {
        std::cout << "Robot tidak boleh masuk arena!" << std::endl;
    }

    return 0;
}

