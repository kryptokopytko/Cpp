#ifndef ZMIENNA
#define ZMIENNA

#include <iostream>
using namespace std;

class Zmienna {
private:
    string nazwa;
    double wartosc;
public:
    Zmienna();
    Zmienna(string nazw);
    Zmienna(string nazw, double war);
    string getNazwa();
    double getWartosc();
    void setWartosc(double war);
};

#endif
#pragma once
