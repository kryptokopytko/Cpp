#ifndef TABBIT
#define TABBIT

#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;

class tabbit {
	
	typedef uint64_t slowo; // komorka w tablicy
	static const int rozmiarSlowa; // rozmiar slowa w bitach
	friend istream& operator >> (istream& we, tabbit& tb);
	friend ostream& operator << (ostream& wy, const tabbit& tb);

	class ref {
	public:
		bool getbit(uint64_t* tab, int index);
		void setbit(uint64_t* tab, int index, bool val);
		uint64_t& getptr(uint64_t* tab, int i);
	};

protected:
	int dl; // liczba bitów
	slowo* tab; // tablica bitów

public:
	explicit tabbit(int rozm);  // wyzerowana tablica bitow [0...rozm]
	explicit tabbit(slowo tb); // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
	explicit tabbit(initializer_list<bool> list);

	~tabbit(); // destruktor
	tabbit(const tabbit& tb); // konstruktor kopiujący
	tabbit(tabbit&& tb);     // konstruktor przenoszący

	tabbit& operator = (const tabbit& tb); // przypisanie kopiujące
	tabbit& operator = (tabbit&& tb);     // przypisanie przenoszące

private:
	bool czytaj(int i) const;  // metoda pomocnicza do odczytu bitu
	void pisz(int i, bool b); // metoda pomocnicza do zapisu bitu

public:
	bool operator [] (int i) const; // indeksowanie dla stałych tablic bitowych
	uint64_t& operator [] (int i);       // indeksowanie dla zwykłych tablic bitowych
	inline int rozmiar() const;   // rozmiar tablicy w bitach

	// operatory bitowe: | i |=, & i &=, ^ i ^= oraz !

	friend tabbit operator | (const tabbit& u, const tabbit& v);
	friend tabbit operator & (const tabbit& u, const tabbit& v);
	friend tabbit operator ^ (const tabbit& u, const tabbit& v);

	tabbit& operator |= (const tabbit& v);
	tabbit& operator &= (const tabbit& v);
	tabbit& operator ^= (const tabbit& v);
	tabbit operator ! ();
	
};

#endif