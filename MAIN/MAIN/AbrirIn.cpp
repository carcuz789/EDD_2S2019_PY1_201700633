#include "pch.h"
#include <fstream> 
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>


using namespace std;
class OPEN {
public:
	string ArchIn[2][100];
	void Abrir(string txt) {
	   ifstream archivo(txt, ios::in);
		char linea[128];
		long contador = 0L;

		if (archivo.fail())
			cerr << "Error al abrir el archivo" << endl;
		else
			while (!archivo.eof())
			{
				archivo.getline(linea, sizeof(linea));
				cout << linea << endl;

				if ((++contador % 24) == 0)
				{ 
					cout << "CONTINUA...";
					cin.get();
				}
			}
		archivo.close();
	}
	void separar(string text) {
		 
		vector <vector <string> > data;
		ifstream infile(text);
		string line;
		string str;
		int estado = 0,k=0;
		
		//  Read the file    
		while (getline(infile, line))
		{
			istringstream ss(line);
			vector <string> record;

			while (getline(ss, str, ';'))
				record.push_back(str);
			data.push_back(record);
		}
		//  sin ;
		for (size_t i = 0; i < data.size(); i++)
		{
			vector <string>    record;
			record = data[i];
			//  Print each record
			for (size_t j = 0; j < record.size(); j++)
				if (estado == 0)
				{
					cout << record[j] << " ";
					ArchIn[0][k] = record[j];
					estado = 1;
				}
				else
				{
					cout << record[j] << " ";
					ArchIn[1][k] = record[j];
					estado = 0;
					k++;
				}            
			//aqui se separan por ; y linea a linea hacer metodo para abrir los archivos y guardarlos en la matriz
			cout << endl;
		}
		abrirConfig();
		
	}
	void abrirConfig() {
		int i = 0;
		do
		{

			
		} while (ArchIn[0][i]!= " ");

	}
};