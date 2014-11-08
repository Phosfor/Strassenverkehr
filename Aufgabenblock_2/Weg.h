#pragma once
#include "AktivesVO.h"
#include <list>
#include <string>

using namespace std;

class Fahrzeug;

class Weg :
	public AktivesVO
{
public:
	static enum Begrenzung {Innerorts, Landstrasse, Autobahn};
	Weg();
	Weg(const string& sName, double dLaenge, Begrenzung eLimit = Autobahn);
	~Weg();

	virtual void vAbfertigung();

	virtual ostream& ostreamAusgabe(ostream& os) const;

	double getLaenge() const;

	void vAnnahme(Fahrzeug* pFzg);
	void vAnnahme(Fahrzeug* pFzg, double dStartzeit);

	Begrenzung getLimit() const;

private:
	double p_dLaenge;
	Begrenzung p_eLimit;
	list<Fahrzeug*> p_pFahrzeuge;

};

