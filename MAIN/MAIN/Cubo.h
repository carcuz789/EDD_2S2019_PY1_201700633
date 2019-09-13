#pragma once
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct nodod {
	vector <vector <string> > data;
	int numero;
	string nombre;
	struct nodod *sgte;
};
typedef struct nodod *Tlista;

class ListaSimp {
public:
	void insertarInicio(Tlista &lista, vector <vector <string> > data1, int numero,string name)
	{
		Tlista q;
		q = new(struct nodod);
		q->data = data1;
		q->numero = numero;
		q->nombre = name;
		q->sgte = lista;
		lista = q;
	}

	void insertarFinal(Tlista &lista, vector <vector <string> > data1, int numero,string name)
	{
		Tlista t, q = new(struct nodod);

		q->data = data1;
		q->nombre = name;
		q->numero = numero;
		q->sgte = NULL;

		if (lista == NULL)
		{
			lista = q;
		}
		else
		{
			t = lista;
			while (t->sgte != NULL)
			{
				t = t->sgte;
			}
			t->sgte = q;
		}

	}

	int insertarAntesDespues()
	{
		int _op, band;
		cout << endl;
		cout << "\t 1. Antes de la posicion           " << endl;
		cout << "\t 2. Despues de la posicion         " << endl;

		cout << "\n\t Opcion : "; cin >> _op;

		if (_op == 1)
			band = -1;
		else
			band = 0;

		return band;
	}
	//por si se modifica una matriz insertarla en la pos qu
	void insertarElemento(Tlista &lista, vector <vector <string> > data1, int pos,string name)
	{
		Tlista q, t;
		int i;
		q = new(struct nodod);
		q->data = data1;
		q->numero = pos;
		q->nombre = name;
		if (pos == 1)
		{
			q->sgte = lista;
			lista = q;
		}
		else
		{
			int x = insertarAntesDespues();
			t = lista;

			for (i = 1; t != NULL; i++)
			{
				if (i == pos + x)
				{
					q->sgte = t->sgte;
					t->sgte = q;
					return;
				}
				t = t->sgte;
			}
		}
		cout << "   Error...Posicion no encontrada..!" << endl;
	}

	void buscarElemento(Tlista lista, int numero)
	{
		//ingresar un numero y hacer q=q->sgte hasta que llegue a la matriz
		Tlista q = lista;
		int i = 1, band = 0;

		while (q != NULL)
		{
			if (q->numero == numero)
			{
				cout << endl << " Encontrada en posicion " << i << endl;
				cout << "capa -> " + q->nombre<< endl;
				band = 1;
			}
			q = q->sgte;
			i++;
		}

		if (band == 0)
			cout << "\n\n Numero no encontrado..!" << endl;
	}

	void reportarLista(Tlista lista)
	{
		int i = 0;

		while (lista != NULL)
		{
			
			cout <<  lista->numero << endl;
			cout << lista->nombre + "\n"<< endl;
			lista = lista->sgte;
			i++;
		}
	}


	void eliminarElemento(Tlista &lista, int valor)
	{
		Tlista p, ant;
		p = lista;

		if (lista != NULL)
		{
			while (p != NULL)
			{
				if (p->numero == valor)
				{
					if (p == lista)
						lista = lista->sgte;
					else
						ant->sgte = p->sgte;

					delete(p);
					return;
				}
				ant = p;
				p = p->sgte;
			}
		}
		else
			cout << " Lista vacia..!";
	}

};
