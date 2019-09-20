#include "pch.h"
#include <fstream> 
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Cubo.h"
#include "ABB.h"


using namespace std;
class OPEN {
public:	
	int imageSelect = 0;
	int numerin = 0;
	string anterior;
	int posMandar=0;
	string cadena1="",cadena2="", RUTA = "C:\\Users\\Rodrigo Carcuz\\Desktop\\";
	ABB arbol = NULL;
	ArbolEqui hoja;
	ListaSimp Lis;
	Tlista Tlista = NULL;
	vector <vector <string> > matrizConfig;
	int numeroCapa,numeroNodoArb;
	int capaNo = 0;
	string nomb;
	std::vector< std::string > lista;
	std::vector< std::string > lista2;
	void Abrir(string txt) {
		
	   ifstream archivo(txt, ios::in);
	   string lin;
		char linea[128];
		long contador = 0L;
		int cont=0;


		if (archivo.fail())
			cerr << "Error al abrir el archivo" << endl;
		else
			while (!archivo.eof())
			{
				archivo.getline(linea, sizeof(linea));
				cout << linea << endl;
				if (archivo.eof()) {
					
				}
				else
				{
					lin = linea;
					lista2.push_back(lin);
					lista.push_back(lin);
					//separar(linea)
					numerin++;
				}
							
				
			}
		archivo.close();
		iniciOrden();
	}
	void iniciOrden()
	{
		int j=0,p= numerin-1 ;
		std::sort(lista.begin(), lista.end());
		
		 do
		 {
			if (lista[p] == lista2[j])
			{
				posMandar = j;
				separar(lista[p]);				
				p--;
				j = 0;
			}
			else
			{
				j++;
			}			
			
		 } while (p != -1);
			
			
		
	}
	
	void separar(string text) {
		nomb = text;
		vector <vector <string> > data;
		ifstream infile(RUTA + text);
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
						string estadol = record[j],rutaconfig =  record[j+1];
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
		MandarHojaARB();//mando la hoja y el numero
		
	}
	void abrirConfig(string estado,string ruta) {
		
		int cont=0,estado5=0;
		vector <vector <string> > data;
		ifstream infile(RUTA + ruta);
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
		string nomb = ruta;
		ifstream infile(RUTA + ruta);
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
		Lis.insertarInicio(Tlista,data,capaNo,nomb);
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
	void MandarHojaARB() {
	     
		
		hoja.insertar(arbol,posMandar , Lis,Tlista, matrizConfig,nomb);
		
	
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
		std::ofstream outfile("kk.txt");
		outfile << "digraph G {" << std::endl;
		outfile << "rankdir=\"LR\";" << std::endl;
		outfile << "node [ fontname = \" Arial \" ];" << std::endl;
		enOrden(arbol);
		outfile << cadena1 << std::endl;
		outfile << cadena2 << std::endl;
		outfile << "}" << std::endl;
		outfile.close();
		cadena1 = " ";
		cadena2 = " ";
		
	}
	void enOrden(ABB arbol)
	{		
		if (arbol != NULL)
		{
			enOrden(arbol->izq);
			anterior = arbol->NombreIma;
			if (arbol->izq == NULL )
			{
				if (arbol->der == NULL)
				{
					cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
					cadena2 += std::to_string(arbol->nro) + " ;";
				}
				else
				{
					cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
					cadena2 += std::to_string(arbol->nro) + " -> ";
					enOrden(arbol->der);
				}
				
			}
			else
			{
				cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
				cadena2 += std::to_string(arbol->nro) + " -> ";
				enOrden(arbol->der);
			}
			
		}
	}
	void Imprimir_preorder() {
		std::ofstream outfile("preord.txt");
		outfile << "digraph G {" << std::endl;
		outfile << "rankdir=\"LR\";" << std::endl;
		outfile << "node [ fontname = \" Arial \" ];" << std::endl;
		preOrden(arbol);
		outfile << cadena1 << std::endl;
		outfile << cadena2 << std::endl;
		outfile << "}" << std::endl;
		outfile.close();
		cadena1 = " ";
		cadena2 = " ";
	}
	void preOrden(ABB arbol)
	{
		if (arbol != NULL)
		{
			if (arbol->izq == NULL)
			{
				if (arbol->der == NULL)
				{
					cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
					cadena2 += std::to_string(arbol->nro) + " ;";
				}
				else
				{
					cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
					cadena2 += std::to_string(arbol->nro) + " -> ";
					
				}

			}
			else
			{
				cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
				cadena2 += std::to_string(arbol->nro) + " -> ";
				
			}
			preOrden(arbol->izq);
			preOrden(arbol->der);
		}
	}

	ABB BuscaParaImagen() {
		ABB arbolin = hoja.busquedaRec(arbol,imageSelect);
		return arbolin;
	}
	void ImagenSelec(int num) {
		imageSelect = num;
	}
};