#include "kolejka.hpp"

Kolejka::~Kolejka() {
    delete[] kolejka;
}
void Kolejka::wstaw(string napis) {
    if (ile == pojemnosc)
        throw invalid_argument("Za duzo elementow w kolejce");
    kolejka[ile - poczatek] = napis;
    ile++;
}
string Kolejka::usun() {
    if (ile == 0) { throw invalid_argument("Nie ma nic w kolejce"); }
    string usuwany = kolejka[poczatek];
    poczatek++;
    poczatek %= pojemnosc;
    ile--;
    return usuwany;
}
string Kolejka::zprzodu() {
    return kolejka[poczatek];
}
int Kolejka::dlugosc() {
    return ile;
}

Kolejka::Kolejka(int rozmiar) {
    if (rozmiar <= 0) {
        throw invalid_argument("Niedodatni rozmiar");
    }
    pojemnosc = rozmiar;
    kolejka = new string[rozmiar];
    ile = 0;
    poczatek = 0;
}

Kolejka::Kolejka(Kolejka& kop) {
    kolejka = new string[kop.pojemnosc];
    pojemnosc = kop.pojemnosc;
    for (int i = 0; i < pojemnosc; i++) {
        kolejka[i] = kop.kolejka[i];
    }
    poczatek = kop.poczatek;
    ile = kop.ile;
}

Kolejka::Kolejka(Kolejka&& kol) {
    poczatek = kol.poczatek;
    pojemnosc = kol.pojemnosc;
    ile = kol.ile;
    kolejka = kol.kolejka;
    kol.kolejka = nullptr;
}
const Kolejka& Kolejka::operator = (const Kolejka& kol) {
    if (this == &kol) return *this;
    this->~Kolejka();
    pojemnosc = kol.pojemnosc;
    poczatek = kol.poczatek;
    ile = kol.ile;
    kolejka = new string[pojemnosc];
    for (int i = 0; i < pojemnosc; i++) {
        kolejka[i] = kol.kolejka[i];
    }
    return *this;
}

const Kolejka& Kolejka::operator = (Kolejka&& kol) {
    if (this == &kol) return *this;
    ile = kol.ile;
    poczatek = kol.poczatek;
    pojemnosc = kol.pojemnosc;
    kolejka = kol.kolejka;
    return *this;
}

Kolejka::Kolejka(initializer_list<string> napisy) {
    poczatek = ile = 0;
    pojemnosc = napisy.size();
    kolejka = new string[napisy.size()];
    for (string pom : napisy) {
        kolejka[ile++] = pom;
    }
}
