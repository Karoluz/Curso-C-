#include <iostream>
using namespace std;
/* 
 * Crea un programa en C++ que busque dentro de
 * un arreglo desordenado cuantas veces se repite
 * un número, si es que existe. 
 * El número lo puede elegir el usuario.
 */

int main()
{
	int arreglo_de_10[10] = {1,2,2,3,4,5,6,7,7,7};
	int arreglo_indice[10] = {0};
	int contador_ocurrencias = 0;
	int numero_a_buscar = 0;
	int i;
	bool se_encontro_el_numero = false;
	
	cout<<"Introduce el numero que quieres buscar: ";
	cin>>numero_a_buscar;
	/* busqueda del numero en el arreglo */
	for (i = 0; i<=10; i++)
	{
		if (arreglo_de_10[i] == numero_a_buscar)
		{
			/* indice donde el numero coincide */
			arreglo_indice[i] = 1;
			se_encontro_el_numero = true;
		}
		
	}
	if (se_encontro_el_numero)
	{
		for (i = 0; i<=10; i++)
		{
			if (1 == arreglo_indice[i])
			{
				cout<<"Numero : "<<numero_a_buscar<<" encontrado en la posicion: "<<i<<endl;
				/* Incrementar contador si el numero se encontro */
				contador_ocurrencias++;
			}
		}
		
		cout<<"El numero se encontro "<< contador_ocurrencias;
	}
	else
	{
		cout<<"El numero no se encuentra en la lista"<<endl;
	}
	
	return 0;
}
