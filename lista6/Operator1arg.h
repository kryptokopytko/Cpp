#ifndef OPERATOR1
#define OPERATOR1

#include "Wyrazenie.hpp"

class Operator1arg : public Wyrazenie{
protected:
	Wyrazenie* wyr;
};

class ZmianaZnaku : public Operator1arg {
public:
	ZmianaZnaku(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return (-1) * wyr->oblicz(); }
	string zapis() override { return "(-1) * " + wyr->zapis(); }
};


class Sinus : public Operator1arg {
public:
	Sinus(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return sin(wyr->oblicz()); }
	string zapis() override { return "sin(" + wyr->zapis() + ")"; }
};

class Cosinus : public Operator1arg {
public:
	Cosinus(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return cos(wyr->oblicz()); }
	string zapis() override { return "cos(" + wyr->zapis() + ")"; }
};

class Tangens : public Operator1arg {
public:
	Tangens(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return tan(wyr->oblicz()); }
	string zapis() override { return "tan(" + wyr->zapis() + ")"; }
};

class Logarytm : public Operator1arg {
public:
	Logarytm(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return log10(wyr->oblicz()); }
	string zapis() override { return "log10(" + wyr->zapis() + ")"; }
};

class LogarytmNaturalny : public Operator1arg {
public:
	LogarytmNaturalny(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return log(wyr->oblicz()); }
	string zapis() override { return "log(" + wyr->zapis() + ")"; }
};

class FunkcjaEksponencjonalna : public Operator1arg {
public:
	FunkcjaEksponencjonalna(Wyrazenie* w) { wyr = w; }
	double oblicz() override { return pow(M_E, wyr->oblicz()); }
	string zapis() override { return  "e ^ (" + wyr->zapis() + ")"; }
};

#endif
