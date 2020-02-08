#include <iostream>
using namespace std;

/* Ordenamiento por insercion */

int main()
{
	int lista[5] = {5,3,2,4,1};
	int posicion = 0, aux = 0;
	
	for (int i =0; i<5; i++){
		posicion = i;
		aux = lista[i];
		
		while ((lista[posicion-1] > aux) && (posicion > 0)){
			lista[posicion] = lista[posicion-1];
			posicion--;
		}
		
		lista[posicion] = aux;
	}
	
	for (int i=0; i<5; i++){
		cout<<lista[i]<<" ";
	}
	return 0;
}
