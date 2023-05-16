#include "klasa_zbior_zmiennych.hpp"


Zmienna::Zmienna() {
    nazwa = "_";
}
Zmienna::Zmienna(string nazw) {
    nazwa = nazw;
    wartosc = 0;
}
Zmienna::Zmienna(string nazw, double war) {
    nazwa = nazw;
    wartosc = war;
}

string Zmienna::getNazwa() {
    return nazwa;
}

double Zmienna::getWartosc() {
    return wartosc;
}

void Zmienna::setWartosc(double war) {
    wartosc = war;
}