#include "Streckenende.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <iostream>

using namespace std;


Streckenende::Streckenende(Fahrzeug* pFzg, Weg* pWeg) : FahrAusnahme(pFzg, pWeg)
{
}


Streckenende::~Streckenende()
{
}


void Streckenende::vBearbeiten()
{
	cout << ">>> Streckenende: " << p_pFahrzeug->getName() << " auf " << p_pWeg->getName() << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
}
