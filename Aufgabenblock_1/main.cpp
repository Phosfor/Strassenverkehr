#include "Fahrzeug.h"
#include <string>
#include <iostream>

using namespace std;

void vAufgabe_1()
{
	Fahrzeug f0, f1("F1");
	Fahrzeug *f2, *f3;
	f2 = new Fahrzeug;

	string sName;
	cout << "Name fuer f3? ";
	//cout.flush();
	cin >> sName;

	f3 = new Fahrzeug(sName, 70.0);

	f0.vAusgabe(); cout << endl;
	f1.vAusgabe(); cout << endl;
	f2->vAusgabe(); cout << endl;
	f3->vAusgabe(); cout << endl;

	delete f3;
	delete f2;
}

void main() {
	vAufgabe_1();

	/*string tmp;
	cin >> tmp;*/
	system("pause");
}