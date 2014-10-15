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

	void vAusgabe();
private:
	string p_sName;
	int p_iID;

	double p_dMaxGeschwindigkeit, p_dGesamtStrecke, p_dGesamtZeit, p_dZeit;

	static int p_iMaxID;

	void vInitialisiere();
};
