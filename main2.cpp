/*nickName: SieteSiete
ejercicio 12
Tiempo: 00:04
*/
#include <iostream>
//se define la constante
#define MAXIMO_ASISTENCIAS 34

using namespace std;

int main()
{
    //se declaran variables
    int cantFaltas = 0;
    float porcAsistencia = 0;
    //se solicitan datos
    cout<< "Ingrese cantidad de faltas: ";
    //se leen datos
    cin>>cantFaltas;
    //Se realizan las operaciones correspondientes para obtener el resultado solicitado
    porcAsistencia = MAXIMO_ASISTENCIAS - cantFaltas;
    porcAsistencia = (porcAsistencia * 100) / MAXIMO_ASISTENCIAS;
    //se imprime el resultado solicitado/esperado
    cout<< "Porcentaje de asistencias: "<< porcAsistencia << "%";
    return 0;
}
