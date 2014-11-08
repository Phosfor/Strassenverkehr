#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <algorithm>

FzgFahren::~FzgFahren()
{
}

double FzgFahren::dStrecke(const Fahrzeug* pFzg, double dZeit)
{
	double dStrecke = pFzg->dGeschwindigkeit() * dZeit;
	if (p_pWeg) {
		double dUebrig = p_pWeg->getLaenge() - pFzg->getAbschnittStrecke();
		if (dUebrig == 0) //check with delta?!
			exit(1);
		dStrecke = min(dStrecke, dUebrig);
	}
	return dStrecke;
}