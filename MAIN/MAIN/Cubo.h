#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo {

	string matriz[100][100];
	string nombre;
	int numero;
	struct nodo *sgte;
};

typedef struct nodo *Tlista;
class ListaSimp {
	void insertarInicio(Tlista &lista,string matriz1[100][100], int numero,string name)
	{
		Tlista q;
		q = new(struct nodo);
		q->matriz[100][100] = matriz1[100][100];
		q->nombre = name;
		q->numero = numero;
		q->sgte = lista;
		lista = q;
	}

	void insertarFinal(Tlista &lista, string matriz1[100][100], int numero, string name)
	{
		Tlista t, q = new(struct nodo);

		q->matriz[100][100] = matriz1[100][100];
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
	void insertarElemento(Tlista &lista, string mat[100][100], int pos,string nombre)
	{
		Tlista q, t;
		int i;
		q = new(struct nodo);
		q->matriz[100][100] = mat[100][100];
		q->nombre = nombre;
		q->numero = pos;
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

	void buscarElemento(Tlista lista, string NombCapa)
	{
		//ingresar un numero y hacer q=q->sgte hasta que llegue a la matriz
		Tlista q = lista;
		int i = 1, band = 0;

		while (q != NULL)
		{
			if (q->nombre == NombCapa)
			{
				cout << endl << " Encontrada en posicion " << i << endl;
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
			cout << ' ' << i + 1 << ") " << lista->matriz << endl;
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
