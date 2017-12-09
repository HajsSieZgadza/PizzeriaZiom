#include "Rachunek.h"
using namespace std;

Rachunek::Rachunek(){}

void Rachunek::zapiszRachunek(string nazPizzy,double cenPizzy,double cenDodatkow,string nazwaPliku ,string s)
{
	ifstream wczyt(s);
	ofstream zapis(nazwaPliku);
	zapis << nazPizzy << " " << cenPizzy + cenDodatkow << " " << endl;
	zapis << "Dodatki :" << endl;
	string dodatek[100];
	int i = 0;
	while (i<100)
	{
		wczyt >> dodatek[i];
		i++;
	}
	i = 0;
	while (i<100)
	{
		zapis << dodatek[i]<<endl;
		i++;
	}
	zapis.close();
}
