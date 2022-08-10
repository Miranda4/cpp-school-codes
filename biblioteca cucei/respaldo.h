#ifndef RESPALDO_H_INCLUDED
#define RESPALDO_H_INCLUDED

#include <windows.h>
#include <string.h>
#include <fstream>

#include "alumno.h";
#include "libro.h";
#include "prestamo.h";

using namespace std;

class respaldo
{
private:
	Pila alumnosR;
	ListaS libroR;
	ListaDE prestamoR;
	
	string myString1, myString2,myString3,myString4,myString5;
	int myInt1,myInt2;
public:
	void respaldarDatos();
	void mostrarRespaldo();
	void cargarRespaldo();
};

void respaldo::respaldarDatos()
{
	if(alumnosR.mostrarAlumno(true)==true)
	{
		cout<<"Respaldo alumnos hecho con exito!!"<<endl;
	}
	if(libroR.mostrarLibro(true)==true)
	{
		cout<<"Respaldo libros hecho con exito!!"<<endl;
	}
	if(prestamoR.mostrarPrestamo(true)==true)
	{
		cout<<"Respaldo Prestamo hecho con exito!!"<<endl;
	}
	
	system("PAUSE");
}

void respaldo::mostrarRespaldo()
{
	system("CLS");
	
	/// 		Respaldo de Alumnos
    ifstream objetoRespaldoA("respaldoAlumnos.txt");
    if(objetoRespaldoA.is_open())
    {
    	cout<<"\n\t --------- Respaldo de alumnos ---------\n\n"<<endl;
        while(!objetoRespaldoA.eof())
        {
            objetoRespaldoA>>myString1;
            objetoRespaldoA>>myString2;
            objetoRespaldoA>>myString3;
            objetoRespaldoA>>myInt1;
            objetoRespaldoA>>myString4;
            if(objetoRespaldoA.eof()){break;}
            cout<<"Codigo: "<<myString1<<endl;
            cout<<"Nombre: "<<myString2<<endl;
            cout<<"Correo: "<<myString3<<endl;
            cout<<"Libros a cargo: "<<myInt1<<endl;
            cout<<"Telefono: "<<myString4<<endl;
            
            cout<<endl;
        }
    }else
    {
        cout<<"No existe un respaldo de los registros de los alumnos"<<endl<<endl;
    }
    objetoRespaldoA.close();
	/// 		Respaldo de Alumnos
	
	
	/// 		Respaldo de Libros
    ifstream objetoRespaldoL("respaldoLibros.txt");
    if(objetoRespaldoL.is_open())
    {
    	cout<<"\n\t --------- Respaldo de Libros ---------\n\n"<<endl;
        while(!objetoRespaldoL.eof())
        {
            objetoRespaldoL>>myString1;
            objetoRespaldoL>>myString2;
            objetoRespaldoL>>myString3;
            objetoRespaldoL>>myInt1;
            objetoRespaldoL>>myInt2;
            if(objetoRespaldoL.eof()){break;}
			cout<<"Codigo: "<<myString1;
			cout<<"\nTitulo: "<<myString2;
			cout<<"\nEditorial: "<<myString3;
			cout<<"\nExistencia: "<<myInt1<<endl<<endl;
        }
    }else
    {
        cout<<"No existe un respaldo de los registros de los libros"<<endl<<endl;
    }
    objetoRespaldoL.close();
	/// 		Respaldo de Libros
	
	/// 		Respaldo de Prestamo
	
    ifstream objetoRespaldoP("respaldoPrestamo.txt");
    if(objetoRespaldoP.is_open())
    {
    	cout<<"\n\t --------- Respaldo de Prestamos ---------\n\n"<<endl;
        while(!objetoRespaldoP.eof())
        {
            objetoRespaldoP>>myInt1;
            objetoRespaldoP>>myString1;
            objetoRespaldoP>>myString2;
            objetoRespaldoP>>myString3;
            objetoRespaldoP>>myInt2;
            if(objetoRespaldoP.eof()){break;}
        	cout<<"\tFolio: "<<myInt1;
            cout<<"\tFecha del prestamo: "<<myString1<<endl;
            cout<<"Codigo del alumno: "<<myString2<<endl;
            cout<<"Codigo del libro: "<<myString3<<endl;
            cout<<"Estatus: "<<myInt2<<endl<<endl;
        }
    }else
    {
        cout<<"No existe un respaldo de los registros de los Prestamos"<<endl<<endl;
    }
    objetoRespaldoP.close();
	
	/// 		Respaldo de Prestamo
}

void respaldo::cargarRespaldo()
{
	//Cargar respaldo Alumnos
	ifstream objetoRespaldoA("respaldoAlumnos.txt");
	if(objetoRespaldoA.is_open())
    {
		alumnosR.eliminarPila();
    	if(alumnosR.cargarRespaldo()==true)
		{
			cout<<"El respaldo de alumnos se ha cargado!!"<<endl;
			objetoRespaldoA.close();
            remove("respaldoAlumnos.txt");
		}
    }else
    {
    	cout<<"No existe un archivo de respaldo de los alumnos!!\nNo se eliminaron los registros de la memoria"<<endl<<endl;
	}
	objetoRespaldoA.close();
	//Cargar respaldo Alumnos
	
	
	//Cargar respaldo Libros
	ifstream objetoRespaldoL("respaldoLibros.txt");
	if(objetoRespaldoL.is_open())
    {
    	libroR.eliminarListaS();
    	if(libroR.cargarRespaldo()==true)
		{
			cout<<"El respaldo de libros se ha cargado!!"<<endl;
			objetoRespaldoL.close();
            remove("respaldoLibros.txt");
		}
    }else
    {
    	cout<<"No existe un archivo de respaldo de los libros!!\nNo se eliminaron los registros de la memoria"<<endl<<endl;
	}
	objetoRespaldoL.close();
	//Cargar respaldo Libros
	
	//Cargar respaldo Prestamos
    ifstream objetoRespaldoP("respaldoPrestamo.txt");
	if(objetoRespaldoP.is_open())
    {
    	prestamoR.eliminarListaDE();
    	if(prestamoR.cargarRespaldo()==true)
		{
			cout<<"El respaldo de Prestamos se ha cargado!!"<<endl;
			objetoRespaldoP.close();
            remove("respaldoPrestamo.txt");
		}
    }else
    {
    	cout<<"No existe un archivo de respaldo de los libros!!\nNo se eliminaron los registros de la memoria"<<endl<<endl;
	}
	objetoRespaldoP.close();
	//Cargar respaldo Prestamos
}

#endif // RESPALDO_H_INCLUDED
