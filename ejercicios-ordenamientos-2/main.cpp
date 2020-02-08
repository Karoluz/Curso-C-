#include <iostream>
#include <string.h>
using namespace std;

/* Crea un programa que guarde las nota y
 * nombres de 10 alumnos en una matriz, y 
 * muestre las notas de mayor a menor junto
 * con el nombre correcto del alumno. 
 */

int main()
{
	int notas[10];
	string alumnos[10];
	int auxnota;
	string auxname;
	
	cout<<"Introduce las notas y el nombre del alumno"<<endl;
	
	for (int i=0; i<10; i++)
	{
		cout<<"Introduce el nombre del alumno "<<i<<" : ";
		cin>>alumnos[i];
		cout<<"Introduce la nota :";
		cin>>notas[i];
	}
	
	/* ordenando */
	for (int i =0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			if (notas[j]<notas[j+1])
			{
				auxnota = notas[j];
				auxname = alumnos[j];
				
				notas[j] = notas[j+1];
				alumnos[j] = alumnos[j+1];
				
				notas[j+1] = auxnota;
				alumnos[j+1] = auxname;
			}
		}
	}
	
	for (int i =0; i<10; i++)
	{
		cout<<alumnos[i]<<" tiene : "<<notas[i]<<" "<<endl;
	}
	
	return 0;
}
