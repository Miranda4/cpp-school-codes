#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <iostream>
#include <windows.h>

#include <fstream>
#include <stdlib.h>

using namespace std;

class alumno
{
private:
	string codigo, nombre,correo,telefono;
	int librosCargo;
public:

	void menuAlumno();

	void setCodigo(string c)
	{
		codigo=c;
	}
	void setNombre(string n)
	{
		nombre=n;
	}
	void setCorreo(string c)
	{
		correo=c;
	}
	void setLibrosCargo(int l)
	{
		librosCargo=l;
	}
	void setTelefono(string t)
	{
		telefono=t;
	}

	string returnCodigo()
	{
		return codigo;
	}
	string returnNombre()
	{
		return nombre;
	}
	string returnCorreo()
	{
		return correo;
	}
	int returnLibrosCargo()
	{
		return librosCargo;
	}
	string returnTelefono()
	{
		return telefono;
	}
};

class Pila ///Pila
{
private:
	alumno alum;
	string myString1,myString2,myString3,myString4;
	int myInt1;
public:
    Pila *siguiente;

	void registrarAlumno();
	bool mostrarAlumno(bool resData); ///¿Respaldar Datos?
	string buscarAlumno(string myString,bool exis,bool cExis, bool mDevol, bool devol); /// Nombre por el cual se busca - ¿Puede existir? (True para metodos externos) - ¿Contar existencias para prestamo? (marcar "true" exclusivamente si se va a usar para registrar un prestamo) - "Mostrar nombre del alumno que lo va a devolver" Apenas se vera si se devolvera (Marcar true en dado que si "Solo en metodo prestamo") - "Devolver" ya se devolvera el libro (Marcar true en dado que si "Solo en metodo prestamo")
	void modificarAlumno();
	
	void eliminarPila();
	bool cargarRespaldo();
}*cima;

void alumno::menuAlumno()
{
	int op;
	Pila pil;
	do
	{
		system("CLS");
		cout<<"Este es el menu de los ALUMNOS\nQue desea hacer"<<endl;
		cout<<"1.- Registrar\n2.- Mostrar\n3.- Buscar\n4.- Modificar\n5.- Salir\nOP: ";
		cin>>op;
		switch(op)
		{
			case 1:
				pil.registrarAlumno();
				system("PAUSE");
				break;
			case 2:
				pil.mostrarAlumno(false);
				system("PAUSE");
				break;
			case 3:
                pil.buscarAlumno(" ",false,false,false,false);
                system("PAUSE");
				break;
			case 4:
                pil.modificarAlumno();
				system("PAUSE");
				break;
			case 5:

				break;
			default:
				cout<<"Lo siento, opcion invalida!!";
				system("PAUSE");
				break;
		}
	}while(op!=5);
}

bool Pila::cargarRespaldo()
{
	ifstream objetoRespaldoA("respaldoAlumnos.txt");
    if(objetoRespaldoA.is_open())
    {
        while(!objetoRespaldoA.eof())
        {
			Pila* nuevo=new Pila();
            objetoRespaldoA>>myString1;
            objetoRespaldoA>>myString2;
            objetoRespaldoA>>myString3;
            objetoRespaldoA>>myInt1;
            objetoRespaldoA>>myString4;
            if(objetoRespaldoA.eof()){break;}
			nuevo->alum.setCodigo(myString1);
			nuevo->alum.setNombre(myString2);
			nuevo->alum.setCorreo(myString3);
			nuevo->alum.setLibrosCargo(myInt1);
			nuevo->alum.setTelefono(myString4);
			
			nuevo->siguiente=cima;
    		cima=nuevo;
        }
    }else
    {
        cout<<"No existe un respaldo de los registros de los alumnos"<<endl<<endl;
    	objetoRespaldoA.close();
    	return false;
    }
    objetoRespaldoA.close();
    return true;
}

