#include "klasa_zbior_zmiennych.hpp"



void zbior_zmiennych::wstaw(string Nazwa, double war)
{
    if (czy_istnieje(Nazwa) == true)
    {
        throw invalid_argument("Nazwa juz istnieje");
        return;
    }
    if (liczba_zmiennych == n)
    {
        cerr << "za duzo elementow w zbiorze";
        return;
    }
    tab[liczba_zmiennych] = Zmienna(Nazwa, war);
    liczba_zmiennych++;
}

void zbior_zmiennych::usun(string Nazwa)
{
    if (czy_istnieje(Nazwa) == false)
    {
        cerr << "Nie ma takiej zmiennej";
        return;
    }
    int i = 0;
    for (i; i < liczba_zmiennych; i++)
        if (tab[i].getNazwa() == Nazwa)
            break;
    tab[liczba_zmiennych - 1] = Zmienna("cokolwiek", 0.0);
    for (i; i < liczba_zmiennych; i++)
        tab[i] = tab[i + 1];
    liczba_zmiennych--;

}

double zbior_zmiennych::odczyt(string Nazwa)
{
    for (int i = 0; i < liczba_zmiennych; i++)
        if (tab[i].getNazwa() == Nazwa)
            return tab[i].getWartosc();
    throw invalid_argument("Nie ma takiej zmiennej");
}

void zbior_zmiennych::modyfikacja(string Nazwa, double war)
{
    for (int i = 0; i < liczba_zmiennych; i++)
        if (tab[i].getNazwa() == Nazwa) {
            tab[i].setWartosc(war);
            return;
        }
    zbior_zmiennych::wstaw(Nazwa, war);
}

zbior_zmiennych::~zbior_zmiennych() {
    delete[] tab;
}

zbior_zmiennych::zbior_zmiennych(const int rozmiar) : n(rozmiar) {
    if (rozmiar <= 0) {
        throw invalid_argument("Niedodatni rozmiar");
    }
    tab = new Zmienna[rozmiar];
    liczba_zmiennych = 0;
}

bool zbior_zmiennych::czy_nowa(Zmienna* nowa) {
    for (int i = 0; i < liczba_zmiennych; i++)
        if (tab[i].getNazwa() == nowa->getNazwa())
            return false;
    return true;
}

bool zbior_zmiennych::czy_istnieje(string Nazwa) {
    for (int i = 0; i < liczba_zmiennych; i++)
        if (tab[i].getNazwa() == Nazwa)
            return true;
    return false;
}

void zbior_zmiennych::wstaw_ze_wskaznika(Zmienna* nowa) {
    if (czy_nowa(nowa) == 0)
    {
        throw invalid_argument("Nazwa juz istnieje");
        return;
    }
    if (liczba_zmiennych == n)
    {
        throw invalid_argument("za duzo elementow w zbiorze");
        return;
    }
    tab[liczba_zmiennych] = *nowa;
    liczba_zmiennych++;
}