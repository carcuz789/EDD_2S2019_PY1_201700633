#include "pch.h"
#include <fstream> 
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include "Cubo.h"
#include "ABB.h"



using namespace std;
class OPEN {
public:	
	
	string anterior;
	string cadena1="",cadena2="";
	ABB arbol = NULL;
	ArbolEqui hoja;
	ListaSimp Lis;
	Tlista Tlista = NULL;
	vector <vector <string> > matrizConfig;
	int numeroCapa,numeroNodoArb;
	int capaNo = 0;
	int numerohoja = 1;
	string nomb;
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
				separar(linea);			
				
			}
		archivo.close();
	}
	void separar(string text) {
		nomb = text;
		vector <vector <string> > data;
		ifstream infile(text);
		string line;
		string str;
		string est;
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
					if (record[j]=="0")
					{
						string estadol = record[j],rutaconfig = record[j+1];
						abrirConfig(estadol,rutaconfig);
						est = 1;//para saber que los que vengan ya seran los numeros
						estado = 1;
						j++;
						capaNo = 0;
					}					
				}
				else if(estado ==1)
				{					
					string esstado = record[j];
					string rutaconfigg = record[j + 1];
					mandarcapas(esstado,rutaconfigg);
					j++;
					
				}            
			//aqui se separan por ; y linea a linea hacer metodo para abrir los archivos y guardarlos en la matriz
			cout << endl;			
		}
		MandarPaquete();
		
	}
	void abrirConfig(string estado,string ruta) {
		
		int cont=0,estado5=0;
		vector <vector <string> > data;
		ifstream infile(ruta);
		string line;
		string str;
		string est;
		

		//  Read the file    
		while (getline(infile, line))
		{
			istringstream ss(line);
			vector <string> record;

			while (getline(ss, str, ';'))
				record.push_back(str);
			data.push_back(record);
		}	
		matrizConfig = data;
	}
	void mandarcapas(string numero, string ruta) {
		vector <vector <string> > data;
		string MatCapa[100][100];
		ifstream infile(ruta);
		string line;
		string str;
		string est;


		//  Read the file    
		while (getline(infile, line))
		{
			istringstream ss(line);
			vector <string> record;

			while (getline(ss, str, ';'))
				record.push_back(str);
			data.push_back(record);
		}
		Lis.insertarInicio(Tlista,data,capaNo,ruta);
		capaNo++;
//		for (size_t i = 0; i < data.size(); i++)
	//	{
	//		vector <string>    record;
		//	record = data[i];
			//  Print each record
		//	for (size_t j = 0; j < record.size(); j++)
			//	MatCapa[i][j]=record[j];
			//aqui se separan por ; y linea a linea hacer metodo para abrir los archivos y guardarlos en la matriz
			//cout << endl;
		//}
		//Lis.insertarElemento(lista, MatCapa, capaNo, nomb);
		//capaNo++;
	}
	void MandarPaquete() {
		hoja.insertar(arbol, numerohoja, Lis,Tlista, matrizConfig,nomb);
		numerohoja++;
	
	}
	void mostrar_arbol() {
		hoja.enOrden(arbol);
	}
	
	void Graficar_Arbol() {
		std::ofstream outfile("ARBOL.txt");

		outfile << "digraph BST {" << std::endl;
		outfile <<   "node [ fontname = \" Arial \" ];" << std::endl;
		//crear los nodos
		
		outfile << "No"+arbol->NombreIma+" [ label = \""+ arbol->NombreIma+"  \" ];"  << std::endl;
				
		outfile << "}" << std::endl;

		outfile.close();
	}
	void arbi() {
		hoja.verArbol(arbol,0);
	}
	void Imprimir_inorder() {
		std::ofstream outfile("INORDER_TRASNVERSAL.txt");
		outfile << "digraph G {" << std::endl;
		outfile << "node [ fontname = \" Arial \" ];" << std::endl;
		enOrden(arbol, outfile);
		outfile << cadena1 << std::endl;
		outfile << cadena2 << std::endl;
		outfile << "}" << std::endl;

		outfile.close();
		cadena1 = " ";
		cadena2 = " ";
		
	}
	void enOrden(ABB arbol,ofstream & file)
	{
		
		
		if (arbol != NULL)
		{
			enOrden(arbol->izq,file);
			anterior = arbol->NombreIma;
			cadena1 +=   std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];"+"\n";
			cadena2 += std::to_string( arbol->nro) + " -> ";

			
			enOrden(arbol->der,file);
		}
	}

    
};