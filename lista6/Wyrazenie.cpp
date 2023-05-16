#include "Operator2arg.hpp"

int main()
{
	Liczba a(1);
	Liczba b(2);
	Stala pi(M_PI, "pi");
	Stala E(M_E, "e");
	
	zmienna Z = zmienna();
	Z.dodaj("x", 0);
	Z.dodaj("y", 0);

	for (int i = 0; i <= 10; i++) {

		Z.zmodyfikuj("x", (double)i / 10);
		Z.zmodyfikuj("y", (double)i / 10);

		//((x - 1) * x) / 2
		Zmienna x("x");
		Odejmowanie x1(&x, &a);
		Mnozenie x2(&x1, &x);
		Dzielenie x3(&x2, &b);
		cout << x3.zapis() << "    " << x3.oblicz() << '\n';


		//	(3 + 5) / (2 + x * 7)
		Liczba c(3);
		Liczba f(5);
		Liczba e(7);
		Dodawanie y1(&c, &f);
		Mnozenie y2(&x, &e);
		Dodawanie y3(&b, &y2);
		Dzielenie y4(&y1, &y3);
		cout << y4.zapis() << "    " << y4.oblicz() << '\n';

		//	2 + x * 7 - (y * 3 + 5)

		Zmienna y("y");
		Mnozenie z1(&y, &c);
		Dodawanie z2(&z1, &f);
		Odejmowanie z3(&y3, &z2);
		cout << z3.zapis() << "    " << z3.oblicz() << '\n';

		//	cos((x + 1) * pi) / e ^ x ^ 2

		Dodawanie q1(&x, &a);
		Cosinus cos(&q1);
		Mnozenie co(&cos, &pi);
		Potegowanie pot(&x, &b);
		Potegowanie po(&E, &pot);
		Dzielenie q2(&co, &po);

		cout << q2.zapis() << "    " << q2.oblicz() << '\n';
	}
}