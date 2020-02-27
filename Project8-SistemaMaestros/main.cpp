#include <iostream>
#include <string.h>
using namespace std;
/* 
 *En Azul Web se desea hacer un programa en C++
 * que guarde la información de los maestros que
 * ofrecen cursos dentro de su plataforma, el programa
 * debe de realizar lo siguiente:
 * 1.- Permitir guardar datos completos del maestro.
 * Maestro; nombre, edad, país, especialidad.
 * Especialidad; programación, base de datos y servidores.
 * 
 * 2.- También se desea ordenar los cursos que se
 * están brindando. Curso; maestro, especialidad,
 * y fecha. Fecha: día, mes y año.
 *
 *(Todos los datos se deben de guardar al momento
 * de programar, no hay que pedírselo al usuario).
 * 
 * 3.- Al momento de correr el programa se debe
 * de mostrar en pantalla el siguiente menú:
 * >> Buscar cursos por maestro.
 * >> Buscar cursos por especialidad.
 * >> Buscar cursos mayores a un año brindado por el usuario.
 * >> Buscar cursos menores a un año brindado por el usuario.
 * >> Permitir al usuario modificar cualquiera de los datos
 *    mostrados anteriormente utilizando una contraseña.
 *    (La contraseña la definimos al momento de programar).
 * >> Permitir salir del programa. (El programa no se debe
 *    de cerrar hasta que el usuario así lo desee).
 * Nota: Solo se puede utilizar lo aprendido
 * en los módulos anteriores.
 */
/* datos del maestro */
struct datos_maestro
{
	char nombre[20];
	int edad;
	char pais[10];
	char especialidad[20];
};
/* elementos de la fecha */
struct datos_fecha
{
	int anio, mes, dia;
};
/* datos del curso */
struct datos_curso
{
	char nombre_curso[20];
	datos_maestro maestro;
	char especialidad_curso[30];
	datos_fecha fecha;
};
	
int main()
{
	datos_curso curso[50];
	int option;
	char maestro_a_buscar[20];
	char curso_a_buscar[20];
	int password = 123456;
	int anio_a_buscar;
	int i, j;
	char curso_encontrado[50];
	
	/* asignando valores al curso */
	strcpy(curso[0].nombre_curso,"Programacion C++");
	strcpy(curso[0].maestro.nombre,"Carlos");
	curso[0].maestro.edad = 33;
	strcpy(curso[0].maestro.pais,"Mexico");
	strcpy(curso[0].maestro.especialidad,"Programacion");
	strcpy(curso[0].especialidad_curso,"Programacion");
	curso[0].fecha.anio = 2019;
	curso[0].fecha.mes = 9;
	curso[0].fecha.dia = 19;
	
	/* Mostrando menu */
	while (option != 6)
	{
		cout<<"Sistema Azul School"<<endl;
		cout<<"-------------------"<<endl;
		cout<<"Menu:"<<endl;
		cout<<"1.- Buscar cursos por maestro"<<endl;
		cout<<"2.- Buscar cursos por especialidad"<<endl;
		cout<<"3.- Buscar cursos mayores a un año determinado"<<endl;
		cout<<"4.- Buscar cursos menores a un año determinado"<<endl;
		cout<<"5.- Modificar cursos"<<endl;
		cout<<"6.- Salir"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<"selecciona una opcion:";
		cin>>option;
		cout<<endl<<endl;
		
		for (i = 0; i < 50; i++)
		{
			curso_encontrado[i] = 'F';
		}
		
		switch (option)
		{
			case 1:
				{
					cout<<"Buscar cursos por maestro"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"Introduce el nombre del maestro a buscar: ";
					cin>>maestro_a_buscar;
					
					/* buscando en cada curso */
					for (i = 0; i < 50; i++)
					{
						/*buscando en el nombre del maestro*/
						for (j = 0; j < 20; j++)
						{
							if ((curso[i].maestro.nombre[j] == maestro_a_buscar[j]) && (curso[i].maestro.nombre[j] != 0))
							{
								curso_encontrado[i] = 'V';
							}
						}
					}
					/* mostrando cursos encontrados */
					for (i = 0; i < 50; i++)
					{
						if (curso_encontrado[i] == 'V')
						{
							cout<<"Nombre: "<<curso[i].nombre_curso<<endl;
							cout<<"Maestro: "<<curso[i].maestro.nombre<<endl;
							cout<<"Especialidad: "<<curso[i].especialidad_curso<<endl;
						}						
					}
					
					break;
				}
			case 2:
				{
					cout<<"Buscar cursos por especialidad"<<endl;
					cout<<"------------------------------"<<endl;
					cout<<"Introduce el nombre del curso a buscar: ";
					cin>>curso_a_buscar;
					break;
				}
			case 3:
				{
					cout<<"Buscar cursos mayores a un año determinado"<<endl;
					cout<<"------------------------------------------"<<endl;
					cout<<"Introduce el año a buscar: ";
					cin>>anio_a_buscar;
					break;
				}
			case 4:
				{
					cout<<"Buscar cursos menores a un año determinado"<<endl;
					cout<<"------------------------------------------"<<endl;
					cout<<"Introduce el año a buscar: ";
					cin>>anio_a_buscar;
					break;
				}
			case 5:
				{
					cout<<"Modificar cursos"<<endl;
					cout<<"----------------"<<endl;
					cout<<"Introduce la contrasena: ";
					cin>>password;
					break;
				}
			case 6:
				{
					cout<<"Saliendo del sistema"<<endl;
					cout<<"--------------------"<<endl;
					break;
				}
		}
	}
	
	
	return 0;
}