void Pila::registrarAlumno()
{
	string myString;
	int myInt=0;
	Pila* nuevo=new Pila();
    cout<<"Ingresa el codigo: ";
    cin.ignore();
    getline(cin,myString);
    if(myString==buscarAlumno(myString,true,false,false,false))
    {
        cout<<"Lo siento, pero ya existe un alumno con este codigo"<<endl;
    }else
    {
        nuevo->alum.setCodigo(myString);
    do{
        cout<<"Ingresa el nombre: ";
        getline(cin,myString);
        if(myString=="" || myString==" ")
        {
        	cout<<"\nNo puedes ingresar nulos!!, inserte un dato valido"<<endl<<endl;
		}
	}while(myString=="" || myString==" ");
        nuevo->alum.setNombre(myString);
        
    do{
        cout<<"Ingresa el correo electronico: ";
        getline(cin,myString);
        if(myString=="" || myString==" ")
        {
        	cout<<"\nNo puedes ingresar nulos!!, inserte un dato valido"<<endl<<endl;
		}
	}while(myString=="" || myString==" ");
        nuevo->alum.setCorreo(myString);

        nuevo->alum.setLibrosCargo(myInt);

    do{
        cout<<"Ingresa el numero telefonico: ";
        getline(cin,myString);
        if(myString=="" || myString==" ")
        {
        	cout<<"\nNo puedes ingresar nulos!!, inserte un dato valido"<<endl<<endl;
		}
	}while(myString=="" || myString==" ");
        nuevo->alum.setTelefono(myString);
        cout<<"Registro hecho!!"<<endl;
        
    	nuevo->siguiente=cima;
    	cima=nuevo;
    }
}

void Pila::eliminarPila()
{
	Pila* actual;

    while(cima!=NULL){
        actual=cima;
        cima=cima->siguiente;
        delete(actual);
    }
}

bool Pila::mostrarAlumno(bool resData)///¿Respaldar Datos?
{
	Pila *actual;
	actual=cima;
    if(actual!=NULL)
    {
    	ifstream respaldo("respaldoAlumnos.txt");
    	if(respaldo.is_open() && resData==true)
    	{
    		ofstream respaldo("respaldoAlumnos.txt");
    	}
        while(actual!=NULL){
        	if(resData==false)
        	{
            	cout<<"Codigo: "<<actual->alum.returnCodigo()<<endl;
            	cout<<"Nombre: "<<actual->alum.returnNombre()<<endl;
            	cout<<"Correo: "<<actual->alum.returnCorreo()<<endl;
            	cout<<"Libros a cargo: "<<actual->alum.returnLibrosCargo()<<endl;
            	cout<<"Telefono: "<<actual->alum.returnTelefono()<<endl;
            	cout<<endl;
			}else
			{
				ofstream respaldo("respaldoAlumnos.txt",ios::app);
            	respaldo<<actual->alum.returnCodigo()<<endl;
            	respaldo<<actual->alum.returnNombre()<<endl;
            	respaldo<<actual->alum.returnCorreo()<<endl;
            	respaldo<<actual->alum.returnLibrosCargo()<<endl;
            	respaldo<<actual->alum.returnTelefono()<<endl;
			}
            actual=actual->siguiente;
        }
        if(resData==true)
        {
        	eliminarPila();
		}
        return true;
    }else{
    	if(resData==false){
        	cout<<"Lo siento, pero no existe registro alguno"<<endl;
		}else{
			cout<<"Alumnos no tiene registros, no se le hara respaldo a este apartado!!"<<endl;
			return false;
		}
    }
}

