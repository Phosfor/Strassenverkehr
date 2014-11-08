#pragma once
#include "FzgVerhalten.h"

class FzgFahren : public FzgVerhalten
{
public:
	FzgFahren(const Weg* pWeg) : FzgVerhalten(pWeg) {}
	virtual ~FzgFahren();

	virtual double dStrecke(const Fahrzeug* pFzg, double dZeit);
};

