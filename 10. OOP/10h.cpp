#include <iostream>
#include <string>

class Bentuk {
public:
    virtual void gambar() {
        std::cout << "Menggambar bentuk." << std::endl;
    }
};

class Lingkaran : public Bentuk {
    void gambar() override {
        std::cout << "Menggambar lingkaran ⭕." << std::endl;
    }
};

class Persegi : public Bentuk {
    void gambar() override {
        std::cout << "Menggambar persegi ◼️." << std::endl;
    }
};

int main() {
    Bentuk* bentuk[3];

    bentuk[0] = new Bentuk();
    bentuk[1] = new Lingkaran();
    bentuk[2] = new Persegi();

    for (int i = 0; i < 3; i++) {
        bentuk[i]->gambar();
        delete bentuk[i];
    }

    return 0;
}