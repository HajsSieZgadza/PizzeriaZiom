#include "Pizza.h"
using namespace std;
#include <sstream>

Pizza::Pizza() {};
Pizza::Pizza(string _nazwa, double _cena)
{
	nazwa = _nazwa;
	cena = _cena;
}
void Pizza::wypiszMenu()
{
	for (int i = 1; i < iloscPizzy(); i++)
	{
		cout << i << ") " << pizze[i].nazwa << " " << pizze[i].cena << " " << pizze[i].cena * 2 << " " << pizze[i].cena * 3 << endl;
	}
}

void Pizza::wczytajMenu(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream bob(linie);
		string nazwa;
		double cena;
		bob >> nazwa;
		bob.ignore();
		bob >> cena;
		pizze.push_back(Pizza(nazwa, cena));
	}
	plik.close();
}
int Pizza::iloscPizzy()
{
	return pizze.size();
}
string Pizza::wybierzPizze(int jaka)
{
	
	string nazwa1;
	for (int i = 1; i < iloscPizzy(); i++)
	{
		if (i == jaka)
		{
			nazwa1 = pizze[i].nazwa;
			break;
		}
	}
	
	return nazwa1;
	
}

double Pizza::dobierzCene(int jaka,int roz)
{
	double cena1;
	for (int i = 1; i < iloscPizzy(); i++)
	{
		if (i==jaka)
		{
			cena1 = pizze[i].cena;
		}
	}
	switch (roz)
	{
	case 1:
	{
		cena1 = cena1 * 1;
	}
	break;
	case 2:
	{
		cena1 = cena1 * 2;
	}
	break;
	case 3:
	{
		cena1 = cena1 * 3;
	}
	break;
	default:
		break;
	}
	return cena1;
}