#include "Weg.h"


Weg::Weg() : AktivesVO()
{
	p_dLaenge = 0.0;
}


Weg::Weg(const string& sName, double dLaenge, Weg::Begrenzung eLimit) : AktivesVO(sName)
{
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
}

Weg::~Weg()
{
}

void Weg::vAbfertigung()
{

}

double Weg::getLaenge() const
{
	return p_dLaenge;
}

ostream& Weg::ostreamAusgabe(ostream& os) const
{
	AktivesVO::ostreamAusgabe(os);
	os << p_dLaenge;

	return os;
}