#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <iostream>
#include <windows.h>

#include <fstream>
#include <stdlib.h>

using namespace std;

class libro
{
private:
	string codigo, titulo, editorial;
	int existencia,prestamos=0; //Existencias - Cuantos libros se han prestado
public:

	void menuLibro();

	void setCodigo(string c)
	{
		codigo=c;
	}
	void setTitulo(string t)
	{
		titulo=t;
	}
	void setEditorial(string e)
	{
		editorial=e;
	}
	void setExistencia(int e)
	{
		existencia=e;
	}
	void setPrestamos(int p)
	{
		prestamos=p;
	}

	string returnCodigo()
	{
		return codigo;
	}
	string returnTitulo()
	{
		return titulo;
	}
	string returnEditorial()
	{
		return editorial;
	}
	int returnExistencia()
	{
		return existencia;
	}
	int returnPrestamos()
	{
		return prestamos;
	}
};

class ListaS ///Lista simple
{
private:
    libro myLibro;
	string myString1,myString2,myString3;
	int myInt1,myInt2;
public:
    ListaS *siguiente;

    void registrarLibro();
    bool mostrarLibro(bool resData); ///¿Respaldar Datos?
    string buscarLibro(bool MIDL,bool retornoMSG, string myString, bool cExis, bool mDevol, bool devol, bool cEPR); // ¿Mostrar informacion del libro? - ¿Quieres retornar mensajes? como: ("Ingresar libro a buscar", "no existe libro", etc...) - codigo a buscar (si el anterior es "false", ingresar un string en este campo) - ¿Contar existencias en prestamo? (marcar "true" exclusivamente si se va a usar para registrar un prestamo) - "Mostrar titulo y editorial del libro que se va a devolver" Apenas se vera si se devolvera (Marcar true en dado que si "Solo en metodo prestamo") - "Devolver" ya se regresara el libro (Marcar true en dado que si "Solo en metodo prestamo" - ¿contar Existencias Para Registro? (Marcar true exclusivamente al buscar un libro al hacer un registro)
	void modificarLibro(string myString,bool Exis); // En caso de que bool "Exis" sea falso, ingresar " " en el canmpo - ¿El libro a modificar puede existir en (registrarLibro)? (Si no se usa en ese metodo marcar "false")
    void ordenarLibro();
    
    void eliminarListaS();
	bool cargarRespaldo();

    libro getLibro()
    {
        return myLibro;
    }
    void setLibro(libro lib)
    {
        myLibro=lib;
    }

}*primeroL,*ultimoL;

void libro::menuLibro()
{
	int op;
	ListaS lista;
	do
	{
		system("CLS");
		cout<<"Este es el menu de los LIBROS\nQue desea hacer"<<endl;
		cout<<"1.- Registrar\n2.- Mostrar\n3.- Buscar\n4.- Modificar\n5.- Ordenar\n6.- Salir\nOP: ";
		cin>>op;
		switch(op)
		{
			case 1:
				lista.registrarLibro();
				system("PAUSE");
				break;
			case 2:
				lista.mostrarLibro(false);
				system("PAUSE");
				break;
			case 3:
			    lista.buscarLibro(true,true," ",false,false,false,false);
				system("PAUSE");
				break;
			case 4:
			    lista.modificarLibro(" ",false);
				system("PAUSE");
				break;
			case 5:
			    lista.ordenarLibro();
				system("PAUSE");
				break;
            case 6:

                break;
			default:
				cout<<"Lo siento, opcion invalida!!";
				system("PAUSE");
				break;
		}
	}while(op!=6);
}

bool ListaS::cargarRespaldo()
{
	ifstream objetoRespaldoL("respaldoLibros.txt");
    if(objetoRespaldoL.is_open())
    {
        while(!objetoRespaldoL.eof())
        {
    		ListaS* nuevo=new ListaS();
			objetoRespaldoL>>myString1;
            objetoRespaldoL>>myString2;
            objetoRespaldoL>>myString3;
            objetoRespaldoL>>myInt1;
            objetoRespaldoL>>myInt2;
            if(objetoRespaldoL.eof()){break;}
            nuevo->myLibro.setCodigo(myString1);
            nuevo->myLibro.setTitulo(myString2);
            nuevo->myLibro.setEditorial(myString3);
            nuevo->myLibro.setExistencia(myInt1);
            nuevo->myLibro.setPrestamos(myInt2);
			
        	if(primeroL==NULL)
        	{
          	  	primeroL=nuevo;
          	  	primeroL->siguiente=NULL;
        		ultimoL=nuevo;
        	}
        	else
        	{
         	   ultimoL->siguiente=nuevo;
         	   nuevo->siguiente=NULL;
         	   ultimoL=nuevo;
        	}
        }
    }else
    {
        cout<<"No existe un respaldo de los registros de los Libros"<<endl<<endl;
    	objetoRespaldoL.close();
    	return false;
    }
    objetoRespaldoL.close();
    return true;
}

