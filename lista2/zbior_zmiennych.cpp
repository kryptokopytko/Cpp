#include <iostream>
#include "klasa_zbior_zmiennych.hpp"
using namespace std;


int main()
{
    const int rozmiar = 12;
    zbior_zmiennych zbior = zbior_zmiennych(rozmiar);
    zbior.wstaw("przyklad", 1234.56789);
    cout << zbior.odczyt("przyklad") << '\n';
    zbior.wstaw("kopytko", 4224.4224);
    cout << zbior.odczyt("kopytko") << '\n';

    if (zbior.czy_istnieje("kopytko"))
        cout << "Istnieje kopytko\n";
    if (zbior.czy_istnieje("Kopytko") == 0)
        cout << "Nie istnieje Kopytko\n";

    zbior.modyfikacja("kopytko", 12345678.87654);
    cout << zbior.odczyt("kopytko") << '\n';

    zbior.usun("kopytko");
    if (zbior.czy_istnieje("kopytko"))
        cout << "Istnieje kopytko\n";
    else
        cout << "Juz nie istnieje kopytko\n";


}