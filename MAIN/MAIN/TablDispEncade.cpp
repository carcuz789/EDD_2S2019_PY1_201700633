#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <fstream>
struct Fecha { int dia;    int mes;    int anno; };
class TipoSocio {
protected: 
	int codigo;
	char * nombre;  
	int edad;
	Fecha f;
public: 
	TipoSocio() {};    
	TipoSocio(int c, char *nom, int ed, Fecha fech)
	{ codigo = c; nombre = nom; edad = ed; f = fech; }
	int Ocodigo() { return codigo; }   
	void Pcodigo(int c) { codigo = c; }  
	void Pedad(int e) { edad = e; }   
	int Oedad() { return edad; }
    void Pnombre(char * nom) { nombre = nom; }   
	char * Onombre() { return nombre; }   
	void PFecha(Fecha fech) { f = fech; }   
	Fecha OFecha() { return f; }
};

class Elemento {
protected:
	TipoSocio socio;
	Elemento *sgte; 
public:  
	Elemento(TipoSocio e)
	{
		socio = e;  
		sgte = NULL; 
	}; 
	Elemento() {};  
	Elemento* Osgte() { return sgte; } 
	void Psgte(Elemento *sig) { sgte = sig; }
	TipoSocio Osocio() { return socio; }
	void Psocio(TipoSocio s) { socio = s; }
};
