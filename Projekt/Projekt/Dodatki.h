#ifndef Dodatki_h
#define Dodatki_h
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Dodatki
{
	
public:
	std::vector<Dodatki> dodatki;
	std::string nazwa;
	double cena;
	bool opcja;
	Dodatki();
	Dodatki(std::string _nazwa, double _cena);
	void wypiszDodatki(std::string s);
	int iloscDodatkow();
	void wyswietlDodatki();
	void nazwaDodatku(int j);
	double cenaDodatku(int j);
	void menuDodatkow();
	double sumowanieDod();
	void wypisywanieDod(std::string s);

};
#endif // !Dodatki_h
