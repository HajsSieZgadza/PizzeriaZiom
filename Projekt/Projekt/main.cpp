#include <iostream>
#include "konto.h"
#include <string>
#include "Pizza.h"
#include "Dodatki.h"
#include "Rachunek.h"

using namespace std;

int main()
{
	string a = "bazaDanych.txt", b = "menu.txt", c = "dodatki.txt", d = "rachunek.txt",e="przejscie.txt";
	Konto Baza;
	Pizza Jan;
	Dodatki dod;
	Rachunek rach;
	dod.wypiszDodatki(c);
	Baza.wczytKont(a);
	Jan.wczytajMenu(b);
	cout << "Wybierz Opcjê :" << endl << "1) Nowe Konto" << endl << "2) Zaloguj" <<endl;
	int opcja;
	cin >> opcja;
	switch (opcja)
	{
		case 1 :
		{
			Baza.noweKonto(a);
		}
		break;
		case 2 :
		{
			Baza.zaloguj();
		}
		break;
		case 3:
		{
			Jan.wypiszMenu();
			cout << "Wybierz Pizze Ziom : ";
			int jaka;
			while (!(cin >> jaka)) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
			{
				//ew komunikat b³êdu
				cin.clear(); //kasowanie flagi b³êdu strumienia
				cin.sync(); //kasowanie zbêdnych znaków z bufora
			}
			string nazPiz = Jan.wybierzPizze(jaka);
			cout << "Wybierz Rozmiar (1, 2, 3) : ";
			int roz;
			while (!(cin >> roz)) 
			{
				cin.clear(); 
				cin.sync(); 
			}
			double cenaPiz = Jan.dobierzCene(jaka,roz);
			int ynm;
			cout << "Dodatki? 1 jak tak:";
			cin >> ynm;
			if (ynm == 1)
			{
				dod.wyswietlDodatki();
				dod.menuDodatkow();
				
			}
			dod.wypisywanieDod(e);
			double cenaDod = dod.sumowanieDod();
			rach.zapiszRachunek(nazPiz, cenaPiz, cenaDod, d,e);
		}
		break;
	
	default:
		break;
	}
	Baza.zapisKont(Baza, a);
	system("pause");
	return 0;
}