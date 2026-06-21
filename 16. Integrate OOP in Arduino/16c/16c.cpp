#include "16c.h"

LED::LED(byte p) {
    pin = p;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void LED::nyalakan() {
    digitalWrite(pin, HIGH);
}

void LED::matikan() {
    digitalWrite(pin, LOW);
}

bool LED::apakahNyala() {
    return digitalRead(pin);
}