void ListaS::eliminarListaS()
{
	ListaS* actual;

    while(primeroL!=NULL){
        actual=primeroL;
        primeroL=primeroL->siguiente;
        delete(actual);
    }
}

void ListaS::registrarLibro()
{
	string codigo, titulo, editorial;
	int existencia;

	string myString;
    int myInt=0;
    float myFloat;
    ListaS* nuevo=new ListaS();
    cout<<endl<<"Ingresa el codigo del libro: ";
    cin.ignore();
    getline(cin,myString);

    if(myString==buscarLibro(true,false,myString,false,false,false,false))
    {
        cout<<"Ya existe un libro con el mismo codigo!!"<<endl;
        modificarLibro(myString,true);
    }else{
        nuevo->myLibro.setCodigo(myString);
        
    do{
        cout<<endl<<"Ingresa el titulo del libro: ";
        getline(cin,myString);
        if(myString=="" || myString==" ")
        {
        	cout<<"\nNo puedes ingresar nulos!!, inserte un dato valido"<<endl<<endl;
		}
	}while(myString=="" || myString==" ");
        nuevo->myLibro.setTitulo(myString);
        
    do{
        cout<<endl<<"Ingresa el editorial del libro: ";
        getline(cin,myString);
        if(myString=="" || myString==" ")
        {
        	cout<<"\nNo puedes ingresar nulos!!, inserte un dato valido"<<endl<<endl;
		}
	}while(myString=="" || myString==" ");
        nuevo->myLibro.setEditorial(myString);
        
        nuevo->myLibro.setExistencia(myInt);
        do{
            cout<<endl<<"Ingresa la existencia del libro: ";
            cin>>myInt;
            if(myInt<0)
            {
                cout<<"No se puede registrar un libro con un numero de existencias en negativo"<<endl;
            }
        }while(myInt<0);
        nuevo->myLibro.setExistencia(myInt);
        cout<<"Registro Hecho!!\n";
        if(primeroL==NULL)
        {
            primeroL=nuevo;
            primeroL->siguiente=NULL;
            ultimoL=nuevo;
        }
        else
        {
            ultimoL->siguiente=nuevo;
            nuevo->siguiente=NULL;
            ultimoL=nuevo;
        }
    }
}

bool ListaS::mostrarLibro(bool resData){ ///¿Respaldar Datos?
    ListaS *actual=new ListaS();
    actual=primeroL;
    if(primeroL!=NULL)
    {
		ifstream respaldo("respaldoLibros.txt");
    	if(respaldo.is_open() && resData==true)
    	{
    		ofstream respaldo("respaldoLibros.txt");
    	}
        while (actual!=NULL)
        {
        	if(resData==false)
        	{
            	cout<<"Codigo: "<<actual->myLibro.returnCodigo()<<"\nTitulo: "<<actual->myLibro.returnTitulo()<<"\nEditorial: "<<actual->myLibro.returnEditorial()<<"\nExistencia: "<<actual->myLibro.returnExistencia()<<endl<<endl;
            	cout<<endl;
			}else
			{
				ofstream respaldo("respaldoLibros.txt",ios::app);
            	respaldo<<actual->myLibro.returnCodigo()<<endl;
            	respaldo<<actual->myLibro.returnTitulo()<<endl;
            	respaldo<<actual->myLibro.returnEditorial()<<endl;
            	respaldo<<actual->myLibro.returnExistencia()<<endl;
            	respaldo<<actual->myLibro.returnPrestamos()<<endl;
			}
			actual=actual->siguiente;
        }
        if(resData==true)
        {
        	eliminarListaS();
		}
        return true;
    }
    else
    {
		if(resData==false){
        	cout<<"Lo siento, pero no existe registro alguno"<<endl;
		}else{
			cout<<"Libros no tiene registros, no se le hara respaldo a este apartado!!"<<endl;
			return false;
		}
    }
}

