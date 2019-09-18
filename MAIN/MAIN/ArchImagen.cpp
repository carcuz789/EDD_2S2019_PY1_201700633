#include "pch.h"
#include <fstream> 
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include "ABB.h"
#include "Cubo.h"
using namespace std;
class HTML {
public:
	ListaSimp lista;
	Tlista tlista;
	void InicioHTML() {
		std::ofstream outfile("IMAGEN.html");
		outfile << " <link rel=\"stylesheet\" href=\"template.scss \" >" << std::endl;
		outfile << "<div class=\"pixel - block\">" << std::endl;
		outfile << "<div class=\"pixelized--heart\">" << std::endl;
		outfile << " </div>" << std::endl;
		outfile << "</div>" << std::endl;
		
	}
	void CreateCss(ABB arbol) {
		lista = arbol->li;
		tlista = arbol->tli;
		vector <vector <string> > data;
		std::ofstream outfile("template.scss");

		outfile << ".pixel-block {" << std::endl;
		outfile << "position: absolute;" << std::endl;
		outfile << "top: 50%;" << std::endl;
		outfile << "left:50%;" << std::endl;
		outfile << "transform: translate(-50%, -50%);" << std::endl;
		outfile << "width: 20em;" << std::endl;
		outfile << "height: 20em;" << std::endl;
		outfile << "}" << std::endl;
		
		
		outfile << ".pixelized--heart {" << std::endl;
		outfile << "display: block;" << std::endl;
		outfile << "width: 1em;" << std::endl;
		outfile << "height: 1em;" << std::endl;
		outfile << "box-shadow:" << std::endl;
		while (tlista != NULL)
		{
			data = tlista->data;
			for (int i = 0; i < data.size(); i++)
			{
				vector <string>    record;
				record = data[i];
				//  Print each record
				for (int j = 0; j < record.size(); j++)
				{
					string celda = record[j];
					if (record[j]=="x")
					{
						
					}
					else {
						string manda = std::to_string(j) + "em " + std::to_string(i) + "em #F22613;";
						outfile << manda << std::endl;

					}
					
				}
					

				cout << endl;
			}
			tlista = tlista->sgte;
		}		
		outfile << "}" << std::endl;
		
	}
};
