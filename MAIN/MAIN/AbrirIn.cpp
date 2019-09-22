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
	string anterior,concaARbol1,concaArbol2;
	int posMandar=0;
	string cadena1="",cadena2="", RUTA = "C:\\Users\\Rodrigo Carcuz\\Desktop\\";
	ABB arbol = NULL;
	ArbolEqui hoja;
	ListaSimp Lis;
	Tlista Tlista = NULL;
	
	vector <vector <string> > matrizConfig;
	int numeroCapa,numeroNodoArb;
	int capaNo = 0;
	string nomb,nomb1="";
	std::vector< std::string > lista;
	std::vector< std::string > lista2;
	
	void iniciOrden()
	{
		int j=0,p= numerin-1 ;
		std::sort(lista.begin(), lista.end());
		
		 do
		 {
			if (lista[p] == lista2[j])
			{
				posMandar = j;
				nomb1 = lista[p];
				//separar(lista[p]);				
				p--;
				j = 0;
				
				MandarHojaARB();
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
		ifstream infile( text);
		string line;
		string str;
		string est;
		int estado = 0,k=0;
		
		//  Read the file    
		while (getline(infile, line))
		{
			istringstream ss(line);
			vector <string> record;

			while (getline(ss, str, ','))
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
					lista.push_back(rutaconfigg);
					lista2.push_back(rutaconfigg);
					numerin++;
					mandarcapas(esstado,rutaconfigg);
					
					j++;
					
				}            
			//aqui se separan por ; y linea a linea hacer metodo para abrir los archivos y guardarlos en la matriz
			cout << endl;			
		}
	   //	MandarHojaARB();//mando la hoja y el numero
		iniciOrden();
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

			while (getline(ss, str, ','))
				record.push_back(str);
			data.push_back(record);
		}	
		matrizConfig = data;
	}
	void mandarcapas(string numero, string ruta) {
		vector <vector <string> > data;
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

			while (getline(ss, str, ','))
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
		
		hoja.insertar(arbol,posMandar , Lis,Tlista, matrizConfig,nomb1);
	
	}

	
	void mostrar_arbol() {
		hoja.enOrden(arbol);
	}
	
	void Graficar_Arbol() {
		std::ofstream outfile("ARBOL.txt");
		outfile << "digraph BST {" << std::endl;
		outfile << " rankdir=TB" << std::endl;
		outfile <<   "node [shape = record, style=filled, fillcolor=seashell2,width=0.7,height=0.2];" << std::endl;
		//crear los nodos	
		verArbol(arbol, 0);
		outfile <<concaARbol1 << std::endl;
		outfile << concaArbol2 << std::endl;
		outfile << "}" << std::endl;

		outfile.close();
	}
	void reporteCapas(ABB arbol, int nocapa){
		//CAPAS.TXT ->MIN
		Tlista = arbol->tli;
		vector <vector <string> > data ;

		std::ofstream outfile("capas.txt");
		outfile << "digraph so{" << std::endl;
		outfile << " rankdir=LR;" << std::endl;
		outfile << " subgraph cluster0 {" << std::endl;
		outfile << " rank = same{ Array notes }" << std::endl;
		outfile << " color = white;" << std::endl;
		
			
			do
			{
				if (Tlista->numero==nocapa)
				{
					data = Tlista->data;
					Tlista = Tlista->sgte;
				}	
				else
				{
					Tlista = Tlista->sgte;
				}
				
			} while (Tlista!=NULL);
			for (int i = 0; i < data.size(); i++)
			{
				vector <string>    record;
				record = data[i];
				concaARbol1 += std::to_string(i) +"[ shape = record, label = \"{ ";
				
				
				//  Print each record
				for (int j = 0; j < record.size(); j++)
				{
					string celda = record[j];	
					if (celda=="x")
					{
						concaARbol1 +=  "-----------|";
					}
					else
					{
						concaARbol1 += celda + "|";
					}
					
				}
				concaARbol1 += "}\"] \n ;";
			}
		outfile << concaARbol1 << std::endl;		
		outfile << " } " << std::endl;
		outfile << " nodesep = .0741; }" << std::endl;
		concaARbol1 = "";
		
	}
	void verArbol(ABB arbol, int n)
	{

		if (arbol == NULL)
			return;

		verArbol(arbol->der, n + 1);
		//nodo20 [ label ="<C0>|20|<C1>"];
		concaARbol1 += std::to_string(arbol->nro) + " [ label = \" <C0>|" + arbol->NombreIma + " |<C1> \" ];" + "\n";				
	   
				
		//cout << arbol->nro << endl;
		
		
		verArbol(arbol->izq, n + 1);
		if (arbol->izq!=NULL)
		{
			concaArbol2 += std::to_string(arbol->nro) + "->" + std::to_string(arbol->izq->nro) + ";" + "\n";
		}
		if (arbol->der!=NULL)
		{
			concaArbol2 += std::to_string(arbol->nro) + "->" + std::to_string(arbol->der->nro) + ";" + "\n";
		}
		
		
	}
	void ArbolConsola() {
		hoja.verArbol(arbol,0);
	}
	void Imprimir_inorder() {
		std::ofstream outfile("kk.txt");
		outfile << "digraph G {" << std::endl;
		outfile << "rankdir=\"LR\";" << std::endl;
		outfile << "node [ fontname = \" Arial \" ];" << std::endl;
		enOrden(arbol);
		cadena1 += "9999999 [ label = \"  FIN    \" ]; \n";
		cadena2 += "9999999 ; ";
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
					cadena2 += std::to_string(arbol->nro) + " ->";					
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
		cadena1 += "9999999 [ label = \"  FIN    \" ]; \n";
		cadena2 += "9999999 ; ";
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
			cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
			cadena2 += std::to_string(arbol->nro) + " -> ";
			preOrden(arbol->izq);
			preOrden(arbol->der);
		}
	}
	void Imprimir_postorden() {
		std::ofstream outfile("postorden.txt");
		outfile << "digraph G {" << std::endl;
		outfile << "rankdir=\"LR\";" << std::endl;
		outfile << "node [ fontname = \" Arial \" ];" << std::endl;
		postOrden(arbol);
		cadena1 += "9999999 [ label = \"  FIN    \" ]; \n";
		cadena2 += "9999999 ; ";
		outfile << cadena1 << std::endl;
		outfile << cadena2 << std::endl;
		outfile << "}" << std::endl;
		outfile.close();
		cadena1 = " ";
		cadena2 = " ";
	}
	void postOrden(ABB arbol)
	{
		if (arbol != NULL)
		{
			enOrden(arbol->izq);
			enOrden(arbol->der);
			cadena1 += std::to_string(arbol->nro) + " [ label = \"" + arbol->NombreIma + "  \" ];" + "\n";
			cadena2 += std::to_string(arbol->nro) + " -> ";
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