#pragma once
#include <iostream>
using namespace std;

class nodoK {
public:
	nodoK(string nombre,  int v, nodoK  *sig = NULL)
	{
		filtro = nombre;
		valor = v;
		siguiente = sig;
	}


	int valor;
	string filtro;
	nodoK  *siguiente;

	friend class lista;
};

typedef nodoK  *pnodo;

class listina {
public:
	listina() { actual = NULL; }
	~listina();
	string cadena1, cadena2;
	void Insertar(string filt,int v);
	bool ListaVacia() { return actual == NULL; }
	void MostrarD();
	void Siguiente();
	bool Actual() { return actual != NULL; }
	int ValorActual() { return actual->valor; }


	pnodo actual;
};

listina::~listina()
{
	pnodo nodo;

	// Mientras la lista tenga más de un nodo
	while (actual->siguiente != actual) {
		// Borrar el nodo siguiente al apuntado por lista
		nodo = actual->siguiente;
		actual->siguiente = nodo->siguiente;
		delete nodo;
	}
	// Y borrar el último nodo
	delete actual;
	actual = NULL;
}

void listina::Insertar(string filt,int v)
{
	pnodo Nodo;

	// Creamos un nodo para el nuevo valor a insertar
	Nodo = new nodoK(filt,v);

	// Si la lista está vacía, la lista será el nuevo nodo
	// Si no lo está, insertamos el nuevo nodo a continuación del apuntado
	// por lista
	if (actual == NULL) actual = Nodo;
	else Nodo->siguiente = actual->siguiente;
	// En cualquier caso, cerramos la lista circular
	actual->siguiente = Nodo;
}

void Imprimirlista(string cadena1,string cadena2) {
	
	std::ofstream outfile("Circular.txt");
	outfile << "digraph G {" << std::endl;
	outfile << "rankdir=\"LR\";" << std::endl;
	outfile << "node [ fontname = \" Arial \" ];" << std::endl;
	outfile << cadena1 << std::endl;
	outfile << cadena2 << std::endl;
	outfile << "}" << std::endl;
	outfile.close();


}
void listina::MostrarD()
{ 
	
	pnodo nodo = actual;
	int numero = 0;
	do {
		
		
		
		nodo = nodo->siguiente;
		if (actual == nodo)
		{
			cadena1 += std::to_string(numero) + " [ label = \"" + nodo->filtro + "  \" ];" + "\n";
			cadena2 = nodo->filtro + ";";
		}
		else {
			cadena1 += std::to_string(numero) + " [ label = \"" + nodo->filtro + "  \" ];" + "\n";
			cadena2 = nodo->filtro + "->";
			numero++;
		}
	} while (nodo != actual);
	Imprimirlista(cadena1, cadena2);
	cadena1 = "";
	cadena2 = "";
	cout << endl;
}

void listina::Siguiente()
{
	if (actual) actual = actual->siguiente;
}


