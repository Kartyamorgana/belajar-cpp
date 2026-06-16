#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

int main() {
    std::string data = "SUHU:36.5:LEMBAB:80";

    int pos1 = data.find(":");
    int pos2 = data.find(":", pos1 + 1);
    int pos3 = data.find(":", pos2 + 1);
    int pos4 = data.find(":", pos3 + 1);

    std::string jenis = data.substr(0, pos1);
    std::cout << "Jenis data pertama: " << jenis << std::endl;

    std::cout << "Nilai pertama: " << data.substr(pos1 + 1, pos2 - pos1 - 1) << std::endl;
    
    std::cout << "Jenis data kedua: " << data.substr(pos2 + 1, pos3 - pos2  - 1) << std::endl;

    std::cout << "Nilai kedua: " << data.substr(pos3 + 1) << std::endl;

    std::string terbalik = jenis;
    std::reverse(terbalik.begin(), terbalik.end());
    std::cout << "Terbalik: " << terbalik << std::endl;
    
    return 0;
}