string Pila::buscarAlumno(string myString,bool exis,bool cExis, bool mDevol, bool devol)/// Nombre por el cual se busca - ¿Puede existir? (True para metodos externos) - ¿Contar existencias para prestamo? (marcar "true" exclusivamente si se va a usar para registrar un prestamo) - "Mostrar nombre del alumno que lo va a devolver" Apenas se vera si se devolvera (Marcar true en dado que si "Solo en metodo prestamo") - "Devolver" ya se devolvera el libro (Marcar true en dado que si "Solo en metodo prestamo")
{
	Pila *actual;
	actual=cima;

    string returnString;
    bool isEncontred=false;
    if(actual!=NULL)
    {
        if(exis==false)
        {
            cout<<"Ingrese el codigo del alumno que desea buscar: ";
            cin.ignore();
            getline(cin,myString);
        }
        while(actual!=NULL){
            if(actual->alum.returnCodigo()==myString)
            {
            	if(mDevol==false)
            	{
            		if(cExis==true)
        			{
        				if(actual->alum.returnLibrosCargo()>=3)
        				{
        					cout<<"Lo siento, pero ya no se le pueden prestar mas libros a este alumno"<<endl;
        					returnString=" ";
						}else
						{
							actual->alum.setLibrosCargo(actual->alum.returnLibrosCargo()+1);
        					returnString="a";
						}
					}else
					{
						cout<<endl<<"Alumno encontrado"<<endl;
                		cout<<"Codigo: "<<actual->alum.returnCodigo()<<endl;
        				cout<<"Nombre: "<<actual->alum.returnNombre()<<endl;
        				cout<<"Correo: "<<actual->alum.returnCorreo()<<endl;
        				cout<<"Libros a cargo: "<<actual->alum.returnLibrosCargo()<<endl;
        				cout<<"Telefono: "<<actual->alum.returnTelefono()<<endl<<endl;
        				returnString=myString;
					}
				}else{
					if(devol==false)
					{
						cout<<"Nombre del alumno: "<<actual->alum.returnNombre()<<endl;
					}
				}
				if(devol==true)
				{
					actual->alum.setLibrosCargo(actual->alum.returnLibrosCargo()-1);
				}
        		return returnString;
            }
            else
            {
        		actual=actual->siguiente;
            }
        }
        if(isEncontred==false && exis==false)
        {
            cout<<"Alumno no encontrado\n";
            returnString=" ";
            return returnString;
        }
    }else
    {
        if(exis==false)
        {
            cout<<"Lo siento, pero no hay registro alguno de alumnos!!"<<endl;
            returnString=" ";
            return returnString;
        }
    }
}

void Pila ::modificarAlumno()
{
	Pila *actual;
	actual=cima;

    string myString,mString;
    int op;
    bool isModifiqued=false;
    if(actual!=NULL)
    {
        myString=buscarAlumno(" ",false,false,false,false);
        if(myString!=" ")
        {
            while(actual!=NULL){
                if(actual->alum.returnCodigo()==myString)
                {
                    cout<<"Que desea modificar\n1.- Codigo\n2.- Nombre\n3.- Correo\n4.- Telefono\n(Elegir una opcion invalida lo regresara al menu de alumnos)\nOP: ";
                    cin>>op;
                    if(op>0 && op<5)
                    {
                        cout<<"Ingrese el nuevo dato: ";
                        cin.ignore();
                        getline(cin,mString);
                        isModifiqued=true;
                    }
                    switch(op)
                    {
                        case 1:
                            if(mString!=buscarAlumno(mString,true,false,false,false))
                            {
                            	if(actual->alum.returnLibrosCargo()<=0)
                            	{
                                	actual->alum.setCodigo(mString);
								}else
								{
									cout<<"Lo siento, pero el codigo no puede ser cambiado mientras se tengan prestamos activos"<<endl;
                                	isModifiqued=false;
								}
                            }else{
                                cout<<"Lo siento, pero ya existe ese codigo, elija otro!!"<<endl;
                                isModifiqued=false;
                            }
                            break;
                        case 2:
                            actual->alum.setNombre(mString);
                            break;
                        case 3:
                            actual->alum.setCorreo(mString);
                            break;
                        case 4:
                            actual->alum.setTelefono(mString);
                            break;
                        default:
                            cout<<"Opcion invalida, se le regresara al menu"<<endl;
                            break;
                    }
                    if(isModifiqued==true)
                    {
                        cout<<"Modificacion hecha con exito!!"<<endl;
                    }
                    break;
                }
                else
                {
        			actual=actual->siguiente;
                }
            }
        }
    }else{
        cout<<"Lo siento, pero no existe registro alguno"<<endl;
    }
}
#endif // ALUMNO_H_INCLUDED
