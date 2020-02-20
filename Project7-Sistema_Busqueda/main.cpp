#include <iostream>
using namespace std;
/* 
 * Una empresa desea un pequeño sistema que les permita guardar
 * los datos de 20 empleados; número de empleado y primer nombre.
 * Los números de empleados van del 1 al 20, pero no se ingresan
 * de forma consecutiva, el usuario lo ingresa aleatoriamente,
 * por ejemplo: primero ingresa el número 5, después ingresa el
 * número 2, etc.
 * 
 * Una vez que los datos estén guardados el usuario
 * desea tener las siguientes funciones:
 * >> Buscar el nombre de un empleado por su número de empleado.
 * >> Buscar el número de empleado por su nombre.
 * >> Saber si un usuario no existe.
 * >> Saber si hay nombres similares entre sus empleados.
 * >> Mostrar empleados de forma ascendente por número de empleado.
 * >> Mostrar empleados de forma descendente por número de empleado.
 * Crea un programa en C++ que de solución a este problema.
 * Solo utiliza lo aprendido en los módulos anteriores.
 */

int main()
{
	/* array empleado tiene num_empleado y nombre empleado*/
	char empleado[20][10]={ };
	char ocupado[20] = {'F'};
	char nom_emp_busca[10];
	int se_encontro[20]={0};
	int i, j, num_temp = 0, num_emp_busca = 0;
	char* nom_temp;
	int contador_emp = 0;
	int option = 0;
	int conta_coincide = 0;
	bool se_encontro_empleado = false;
		
	while (contador_emp < 20)
	{
		/* Introduciendo 20 los empleados*/
		cout<<"Introduce el numero del empleado (1 - 20) : ";
		cin>>num_temp;
		
		/* revisamos si es un numero de empleado valido */
		if ((num_temp > 0) && (num_temp <= 20))
		{
			/* Revisamos que no este ocupado */
			if (ocupado[num_temp-1] != 'V')
			{
				cout<<"Introduce el nombre del empleado: ";
				cin>>empleado[num_temp-1];
				ocupado[num_temp-1]='V';
				contador_emp++;
			}
			else
			{
				cout<<"Numero de empleado ocupado"<<endl;
			}
		}
		else
		{
			cout<<"Numero no valido"<<endl;
		}
	}
	
	/* Mostrando menu */
	while (option != 6)
	{
		cout<<endl<<"********************************************************"<<endl;
		cout<<"Selecciona el numero de la funcion de busqueda deseada: "<<endl;
		cout<<"1.- Buscar nombre de empleado por numero de empleado"<<endl;
		cout<<"2.- Buscar numero empleado por nombre de empleado"<<endl;
		cout<<"3.- Saber si hay nombres similares entre empleados"<<endl;
		cout<<"4.- Mostrar empleados de manera ascendente por numero de empleado"<<endl;
		cout<<"5.- Mostrar empleados de manera descendente por numero de empleado"<<endl;
		cout<<"6.- Para salir"<<endl;
		cout<<endl<<"********************************************************"<<endl;
		cin>>option;
		
		switch(option)
		{
			case 1:
				{
					cout<<"Introduce el numero de empleado a buscar (1 - 20): ";
					cin>>num_emp_busca;
					
					/* El numero introducido es valido */
					if ((num_emp_busca > 0) && (num_emp_busca <= 20))
					{
						cout<<"El empleado "<<num_emp_busca;
						cout<<" se llama: "<<empleado[num_emp_busca-1]<<endl;
					}
					else
					{
						cout<<"El numero no es valido"<<endl;
					}
					break;
				}
			case 2:
				{
					cout<<"Introduce el nombre del empleado a buscar: ";
					cin>>nom_emp_busca;
					se_encontro_empleado = false;
					
					/* inicializar en cero la bandera de si se encontro */
					for (i = 0; i < 20; i++)
					{
						se_encontro[i] = 0;
					}
					
					/* Iniciamos revisando las coincidencias en el nombre del empleado */
					for (i = 0; i < 20; i++)
					{
						conta_coincide = 0;
						
						for (j = 0; j < 10; j++)
						{
							/* compara cada letra del nombre y que no este vacia */
							if ((nom_emp_busca[j] == empleado[i][j]) && (empleado[i][j] != 0))
							{
								conta_coincide++;
								
								/* si coincide con mas de 4 caracteres */
								if (conta_coincide > 3)
								{
									/* se indica que se encontro */
									se_encontro[i] = 1;
									conta_coincide = 0;
									break;
								}
							}
						}
					}
					
					/* Mostramos el empleados que se encontro */
					for (j = 0; j < 20; j++)
					{
						if (se_encontro[j] == 1)
						{
				            cout<<"Se encontro el empleado "<<nom_emp_busca;
							cout<<" con el numero "<<j+1<<endl;
							se_encontro_empleado = true;
							se_encontro[j] = 0;
				        }
				    }
				    
					/* si no se encontro empleado mostrar mensaje */
				    if (!se_encontro_empleado)
					{
						cout<<"El nombre no coincide con ningun empleado"<<endl;
					}
					
					break;
				}
			case 3:
				{
					cout<<"Muestra los nombre similares en los empleados"<<endl;
					cout<<"Introduce el nombre a buscar: ";
					cin>>nom_emp_busca;
					
					/* inicializar en cero la bandera de si se encontro */
					for (i = 0; i < 20; i++)
					{
						se_encontro[i] = 0;
					}
					
					/* Iniciamos revisando las coincidencias en el nombre del empleado */
					for (i = 0; i < 20; i++)
					{
						conta_coincide = 0;
						
						for (j = 0; j < 10; j++)
						{
							/* compara cada letra del nombre y que no este vacia */
							if ((nom_emp_busca[j] == empleado[i][j]) && (empleado[i][j] != 0))
							{
								conta_coincide++;
								
								/* si coincide con 3 caracteres */
								if (conta_coincide >= 2)
								{
									/* se indica que se encontro */
									se_encontro[i] = 1;
									conta_coincide = 0;
									break;
								}
							}
						}
					}
					
					/* mostramos las coincidencias encontradas */
					cout<<"Lista de coincidencias de "<<nom_emp_busca<<endl;
					for (j = 0; j < 20; j++)
					{
						if (se_encontro[j] == 1)
						{
				            cout<<"Se encontro el empleado "<<empleado[j];
							cout<<" con el numero "<<j+1<<endl;
							se_encontro_empleado = true;
							se_encontro[j] = 0;
				        }
				    }
				    
				    /* si no se encontro empleado mostrar mensaje */
				    if (!se_encontro_empleado)
					{
						cout<<"El nombre no coincide con ningun empleado"<<endl;
					}
					
					break;
				}
			case 4:
				{
					cout<<"Mostrando empleados por numero de empleado ascendente: "<<endl;
					for (i = 0; i < 20; i++)
					{
						cout<<i+1<<" ";
						cout<<empleado[i]<<endl;
					}
					break;
				}
			case 5:
				{
					cout<<"Mostrando empleados por numero de empleado descendente: "<<endl;
					for (i = 19; i >= 0; i--)
					{
						cout<<i+1<<" ";
						cout<<empleado[i]<<endl;
					}
					break;
				}
		}
	}
	
	cout<<endl<<"********************************************************"<<endl;
	cout<<"cerrando programa";
	cout<<endl<<"********************************************************"<<endl;
	
	return 0;
}
