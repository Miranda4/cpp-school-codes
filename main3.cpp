/*
NickName: SieteSiete
ejercicio 13
Tiempo: 00:12
*/
#include <iostream>

using namespace std;

int main()
{   //Se declaran los vectores y multiplicador
    int vectorBase[10], vectorResultados[10], multiplicador = 0;
    //Se crea ciclo iterador para solicitar datos y escribirlos en el vectorBase
        for (int i = 0; i < 10; i++){
            cout << "Ingrese el valor"<< i <<" del vector: ";
            cin >> vectorBase[i];
        }
        //Se solicita multiplicador para cada uno de los datos del vector base
        cout << "Ingrese multiplicador" << endl;
        cin >> multiplicador;
        for (int i = 0; i < 10; i++){
            //se multiplican los datos del vectorBase por el multiplicador y se escriben en vectorResultados
            vectorResultados[i] = vectorBase[i] * multiplicador;
            cout << vectorResultados[i] << endl;
        }
    return 0;
}
