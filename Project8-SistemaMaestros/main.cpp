#include <iostream>
#include <string.h>
using namespace std;
/*
 * En Azul Web se desea hacer un programa en C++
 * que guarde la información de los maestros que
 * ofrecen cursos dentro de su plataforma, el programa
 * debe de realizar lo siguiente:
 *
 * 1.- Permitir guardar datos completos del maestro.
 * Maestro; nombre, edad, país, especialidad.
 * Especialidad; programación, base de datos y servidores.
 * 
 * 2.- También se desea ordenar los cursos que se están
 * brindando. Curso; maestro, especialidad, y fecha.
 * Fecha: día, mes y año.
 * (Todos los dato se deben de guardar al momento de
 * programar, no hay que pedírselo al usuario).
 * 
 * 3.- Al momento de correr el programa se debe de
 * mostrar en pantalla el siguiente menú:
 * >> Buscar cursos por maestro.
 * >> Buscar cursos por especialidad.
 * >> Buscar cursos mayores a un año brindado por el usuario.
 * >> Buscar cursos menores a un año brindado por el usuario.
 * >> Permitir al usuario modificar cualquiera de los datos
 *    mostrados anteriormente utilizando una contraseña.
 *    (La contraseña la definimos al momento de programar).
 * >> Permitir salir del programa. (El programa no se
 *    debe de cerrar hasta que el usuario así lo desee).
 * 
 * Nota: Solo se puede utilizar lo aprendido en los
 * módulos anteriores.
 */
struct datos_fecha
{
	int day, month, year;
};

struct datos_maestro
{
	char nombre[10];
	int edad;
	char pais[15];
	char especialidad[15];
};

struct datos_curso
{
	char nombre_curso[30];
	datos_maestro maestro;
	char especialidad_curso[15];
	datos_fecha fecha;
};
	
