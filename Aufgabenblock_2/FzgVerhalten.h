#pragma once

class Weg;
class Fahrzeug;

class FzgVerhalten
{
public:
	FzgVerhalten(const Weg* pWeg);
	virtual ~FzgVerhalten();

	virtual double dStrecke(const Fahrzeug* pFzg, double dZeit);

private:
	const Weg* p_pWeg;
};

