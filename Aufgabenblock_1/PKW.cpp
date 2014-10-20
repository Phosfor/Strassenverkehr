#include "PKW.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;


PKW::PKW() : Fahrzeug()
{
}

PKW::PKW(const string& sName) : Fahrzeug(sName)
{
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit, double dVerbrauch) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	p_dVerbrauch = dVerbrauch;
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	p_dVerbrauch = dVerbrauch;
	p_dTankinhalt = p_dTankvolumen = dTankvolumen;
}


PKW::~PKW()
{
}


void PKW::vInitialisiere()
{
	Fahrzeug::vInitialisiere();
	p_dVerbrauch = 10.0;
	p_dTankinhalt = p_dTankvolumen = 551.0;
	p_dGesamtVerbrauch = 0.0;
}

double PKW::dTanken(double dMenge)
{
	if (dMenge < 0.0) {
		dMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dMenge;
	} else {
		dMenge = fmin(dMenge, p_dTankvolumen - p_dTankinhalt);
		p_dTankinhalt += dMenge;
		return dMenge;
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setw(7) << p_dGesamtVerbrauch;
	cout << setw(7) << p_dTankinhalt;// << "/" << p_dTankvolumen;
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt < 0.0) return;
	double dZeitDiff = dGlobaleZeit - p_dZeit;
	double dVerbrauch = dZeitDiff * p_dVerbrauch;
	p_dTankinhalt -= dVerbrauch;
	p_dGesamtVerbrauch += dVerbrauch;
	Fahrzeug::vAbfertigung();
}