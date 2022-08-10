#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>

#include <fstream>
#include <stdlib.h>

#include "alumno.h";
#include "libro.h";

using namespace std;

class prestamo
{
private:
	int folio=0,estatus;
	string fecha;
	string CA,CL; //Codigo Alumno - Codigo Libro
public:
    void menuPrestamo();
    void setFolio(int f)
    {
    	folio=f;
	}
	void setEstatus(int e)
	{
		estatus=e;
	}
	void setCodA(string a)
	{
		CA=a;
	}
	void setCodL(string l)
	{
		CL=l;
	}
	void setDate(string d)
	{
		fecha=d;
	}
	
	int returnFolio()
	{
		return folio;
	}
	int returnEstatus()
	{
		return estatus;
	}
	string returnCodAl()
	{
		return CA;
	}
	string returnCodLib()
	{
		return CL;
	}
	string returnDate()
	{
		return fecha;
	}
};

class ListaDE /// lista doblemente enlazada
{
private:
	prestamo myPrestamo;
	Pila myAlumno;
	ListaS myLibro;
	
	string myString1,myString2,myString3;
	int myInt1,myInt2;
public:
    ListaDE *siguiente;
    ListaDE *anterior;

    void registrarPrestamo();
    void devolverPrestamo();
    bool mostrarPrestamo(bool resData); ///¿Respaldar Datos?
    
    void inicializarFolio();
    void eliminarListaDE();
	bool cargarRespaldo();

}*primeroDE,*ultimoDE;

bool ListaDE::cargarRespaldo()
{
	ifstream objetoRespaldoP("respaldoPrestamo.txt");
    if(objetoRespaldoP.is_open())
    {
        while(!objetoRespaldoP.eof())
        {
    		ListaDE* nuevo=new ListaDE();
            objetoRespaldoP>>myInt1;
            objetoRespaldoP>>myString1;
            objetoRespaldoP>>myString2;
            objetoRespaldoP>>myString3;
            objetoRespaldoP>>myInt2;
            if(objetoRespaldoP.eof()){break;}
            nuevo->myPrestamo.setFolio(myInt1);
            nuevo->myPrestamo.setDate(myString1);
            nuevo->myPrestamo.setCodA(myString2);
            nuevo->myPrestamo.setCodL(myString3);
            nuevo->myPrestamo.setEstatus(myInt2);
			
        	if(primeroDE==NULL)
    		{
        		primeroDE=ultimoDE=nuevo;
    		}
    		else
    		{
       			ultimoDE->siguiente=nuevo;
        		nuevo->anterior=ultimoDE;
        		ultimoDE=nuevo;
    		}
        }
    }else
    {
        cout<<"No existe un respaldo de los registros de los Prestamos"<<endl<<endl;
    	objetoRespaldoP.close();
    	return false;
    }
    objetoRespaldoP.close();
    return true;
}

void ListaDE::eliminarListaDE()
{
	ListaDE* actual;

    while(primeroDE!=NULL){
        actual=primeroDE;
        primeroDE=primeroDE->siguiente;
        delete(actual);
    }
}

bool ListaDE::mostrarPrestamo(bool resData)
{
	ListaDE *actual=new ListaDE();
    actual=primeroDE;

    if(primeroDE!=NULL)
    {
		ifstream respaldo("respaldoPrestamo.txt");
    	if(respaldo.is_open() && resData==true)
    	{
    		ofstream respaldo("respaldoPrestamo.txt");
    	}
        while (actual!=NULL)
        {
        	if(resData==false)
        	{
        		cout<<"\tFolio: "<<actual->myPrestamo.returnFolio();
            	cout<<"\tFecha del prestamo: "<<actual->myPrestamo.returnDate()<<endl;
            	cout<<"Codigo del alumno: "<<actual->myPrestamo.returnCodAl()<<endl;
            	cout<<"Codigo del libro: "<<actual->myPrestamo.returnCodLib()<<endl;
            	cout<<"Estatus: "<<actual->myPrestamo.returnEstatus()<<endl<<endl;
			}else
			{
				ofstream respaldo("respaldoPrestamo.txt",ios::app);
            	respaldo<<actual->myPrestamo.returnFolio()<<endl;
            	respaldo<<actual->myPrestamo.returnDate()<<endl;
            	respaldo<<actual->myPrestamo.returnCodAl()<<endl;
            	respaldo<<actual->myPrestamo.returnCodLib()<<endl;
            	respaldo<<actual->myPrestamo.returnEstatus()<<endl;
			}
			actual=actual->siguiente;
        }
        if(resData==true)
        {
        	eliminarListaDE();
		}
        return true;
    }
    else
    {
    	if(resData==false)
    	{
        	cout<<endl<<"No hay ningun prestamo registrado!!"<<endl;
		}else
		{
			cout<<"Prestamo no tiene registros, no se le hara respaldo a este apartado!!"<<endl;
			return false;
		}
    }
}

void ListaDE::inicializarFolio()
{
	ListaDE *actual=new ListaDE();
    actual=primeroDE;
    int i=0;
    if(primeroDE!=NULL)
    {
        while (actual!=NULL)
        {
        	i++;
            actual=actual->siguiente;
        }
        myPrestamo.setFolio(i);
    }
    else
    {
        myPrestamo.setFolio(i);
    }
}

