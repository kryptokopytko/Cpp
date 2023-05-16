#ifndef KOLEJKA
#define KOLEJKA

#include <iostream>
using namespace std;


class Kolejka
{
    string* kolejka;
    int pojemnosc, poczatek = 0, ile = 0;
public:
    Kolejka(int rozmiar);
    Kolejka(Kolejka& kop);
    Kolejka(Kolejka&& kol);
    const Kolejka& operator = (const Kolejka& kol);
    const Kolejka& operator = (Kolejka&& kol);
    Kolejka(initializer_list<string> napisy);
    ~Kolejka();
    void wstaw(string napis);
    string usun();
    string zprzodu();
    int dlugosc();
};

#endif