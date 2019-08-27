#include "pch.h"
#include "AbrirArch.h"
#include <fstream> 
#include <iostream>
using namespace std;

AbrirArch::AbrirArch(string ruta)
{
	char cadena[128];
	ifstream fe(ruta);
	while (!fe.eof()) {		fe >> cadena;
		cout << cadena << endl;
	}
	fe.close();
	system("pause");
}


AbrirArch::~AbrirArch()
{
}
