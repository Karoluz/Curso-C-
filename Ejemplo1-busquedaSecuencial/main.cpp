#include <iostream>
using namespace std;

/* busqueda secuencial */

int main()
{
	int lista[5] = {2,6,9,9,7};
    int i = 0, buscar = 0;
    char bandera = 'F';
    
	/* numero a buscar en el arreglo */ 
    buscar = 6;
     
    /*Algoritmo*/
     
    while((bandera == 'F') && (i<=4))
	{
        if(lista[i] == buscar){
            bandera = 'V';
        }
        i++;
    }
     
    if(bandera == 'V'){
        cout<<"El numero "<<buscar<<" ha sido encontrado en la posicion: "<<i-1<<endl;
    } else {
        cout<<"El numero no se encontro.";
    }
     
    return 0;
}
