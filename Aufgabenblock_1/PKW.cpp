#include "PKW.h"


PKW::PKW() : Fahrzeug()
{
}

PKW::PKW(const string& sName) : Fahrzeug(sName)
{
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
}


PKW::~PKW()
{
}


void PKW::vInitialisiere()
{
	Fahrzeug::vInitialisiere();
	p_dVerbrauch = 10.0;
	p_dTankinhalt = p_dTankVolumen = 551.0;
}