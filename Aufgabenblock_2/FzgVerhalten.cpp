#include "FzgVerhalten.h"

FzgVerhalten::FzgVerhalten(const Weg* pWeg) : p_pWeg(pWeg)
{
}


FzgVerhalten::~FzgVerhalten()
{
}


const Weg* FzgVerhalten::getWeg() const
{
	return p_pWeg;
}