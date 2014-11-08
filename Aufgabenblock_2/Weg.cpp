#include "Weg.h"
#include "Fahrzeug.h"
#include <iomanip>

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

void Weg::vAnnahme(Fahrzeug* pFzg)
{
	p_pFahrzeuge.push_back(pFzg);
	pFzg->vNeueStrecke(this);
}

void Weg::vAnnahme(Fahrzeug* pFzg, double dStartzeit)
{
	p_pFahrzeuge.push_back(pFzg);
	pFzg->vNeueStrecke(this, dStartzeit);
}

ostream& Weg::ostreamAusgabe(ostream& os) const
{
	AktivesVO::ostreamAusgabe(os);
	os << setw(10) << p_dLaenge;

	os << "( ";
	for (list<Fahrzeug*>::const_iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++) {
		os << (*it)->getName() << " ";
	}
	os << ")";

	return os;
}

Weg::Begrenzung Weg::getLimit() const
{
	return p_eLimit;
}