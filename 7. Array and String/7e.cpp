#include <iostream>
#include <cstring>
#include <string>

int main() {
    std::cout << "=== C-STRING ===" << std::endl;
    char perintah[15] = "STOP";
    std::cout << perintah << std::endl;
    std::cout << "Panjang: " << strlen(perintah) << std::endl;

    strcat(perintah, " MESIN");

    std::cout << perintah << std::endl;

    std::cout << "\n=== STD::STRING ===" << std::endl;
    std::string perintahStd = "START";
    std::cout << perintahStd << std::endl;
    std::cout << "Panjang: " << perintahStd.length() << std::endl;

    perintahStd = "RESET";
    perintahStd += " ROBOT";
    std::cout << perintahStd << std::endl;
    
    return 0;
}