int main()
{
	int option = 0;
	datos_curso curso[50];
	
	char nuevo_nombre_curso[30];
	char nueva_especialidad[15];
	char nueva_nombre_maestro[10];
	int nueva_edad_maestro;
	char nueva_especi_maestro[15];
	char nueva_pais_maestro[15];
	
	char nombre_maestro_buscar[10];
	char especialidad_a_buscar[15];
	int year_a_buscar;
	int password;
	int i, j, contrasena = 123456;
	char curso_encontrado[50];
	bool se_encontraron_cursos, admin_habilitado;
	int curso_id;
	int admin_option;
	
	/* Incializa los valores a cero */
	for (i = 0; i < 50; i++)
	{
		strcpy(curso[i].nombre_curso,"000000000000000000000000000000");
		strcpy(curso[i].maestro.nombre,"0000000000");
		curso[i].maestro.edad = 0;
		strcpy(curso[i].maestro.pais, "000000000000000");
		strcpy(curso[i].maestro.especialidad,"000000000000000");
		strcpy(curso[i].especialidad_curso, "000000000000000");
		curso[i].fecha.day = 0;
		curso[i].fecha.month = 0;
		curso[i].fecha.year = 0;
	}
	
	/* Asignando datos a los cursos */
	//curso[0].nombre_curso = "Curso profesional C++";
	strcpy(curso[0].nombre_curso,"Curso profesional C++");
	//curso[0].maestro.nombre = "Angel";
	strcpy(curso[0].maestro.nombre,"Carlos");
	curso[0].maestro.edad = 29;
	//curso[0].maestro.pais = "Mexico";
	strcpy(curso[0].maestro.pais, "Mexico");
	//curso[0].maestro.especialidad = "programacion";
	strcpy(curso[0].maestro.especialidad,"programacion");
	//curso[0].especialidad_curso = "especialidad";
	strcpy(curso[0].especialidad_curso, "ingenieria");
	curso[0].fecha.day = 3;
	curso[0].fecha.month = 9;
	curso[0].fecha.year = 2020;
	
	while (option != 6)
	{
		/* Mostrando menu */
		cout<<"Azul School Systems"<<endl;
		cout<<"-------------------"<<endl;
		cout<<"1.- Buscar cursos por maestro"<<endl;
		cout<<"2.- Buscar cursos por especialidad"<<endl;
		cout<<"3.- Buscar cursos mayores a un año indicado"<<endl;
		cout<<"4.- Buscar cursos menores a un año indicado"<<endl;
		cout<<"5.- Modificar algun curso"<<endl;
		cout<<"6.- Para salir"<<endl;
		cout<<"Selecciona una opcion del menu: ";
		cin>>option;
		
		/* limpiar cursos encontrados */
		for (i = 0; i < 50; i++)
		{
			curso_encontrado[i] = 'F';
		}
		
		switch (option)
		{
			case 1:
				{
					admin_habilitado = false;
					cout<<"Buscar cursos por maestro"<<endl;
					cout<<"-------------------------"<<endl;
					cout<<"Introduce el nombre del maestro: ";
					cin>>nombre_maestro_buscar;
					
					/* buscando en los cursos */
					for (i = 0; i < 50; i++)
					{
						/* buscando en el nombre del maestro*/
						for (j = 0; j < 10; j++)
						{
							if ((curso[i].maestro.nombre[j] == nombre_maestro_buscar[j]) &&
							    (curso[i].maestro.nombre[j] != '0'))
							{
								curso_encontrado[i] = 'V';
								se_encontraron_cursos = true;
							}
						}
					}
												
					break;
				}
			case 2:
				{
					admin_habilitado = false;
					cout<<"Buscar cursos por especialidad"<<endl;
					cout<<"------------------------------"<<endl;
					cout<<"Introduce la especialidad a buscar: ";
					cin>>especialidad_a_buscar;
					
					/* buscando en los cursos */
					for (i = 0; i < 50; i++)
					{
						/* buscando en el nombre de la especialidad*/
						for (j = 0; j < 15; j++)
						{
							if ((curso[i].especialidad_curso[j] == especialidad_a_buscar[j]) &&
							    (curso[i].especialidad_curso[j] != '0'))
							{
								curso_encontrado[i] = 'V';
								se_encontraron_cursos = true;
							}
						}
					}
					
					break;
				}
			case 3:
				{
					admin_habilitado = false;
					cout<<"Buscar cursos mayores a un año indicado"<<endl;
					cout<<"---------------------------------------"<<endl;
					cout<<"Introduce el año a buscar: ";
					cin>>year_a_buscar;
					
					/* buscando en todos los cursos */
					for (i = 0; i < 50;i++)
					{
						/* buscando coincidencias del año */
						if (curso[i].fecha.year > year_a_buscar)
						{
							curso_encontrado[i] = 'V';
							se_encontraron_cursos = true;
						}
					}
					
					break;
				}
			case 4:
				{
					admin_habilitado = false;
					cout<<"Buscar cursos menores a un año indicado"<<endl;
					cout<<"---------------------------------------"<<endl;
					cout<<"Introduce el año a buscar: ";
					cin>>year_a_buscar;
					
					/* buscando en todos los cursos */
					for (i = 0; i < 50; i++)
					{
						/* buscando coincidencias del año */
						if (curso[i].fecha.year < year_a_buscar)
						{
							curso_encontrado[i] = 'V';
							se_encontraron_cursos = true;
						}
					}
					break;
				}
			case 5:
				{
					cout<<"Modificar algun curso"<<endl;
					cout<<"---------------------"<<endl;
					cout<<"Introduce la contrasena de administrador:";
					cin>>password;
					admin_habilitado = true;
					
					if (contrasena == password)
					{
						cout<<" Contrasena valida "<<endl;
						cout<<"-------------------"<<endl;
						cout<<"Introduce el ID del curso para mostrar los datos: "<<endl;
						cin>>curso_id;
						cout<<"-------------------------------------"<<endl;
						cout<<"Datos del curso: "<<endl;
						cout<<"-----------------"<<endl;
						cout<<"Nombre: "<<curso[curso_id-1].nombre_curso<<endl;
						cout<<"Especialidad: "<<curso[curso_id-1].especialidad_curso<<endl;
						cout<<"Fecha: "<<curso[curso_id-1].fecha.day<<"/"<<curso[curso_id-1].fecha.month<<"/"<<curso[curso_id-1].fecha.year<<endl;
						cout<<"Datos del maestro: "<<endl;
						cout<<"-------------------"<<endl;
						cout<<"Nombre: "<<curso[curso_id-1].maestro.nombre<<endl;
						cout<<"Edad: "<<curso[curso_id-1].maestro.edad<<endl;
						cout<<"Especialidad: "<<curso[curso_id-1].maestro.especialidad<<endl;
						cout<<"Pais: "<<curso[curso_id-1].maestro.pais<<endl;
						cout<<"-------------------"<<endl;
						cout<<"Que dato deseas cambiar: "<<endl;
						cout<<"1.- Nombre del curso"<<endl;
						cout<<"2.- Especialidad del curso"<<endl;
						cout<<"3.- Nombre del maestro"<<endl;
						cout<<"4.- Edad del maestro"<<endl;
						cout<<"5.- Especialidad del maestro"<<endl;
						cout<<"6.- Pais del maestro"<<endl;
						cout<<"7.- Regresar al menu anterior"<<endl;
						cout<<"-------------------"<<endl;
						cin>>admin_option;
						
						switch (admin_option)
						{
							case 1:
								{
									cout<<"Cambiando el nombre del curso"<<endl;
									cout<<"-----------------------------"<<endl;
									cout<<"Introduce el nuevo nombre: "<<endl;
									cin.ignore();
									cin.getline(nuevo_nombre_curso,30);
									strcpy(curso[curso_id-1].nombre_curso, nuevo_nombre_curso);
									break;
								}
							case 2:
								{
									cout<<"Cambiando la especialidad del curso"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<"Introduce la nueva especialidad: "<<endl;
									cin.ignore();
									cin.getline(nueva_especialidad, 15);
									strcpy(curso[curso_id-1].especialidad_curso, nueva_especialidad);
									break;
								}
							case 3:
								{
									cout<<"Cambiando el nombre del maestro"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<"Introduce nuevo nombre: "<<endl;
									cin.ignore();
									cin.getline(nueva_nombre_maestro,10);
									strcpy(curso[curso_id-1].maestro.nombre, nueva_nombre_maestro);
									break;
								}
							case 4:
								{
									cout<<"Cambiando la edad del maestro"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<"Introduce la nueva edad: "<<endl;
									cin>>nueva_edad_maestro;
									curso[curso_id-1].maestro.edad = nueva_edad_maestro;
									break;
								}
							case 5:
								{
									cout<<"Cambiando la especialidad del maestro"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<"Introduce la nueva especialidad: "<<endl;
									cin.ignore();
									cin.getline(nueva_especi_maestro, 15);
									strcpy(curso[curso_id-1].maestro.especialidad, nueva_especi_maestro);
									break;
								}
							case 6:
								{
									cout<<"Cambiando el pais del maestro"<<endl;
									cout<<"-----------------------------------"<<endl;
									cout<<"Introduce el nuevo pais: "<<endl;
									cin.ignore();
									cin.getline(nueva_pais_maestro, 15);									
									strcpy(curso[curso_id-1].maestro.pais, nueva_pais_maestro);
									break;
								}
							case 7:
								{
									cout<<"Ningun cambio se realizo"<<endl;
									break;
								}
							default:
								{
									cout<<"Opcion no valida, intenta de nuevo"<<endl;
									break;
								}
						}
						
					}
					else
					{
						cout<<" Contrasena invalida, intenta de nuevo"<<endl;
						cout<<"--------------------------------------"<<endl;
					}
					break;
				}
			default:
				{
					cout<<"Gracias por usar el sistema"<<endl;
					cout<<"Cerrando programa"<<endl;
					break;
				}
		}
		
		if (!admin_habilitado)
		{
			if (se_encontraron_cursos)
			{
				
				/* mostrando cursos encontrados */
				for (i = 0; i < 50; i++)
				{
					if (curso_encontrado[i] == 'V')
					{
						cout<<"Estos fueron los cursos encontrados: "<<endl;
						cout<<"-------------------------------------"<<endl;
						cout<<"Datos del curso: "<<endl;
						cout<<"-----------------"<<endl;
						cout<<"Nombre: "<<curso[i].nombre_curso<<endl;
						cout<<"Especialidad: "<<curso[i].especialidad_curso<<endl;
						cout<<"Fecha: "<<curso[i].fecha.day<<"/"<<curso[i].fecha.month<<"/"<<curso[i].fecha.year<<endl<<endl;
						cout<<"Datos del maestro: "<<endl;
						cout<<"-------------------"<<endl;
						cout<<"Nombre: "<<curso[i].maestro.nombre<<endl;
						cout<<"Edad: "<<curso[i].maestro.edad<<endl;
						cout<<"Especialidad: "<<curso[i].maestro.especialidad<<endl;
						cout<<"Pais: "<<curso[i].maestro.pais<<endl;
						cout<<"-------------------"<<endl;
					}
				}
				
				se_encontraron_cursos = false;
			}
			else
			{
				cout<<"No se encontraron resultados"<<endl;
			}
		}
		
		
	}
	
	return 0;
}
