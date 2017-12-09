#ifndef Pizza_h
#define Pizza_h
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Rachunek.h"

class Pizza
{
public :
	std::vector<Pizza>pizze;
	std::string nazwa;
	double cena;
	Pizza();
	Pizza(std::string _nazwa, double _cena);
	int iloscPizzy();
	void wczytajMenu(std::string s);
	std::string wybierzPizze(int jaka);
	double dobierzCene(int jaka,int roz);
	void wypiszMenu();
};
#endif // !Pizza_h
#pragma once
