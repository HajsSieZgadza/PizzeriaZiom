#include "konto.h"
#include<sstream>
using namespace std;

Konto::Konto() {};

Konto::Konto(string login1, string haslo1, string adres1, string telefon1)
{
	login = login1;
	haslo = haslo1;
	adres = adres1;
	telefon = telefon1;

}

void Konto::wczytKont(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream bob(linie);
		string login, haslo;
		bob >> login;
		bob.ignore();
		bob >> haslo;
		dane.push_back(Konto(login, haslo, adres, telefon));
	}
	plik.close();
}
int Konto::iloscKont()
{
	return dane.size();
}
void Konto::zapisKont(Konto& daneKonta, std::string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<iloscKont(); i++)
	{
		zapis << dane[i].login << " " << dane[i].haslo << " " << dane[i].adres << " " << dane[i].telefon << endl;
	}
	zapis.close();
}
void Konto::noweKonto(string nazwaPliku)
{
	int dziala = 0;
	string newLogin, newHaslo, newAdres, newTelefon;
	cout << "Podaj login : ";
	cin >> newLogin;
	cout << endl;
	for (int i = 0; i<iloscKont(); i++)
	{
		if (newLogin == dane[i].login)
		{
			dziala++;
			break;

		}

	}
	if (dziala == 0)
	{
		cout << "Podaj haslo : ";
		cin >> newHaslo;
		cout << endl;
		cout << "Podaj adres do zamowien : ";
		cin >> newAdres;
		cout << endl;
		cout << "Podaj telefon kontaktowy : ";
		cin >> newTelefon;
		cout << endl;
		dane.push_back(Konto(newLogin, newHaslo, newAdres, newTelefon));
	}
	else
	{
		cout << " Dany Login jest zajety, sprobuj ponownie " << endl;
		return noweKonto(nazwaPliku);
	}

}
void Konto::zaloguj() //Tutaj mo¿na zrobiæ klasê abstrakcyjn¹ na wczytane dane tzn wczyta raz i bedzie caly czas w pamieci programy do jego zakonczenia
{
	string wczytanyLogin, wczytaneHaslo, wczytanyAdres, wczytanyTel; // to by byly elementy abstrakcyjne
	cout << "Login : ";
	cin >> wczytanyLogin;

	for (int i = 0; i < iloscKont(); i++)
	{
		if (wczytanyLogin == dane[i].login)
		{
			cout << endl << "Haslo : ";
			cin >> wczytaneHaslo;

			if (wczytaneHaslo == dane[i].haslo)
			{
				wczytanyAdres = dane[i].adres;
				wczytanyTel = dane[i].telefon;
				cout << "Logowanie prawidlowe."<<endl;
				break;
			}
			else
			{
				cout << "Bledne haslo!"<<endl;
				break;
			}
		}
		else
		{
			cout << "Taki uzytkownik nie jest zarejestrowany"<<endl;
			break;
		}
	}
	

}