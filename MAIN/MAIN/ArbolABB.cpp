#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class nodo {
private:
	int clave;
	nodo *izdo;
	nodo *dcho;
	nodo(int cl=0 ,nodo *iz=NULL, nodo *de=NULL) {
		clave = cl;
		izdo = iz;
		dcho = de;
	}
	friend class ArbolEqui;
};
typedef nodo *pnodo;

class ArbolEqui
{
public:
	nodo *raiz;
	void LiberarMem(pnodo);
	//constructores y destructores 
	ArbolEqui(pnodo r = NULL)
	{
		raiz = r;
	}
	~ArbolEqui() { LiberarMem(raiz); }
	//funciones miembro 
	int ArbolVacio(pnodo raiz) { return  raiz == NULL; }
	void Construir(int n) { raiz = construir_arbol(n); }
	void Visualizar(int n) { visualizar_arbol(raiz, n); }
	pnodo construir_arbol(int);
	void visualizar_arbol(pnodo, int);
};
//liberar la memoria ocupada por un arbol funcion recursiva
void ArbolEqui::LiberarMem(pnodo a)
{
	//rrecorido del arbol utilizando el modo postorden 
	if (!ArbolVacio(a)) {
		LiberarMem(a->izdo);
		LiberarMem(a->dcho);
		delete a;
	}
}
//construir un arbol de n nodos perfectamente equilibrado 
pnodo ArbolEqui::construir_arbol(int n)
{
	pnodo nuevonodo;
	int ni, nd;
	if (n == 0)
		return(NULL);
	else
	{
		ni = n / 2;
		nd = n - ni - 1;
		nuevonodo = new nodo;
		cout << "clave"; cin >> nuevonodo->clave;
		nuevonodo->izdo = construir_arbol(ni);
		nuevonodo->dcho = construir_arbol(nd);
		return(nuevonodo);
	}
}
//imprimir el arbol
void ArbolEqui::visualizar_arbol(pnodo a, int n) {
	//imprimir arbol a con margen n se emplea la forma inorden para recorer el arbol
	int i;
	if (!ArbolVacio(a))
	{
		visualizar_arbol(a->izdo, n + 1);
		for ( i = 0; i <= n; i++)
		cout << " ";
		cout << a->clave+"\n";
		visualizar_arbol(a->dcho,n+1);		
	}
}
void iniciar() {
	ArbolEqui arbol_e;
	int n;
	system("cls");
	cout << "numero de nodos: "; cin >> n;
	cout << "introducir claves : \n\n";
	arbol_e.Construir(n);
	system("cls");
	arbol_e.Visualizar(0);
}