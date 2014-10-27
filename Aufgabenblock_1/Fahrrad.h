#pragma once
#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>

class Fahrrad : public Fahrzeug
{
public:
	Fahrrad(void);
	~Fahrrad(void);

	double dGeschwindigkeit();

	virtual ostream& ostreamAusgabe(ostream& os);
};

