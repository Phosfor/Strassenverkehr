#include "PKW.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;


PKW::PKW() : Fahrzeug()
{
	vInitialisiere();
}

PKW::PKW(const string& sName) : Fahrzeug(sName)
{
	vInitialisiere();
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	vInitialisiere();
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit, double dVerbrauch) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	vInitialisiere();
	p_dVerbrauch = dVerbrauch;
}

PKW::PKW(const string& sName, const double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	vInitialisiere();
	p_dVerbrauch = dVerbrauch;
	p_dTankinhalt = p_dTankvolumen = dTankvolumen;
}


PKW::~PKW()
{
}


void PKW::vInitialisiere()
{
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
		dMenge = min(dMenge, p_dTankvolumen - p_dTankinhalt);
		p_dTankinhalt += dMenge;
		return dMenge;
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setprecision(1);
	cout << setw(7) << p_dGesamtVerbrauch;
	cout << setw(7) << p_dTankinhalt;// << "/" << p_dTankvolumen;
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt < 0.0) return;
	double dZeitDiff = dGlobaleZeit - p_dZeit;
	double dVerbrauch = dZeitDiff * p_dVerbrauch;
	p_dTankinhalt -= dVerbrauch;
	if (p_dTankinhalt < 0.0) p_dTankinhalt = 0.0;
	p_dGesamtVerbrauch += dVerbrauch; //TODO: checken ob hier nur differenz addert werde soll
	Fahrzeug::vAbfertigung();
}