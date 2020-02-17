#include <iostream>
using namespace std;
/* Busqueda secuencial */
/* encontrar todas la coincidencias del numero */

int main()
{
	int lista[5] = {2,6,9,9,9};
    int i = 0, buscar = 0;
    char resultados[5] = {'F', 'F', 'F', 'F', 'F'};
     
    buscar = 9;/* numero a buscar */
     
    /*Algoritmo*/
     
    for(i=0; i<=4; i++){
        if(lista[i] == buscar){
            resultados[i] = 'V';
        }
    }
     
    i=0;
     
    for(int j=0; j<=4; j++){
        if(resultados[j] == 'V'){
            cout<<"Se encontro el numero "<<buscar<<" en la posicion "<<j<<endl;
            i++;
        }
    }
     
    cout<<"El numero se encontro "<<i<<" veces.";
     
    return 0;
}
