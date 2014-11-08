#include "FzgParken.h"
#include <stdlib.h> //exit

FzgParken::~FzgParken()
{
}


double FzgParken::dStrecke(const Fahrzeug* pFzg, double dZeit)
{
	if ((p_dStartzeit -= dZeit) <= 0.0)
		exit(2);
}