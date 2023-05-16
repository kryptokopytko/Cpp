#include "kolejka.hpp"
int main()
{
    int rozmiar = 4;
    Kolejka kol = Kolejka(4);
    kol.wstaw("kopytko");
    kol.wstaw("kucyk");
    kol.wstaw("krowa");
    kol.wstaw("kapucyn");
    Kolejka nkol = Kolejka(kol);
    cout << "Usuwamy pierwszy element w kolejce: " << kol.usun() << '\n';
    cout << "Teraz pierwszy jest: " << kol.zprzodu() << ". Liczba elementow w kolejce to: " << kol.dlugosc() << '\n';
    cout << "Ale w kolejce, do ktorej skopiwalismy kol wczesniej nadal pierwszy jest: " << nkol.zprzodu() << '\n';
    Kolejka nowsza{ "kapcie", "kolorowe", "kosmyki" };
    cout << "W nowszej byly: " << nowsza.usun() << ' ' << nowsza.usun() << ' ' << nowsza.usun() << '\n';

}