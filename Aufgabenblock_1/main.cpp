#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double dGlobaleZeit = 0.0;

void vFahrzeugHeader()
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left);
	cout << setw(4) << "ID";
	cout << setw(7) << "Name" << " : ";
	cout << setw(10) << "KmH";
	cout << setw(10) << "MaxKmh";
	cout << setw(10) << "Strecke";
	cout << setw(7) << "Tank";
	cout << setw(10) << "Verbrauch";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vAufgabe_1()
{
	Fahrzeug f0, f1("F1");
	Fahrzeug *f2, *f3, *f4, *f5;
	f2 = new Fahrzeug;

	string sName;
	cout << "Name fuer f3? ";
	//cout.flush();
	cin >> sName;

	f3 = new Fahrzeug(sName, 70.0);
	f4 = new Fahrzeug("", 30.0);
	f5 = new Fahrzeug("", 30.0);

	vFahrzeugHeader();
	f0.vAusgabe(); cout << endl;
	f1.vAusgabe(); cout << endl;
	f2->vAusgabe(); cout << endl;
	f3->vAusgabe(); cout << endl;
	f4->vAusgabe(); cout << endl;
	f5->vAusgabe(); cout << endl;

	double dInterval = 0.3;
	for (int i = 0; i < 25; i++) {
		dGlobaleZeit += dInterval;
		f0.vAbfertigung();
		f1.vAbfertigung();
		f2->vAbfertigung();
		f3->vAbfertigung();
		f4->vAbfertigung();
		f5->vAbfertigung();
		f5->vAbfertigung();

		cout << endl;
		f0.vAusgabe(); cout << endl;
		f1.vAusgabe(); cout << endl;
		f2->vAusgabe(); cout << endl;
		f3->vAusgabe(); cout << endl;
		f4->vAusgabe(); cout << endl;
		f5->vAusgabe(); cout << endl;
	}

	delete f5;
	delete f4;
	delete f3;
	delete f2;
}

void vAufgabe_1_deb()
{
	Fahrzeug f0, f1, f2, f3;
	Fahrzeug* pFahrzeuge[4] = { &f0, &f1, &f2, &f3 };

	vFahrzeugHeader();
	for (int i = 0; i < 4; i++)
	{
		pFahrzeuge[i]->vAusgabe(); cout << endl;
	}

	pFahrzeuge[2] = 0; //Fehler einbauen

	for (int i = 0; i < 4; i++) {
		pFahrzeuge[i]->vAusgabe(); cout << endl;
	}
}

void vAufgabe_2()
{
	int iPKWs, iFahrraeder;
	cout << "Anzahl PKWs? ";
	cin >> iPKWs;
	cout << "Anzahl Fahrraeder? ";
	cin >> iFahrraeder;

	vector<Fahrzeug*> fahrzeuge;
	for (int i = 0; i < iPKWs; i++) {
		string sName;
		double dMaxGeschwindigkeit, dVerbrauch;
		cout << "Fahrzeug " << i << endl;
		cout << "Name: "; cin >> sName;
		cout << "Max Geschwindigkeit: "; cin >> dMaxGeschwindigkeit;
		cout << "Verbrauch: "; cin >> dVerbrauch;
		cout << endl;
		PKW* pkw = new PKW(sName, dMaxGeschwindigkeit, dVerbrauch);

		fahrzeuge.push_back(pkw);
	}

	for (int i = 0; i < iFahrraeder; i++) {
		cout << "Fahrrad" << "Nr. " << i << endl;
		string sName;
		double dMaxGeschwindigkeit;
		cout << "Fahrzeug " << i << endl;
		cout << "Name: "; cin >> sName;
		cout << "Max Geschwindigkeit: "; cin >> dMaxGeschwindigkeit;
		cout << endl;
		Fahrrad* fahrrad = new Fahrrad(sName, dMaxGeschwindigkeit);

		fahrzeuge.push_back(fahrrad);
	}

	vFahrzeugHeader();
	double dInterval = 0.1;
	while (dGlobaleZeit < 5.0)
	{
		dGlobaleZeit += dInterval;
		for (vector<Fahrzeug*>::iterator it = fahrzeuge.begin(); it != fahrzeuge.end(); it++) {
			(*it)->vAbfertigung();
			if (fabs(dGlobaleZeit - 3.0) < 0.0000000001)
				(*it)->dTanken();
			(*it)->vAusgabe(); cout << endl;
		}
		cout << "----" << endl;
	}

	for (vector<Fahrzeug*>::iterator it = fahrzeuge.begin(); it != fahrzeuge.end(); it++) {
		delete *it;
	}
}

void vAufgabe_3()
{
	dGlobaleZeit = 1.0;
	PKW p0("test", 10.0, 100, 3000), p1("test2", 20.0);
	p1.vAbfertigung();
	cout << p0 << endl << p1 << endl;
	cout << "test < test2? " << (p0 < p1) << endl;


	PKW copy(p0);
	cout << "Kopie: " << copy << endl;
	PKW assign = p0;
	cout << "Zuweisung: " << assign << endl;

}

void main() {
	vAufgabe_2();

	/*string tmp;
	cin >> tmp;*/
	system("pause");
}