#include <iostream>
#include <string.h>
using namespace std;
/* Crea un programa que ingrese los datos de 20 alumnos,
 * nombre, apellido, nombre de materia 1, calificación materia 1,
 * nombre de materia 2, calificación materia 2, nombre de materia 3,
 * calificación materia 3, nombre de materia 4, calificación materia 4,
 * nombre de materia 5, calificación materia 5. Y después calcular el
 * promedio general de cada alumno, y promedio final del grupo de 20 alumnos.
 *
 * Mostrar en pantalla.
 * Nombre con apellido del alumno.
 * Promedio general de alumno.
 * Materia con mayor calificación.
 * Materia con menor calificación.
 * Y al final el promedio general del grupo.
 *
 * Una vez que se muestre en pantalla, darle la opción al usuario
 * si todos los datos están correctos, y de no ser así se
 * pueda modificar el dato erróneo y posteriormente mostrar
 * de nuevo los datos en pantalla ya con los datos correctos.
 */

int main()
{
	struct datos_alumno{
		char nombre[20];
		char apellido[20];
		float calif_mat_1;
		float calif_mat_2;
		float calif_mat_3;
		float calif_mat_4;
		float calif_mat_5;
		float calif_mayor;
		char nom_mat_mayor[20];
		float calif_menor;
		char nom_mat_menor[20];
		float promedio;
	};
	
	struct datos_materia{
		char nom_mat[20];
	};
	datos_alumno alumno[20];
	datos_materia materia[5];
	float promedio_grupo;
	char opcion, masalumnos;
	bool ya_guardados = 0;
	int num_alum;
	
	/* Introduce las 5 materias */
	cout<<" Introduciendo las materias "<<endl;
	cout<<" ************************** "<<endl;
	for (int j = 0; j < 5; j++){
		cout<<"Introduce el nombre de la materia "<<j+1<<" : ";
		cin>>materia[j].nom_mat;
	}
	
	do{
		if (ya_guardados)
		{
			do
			{
				cout<<"Cual alumno quieres modificar 1-20: ";
				cin>>num_alum;
			
				cout<<"Alumno "<<num_alum<<" : "<<endl;
				cout<<"*******************"<<endl;
				cout<<"Introduce el nombre del alumno: ";
				cin>>alumno[num_alum-1].nombre;
				cout<<"Introduce el apellido del alumno: ";
				cin>>alumno[num_alum-1].apellido;
				cout<<"Introduce la calificacion de "<<materia[0].nom_mat<<" : ";
				cin>>alumno[num_alum-1].calif_mat_1;
				cout<<"Introduce la calificacion de "<<materia[1].nom_mat<<" : ";
				cin>>alumno[num_alum-1].calif_mat_2;
				cout<<"Introduce la calificacion de "<<materia[2].nom_mat<<" : ";
				cin>>alumno[num_alum-1].calif_mat_3;
				cout<<"Introduce la calificacion de "<<materia[3].nom_mat<<" : ";
				cin>>alumno[num_alum-1].calif_mat_4;
				cout<<"Introduce la calificacion de "<<materia[4].nom_mat<<" : ";
				cin>>alumno[num_alum-1].calif_mat_5;
				
				cout<<"Quieres modificar otro alumno S/N ? ";
				cin>>masalumnos;
				cout<<endl;
			}while(masalumnos == 'S' || masalumnos == 's');
		}
		else
		{
			/* Introduce los 20 alumnos */
			cout<<" Introduciendo calificaciones "<<endl;
			cout<<" **************************** "<<endl;
			for (int i = 0; i < 3 ; i++){
				cout<<"Alumno "<<i+1<<" : "<<endl;
				cout<<"*******************"<<endl;
				cout<<"Introduce el nombre del alumno: ";
				cin>>alumno[i].nombre;
				cout<<"Introduce el apellido del alumno: ";
				cin>>alumno[i].apellido;
						
				cout<<"Introduce la calificacion de "<<materia[0].nom_mat<<" : ";
				cin>>alumno[i].calif_mat_1;
				cout<<"Introduce la calificacion de "<<materia[1].nom_mat<<" : ";
				cin>>alumno[i].calif_mat_2;
				cout<<"Introduce la calificacion de "<<materia[2].nom_mat<<" : ";
				cin>>alumno[i].calif_mat_3;
				cout<<"Introduce la calificacion de "<<materia[3].nom_mat<<" : ";
				cin>>alumno[i].calif_mat_4;
				cout<<"Introduce la calificacion de "<<materia[4].nom_mat<<" : ";
				cin>>alumno[i].calif_mat_5;
				
				cout<<endl;
			}
			
			ya_guardados = 1;
		}
		
	/* Mostrando resultados */
	for (int i = 0; i < 20 ; i++){
		/* calculando promedio de cada alumno */
		alumno[i].promedio = (alumno[i].calif_mat_1 + alumno[i].calif_mat_2 + alumno[i].calif_mat_3 +
		                     alumno[i].calif_mat_4 + alumno[i].calif_mat_5)/5;
		cout<<"El promedio del alumno: "<<alumno[i].nombre<<" "<<alumno[i].apellido<<" es: "<<alumno[i].promedio<<endl;
		
		/* materia con mayor calificacion */
		alumno[i].calif_mayor = alumno[i].calif_mat_1;
		strcpy(alumno[i].nom_mat_mayor,materia[0].nom_mat);
		
		if ( alumno[i].calif_mat_2 > alumno[i].calif_mayor ){
			alumno[i].calif_mayor = alumno[i].calif_mat_2;
			strcpy(alumno[i].nom_mat_mayor,materia[1].nom_mat);
		}
		if (alumno[i].calif_mat_3 > alumno[i].calif_mayor){
			alumno[i].calif_mayor = alumno[i].calif_mat_3;
			strcpy(alumno[i].nom_mat_mayor,materia[2].nom_mat);
		}
		if (alumno[i].calif_mat_4 > alumno[i].calif_mayor){
			alumno[i].calif_mayor = alumno[i].calif_mat_4;
			strcpy(alumno[i].nom_mat_mayor,materia[3].nom_mat);
		}
		if (alumno[i].calif_mat_5 > alumno[i].calif_mayor){
			alumno[i].calif_mayor = alumno[i].calif_mat_5;
			strcpy(alumno[i].nom_mat_mayor,materia[4].nom_mat);
		}
		
		cout<<"la calificacion mayor es "<<alumno[i].nom_mat_mayor<<" con: "<<alumno[i].calif_mayor<<endl;
					
		/* materia con menor calificacion */
		alumno[i].calif_menor = alumno[i].calif_mat_1;
		strcpy(alumno[i].nom_mat_menor,materia[0].nom_mat);
		
		if ( alumno[i].calif_mat_2 < alumno[i].calif_menor ){
			alumno[i].calif_menor = alumno[i].calif_mat_2;
			strcpy(alumno[i].nom_mat_menor,materia[1].nom_mat);
		}
		if (alumno[i].calif_mat_3 < alumno[i].calif_menor){
			alumno[i].calif_menor = alumno[i].calif_mat_3;
			strcpy(alumno[i].nom_mat_menor,materia[2].nom_mat);
		}
		if (alumno[i].calif_mat_4 < alumno[i].calif_menor){
			alumno[i].calif_menor = alumno[i].calif_mat_4;
			strcpy(alumno[i].nom_mat_menor,materia[3].nom_mat);
		}
		if (alumno[i].calif_mat_5 < alumno[i].calif_menor){
			alumno[i].calif_menor = alumno[i].calif_mat_5;
			strcpy(alumno[i].nom_mat_menor,materia[4].nom_mat);
		}
		
		cout<<"la calificacion menor es "<<alumno[i].nom_mat_menor<<" con: "<<alumno[i].calif_menor<<endl;
	}
	
	/* calculando promedio de grupo */
	for (int i = 0; i < 20 ; i++){
		promedio_grupo += alumno[i].promedio;
	}
	promedio_grupo /= 20;
	cout<<endl;
	cout<<"El promedio del grupo es: "<<promedio_grupo<<endl<<endl;
	
	
	/* opcion si los resultados son correctos */
	cout<<"Los datos mostrados son correctos: S/N ";
	cin>>opcion;
	cout<<endl;
	
	}while(opcion == 'N' || opcion == 'n');
	
	return 0;
}
