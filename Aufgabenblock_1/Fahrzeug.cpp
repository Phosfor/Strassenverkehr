#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>

int Fahrzeug::p_iMaxID;
extern double dGlobaleZeit;

Fahrzeug::Fahrzeug()
{
	vInitialisiere();
	//cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

Fahrzeug::Fahrzeug(const string& sName)
{
	vInitialisiere();
	p_sName = sName;
	//cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

Fahrzeug::Fahrzeug(const string& sName, const double dMaxGeschwindigkeit)
{
	vInitialisiere();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	//cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

void Fahrzeug::vInitialisiere()
{
	p_sName = "";
	p_iID = p_iMaxID++;
	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_dGesamtZeit = 0.0;
	p_dZeit = 0.0;
}

Fahrzeug::~Fahrzeug()
{
	//cout << "Fahrzeug entfernt: '" << p_sName << "' (" << p_iID << ")" << endl;
}

void Fahrzeug::vAusgabe()
{
	ostreamAusgabe(cout);
}

void Fahrzeug::vAbfertigung()
{
	double dZeitDiff = dGlobaleZeit - p_dZeit;
	//if (dZeitDiff == 0.0) return;
	p_dZeit = dGlobaleZeit;
	p_dGesamtStrecke += dZeitDiff * dGeschwindigkeit(); //p_dMaxGeschwindigkeit
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& os)
{
	os << resetiosflags(ios::right) << setiosflags(ios::left | ios::fixed);
	os << setprecision(1);
	os << setw(4) << p_iID;
	os << setw(7) << p_sName << " : ";

	os << setw(10) << dGeschwindigkeit();
	os << setw(10) << p_dMaxGeschwindigkeit;
	os << setw(10) << p_dGesamtStrecke;

	return os;
}

ostream& operator<<(ostream& os, Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(os);
}