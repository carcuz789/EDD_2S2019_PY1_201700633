#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
class MANEJO {
public:
	void manejo(char ruta) {
		cout << ruta;
		std::string s = " ";
		string texto = " ";
		s = ruta;
		ifstream archivo;
		archivo.open(s, ios::in);
		if (archivo.fail())
		{
			cout << "No se pudo abrir el archivo ";
		}
		while (!archivo.eof())
		{
			getline(archivo, texto);
			cout << texto << endl;
		}
		archivo.close();
	}
};

