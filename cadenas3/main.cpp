/*  Crea un programa en C++ que pueda realizar lo siguiente:
 * Declarar una cadena al inicio.
 * Determinar la longitud de dicha cadena.
 * Con la longitud declarar otra cadena.
 * Pasar los datos de la cadena 1 a la cadena 2.
 */
 
#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
	char cadena_ini[25];
	int size_cadena_ini;
	
	cout<<"Introduce la cadena de caracteres: "<<endl;
	cin.getline(cadena_ini,25,'\n');
	
	size_cadena_ini = strlen(cadena_ini);
	cout<<"El tamano es: "<<size_cadena_ini<<endl;
	
	char cadena_dos[size_cadena_ini];
	
	strcpy(cadena_dos,cadena_ini);
	
	cout<<"La cadena inicial es: "<<cadena_ini<<endl;
	cout<<"La cadena dos es: "<<cadena_dos<<endl;
	return 0;
}
