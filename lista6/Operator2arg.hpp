#ifndef OPERATOR2
#define OPERATOR2

#include "Operator1arg.h"

class Operator2arg : public Operator1arg {
protected:
	Wyrazenie* prawe, * lewe;
};

class Dodawanie : public Operator2arg {
public:
	Dodawanie(Wyrazenie* p, Wyrazenie* l) { prawe = p, lewe = l; op = '+'; }
	double oblicz() override { return prawe->oblicz() + lewe->oblicz(); }
	string zapis() override { 
		return  prawe->zapis() + " + " + lewe->zapis(); 
	}
};

class Odejmowanie : public Operator2arg {
public:
	Odejmowanie(Wyrazenie* p, Wyrazenie* l) { prawe = p, lewe = l; op = '+'; }
	double oblicz() override { return prawe->oblicz() - lewe->oblicz(); }
	string zapis() override { return  prawe->zapis() + " - " + lewe->zapis(); }
};

class Mnozenie : public Operator2arg {
public:
	Mnozenie(Wyrazenie* p, Wyrazenie* l) { prawe = p, lewe = l; op = '*'; }
	double oblicz() override { return prawe->oblicz() * lewe->oblicz(); }
	string zapis() override {
		string wynik;
		if (prawe->op == '0' || prawe->op == '*') wynik = prawe->zapis() + " * ";
		else wynik = "(" + prawe->zapis() + ") * ";
		if (lewe->op == '0' || lewe->op == '*') wynik += lewe->zapis();
		else wynik = "(" + lewe->zapis() + ")";

		return wynik;
	}
};

class Dzielenie : public Operator2arg {
public:
	Dzielenie(Wyrazenie* p, Wyrazenie* l) {
		prawe = p;
		lewe = l;
		op = '*';
	}
	double oblicz() override {
		if (lewe->oblicz() == 0)
			throw invalid_argument("DIVIDER CANNOT BE 0");
		string wynik;
		if (prawe->op == '0' || prawe->op == '*') wynik = prawe->zapis() + " / ";
		else wynik = "(" + prawe->zapis() + ") / ";
		if (lewe->op == '0' || lewe->op == '*') wynik += lewe->zapis();
		else wynik = "(" + lewe->zapis() + ")";

	}
	string zapis() override { return "(" + prawe->zapis() + " / " + lewe->zapis() + ")"; }
};

class Potegowanie : public Operator2arg {
public:
	Potegowanie(Wyrazenie* p, Wyrazenie* l) { prawe = p, lewe = l; op = '0'; }
	double oblicz() override { return pow(prawe->oblicz(), lewe->oblicz()); }
	string zapis() override { return prawe->zapis() + " ^ " + lewe->zapis(); }
};

#endif
