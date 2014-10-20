#pragma once
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{
public:
	Fahrrad(void);
	~Fahrrad(void);

	double dGeschwindigkeit();
};

