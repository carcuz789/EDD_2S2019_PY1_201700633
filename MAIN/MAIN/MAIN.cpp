
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "AbrirIn.cpp"
#include <fstream>
#include "ArchImagen.cpp"
#include "DoblementeEnlazada.h"
using namespace std;
void pausa();
void rutaIN();
void Reportes();
void filtros();
OPEN abrir;
int ima;
HTML htm;
listina hola;
int main()
{

	bool bandera = false;
	char tecla = ' ';
	
	do 
	{
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
			cout << "====================== IMAGENES ================" << endl;
			abrir.mostrar_arbol();
			cout << "seleccione el numero de la imagen " << endl;
			cin >> ima;
			abrir.ImagenSelec(ima);
			// guardamos en la variable ima para trabajar con ella 
			pausa();

			break;



		case '3':

			system("cls");
			cout << "Apply Filters.\n";	
			filtros();
			pausa();
			break;



		case '4':

			system("cls");
			cout << "Manual Editing.\n";
			abrir.ArbolConsola();
			pausa();
			break;

		case '5':

			system("cls");
			cout << "Export Image.\n";		
			htm.CreateCss(abrir.BuscaParaImagen());
			system("IMAGEN.html");
			pausa();
			break;
			
		case '6':

			system("cls");
			cout << "Report .\n";
			Reportes();
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
	
	
	
	string name,RUTA;
	cout << "INGRESA EL NOMBRE DEL ARCHIVO INICIAL : \n" << flush;
	cin.get();
	getline(cin, name);
	RUTA = "C:\\Users\\Rodrigo Carcuz\\Desktop\\" + name;
	abrir.separar(RUTA);

	//Arbol.crearNodo(numeroNodoARB, abrir.Retornar_Lista,abrir.MatMandar);
	//numeroNodoARB++;
}
void Reportes() {
	char tecla=' ';
	bool bandera = false;
	do {
		
		system("cls");
		cin.clear();
		cout << "------ REPORTES ------" << endl;
		cout << "1. IMPORTED IMAGES REPORT" << endl;
		cout << "2. IMAGE LAYER REPORT" << endl;
		cout << "3. LINEAR MATRIX REPORT" << endl;
		cout << "4. TRAVERSAL REPORT" << endl;
		cout << "5. FILTERS REPORT -> ALL FILTERS REPORT" << endl;
		cout << "6. FILTERS REPORT -> INDIVIDUAL FILTER REPORT" << endl;
		cout << "7. EXIT" << endl;
		cin >> tecla;
		switch (tecla)

		{

		case '1':
			abrir.Graficar_Arbol();			
			system("dot -Tpng ARBOL.txt -o ARBOL.png");
			system("ARBOL.png");
			
			break;
     	case '2':
			break;			
		case '3':
			break;
		case '4':
			abrir.Imprimir_inorder();
			system("dot -Tpng kk.txt -o INORDER_TRANSVERSAL.png");
			system("INORDER_TRANSVERSAL.png");
			abrir.Imprimir_preorder();
			system("dot -Tpng preord.txt -o PREORDEN_TRANSVERSAL.png");
			system("PREORDEN_TRANSVERSAL.png");
			abrir.Imprimir_postorden();
			system("dot -Tpng postorden.txt -o POSTORDEN_TRANSVERSAL.png");
			system("POSTORDEN_TRANSVERSAL.png");
			pausa();			
			break;
		case '5':
			hola.MostrarD();
			//Circular.txt
			system("dot -Tpng Circular.txt -o TodosLosFiltros.png");
			system("TodosLosFiltros.png");
			break;
		case '6':
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
void filtros() {
	char tecla = ' ';
	bool bandera = false;
	do {

		system("cls");
		cin.clear();
		cout << "------ FILTROS ------" << endl;
		cout << "1. NEGATIVO" << endl;
		cout << "2. GRAYSCALE" << endl;
		cout << "3. MIRROR" << endl;
		cout << "4. COLLAGE" << endl;
		cout << "5. MOSAIC" << endl;
		cout << "6. EXIT" << endl;
		
		cin >> tecla;
		switch (tecla)

		{

		case '1':
			htm.FiltroNEGATi(abrir.BuscaParaImagen());
			system("FiltroNEGA.html");
			hola.Insertar("NEGATIVO",ima);
			break;
		case '2':
			htm.FiltroBlack(abrir.BuscaParaImagen());
			system("FiltroByN.html");
			hola.Insertar("GRAYSCALE", ima);
			break;
		case '3':
			htm.CreateInvert(abrir.BuscaParaImagen());
			system("Invert.html");
			hola.Insertar("MIRROR", ima);
			break;
		case '4':	
			hola.Insertar("MOSAIC", ima);
			break;
		case '5':
			hola.Insertar("MIRROR", ima);
			break;
		case '6':
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