void ListaDE::registrarPrestamo()
{
	string codL="",codA,codL2;
	int est=1;
	
	///Fecha
	time_t t;
	struct tm *tm;
	char fechayhora[100];
	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora,100,"%d/%m/%y-%H:%M:%S", tm);
	///Fecha
	
	cout<<endl<<"\tFolio: "<<myPrestamo.returnFolio()+1<<"\nFecha: ";printf("%s\n\n",fechayhora);
	cout<<endl;
	codA=myAlumno.buscarAlumno(" ",false,false,false,false);
	if(codA!=" ")
	{
		cout<<"Ingrese el codigo del libro que desea buscar: ";
    	fflush(stdin);
		getline(cin,codL2);
		codL=myLibro.buscarLibro(true,false,codL2,false,false,false,true);
		if(codL!="")
		{
			if(myAlumno.buscarAlumno(codA,true,true,false,false)!=" ")
			{
    			ListaDE* nuevo=new ListaDE();
    			nuevo->myPrestamo.setFolio(myPrestamo.returnFolio()+1);
    			nuevo->myPrestamo.setDate(fechayhora);
    			myPrestamo.setFolio(myPrestamo.returnFolio()+1);
				myLibro.buscarLibro(false,false,codL2,true,false,false,false);
    			nuevo->myPrestamo.setEstatus(est);
    			nuevo->myPrestamo.setCodA(codA);
    			nuevo->myPrestamo.setCodL(codL);
    			cout<<"Registro hecho con exito!!"<<endl;
    			if(primeroDE==NULL)
    			{
        			primeroDE=ultimoDE=nuevo;
    			}
    			else
    			{
       				ultimoDE->siguiente=nuevo;
        			nuevo->anterior=ultimoDE;
        			ultimoDE=nuevo;
    			}
			}
		}else{
			cout<<"Lo siento, pero no se encontro el libro o no tiene existencias disponibles"<<endl;
		}
	}
	
}

void ListaDE::devolverPrestamo()
{
	ListaDE *actual=new ListaDE();
    actual=primeroDE;
    
    int myInt,op;
    bool isEncontred=false;

    if(primeroDE!=NULL)
    {
        cout<<"Ingrese el numero de Folio: ";
        cin>>myInt;
        while (actual!=NULL)
        {
            if(actual->myPrestamo.returnFolio()==myInt)
            {
				isEncontred=true;
            	if(actual->myPrestamo.returnEstatus()!=0)
            	{
            		cout<<endl<<"\t\tFolio encontrado"<<endl;
            		cout<<"\tFecha del prestamo fue el "<<actual->myPrestamo.returnDate()<<endl;
                	cout<<"Codigo del alumno: "<<actual->myPrestamo.returnCodAl()<<endl;
                	myAlumno.buscarAlumno(actual->myPrestamo.returnCodAl(),true,false,true,false);
                	cout<<"Codigo del libro: "<<actual->myPrestamo.returnCodLib()<<endl;
                	myLibro.buscarLibro(false,false,actual->myPrestamo.returnCodLib(),false,true,false,false);
                	do{
						cout<<"Desea devolver el libro\n1.- Si\n2.- No\nOP: ";
						cin>>op;
					}while(op<1 && op>2);
                	switch(op)
                	{
                		case 1:
                			cout<<"El libro del Folio: "<<myInt<<" se ha devuelto"<<endl;
                			myAlumno.buscarAlumno(actual->myPrestamo.returnCodAl(),true,false,true,true);
                			myLibro.buscarLibro(false,false,actual->myPrestamo.returnCodLib(),false,true,true,false);
                			actual->myPrestamo.setEstatus(0);
                			break;
                		case 2:
                			cout<<"Se le regresara al menu de PRESTAMO"<<endl;
                			break;
					}
				}else
				{
					cout<<"Lo siento, pero el prestamo de ese numero de FOLIO ya fue devuelto"<<endl;
				}
				break;
            }
            else
            {
                actual=actual->siguiente;
            }
        }
        if(isEncontred==false)
        {
            cout<<"Folio no encontrado\n";
        }
    }
    else
    {
        cout<<endl<<"No hay ningun prestamo registrado!!"<<endl;
    }
}

void prestamo::menuPrestamo()
{
    int op;
    ListaDE LP;
    LP.inicializarFolio();
	do
	{
		system("CLS");
		cout<<"Este es el menu de PRESTAMO\nQue desea hacer"<<endl;
		cout<<"1.- Registrar\n2.- Devolver\n3.- Mostrar\n4.- Salir\nOP: ";
		cin>>op;
		switch(op)
		{
			case 1:
				LP.registrarPrestamo();
                system("PAUSE");
				break;
			case 2:
				LP.devolverPrestamo();
                system("PAUSE");
				break;
			case 3:
				LP.mostrarPrestamo(false);
                system("PAUSE");
				break;
			case 4:
				
				break;
			default:
				cout<<"Lo siento, opcion invalida!!";
				system("PAUSE");
				break;
		}
	}while(op!=4);
}

#endif // PRESTAMO_H_INCLUDED
