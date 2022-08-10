#include <iostream>
#include <windows.h>

#include "alumno.h";
#include "libro.h";
#include "prestamo.h";
#include "respaldo.h";

using namespace std;

int main()
{
	int op;
	alumno alum;
	libro lib;
	prestamo pres;
	respaldo res;
	do
	{
		system("CLS");
		cout<<"Bienvenido a la biblioteca de CUCEI\nQue desea hacer"<<endl;
		cout<<"1.- Alumnos\n2.- Libro\n3.- Prestamo\n4.- Respaldar datos\n5.- Mostrar respaldo\n6.- Cargar Respaldo\n7.- Salir\nOP: ";
		cin>>op;
		switch(op)
		{
			case 1:
				alum.menuAlumno();
				break;
			case 2:
				lib.menuLibro();
				break;
			case 3:
				pres.menuPrestamo();
				break;
			case 4:
				res.respaldarDatos();
				break;
			case 5:
				res.mostrarRespaldo();
    			system("PAUSE");
				break;
			case 6:
				res.cargarRespaldo();
    			system("PAUSE");
				break;
			case 7:

				break;
			default:
				cout<<"Lo siento, opcion invalida!!";
				system("PAUSE");
				break;
		}
	}while(op!=7);
}
