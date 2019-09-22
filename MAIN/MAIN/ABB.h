#pragma once
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <fstream>
#include "Cubo.h"
using namespace std;

typedef struct nodo {
	int nro;
	string NombreIma;
	ListaSimp li;
	Tlista tli;
	vector <vector <string> > mat;
	struct nodo *izq, *der;
}*ABB ;

struct nodoCola {
	ABB ptr;
	struct nodoCola *sgte;
};
struct cola {
	struct nodoCola *delante;
	struct nodoCola *atras;
};
class ArbolEqui
{
public:

	void inicializaCola(struct cola &q)
	{
		q.delante = NULL;
		q.atras = NULL;
	}

	void encola(struct cola &q, ABB n)
	{
		struct nodoCola *p;
		p = new(struct nodoCola);
		p->ptr = n;
		p->sgte = NULL;
		if (q.delante == NULL)
			q.delante = p;
		else
			(q.atras)->sgte = p;
		q.atras = p;
	}

	ABB desencola(struct cola &q)
	{
		struct nodoCola *p;
		p = q.delante;
		ABB n = p->ptr;
		q.delante = (q.delante)->sgte;
		delete(p);
		return n;
	}

	ABB crearNodo(int x,  ListaSimp Cubo,Tlista lis, vector <vector <string> > mati,string nombre)
	{
		ABB nuevoNodo = new(struct nodo);
		nuevoNodo->nro = x;
		nuevoNodo->li = Cubo;
		nuevoNodo->tli=lis;
		nuevoNodo->mat=mati;
		nuevoNodo->NombreIma=nombre;
		nuevoNodo->izq = NULL;
		nuevoNodo->der = NULL;

		return nuevoNodo;
	}
	void insertar(ABB &arbol, int x,ListaSimp Cubo,Tlista lis, vector <vector <string> > mati,string nombre)
	{
		if (arbol == NULL)
		{
			arbol = crearNodo(x,Cubo,lis,mati,nombre);
			cout << "\n\t  Insertado..!" << endl << endl;
		}
		else if (x < arbol->nro) {
			insertar(arbol->izq, x, Cubo,lis, mati,nombre);
		}			
		else if (x > arbol->nro) {
			insertar(arbol->der, x, Cubo,lis, mati,nombre);
		}
			
	}

	void preOrden(ABB arbol)
	{
		if (arbol != NULL)
		{
			cout << arbol->nro << " ";
			preOrden(arbol->izq);
			preOrden(arbol->der);
		}
	}

	void enOrden(ABB arbol)
	{
		if (arbol != NULL)
		{
			enOrden(arbol->izq);
			cout << arbol->nro << " ";
			cout << arbol->NombreIma +"\n"<< endl;
			enOrden(arbol->der);
		}
	}

	void postOrden(ABB arbol)
	{
		if (arbol != NULL)
		{
			enOrden(arbol->izq);
			enOrden(arbol->der);
			cout << arbol->nro << " ";
		}
	}

	void verArbol(ABB arbol, int n)
	{
		
		if (arbol == NULL)
			return;
		
		verArbol(arbol->der, n + 1);

    	  for (int i = 0; i < n; i++)
			cout << "   ";	
		cout << arbol->nro << endl;
		
		verArbol(arbol->izq, n + 1);
		
	}

	ABB busquedaRec(ABB arbol, int dato)
	{
		int r = 0;   // 0 indica que lo encontre

		if (arbol == NULL) {

		}
		if (dato == arbol->nro)
		{
			return arbol;
		}
		if (dato < arbol->nro)
		{
			arbol = busquedaRec(arbol->izq, dato);
			
		}
		else if (dato > arbol->nro)
		{
			arbol = busquedaRec(arbol->der, dato);
			
		}
		else
		{
			r = 1;   // son iguales, lo encontre
		}
		
	}

	ABB unirABB(ABB izq, ABB der)
	{
		if (izq == NULL) return der;
		if (der == NULL) return izq;

		ABB centro = unirABB(izq->der, der->izq);
		izq->der = centro;
		der->izq = izq;
		return der;
	}

	void elimina(ABB &arbol, int x)
	{
		if (arbol == NULL) return;

		if (x < arbol->nro)
			elimina(arbol->izq, x);
		else if (x > arbol->nro)
			elimina(arbol->der, x);

		else
		{
			ABB p = arbol;
			arbol = unirABB(arbol->izq, arbol->der);
			delete p;
		}
	}