string ListaS::buscarLibro(bool MIDL,bool retornoMSG, string myString, bool cExis, bool mDevol, bool devol,bool cEPR) //¿Mostrar informacion del libro? - ¿Quieres retornar mensajes? como: ("Ingresar libro a buscar", "no existe libro", etc...) - codigo a buscar (si el anterior es "false", ingresar un string en este campo) - ¿Contar existencias en prestamo? (marcar "true" exclusivamente si se va a usar para registrar un prestamo) - "Mostrar titulo y editorial del libro que se va a devolver" Apenas se vera si se devolvera (Marcar true en dado que si "Solo en metodo prestamo") - "Devolver" ya se regresara el libro (Marcar true en dado que si "Solo en metodo prestamo" - ¿contar Existencias Para Registro? (Marcar true exclusivamente al buscar un libro al hacer un registro)
{
    ListaS *actual=new ListaS();
    actual=primeroL;

    string returnString;
    bool isEncontred=false;

    if(primeroL!=NULL)
    {
    	if(retornoMSG==true)
    	{
        	cout<<"Ingrese el codigo del libro que desea buscar: ";
        	cin.ignore();
        	getline(cin,myString);
    	}
        while (actual!=NULL)
        {
            if(actual->myLibro.returnCodigo()==myString)
            {
            	if(mDevol==false)
            	{
        			returnString=myString;
            		if(MIDL==true)
            		{
            			cout<<endl<<"Libro encontrado"<<endl;
                		cout<<"Codigo: "<<actual->myLibro.returnCodigo()<<"\nTitulo: "<<actual->myLibro.returnTitulo()<<"\nEditorial: "<<actual->myLibro.returnEditorial()<<"\nExistencia: "<<actual->myLibro.returnExistencia()<<endl<<endl;
					}
        			if(cExis==true && cEPR==false)
        			{
        				if(actual->myLibro.returnExistencia()<=0)
        				{
        					cout<<"Lo siento, pero este libro no tiene existencia alguna"<<endl;
        					returnString="";
						}else
						{
							actual->myLibro.setPrestamos(actual->myLibro.returnPrestamos()+1);
							actual->myLibro.setExistencia(actual->myLibro.returnExistencia()-1);
						}
					}else{
						if(actual->myLibro.returnExistencia()<=0 && cEPR==true)
        				{
        					cout<<"Lo siento, pero este libro no tiene existencia alguna"<<endl;
        					returnString="";
						}
					}
				}else{
					if(devol==false)
					{
						cout<<"Titulo del libro: "<<actual->myLibro.returnTitulo()<<endl;
						cout<<"Editorial del libro: "<<actual->myLibro.returnEditorial()<<endl;
					}
				}
				if(devol==true)
				{
					actual->myLibro.setExistencia(actual->myLibro.returnExistencia()+1);
					actual->myLibro.setPrestamos(actual->myLibro.returnPrestamos()-1);
				}
    			return returnString;
        		break;
            }
            else
            {
                actual=actual->siguiente;
            }
        }
        if(isEncontred==false && retornoMSG==true || isEncontred==false && cExis==true)
        {
            cout<<"Libro no encontrado\n";
            returnString=" ";
            return returnString;
        }
    }
    else
    {
        if(retornoMSG==true || cExis==true)
        {
            cout<<endl<<"No existe registro alguno de libros"<<endl;
            returnString=" ";
            return returnString;
        }
    }
}

