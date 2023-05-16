#ifndef KLASY
#define KLASY

#include <iostream>
#include "zmienna.hpp"
using namespace std;

class zbior_zmiennych {
    const int n;
    Zmienna* tab;
public:
    int liczba_zmiennych;
    zbior_zmiennych(const int rozmiar);
    ~zbior_zmiennych();
    bool czy_nowa(Zmienna* nowa);
    bool czy_istnieje(string Nazwa);
    void wstaw_ze_wskaznika(Zmienna* nowa);
    void wstaw(string Nazwa, double war);
    void usun(string Nazwa);
    double odczyt(string Nazwa);
    void modyfikacja(string Nazwa, double war);
};

#endif
