#include "Fahrrad.h"


Fahrrad::Fahrrad(void)
{
}


Fahrrad::~Fahrrad(void)
{
}

double Fahrrad::dGeschwindigkeit()
{
	//pro 20km um 10% abnehmen
	//minimal 12km/h
	double dGeschwindigkeit = p_dMaxGeschwindigkeit;
	double dStrecke = p_dGesamtStrecke;
	while (p_dGesamtStrecke >= 20.0 && dGeschwindigkeit >= 12.0)
	{
		//if(dGeschwindigkeit < 12.0) {dGeschwindigkeit = 12.0} falls dGeschwindigkeit durch die Schleife auf unter 12.0 fällt
		//auf 12.0 wieder hochsetzen.
		dGeschwindigkeit *= 0.9;
	}
	return dGeschwindigkeit;
}

ostream& Fahrrad::ostreamAusgabe(ostream& os)
{
	Fahrzeug::ostreamAusgabe(os);
	
	os << setprecision(1);
	os << setw(10) << dGeschwindigkeit;
	return os;
}