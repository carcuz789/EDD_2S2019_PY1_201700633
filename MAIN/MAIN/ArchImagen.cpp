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
	void HTMLInvert() {
		std::ofstream outfile("Invert.html");
		outfile << " <link rel=\"stylesheet\" href=\"Invert.scss \" >" << std::endl;
		outfile << "<div class=\"pixel - block\">" << std::endl;
		outfile << "<div class=\"pixelized--heart\">" << std::endl;
		outfile << " </div>" << std::endl;
		outfile << "</div>" << std::endl;

	}
	void CreateInvert(ABB arbol) {
		HTMLInvert();
		string Image_width, Image_height, pixel_width, pixel_height;
		lista = arbol->li;
		tlista = arbol->tli;
		vector <vector <string> > data;
		vector <vector <string> > mat = arbol->mat;
		std::ofstream outfile("Invert.scss");
		for (int i = 0; i < mat.size(); i++)
		{
			vector <string>    record;
			record = mat[i];
			//  Print each record
			for (int j = 0; j < record.size(); j++)
			{
				string celda = record[j];
				if (celda == "image_width")
				{
					Image_width = record[j + 1];
				}
				else if (celda == "image_height")
				{
					Image_height = record[j + 1];
				}
				else if (celda == "pixel_width")
				{
					pixel_width = "1";
				}
				else if (celda == "pixel_height")
				{
					pixel_height = "1";
				}
			}

		}
		outfile << ".pixel-block {" << std::endl;
		outfile << "position: absolute;" << std::endl;
		outfile << "top: 50%;" << std::endl;
		outfile << "left:50%;" << std::endl;
		outfile << "transform: translate(-50%, -50%);" << std::endl;
		outfile << "width:" + Image_width + "em;" << std::endl;
		outfile << "height:" + Image_height + "em;" << std::endl;
		outfile << "}" << std::endl;


		outfile << ".pixelized--heart {" << std::endl;
		outfile << "display: block;" << std::endl;
		outfile << "width:" + pixel_width + "em;" << std::endl;
		outfile << "height:" + pixel_height + "em;" << std::endl;
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
					if (record[j] == "x")
					{
						//no hace nada por que es un espacio en blanco
					}
					else {
						if (tlista->sgte != NULL)
						{
							string hex = Conversion(record[j]);
							string manda = std::to_string(i) + "em " + std::to_string(j) + "em  " + "#" + hex + ",";
							outfile << manda << std::endl;
						}
						else
						{
							string hex = Conversion(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ";";
							outfile << manda << std::endl;
						}


					}

				}

			}
			tlista = tlista->sgte;
		}

		outfile << "}" << std::endl;

	}
	void CreateCss(ABB arbol) {
		InicioHTML();
		string Image_width, Image_height,pixel_width,pixel_height;
		lista = arbol->li;
		tlista = arbol->tli;
		vector <vector <string> > data;
		vector <vector <string> > mat = arbol->mat;
		std::ofstream outfile("template.scss");
		for (int i = 0; i < mat.size(); i++)
		{
			vector <string>    record;
			record = mat[i];
			//  Print each record
			for (int j = 0; j < record.size(); j++)
			{
				string celda = record[j];
				if (celda == "image_width")
				{
					Image_width = record[j + 1];
				}				
				else if (celda == "image_height")
				{
					Image_height = record[j + 1];
				}
				else if (celda == "pixel_width")
				{
					pixel_width = "1";
				}
				else if (celda=="pixel_height") 
				{
					pixel_height ="1";
				}
			}

		}
		outfile << ".pixel-block {" << std::endl;
		outfile << "position: absolute;" << std::endl;
		outfile << "top: 50%;" << std::endl;
		outfile << "left:50%;" << std::endl;
		outfile << "transform: translate(-50%, -50%);" << std::endl;
		outfile << "width:"+Image_width +"em;" << std::endl;
		outfile << "height:"+ Image_height+"em;" << std::endl;
		outfile << "}" << std::endl;
		
		
		outfile << ".pixelized--heart {" << std::endl;
		outfile << "display: block;" << std::endl;
		outfile << "width:"+pixel_width +"em;" << std::endl;
		outfile << "height:"+pixel_height+"em;" << std::endl;
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
						//no hace nada por que es un espacio en blanco
					}
					else {
						if (tlista->sgte!=NULL)
						{
							string hex = Conversion(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ",";
							outfile << manda << std::endl;
						}
						else
						{
							string hex = Conversion(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ";";
							outfile << manda << std::endl;
						}
						

					}
					
				}				

			}
			tlista = tlista->sgte;
		}

		outfile << "}" << std::endl;
		
	}
	void FiltroBlack(ABB arbol) {
		HTMLBlack();
		lista = arbol->li;
		tlista = arbol->tli;
		vector <vector <string> > data;
		std::ofstream outfile("Negro.scss");

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
					if (record[j] == "x")
					{
						//no hace nada por que es un espacio en blanco
					}
					else {
						
						if (tlista->sgte != NULL)
						{
							string hex = ConversionANegro(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ",";
							outfile << manda << std::endl;
						}
						else
						{
							string hex = ConversionANegro(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ";";
							outfile << manda << std::endl;
						}

					}

				}

			}
			tlista = tlista->sgte;
		}

		outfile << "}" << std::endl;

	}
	void HTMLBlack() {
		std::ofstream outfile("FiltroByN.html");
		outfile << " <link rel=\"stylesheet\" href=\"Negro.scss \" >" << std::endl;
		outfile << "<div class=\"pixel - block\">" << std::endl;
		outfile << "<div class=\"pixelized--heart\">" << std::endl;
		outfile << " </div>" << std::endl;
		outfile << "</div>" << std::endl;

	}
	void FiltroNEGATi(ABB arbol) {
		HTMLNEGA();
		lista = arbol->li;
		tlista = arbol->tli;
		vector <vector <string> > data;
		std::ofstream outfile("Negativ.scss");

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
					if (record[j] == "x")
					{
						//no hace nada por que es un espacio en blanco
					}
					else {

						if (tlista->sgte != NULL)
						{
							string hex = ConversionANegativo(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ",";
							outfile << manda << std::endl;
						}
						else
						{
							string hex = ConversionANegativo(record[j]);
							string manda = std::to_string(j) + "em " + std::to_string(i) + "em  " + "#" + hex + ";";
							outfile << manda << std::endl;
						}

					}

				}

			}
			tlista = tlista->sgte;
		}

		outfile << "}" << std::endl;

	}
	void HTMLNEGA() {
		std::ofstream outfile("FiltroNEGA.html");
		outfile << " <link rel=\"stylesheet\" href=\"Negativ.scss \" >" << std::endl;
		outfile << "<div class=\"pixel - block\">" << std::endl;
		outfile << "<div class=\"pixelized--heart\">" << std::endl;
		outfile << " </div>" << std::endl;
		outfile << "</div>" << std::endl;

	}
	string ConversionANegativo(string RGB) {
		stringstream stream(RGB);
		int R = 0, G = 0, B = 0;
		string word, result;
		int i = 0;
		while (getline(stream, word, '-')) {
			if (i == 0)
			{
				R = 255-std::stoi(word);
				i++;
			}
			else if (i == 1)
			{
				G = 255-std::stoi(word);
				i++;
			}
			else
			{
				B = 255-std::stoi(word);
			}
		}
		
		char r[255];
		sprintf_s(r, "%.2X", R);
		result.append(r);

		char g[255];
		sprintf_s(g, "%.2X", G);
		result.append(g);

		char b[255];
		sprintf_s(b, "%.2X", B);
		result.append(b);

		return result;
	}
	string ConversionANegro(string RGB) {
		stringstream stream(RGB);
		int R = 0, G = 0, B = 0;
		string word, result;
		int i = 0;
		while (getline(stream, word, '-')) {
			if (i == 0)
			{
				R = std::stoi(word);
				i++;
			}
			else if (i == 1)
			{
				G = std::stoi(word);
				i++;
			}
			else
			{
				B = std::stoi(word);
			}
		}
		if (R>G)
		{
			if (R>B)
			{
				B = R;
				G = R;
			}
		}
		else if (G>B)
		{
			R = G;
			B = G;
		}
		else {
			R = B;
			G = B;
		}
		char r[255];
		sprintf_s(r, "%.2X", R);
		result.append(r);

		char g[255];
		sprintf_s(g, "%.2X", G);
		result.append(g);

		char b[255];
		sprintf_s(b, "%.2X", B);
		result.append(b);

		return result;
	}
	string Conversion(string RGB) {
		stringstream stream(RGB);
		int R = 0, G = 0, B = 0;
		string word, result;
		int i = 0;
		while (getline(stream, word, '-')) {
			if (i == 0)
			{
				R = std::stoi(word) ;
				i++;
			}
			else if (i == 1)
			{
				G = std::stoi(word);
				i++;
			}
			else
			{
				B = std::stoi(word);
			}
		}
		char r[255];
		sprintf_s(r, "%.2X", R);
		result.append(r);

		char g[255];
		sprintf_s(g, "%.2X", G);
		result.append(g);

		char b[255];
		sprintf_s(b, "%.2X", B);
		result.append(b);

		return result;
	}
};
