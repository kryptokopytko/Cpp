#include "tabbit.hpp"

bool tabbit::ref::getbit(uint64_t* tab, int index) {
	return (tab[index / 8] & (1 << (index % 8)));
}
void tabbit::ref::setbit(uint64_t* tab, int index, bool val) {
	if (val == 0)
		tab[index / 8] & ~(1 << (index % 8));
	else
		tab[index / 8] | (1 << (index % 8));
}
uint64_t& tabbit::ref::getptr(uint64_t* tab, int index) {
	uint64_t& ptr = tab[index / 8];
	ptr = ptr << (index % 8);
	return ptr;
}

tabbit::tabbit(int rozmiar) { // wyzerowana tablica bitow [0...rozm]
	dl = rozmiar;
	tab = new slowo[rozmiar / 8 + 2];
	for (int i = 0; i < (rozmiar / 8 + 2); i++)
		tab[i] = 0;
}
tabbit::tabbit(slowo tb) { // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
	dl = sizeof(slowo) * sizeof(tb);
	int bajty = dl / 8 + 2;
	tab = new slowo[bajty];
	for (int i = 0; i < bajty; i++)
		tab[i] = 0;
}

tabbit::tabbit(initializer_list<bool> list) {
	dl = list.size();
	tab = new slowo[dl + 2];
	int i = 0;
	for (auto l : list) {
		pisz(i, l);
		i++;
	}
}

tabbit::~tabbit() { // destruktor
	delete[] tab;
	tab = nullptr;
}
tabbit::tabbit(const tabbit& tb) { // konstruktor kopiujacy
	dl = tb.dl;
	if (tab) delete[] tab;
	tab = new slowo[dl + 2];
	for (int i = 0; i < dl; i++)
		tab[i] = tb.tab[i];
}
tabbit::tabbit(tabbit&& tb) {     // konstruktor przenoszacy
	dl = tb.dl;
	tab = tb.tab;
	tb.dl = 0;
	tb.tab = nullptr;
}

bool tabbit::czytaj(int i) const {
	tabbit::ref pom;
	return pom.getbit(tab, i);
}
void tabbit::pisz(int i, bool b) {
	tabbit::ref pom;
	return pom.setbit(tab, i, b);
}

inline int tabbit::rozmiar() const {
	return dl;
}

//operatory

bool tabbit::operator[] (int i) const {
	return czytaj(i);
}

uint64_t& tabbit::operator[](int i)
{
	tabbit::ref tb;
	uint64_t& ptr = tb.getptr(tab, i);
	return ptr;
}
tabbit& tabbit::operator = (const tabbit& tb) {
	dl = tb.dl;
	delete[] tab;
	tab = new slowo[dl + 2];
	for (int i = 0; i < dl; i++)
		tab[i] = tb.tab[i];
	return *this;
}
tabbit& tabbit::operator = (tabbit&& tb) {
	dl = tb.dl;
	delete[] tab;
	tab = tb.tab;
	tb.tab = nullptr;
	tb.dl = 0;
	return *this;
}

 tabbit operator | (const tabbit& u, const tabbit& v) {
	 tabbit tb(max(u.dl, v.dl));
	 if (u.dl > v.dl) {
		 for (int i = 0; i < v.dl; i++)
			 tb.pisz(i, u[i] | v[i]);

		 for (int i = v.dl; i < u.dl; i++)
			 tb.pisz(i, u[i]);
	 }
	 else {
		 for (int i = 0; i < u.dl; i++)
			 tb.pisz(i, u[i] | v[i]);

		 for (int i = u.dl; i < v.dl; i++)
			 tb.pisz(i, v[i]);
	 }
	 return tb;
}
tabbit operator & (const tabbit& u, const tabbit& v) {
	tabbit tb(max(u.dl, v.dl));
	if (u.dl > v.dl) {
		for (int i = 0; i < v.dl; i++)
			tb.pisz(i, u[i] & v[i]);

		for (int i = v.dl; i < u.dl; i++)
			tb.pisz(i, u[i]);
	}
	else {
		for (int i = 0; i < u.dl; i++)
			tb.pisz(i, u[i] & v[i]);

		for (int i = u.dl; i < v.dl; i++)
			tb.pisz(i, v[i]);
	}
	return tb;
}
tabbit operator ^ (const tabbit& u, const tabbit& v) {
	tabbit tb(max(u.dl, v.dl));
	if (u.dl > v.dl) {
		for (int i = 0; i < v.dl; i++)
			tb.pisz(i, u[i] ^ v[i]);

		for (int i = v.dl; i < u.dl; i++)
			tb.pisz(i, u[i]);
	}
	else {
		for (int i = 0; i < u.dl; i++)
			tb.pisz(i, u[i] ^ v[i]);

		for (int i = u.dl; i < v.dl; i++)
			tb.pisz(i, v[i]);
	}
	return tb;
}

tabbit& tabbit::operator |= (const tabbit& v) {
	if (dl > v.dl) {
		for (int i = 0; i < v.dl; i++)
			pisz(i, czytaj(i) | v[i]);

		for (int i = v.dl; i < dl; i++)
			pisz(i, czytaj(i));
	}
	else {
		for (int i = 0; i < dl; i++)
			pisz(i, czytaj(i) | v[i]);

		for (int i = dl; i < v.dl; i++)
			pisz(i, v[i]);
	}
	return *this;
}
tabbit& tabbit::operator &= (const tabbit& v) {
	if (dl > v.dl) {
		for (int i = 0; i < v.dl; i++)
			pisz(i, czytaj(i) & v[i]);

		for (int i = v.dl; i < dl; i++)
			pisz(i, czytaj(i));
	}
	else {
		for (int i = 0; i < dl; i++)
			pisz(i, czytaj(i) & v[i]);

		for (int i = dl; i < v.dl; i++)
			pisz(i, v[i]);
	}
	return *this;
}
tabbit& tabbit::operator ^= (const tabbit& v) {
	if (dl > v.dl) {
		for (int i = 0; i < v.dl; i++)
			pisz(i, czytaj(i) ^ v[i]);

		for (int i = v.dl; i < dl; i++)
			pisz(i, czytaj(i));
	}
	else {
		for (int i = 0; i < dl; i++)
			pisz(i, czytaj(i) ^ v[i]);

		for (int i = dl; i < v.dl; i++)
			pisz(i, v[i]);
	}
	return *this;
}
tabbit tabbit::operator ! () {
	for (int i = 0; i < dl; i++)
		pisz(i, ~czytaj(i));
	return *this;
}



istream& operator >> (istream& we, tabbit& tb) {
	cout << "Rozmiar tablicy: ";
	we >> tb.dl;
	tabbit ttbb(tb.dl);
	return we;
}
ostream& operator << (ostream& wy, const tabbit& tb) {
	for (int i = 0; i < tb.dl; i++) {
		wy << tb.czytaj(i);
		if (i % 8 == 0)
			wy << ' ';
	}
	return wy;
}