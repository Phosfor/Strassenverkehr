#pragma once
#include "FzgVerhalten.h"

class FzgParken : public FzgVerhalten
{
public:
	FzgParken(const Weg* pWeg, double dStartzeit) : FzgVerhalten(pWeg), p_dStartzeit(dStartzeit) {}
	virtual ~FzgParken();
	
	virtual double dStrecke(const Fahrzeug* pFzg, double dZeit);

private:
	double p_dStartzeit;
};

