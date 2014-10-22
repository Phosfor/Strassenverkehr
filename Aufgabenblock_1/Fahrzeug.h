#pragma once
#include <string>

using namespace std;

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(const string& sName);
	Fahrzeug(const string& sName, const double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();

	virtual void vAbfertigung();
	void vAusgabe();
	virtual double dGeschwindigkeit();

	virtual double dTanken(double dMenge = -1.0);

	virtual ostream& ostreamAusgabe(ostream& os);

private:
	string p_sName;
	int p_iID;

	double p_dGesamtZeit;

	static int p_iMaxID;

	void vInitialisiere();

protected:
	double p_dGesamtStrecke, p_dMaxGeschwindigkeit, p_dZeit;
};

ostream& operator<<(ostream& os, Fahrzeug& fahrzeug);