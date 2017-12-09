#ifndef Rachunek_h
#define Rachunek_h
#include <iostream>
#include <string>
#include <fstream>
#include "konto.h"
#include "Dodatki.h"
#include "Pizza.h"

class Rachunek
{
public:
	Rachunek();
	void zapiszRachunek(std::string nazPizzy, double cenPizzy, double cenDodatkow,std::string nazwaPliku,std::string s);


};

#endif // !Rachunek_h

#pragma once
