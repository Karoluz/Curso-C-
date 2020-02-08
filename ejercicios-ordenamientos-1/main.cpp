#include <iostream>
using namespace std;

/* Implemente el algoritmo de la burbuja de manera que los elementos ordenados queden de mayor a menor. */

int main()
{
	int numeros[10];
	int aux;
	
	cout<<"Introduce 10 numeros"<<endl;
	for  (int i =0; i < 10; i++)
	{
		cout<<"Introduce el numero "<<i<<" : ";
		cin>>numeros[i];
	}
	/* ordenando los numeros */
	for (int i = 0; i<10;i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (numeros[j]>numeros[j+1])
			{
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}
	
	/* mostrando los nuermos ordenados */
	for (int i =0; i<10; i++)
	{
		cout<<numeros[i]<<" ";
	}
	
	return 0;
}
