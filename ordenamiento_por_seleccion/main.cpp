#include <iostream>
using namespace std;

/* ordenamiento_por_seleccion */

int main()
{
	int numeros[5] = {2,3,5,1,4};
	int aux = 0, minimo = 0;
	
	for (int i=0; i<5; i++){
		minimo = i;
		for (int j=i+1; j<5; j++){
			if (numeros[j] < numeros[minimo]){
				minimo = j;
			}
		}
		aux = numeros[i];
		numeros[i] = numeros[minimo];
		numeros[minimo] = aux;
	}
	
	cout<<"Arreglo ordenado de menor a mayor: ";
	for (int i = 0; i<5; i++){
		cout<<numeros[i]<<" ";
	}
	return 0;
}
