#pragma once
#include "Fahrzeug.h"
#include <string>

class PKW :
	public Fahrzeug
{
public:
	PKW();
	PKW(const string& sName);
	PKW(const string& sName, const double dMaxGeschwindigkeit);
	virtual ~PKW();

private:
	double p_dVerbrauch, p_dTankinhalt, p_dTankVolumen;

protected:
	virtual void vInitialisiere();
};

