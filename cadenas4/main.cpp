#include <iostream>
#include <string.h>
using namespace std;
/* Crea un programa en C++ donde el usuario pueda
 * guardar el nombre de 5 alumnos, nombre y apellido,
 * y después concatenar nombre y apellido en una tercer
 * cadena. Imprima en pantalla los datos de los alumnos:
 *
 * Número de alumno.
 * Nombre de alumno.
 * Apellido de alumno.
 * Nombre y apellido de alumno.
 */

int main() 
{
	struct datos_alumno{
		char nombre[10];
		char apellido[20];
		char nombre_apellido[30];
	};
	
	
	datos_alumno alumno[5] = {};
	
	for (int i=0 ; i < 5 ; i++){
		cout<<"Introduce el nombre del alumno "<< i<<": "<<endl;
		cin.getline(alumno[i].nombre,10,'\n');
		cout<<"introduce el apellido del alumno "<< i<<": "<<endl;
		cin.getline(alumno[i].apellido,20,'\n');
		
		/* concatenando nombre y apellido */
		strcpy(alumno[i].nombre_apellido,alumno[i].nombre);
		strcat(alumno[i].nombre_apellido,alumno[i].apellido);
	}
	cout<<"Alumno  Nombre Apellido Concatenado"<<endl;
	for (int i=0 ; i < 5 ; i++){
		cout<<i+1<<" "<<alumno[i].nombre<<" "<<alumno[i].apellido<<" "<<alumno[i].nombre_apellido<<endl;
	}
	
	return 0;
}
