#ifndef WYRAZENIE
#define WYRAZENIE

#define  _USE_MATH_DEFINES a
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;


class Wyrazenie {
public:
	virtual double oblicz() = 0;
	virtual string zapis() = 0;
	char op = '0';
	Wyrazenie& operator= (Wyrazenie&) = delete;
	Wyrazenie(const Wyrazenie&) = delete;
public:
	Wyrazenie() { op = '0'; }

};

class Liczba : public Wyrazenie {
	double liczba;
public:
	Liczba(double n)  { liczba = n; }
	double oblicz() override { return liczba; }
	string zapis() override { return to_string(liczba); }

};

class zmienna {
	static vector<pair <string, double>> zbior;
public:
	static void dodaj(string s, double v) {
		zbior.push_back(make_pair(s, v));

	}
	static void usun(string s) {
		for (vector<pair <string, double>>::iterator it = zbior.begin(); it != zbior.end(); ) {
			if (it->first == s) {
				it = zbior.erase(it);
			}
			else {
				++it;
			}
		}
	}
	static void zmodyfikuj(string s, double nv) {
		usun(s);
		dodaj(s, nv);
	}
	static void wypisz_ostatnie() {
		cout << zbior.back().first << ' ' << zbior.back().second << '\n';
	}
	static double znajdz(string name) {
		for (vector<pair <string, double>>::iterator it = zbior.begin(); it != zbior.end(); ) {
			if (it->first == name) {
				return it->second;
			}
			else {
				++it;
			}
		}
		return 0;
	}
};

vector <pair <string, double>> zmienna::zbior;

class Zmienna : public Wyrazenie {
	string nazwa;
public:
	Zmienna(string s) { nazwa = s; }
	double oblicz() override {
		zmienna A;
		return A.znajdz(nazwa);
	}
	string zapis() override { return nazwa; }
};

class Stala : public Wyrazenie {
protected:
	double wartosc;
	string nazwa;
public:
	Stala() { wartosc = 1; nazwa = "a"; }
	Stala(double n, string s) { wartosc = n; nazwa = s; }
	double oblicz() override { return wartosc; }
	string zapis() override { return nazwa; }

};

class Pi : public Stala {
public:
	Pi() { wartosc = M_PI; nazwa = "pi"; }
};

class Fi : public Stala {
public:
	Fi() { wartosc = (1 + (sqrt(5))) / 2; nazwa = "fi"; }
};

class E : public Stala {
public:
	E() { wartosc = M_E; nazwa = "e"; }
};




#endif
#pragma once
