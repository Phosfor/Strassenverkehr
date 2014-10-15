#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>

int Fahrzeug::p_iMaxID;

Fahrzeug::Fahrzeug()
{
	vInitialisiere();
	cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

Fahrzeug::Fahrzeug(const string& sName)
{
	vInitialisiere();
	p_sName = sName;
	cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
}

Fahrzeug::Fahrzeug(const string& sName, const double dMaxGeschwindigkeit)
{
	vInitialisiere();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	cout << "Neues Fahrzeug: '" << p_sName << "' (" << p_iID << ")" << endl;
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
	cout << "Fahrzeug entfernt: '" << p_sName << "' (" << p_iID << ")" << endl;
}

void Fahrzeug::vAusgabe()
{
	cout << setw(4) << p_iID;
	cout << setw(7) << p_sName << " : ";
	cout << setw(6) << p_dMaxGeschwindigkeit;
	cout << setw(10) << p_dGesamtStrecke;
}