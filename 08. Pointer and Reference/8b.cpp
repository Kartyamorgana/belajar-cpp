#include <iostream>

int main() {
    float suhu = 27.5f;
    float* ptrSuhu = &suhu;

    std::cout << "Alamat suhu: " << &suhu << std::endl;
    std::cout << "Alamat suhu (lewat pointer): " << ptrSuhu << std::endl;
    std::cout << "Nilai suhu awal: " << *ptrSuhu << std::endl;

    *ptrSuhu = 99.9f;
    std::cout << "Nilai suhu akhir (pointer): " << *ptrSuhu << std::endl;
    std::cout << "Nilai suhu akhir (variabel): " << suhu << std::endl;

    return 0;
}