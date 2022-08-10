/*
Autor: SieteSiete
nombre: Ejercicio 14
Tiempo: 00:22
*/
#include <iostream>
#include <string>
using namespace std;
//se crea registro Alumno
struct Alumno{
    string campoCadena;
    int campoEntero;
    float campoFlotante;
};

int main (){
    //se crea el objeto de Alumno
    Alumno alumno;
    //se solicitan los datos
    cout << "Campo cadena: ";
    cin >> alumno.campoCadena;
    cout << "campo entero: ";
    cin >> alumno.campoEntero;
    cout << "campo flotante: ";
    cin >> alumno.campoFlotante;
    //se separan las salidas de consola
    cout << endl;
    //se muestran las salidas de consola
    cout <<"Campo cadena: "<< alumno.campoCadena << endl;
    cout << "Campo entero: "<< alumno.campoEntero << endl;
    cout<<"Campo flotante: "<< alumno.campoFlotante << endl;

    getchar();
}