#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int64_t> rozklad_na_czynniki_pierwsze(int64_t n)
{
	vector<int64_t> rozklad;
	if (n == 0)
	{
		rozklad.push_back(0);
		return rozklad;
	}
	if (n == 1)
	{
		rozklad.push_back(1);
		return rozklad;
	}
	if (n == -1)
	{
		rozklad.push_back(-1);
		return rozklad;
	}
	if (n < 0)
	{
		n *= -1;
		rozklad.push_back(-1);
	}
	for (int i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			rozklad.push_back(i);
			n /= i;
		}
	}
	return rozklad;
}


void wypisz_czynniki(int64_t n, vector<int64_t> rozklad)
{
	size_t rozmiar = rozklad.size();
	cout << n << '=';
	for (int i = 0; i < rozmiar - 1; i++)
		cout << rozklad[i] << '*';
	cout << rozklad[rozmiar - 1] << '\n';
}

void zadanie(int argc, char* argv[])
{
	if (argc == 1)
	{		
		cerr<< "Nalezy wpisac ciag liczb oddzielonych pojedyncza spacja w jednej linii";
		return;
	}
	for (int i = 1; i < argc; i++) 
	{
		int64_t liczba = stoll(argv[i]);
		wypisz_czynniki(liczba, rozklad_na_czynniki_pierwsze(liczba));
	}
}

int main(int argc, char* argv[])
{
	zadanie( argc, argv);
}