void ListaS::modificarLibro(string myString,bool Exis) // En caso de que bool "Exis" sea falso, ingresar " " en el canmpo - ¿El libro a modificar puede existir en (registrarLibro)? (Si no se usa en ese metodo marcar "false")
{
	ListaS *actual=new ListaS();
    actual=primeroL;

    string mString;
    int op,op2,mInt;
    bool isModifiqued=false;

    if(primeroL!=NULL)
    {
        if(Exis==false)
        {
            myString=buscarLibro(true,true," ",false,false,false,false);
        }
        if(myString!=" ")
        {
            while(actual!=NULL){
                if(actual->myLibro.returnCodigo()==myString)
                {
                    if(Exis==false)
                    {
                        cout<<"Que desea modificar\n1.- Codigo\n2.- Titulo\n3.- Editorial\n4.- Existencia\n(Elegir una opcion invalida lo regresara al menu de LIBROS)\nOP: ";
                        cin>>op;
                        if(op>0 && op<4)
                        {
                            cout<<"Ingrese el nuevo dato: ";
                            cin.ignore();
                            getline(cin,mString);
                            isModifiqued=true;
                        }
                        switch(op)
                        {
                            case 1:
                                if(mString!=buscarLibro(true,false,mString,false,false,false,false))
                                {
                                	if(actual->myLibro.returnPrestamos()<=0)
                                	{
                                    	actual->myLibro.setCodigo(mString);
									}else{
                                    	cout<<"Lo siento, pero no se puede modificar el codigo mientras no se devuelvan los libros prestados"<<endl;
                                    	isModifiqued=false;
									}
                                }else
                                {
                                    cout<<"Lo siento, pero ese codigo ya existe. Elija otro!!"<<endl;
                                    isModifiqued=false;
                                }
                                break;
                            case 2:
                                actual->myLibro.setTitulo(mString);
                                break;
                            case 3:
                                actual->myLibro.setEditorial(mString);
                                break;
                            case 4:
                                cout<<endl<<endl<<"Que desea hacer con la existencia de los libros\n1.-Incrementar\n2.-Decrementar\n(Ingresar una opcion invalida se le regresara al menu LIBRO)\nOP: ";
                                cin>>op2;
                                switch(op2)
                                {
                                case 1:
                                    cout<<"Cuantos libros se añadiran a la existencia del titulo "<<actual->myLibro.returnTitulo()<<": ";
                                    cin>>mInt;
                                    if(mInt>=0)
                                    {
                                        actual->myLibro.setExistencia(actual->myLibro.returnExistencia()+mInt);
                                        isModifiqued=true;
                                    }else{
                                        cout<<"Lo siento, pero no!! o\\ _ /o"<<endl;
                                    }
                                    break;
                                case 2:
                                    cout<<"Cuantos libros se restaran a la existencia del titulo "<<actual->myLibro.returnTitulo()<<" (Ingresar un numero superior a las existencias actuales, lo regresara al menu LIBRO): ";
                                    cin>>mInt;
                                    if(mInt > actual->myLibro.returnExistencia())
                                    {
                                        cout<<"Lo siento, pero la cantidad ingresada supera al numero de existencias actual. Se le regresara al menu LIBRO"<<endl;
                                    }else{
                                        if(mInt>=0)
                                        {
                                            actual->myLibro.setExistencia(actual->myLibro.returnExistencia()-mInt);
                                            isModifiqued=true;
                                        }else{
                                            cout<<"Lo siento, pero no!! o\\ _ /o"<<endl;
                                        }
                                    }
                                    break;
                                default:
                                    cout<<"Lo siento, pero no ha sido una opcion valida. Se le regresara al menu LIBRO"<<endl;
                                    isModifiqued=false;
                                    break;
                                }
                                break;
                            default:
                                cout<<"Opcion invalida, se le regresara al menu"<<endl;
                                break;
                        }
                        if(isModifiqued==true)
                        {
                            cout<<"Modificacion hecha con exito!!"<<endl;
                        }
                    }else{
                        cout<<"Cuantos libros se añadiran a la existencia del titulo "<<actual->myLibro.returnTitulo()<<": ";
                        cin>>mInt;
                        if(mInt>=0)
                        {
                            actual->myLibro.setExistencia(actual->myLibro.returnExistencia()+mInt);
                            cout<<"Modificacion hecha con exito!!"<<endl;
                        }else{
                            cout<<"Lo siento, pero no!! o\\ _ /o"<<endl;
                        }
                    }
                    break;
                }
                else{
                    actual=actual->siguiente;
                }
            }
        }
    }
}

void ListaS::ordenarLibro()
{
    ListaS *actual=primeroL;
    ListaS *aux=NULL;

    if(primeroL!=NULL)
    {
        while(actual->siguiente!=NULL)
        {
            aux=actual->siguiente;
            while(aux!=NULL)
            {
                if(actual->myLibro.returnTitulo() > aux->myLibro.returnTitulo())
                {
                    myLibro=aux->getLibro();
                    aux->setLibro(actual->getLibro());
                    actual->setLibro(myLibro);
                }
                aux=aux->siguiente;
            }
            actual=actual->siguiente;
        }
        cout<<"Ordenamiento aplicado con exito!!"<<endl;
    }else{
        cout<<"No hay registro alguno!!";
    }


}
#endif // LIBRO_H_INCLUDED
