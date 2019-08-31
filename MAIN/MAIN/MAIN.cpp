
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "AbrirIn.cpp"
#include <fstream>
using namespace std;
void pausa();
void rutaIN();
int main()
{
	bool bandera = false;
	char tecla = ' ';
	do {
		system("cls");
		cin.clear();
		cout << "------ MENU ------" << endl;
		cout << "1. INSERT IMAGE" << endl;
		cout << "2. SELECT IMAGE" << endl;
		cout << "3. APPLY FILTERS" << endl;
		cout << "4. MANUAL EDITING" << endl;
		cout << "5. EXPORT IMAGE" << endl;
		cout << "6. REPORTS" << endl;
		cout << "7. EXIT" << endl;
		cin >> tecla;
		switch (tecla)

		{

		case '1':

			system("cls");
			rutaIN();				
			pausa();

			break;



		case '2':

			system("cls");
			
			pausa();

			break;



		case '3':

			system("cls");

			cout << "Apply Filters.\n";
			
			pausa();

			break;



		case '4':

			system("cls");

			cout << "Manual Editing.\n";

			pausa();

			break;

		case '5':

			system("cls");

			cout << "Export Image.\n";

			pausa();

			break;

		case '6':

			system("cls");

			cout << "Report .\n";

			pausa();

			break;

		case '7':

			bandera = true;



			break;



		default:

			system("cls");

			cout << "Opcion no valida.\a\n";

			pausa();

			break;

		}
	} while (bandera != true);
}
void rutaIN() {
	
	OPEN abrir;
	string name;
	cout << "INGRESA LA RUTA : \n" << flush;
	cin.get();
	getline(cin, name);
	abrir.separar(name);
}

void pausa()

{
    
	cout << "Pulsa una tecla para continuar...";

	getwchar();

	getwchar();

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
