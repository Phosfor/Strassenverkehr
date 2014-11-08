#pragma once

class Weg;
class Fahrzeug;

class FzgVerhalten
{
public:
	FzgVerhalten(const Weg* pWeg);
	virtual ~FzgVerhalten();

	virtual double dStrecke(const Fahrzeug* pFzg, double dZeit) = 0;

	const Weg* getWeg() const;

protected:
	const Weg* p_pWeg;
};

