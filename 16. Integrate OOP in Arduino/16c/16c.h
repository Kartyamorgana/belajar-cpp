#ifndef FILE_16C_H
#define FILE_16C_H

#include <Arduino.h>

class LED {
    private:
        byte pin;

    public:
        LED (byte p);
        void nyalakan();
        void matikan();
        void apakahNyala();
};

#endif