	int alturaAB(ABB arbol)
	{
		int AltIzq, AltDer;

		if (arbol == NULL)
			return -1;
		else
		{
			AltIzq = alturaAB(arbol->izq);
			AltDer = alturaAB(arbol->der);

			if (AltIzq > AltDer)
				return AltIzq + 1;
			else
				return AltDer + 1;
		}
	}

	void recorrerxNivel(ABB arbol)
	{
		struct cola q;
		inicializaCola(q);
		cout << "\t";

		if (arbol != NULL)
		{
			encola(q, arbol);

			while (q.delante != NULL)
			{
				arbol = desencola(q);
				cout << arbol->nro << ' ';

				if (arbol->izq != NULL)
					encola(q, arbol->izq);
				if (arbol->der != NULL)
					encola(q, arbol->der);
			}
		}
	}

	ABB arbolEspejo(ABB arbol)
	{
		ABB temp;

		if (arbol != NULL)
		{
			temp = arbol->izq;
			arbol->izq = arbolEspejo(arbol->der);
			arbol->der = arbolEspejo(temp);
		}
		return arbol;
	}

	

	int contarHojas(ABB arbol)
	{
		if (arbol == NULL)
		{
			return 0;
		}
		if ((arbol->der == NULL) && (arbol->izq == NULL))
		{
			return 1;
		}
		else
		{
			return contarHojas(arbol->izq) + contarHojas(arbol->der);
		}
	}	
	void menu()
	{
		//system("cls");
		cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
		cout << "\t [1]  Insertar elemento                  \n";
		cout << "\t [2]  Mostrar arbol                      \n";
		cout << "\t [3]  Recorridos de profundiad           \n";
		cout << "\t [4]  Buscar elemento                    \n";
		cout << "\t [5]  Eliminar elemento                  \n";
		cout << "\t [6]  Recorrido por nieveles (Amplitud)  \n";
		cout << "\t [7]  Altura del arbol                   \n";
		cout << "\t [8]  Construir arbol reflejo            \n";
		cout << "\t [9]  Contar nodos                       \n";
		cout << "\t [x]  Contar hojas                       \n";
		cout << "\t [11]  Nodos menores de 'k'               \n";
		cout << "\t [12] SALIR                              \n";

		cout << "\n\t Ingrese opcion : ";
	}

	void menu2()
	{
		//system("cls");   // para limpiar pantalla
		cout << endl;
		cout << "\t [1] En Orden     \n";
		cout << "\t [2] Pre Orden    \n";
		cout << "\t [3] Post Orden   \n";
		cout << "\n\t     Opcion :  ";
	}
	
	void msain()
	{
		ABB arbol = NULL;
		ListaSimp Cubo ;
		string config[2][5];
		int x;
		int op, op2;


		//system("color f9");   // poner color a la consola
		do
		{
			menu();  cin >> op;
			cout << endl;

			switch (op)
			{
			case 1:
				cout << " Ingrese valor : ";  cin >> x;
				//insertar(arbol, x, Cubo, config);
				break;

			case 2:
				verArbol(arbol, 0);
				break;

			case 3:
				menu2();  cin >> op2;

				if (arbol != NULL)
				{
					switch (op2)
					{
					case 1:
						enOrden(arbol); break;
					case 2:
						preOrden(arbol); break;
					case 3:
						postOrden(arbol); break;
					}
				}
				else
					cout << "\n\t Arbol vacio..!";
				break;

			case 4:
				bool band;

				cout << " Valor a buscar: "; cin >> x;

				band = busquedaRec(arbol, x);

				if (band == 1)
					cout << "\n\tEncontrado...";
				else
					cout << "\n\tNo encontrado...";
				break;

			case 5:
				cout << " Valor a eliminar: "; cin >> x;
				elimina(arbol, x);
				cout << "\n\tEliminado..!";
				break;

			case 6:
				cout << "\n\n Mostrando recorrido por amplitud\n\n";
				recorrerxNivel(arbol);
				break;

			case 7:
				int h;
				h = alturaAB(arbol);
				cout << " La altura es : " << h << endl;
				break;

			case 8:
				ABB espejo;
				espejo = NULL;

				cout << "\n\n Arbol incial \n\n";

				verArbol(arbol, 0);

				cout << "\n\n Arbol espejo \n\n";

				espejo = arbolEspejo(arbol);

				verArbol(espejo, 0);
				break;

		
			


			case 12:
				exit(0);
			}

			cout << "\n\n\n";
			//system("pause");  // hacer pausa y presionar una tecla para continuar
		} while (op != 11);

	}
};
