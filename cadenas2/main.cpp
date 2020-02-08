/* Crea un programa en C++ que determine si una
 * palabra ingresada por el usuario es palíndromo.
 * Palíndromo es una palabra o expresión que es igual
 * si se lee de izquierda a derecha que de derecha a
 * izquierda. Ejemplos: arenera, arepera, anilina, etc.
 */
 
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char palabra[10];
	int tamano;
	int espalindromo = 1;
	
	cout<<"Introduce una palabra: "<<endl;
	cin.getline(palabra,10,'\n');
	
	/* saber el tamano de la palabra */
	tamano = strlen(palabra);
	//cout<<tamano<<endl;	
	
	for (int i = 0; i < tamano ; i++){
		//cout<<palabra[i]<<" "<<palabra[tamano-i-1]<<endl;
			if (palabra[i] != palabra[tamano-i-1]){
				espalindromo = 0;
		}
	}
	
	if (espalindromo)
	{
		cout<<"la palabra es un palindromo";
	}
	else
	{
		cout<<"La palabra no es un palindromo";
	}
	
	
	
	return 0;
}
