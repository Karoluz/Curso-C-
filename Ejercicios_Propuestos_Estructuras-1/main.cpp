#include <iostream>
using namespace std;
/* 
 * 1.- Un programa que pida el nombre,
 * el apellido y la edad de una persona,
 * los almacene en un “struct” y luego muestre
 * los tres datos en una misma línea,
 * separados por comas.
 */

int main()
{
	struct datos{
		char nombre[10];
		char apellido[15];
		int edad;
	};
	
	datos persona;
	cout<<"Introduce tu nombre: "<<endl;
	cin>>persona.nombre;
	cout<<"Introduce tu apellido: "<<endl;
	cin>>persona.apellido;
	cout<<"Introduce tu edad: "<<endl;
	cin>>persona.edad;
	
	cout<<"Nombre: "<<persona.nombre<<" , "<<persona.apellido<<" , "<<persona.edad<<endl;
	
	return 0;
}
