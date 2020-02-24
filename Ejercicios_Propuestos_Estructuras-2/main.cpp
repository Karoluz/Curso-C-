#include <iostream>
using namespace std;
/* 
 * 2.- Un programa que sea capaz de almacenar los datos de
 * 50 personas: nombre, dirección, teléfono, edad (usando una tabla de structs).
 * Deberá ir pidiendo los datos uno por uno. Después deberá aparecer un menú que permita:
 * >> Mostrar la lista de todos los nombres.
 * >> Mostrar las personas de una cierta edad.
 * >> Mostrar las personas cuya inicial sea la que el usuario indique.
 * >> Salir del programa (lógicamente, este menú debe
 * repetirse hasta que se escoja la opción de “salir”).
 */

int main()
{
	char encontrado[50] = {};
	int i = 0, j = 0;
	int option = 0;
	int edad_a_buscar = 0;
	char inicial_a_buscar;
	
	struct datos_empleado
	{
		char nombre[10];
		char direccion[30];
		int telefono;
		int edad;
	};
	
	datos_empleado empleado[50] = {};
	char address[30];
		
	cout<<"Introduciendo datos de los empleado"<<endl;
	cout<<"-----------------------------------"<<endl;
	for (i = 0; i < 5; i++)
	{
		cout<<"Empleado "<<i<<" : "<<endl;
		cout<<"-------------------"<<endl;
		cout<<"Nombre: ";
		cin>>empleado[i].nombre;
		cout<<"Direccion: ";
		cin.ignore();/* flush the newline character*/
		cin.getline (empleado[i].direccion,30);
		cout<<"Telefono: ";
		cin>>empleado[i].telefono;
		cout<<"Edad: ";
		cin>>empleado[i].edad;
		cout<<"-------------------"<<endl<<endl;
	}
	while (option != 4)
	{
		cout<<" Menu de Empleados "<<endl;
		cout<<"-------------------"<<endl;
		cout<<"1.- Mostrar todos los empleados"<<endl;
		cout<<"2.- Mostrar los empleados de cierta edad"<<endl;
		cout<<"3.- Mostrar los empleados por inicial"<<endl;
		cout<<"4.- Salir del programa"<<endl;
		cout<<"Selecciona una opcion: ";
		cin>>option;
		
		/* inicializa el arreglo encontrado */
		for (i = 0; i < 50; i++)
		{
			encontrado[i] = 'F';
		}
		
		switch (option)
		{
			case 1:
				{
					cout<<"1.- Mostrar todos los empleados"<<endl;
					cout<<"-------------------------------"<<endl;
					for (i = 0; i < 50; i++)
					{
						cout<<"Empleado: "<<i<<endl;
						cout<<"Nombre: "<<empleado[i].nombre<<endl;
						cout<<"Direccion: "<<empleado[i].direccion<<endl;
						cout<<"Telefono: "<<empleado[i].telefono<<endl;
						cout<<"Edad: "<<empleado[i].edad<<endl;
						cout<<"-------------------------------"<<endl;
					}
					break;
				}
			case 2:
				{
					cout<<"2.- Mostrar los empleados de cierta edad"<<endl;
					cout<<"---------------------------------------"<<endl;
					cout<<"Introduce la edad a buscar: ";
					cin>>edad_a_buscar;
					/* buscando la edad en todos los empleadod */
					for (i = 0; i < 50; i++)
					{
						if (edad_a_buscar == empleado[i].edad)
						{
							encontrado[i] = 'V';
						}
					}
					
					/* mostrando resultados encontrados */
					cout<<"Empleados que coinciden con la edad seleccionada: "<<endl;
					cout<<"--------------------------------------------------"<<endl;
					for (i = 0; i < 50; i++)
					{
						if (encontrado[i] == 'V')
						{
							cout<<"Nombre: "<<empleado[i].nombre<<endl;
							cout<<"Direccion: "<<empleado[i].direccion<<endl;
							cout<<"Telefono: "<<empleado[i].telefono<<endl;
							cout<<"Edad: "<<empleado[i].edad<<endl;
							cout<<"-------------------------------"<<endl;
						}
					}
					break;
				}
			case 3:
				{
					cout<<"3.- Mostrar los empleados por inicial"<<endl;
					cout<<"-------------------------------------"<<endl;
					cout<<"Introduce la inicial a buscar: ";
					cin>>inicial_a_buscar;
					/* buscando en cada empleado */
					for (i = 0; i < 50; i++)
					{
						/* buscando en el nombre del empleado */
						if ( inicial_a_buscar == empleado[i].nombre[0])
						{
							encontrado[i] = 'V';
						}						
					}
					
					/* mostrando resultados encontrados */
					cout<<"Empleados que coinciden con la inicial seleccionada: "<<endl;
					cout<<"-----------------------------------------------------"<<endl;
					for (i = 0; i < 50; i++)
					{
						if (encontrado[i] == 'V')
						{
							cout<<"Nombre: "<<empleado[i].nombre<<endl;
							cout<<"Direccion: "<<empleado[i].direccion<<endl;
							cout<<"Telefono: "<<empleado[i].telefono<<endl;
							cout<<"Edad: "<<empleado[i].edad<<endl;
							cout<<"-------------------------------"<<endl;
						}
					}
					break;
				}
			default:
				{
					cout<<"Saliendo del programa"<<endl;
					cout<<"---------------------"<<endl;
					break;
				}
		}
	}
	
	return 0;
}
