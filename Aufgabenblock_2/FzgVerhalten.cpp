#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <algorithm>

FzgVerhalten::FzgVerhalten(const Weg* pWeg) : p_pWeg(pWeg)
{
}


FzgVerhalten::~FzgVerhalten()
{
}


double FzgVerhalten::dStrecke(const Fahrzeug* pFzg, double dZeit)
{
	double dStrecke = pFzg->dGeschwindigkeit() * dZeit;
	if (p_pWeg)
		dStrecke = min(dStrecke, p_pWeg->getLaenge() - pFzg->getAbschnittStrecke());
	return dStrecke;
}