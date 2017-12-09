#include "Dodatki.h"
#include <sstream>
#include <iostream>
using namespace std;

Dodatki::Dodatki() {};
Dodatki::Dodatki(string _nazwa, double _cena)
{
	nazwa = _nazwa;
	cena = _cena;
}
void Dodatki::wypiszDodatki(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream bolec(linie);
		string nazwa;
		double cena;
		bolec >> nazwa;
		bolec.ignore();
		bolec >> cena;
		dodatki.push_back(Dodatki(nazwa, cena));
	}
	plik.close();
}
int Dodatki::iloscDodatkow()
{
	return dodatki.size();
}

void Dodatki::wyswietlDodatki()
{
	for (int i = 0; i < iloscDodatkow();i++)
	{
		cout <<i+1<<") "<< dodatki[i].nazwa << " " << dodatki[i].cena << endl;
	}
}

void Dodatki::nazwaDodatku(int j)
{
	for (int i = 0; i < iloscDodatkow(); i++)
	{
		if (j == i)
		{
			dodatki[i].opcja = true;
		}
	}
}
double Dodatki::cenaDodatku(int j)
{
	for (int i = 0; i < iloscDodatkow(); i++)
	{
		if (j == i)
		{
			return dodatki[i].cena;
			break;
		}
	}
}
void Dodatki::menuDodatkow()
{
	int wybor;
	char c = 'v';
	char wybor2;
	while (c == 'v')
	{
		cout << "wybierz dodatek";
		while (!(cin >> wybor)) 
		{
			cin.clear(); 
			cin.sync();
		}
		nazwaDodatku(wybor - 1);
		cout << "Cos jeszcze? t/n :";
		cin >> wybor2;
		switch (wybor2)
		{
		case 't':
		{
			
		}
		break;
		case 'n':
		{
			c = 'b';
			break;

		}
		break;
		default :
		{
			cout<<"nie ma takiej opcji";
		}
			break;
		}
	}

	
}
double Dodatki::sumowanieDod()
{
	double suma=0;
	for (int i = 0; i < iloscDodatkow(); i++)
	{
		if (dodatki[i].opcja == true)
		{
			suma = suma + dodatki[i].cena;
		}
	}
	return suma;
}
void Dodatki::wypisywanieDod(string s)
{ 
	ofstream zapis(s);
	for (int i = 0; i < iloscDodatkow(); i++)
	{
		if (dodatki[i].opcja == true)
		{
			zapis << dodatki[i].nazwa << endl;
		}
	}
}