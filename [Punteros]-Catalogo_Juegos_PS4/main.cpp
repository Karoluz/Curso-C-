/*
 * ------------------------------------------- 
 * -  Catalogo de Videojuegos PlayStation 4  -
 * -------------------------------------------
 * Con este programa pretendemos aplicar los
 * conceptos aprendidos de punteros, prodemos:
 * - Agregar nuevos juegos.
 * - consultar juegos por genero, valoracion
 *   y fecha de lanzamiento.
 * -------------------------------------------
 * la informacion sobre los juegos de PS4
 * fueron tomados de:
 * https://juegosadn.eleconomista.es/juegos/ps4/
 * -------------------------------------------
 * Elaborado por Carlos Ibarra
 * 
 */
 
#include <iostream>
#include <string>
#include <conio.h>
#include <clocale>

#define  NUM_MAX_JUEGOS  10

using namespace std;

struct fecha_t {
	int anyo;
	int mes;
	int dia;
};

enum gen_t {
	gen_invalido,
	gen_accion,
	gen_aventura,
	gen_shooter,
	gen_deportes,
	gen_lucha,
	gen_rpg,
	gen_puzle,
};

/* Estructura donde almacenaremos los datos del juego */
struct ps4game_t {
	bool ocupado;
	string nombre;
	fecha_t fecha_lanzamiento;
	gen_t genero;
	string desarrollador;
	float valoracion;
};

struct Menu {
	string nombre;
	void (*funcion)();
};
/* --------------------------------------------------------------- */
/* Apuntador dinamico */
ps4game_t *ptr_juegos = new ps4game_t[NUM_MAX_JUEGOS];

/* Prototipo de la funciones a usar*/
void mostrar_ficha_tecnica(int i);
string Genero_a_Texto(int num_genero);
void mostrar_ficha_tecnica(int i);
/* Funciones del menu */
void Funcion_Agregar();
void Funcion_Consultar_Genero();
void Funcion_Consultar_Valor();
void Funcion_Consultar_Fecha();
void Funcion_Salir();
/* --------------------------------------------------------------- */
/* Menu de opciones */
Menu menu[] = {
	/* Opcion, Apuntador a funcion */
	{"Agregar", Funcion_Agregar},
	{"Consultar por Genero", Funcion_Consultar_Genero},
	{"Consultar por Valoracion", Funcion_Consultar_Valor},
	{"Consultar por Fecha Lanzamiento",Funcion_Consultar_Fecha},
	{"Salir",Funcion_Salir},
};
/* --------------------------------------------------------------- */

/* Numero de elementos en el menu */
const int sels = sizeof menu / sizeof(Menu);
/* --------------------------------------------------------------- */

int main() 
{
	unsigned option = 0;
	setlocale(LC_CTYPE, "Spanish");
	
	/* Inicializamos el valores de ocupado de los juegos */
	for (int i = 0; i < NUM_MAX_JUEGOS; i++)
	{
		ptr_juegos->ocupado = 0;
	}
	
	//codigo para llenar informacion del juego
	ptr_juegos[0].ocupado = 1;
	ptr_juegos[0].nombre ="The Last of Us";
	ptr_juegos[0].fecha_lanzamiento.anyo = 2014;
	ptr_juegos[0].fecha_lanzamiento.mes = 7;
	ptr_juegos[0].fecha_lanzamiento.dia = 30;
	ptr_juegos[0].genero = gen_accion;
	ptr_juegos[0].desarrollador = "Naughty Dog";
	ptr_juegos[0].valoracion = 9.5;
	
	ptr_juegos[1].ocupado = 1;
	ptr_juegos[1].nombre ="inFamous: Second Son";
	ptr_juegos[1].fecha_lanzamiento.anyo = 2014;
	ptr_juegos[1].fecha_lanzamiento.mes = 3;
	ptr_juegos[1].fecha_lanzamiento.dia = 21;
	ptr_juegos[1].genero = gen_accion;
	ptr_juegos[1].desarrollador = "Sucker Punch";
	ptr_juegos[1].valoracion = 8.5;
	
	ptr_juegos[2].ocupado = 1;
	ptr_juegos[2].nombre ="Killzone: Shadow Fall";
	ptr_juegos[2].fecha_lanzamiento.anyo = 2013;
	ptr_juegos[2].fecha_lanzamiento.mes = 11;
	ptr_juegos[2].fecha_lanzamiento.dia = 29;
	ptr_juegos[2].genero = gen_shooter;
	ptr_juegos[2].desarrollador = "Guerrilla Games";
	ptr_juegos[2].valoracion = 8.4;
	
	ptr_juegos[3].ocupado = 1;
	ptr_juegos[3].nombre ="NBA 2K18";
	ptr_juegos[3].fecha_lanzamiento.anyo = 2017;
	ptr_juegos[3].fecha_lanzamiento.mes = 6;
	ptr_juegos[3].fecha_lanzamiento.dia = 15;
	ptr_juegos[3].genero = gen_deportes;
	ptr_juegos[3].desarrollador = "Visual Concepts";
	ptr_juegos[3].valoracion = 9;
	
	ptr_juegos[4].ocupado = 1;
	ptr_juegos[4].nombre ="Grim Fandango Remastered";
	ptr_juegos[4].fecha_lanzamiento.anyo = 2015;
	ptr_juegos[4].fecha_lanzamiento.mes = 1;
	ptr_juegos[4].fecha_lanzamiento.dia = 28;
	ptr_juegos[4].genero = gen_aventura;
	ptr_juegos[4].desarrollador = "Double Fine";
	ptr_juegos[4].valoracion = 8.9;
	
	ptr_juegos[5].ocupado = 1;
	ptr_juegos[5].nombre ="Resident Evil Origins Collection";
	ptr_juegos[5].fecha_lanzamiento.anyo = 2016;
	ptr_juegos[5].fecha_lanzamiento.mes = 1;
	ptr_juegos[5].fecha_lanzamiento.dia = 22;
	ptr_juegos[5].genero = gen_accion;
	ptr_juegos[5].desarrollador = "Capcom";
	ptr_juegos[5].valoracion = 8.5;
	
	while (option != sels)
	{
		/* Mostrando Menu */
		/* Menu principal */
		cout<<endl<<"--------------------------------------"<<endl;
		cout<<"   Catalogo de Juegos PlayStation 4   "<<endl;
		cout<<endl<<"--------------------------------------"<<endl;
		for (int i = 0; i < sels; i++)
		{
			cout<<i+1<<": "<<menu[i].nombre<<endl;
		}
		cout<<"--------------------------------------"<<endl;
		cout<<"Selecciona una opcion: ";
		cin>>option;
		
		if ((option < (sels+1)) && (option > 0))
		{
			(*menu[option-1].funcion)(); //llamando la funcion atravez del apuntador
		}
	}
	
	delete[] ptr_juegos;
	return 0;
}
/* --------------------------------------------------------------- */
/* Declaracion de las funciones */
string Genero_a_Texto(int num_genero)
{
	string txt_genero;
	
	switch(num_genero)
	{
		case 1:
			{
				txt_genero = "Accion";
				break;
			}
		case 2:
			{
				txt_genero = "Aventura";
				break;
			}
		case 3:
			{
				txt_genero = "Shooter";
				break;
			}
		case 4:
			{
				txt_genero = "Deportes";
				break;
			}
		case 5:
			{
				txt_genero = "Pelea";
				break;
			}
		case 6:
			{
				txt_genero = "RPG";
				break;
			}
		case 7:
			{
				txt_genero = "Puzzle";
				break;
			}
		default:
			{				
				break;
			}
	}
	return (txt_genero);
}
void mostrar_ficha_tecnica(int i)
{
	cout<<i+1<<".- "<<"Nombre: "<<ptr_juegos[i].nombre<<"   "<<"Genero: "<<Genero_a_Texto(ptr_juegos[i].genero)<<endl;
	cout<<"Desarrollador: "<<ptr_juegos[i].desarrollador;
	cout<<" Fecha de lanzamiento: "<<ptr_juegos[i].fecha_lanzamiento.mes<<" / "<<ptr_juegos[i].fecha_lanzamiento.dia<<" / "<<ptr_juegos[i].fecha_lanzamiento.anyo<<endl;
	cout<<"Valoracion: "<<ptr_juegos[i].valoracion<<endl;
	cout<<"--------------------------------------"<<endl;
}

void Funcion_Agregar()
{
	int genero = gen_invalido;
	bool genero_invalido = true;
	bool mes_valido = false;
	char datos_correctos = 'N';
	bool datos_agregados = false;
	
	do
	{
		system("cls");// limpiar la pantalla
		cout<<"--------------------------------------"<<endl;
		cout<<" Agrega un juego al catalogo "<<endl;
		cout<<"--------------------------------------"<<endl;
		for (int i = 0; i < NUM_MAX_JUEGOS; i++)
		{
			if (ptr_juegos[i].ocupado == 0)
			{
				cout<<"Ingresa el nombre del juego: "<<endl;
				cin.ignore();
				getline(cin, ptr_juegos[i].nombre);
				
				do
				{
					cout<<"--------------------------------------"<<endl;
					cout<<" Ingresa genero del juego "<<endl;
					cout<<"--------------------------------------"<<endl;
					cout<<"1.- Accion"<<endl;
					cout<<"2.- Aventura"<<endl;
					cout<<"3.- Shooter"<<endl;
					cout<<"4.- Deportes"<<endl;
					cout<<"5.- Pelea"<<endl;
					cout<<"6.- RPG"<<endl;
					cout<<"7.- Puzle"<<endl;
					cout<<"--------------------------------------"<<endl;
					cout<<"Selecciona una opcion: "<<endl;
					cin>>genero;
				
					if ((genero > 0) && (genero < 8))
					{
						genero_invalido = false;
						ptr_juegos[i].genero = (gen_t)genero;
					}
					else
					{
						cout<<"Genero invalido  vuelve a seleccionar"<<endl;
					}
				}while(genero_invalido);

				cout<<"--------------------------------------"<<endl;
				cout<<"Ingresa desarrollador del juego: "<<endl;
				cin.ignore();
				getline(cin, ptr_juegos[i].desarrollador);
				
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingresa fecha de lanzamiento"<<endl;
				cout<<"Ingresa el año: ";
				cin>>ptr_juegos[i].fecha_lanzamiento.anyo;
				do
				{
					cout<<"Ingresa el mes: ";
					cin>>ptr_juegos[i].fecha_lanzamiento.mes;
					if ((ptr_juegos[i].fecha_lanzamiento.mes > 0 ) && (ptr_juegos[i].fecha_lanzamiento.mes <= 12))
					{
						mes_valido = true;
					}
					else
					{
						cout<<"Introduce un mes valido"<<endl;
					}
				}while(mes_valido == false);
				
				cout<<"Ingresa el dia: ";
				cin>>ptr_juegos[i].fecha_lanzamiento.dia;
				
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingresa valoracion del juego: ";
				cin>>ptr_juegos[i].valoracion;
				
				
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<" Datos agregados "<<endl;
				cout<<"--------------------------------------"<<endl;
				mostrar_ficha_tecnica(i);
				cout<<"--------------------------------------"<<endl<<endl;
				cout<<"Estan los datos correctos? S/N ";
				cin>>datos_correctos;
				
				if ((datos_correctos == 'S') || (datos_correctos == 's'))
				{
					ptr_juegos[i].ocupado = 1; //ponemos el juego como ocupado
					datos_agregados = true;
				}
				else
				{
					ptr_juegos[i].ocupado = 0; //ponemos el juego como desocupado
					datos_agregados = false;
				}
				
				system("cls");// limpiar la pantalla
				break; //salir del ciclo for
			}
		}
	}while(datos_agregados == false);
}
void Funcion_Consultar_Genero()
{
	int genero = gen_invalido;
	
	system("cls");// limpiar la pantalla
	cout<<"--------------------------------------"<<endl;
	cout<<" Consulta por genero "<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"1.- Accion"<<endl;
	cout<<"2.- Aventura"<<endl;
	cout<<"3.- Shooter"<<endl;
	cout<<"4.- Deportes"<<endl;
	cout<<"5.- Pelea"<<endl;
	cout<<"6.- RPG"<<endl;
	cout<<"7.- Puzle"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Selecciona un genero: ";
	cin>>genero;
	
	if ((genero > 0) && (genero < 8))
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"Datos encontrados:"<<endl;
		cout<<"--------------------------------------"<<endl;
		for (int i = 0; i < NUM_MAX_JUEGOS; i++)
		{
			if (ptr_juegos[i].genero == genero)
			{
				mostrar_ficha_tecnica(i);
			}
		}
	}
	else
	{
		cout<<"Genero invalido  vuelve a seleccionar"<<endl;
	}
	
	cout<<"--------------------------------------"<<endl<<endl;
	
	cout<<"Presiona cualquier tecla para continuar";
	getch();//presiona una tecla para continuar
	system("cls");// limpiar la pantalla
}
void Funcion_Consultar_Valor()
{
	float valor = 0;
	
	system("cls");// limpiar la pantalla
	cout<<"--------------------------------------"<<endl;
	cout<<" Consulta por valoracion "<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Ingresa un valor: ";
	cin>>valor;
	cout<<"--------------------------------------"<<endl;
	cout<<"Datos encontrados:"<<endl;
	cout<<"--------------------------------------"<<endl;
	for (int i = 0; i < NUM_MAX_JUEGOS; i++)
	{
		if ((ptr_juegos[i].valoracion >= valor) && (ptr_juegos[i].valoracion < (valor+1)))
		{
			mostrar_ficha_tecnica(i);
		}
	}
	cout<<"--------------------------------------"<<endl<<endl;
	
	cout<<"Presiona cualquier tecla para continuar";
	getch();//presiona una tecla para continuar
	system("cls");// limpiar la pantalla
}
void Funcion_Consultar_Fecha()
{
	int option_fecha = 0;
	int mes_buscar = 0;
	int anio_buscar = 0;
	
	system("cls");// limpiar la pantalla
	cout<<"--------------------------------------"<<endl;
	cout<<" Consulta por fecha de lanzamiento "<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"1.- buscar por año"<<endl;
	cout<<"2.- buscar por mes"<<endl;
	cout<<"Seleccion una opcion: ";
	cin>>option_fecha;
	
	switch(option_fecha)
	{
		case 1:
			{
				cout<<"Ingresa el año a buscar: ";
				cin>>anio_buscar;
				cout<<"Buscando: "<<anio_buscar<<endl;
				cout<<"--------------------------------------"<<endl;
				cout<<"Datos encontrados:"<<endl;
				cout<<"--------------------------------------"<<endl;
				for (int i = 0; i < NUM_MAX_JUEGOS; i++)
				{
					if (ptr_juegos[i].fecha_lanzamiento.anyo == anio_buscar)
					{
						mostrar_ficha_tecnica(i);
					}
				}
				break;
			}
		case 2:
			{
				cout<<"Ingresa el mes a buscar: ";
				cin>>mes_buscar;
				cout<<"Buscando: "<<mes_buscar<<endl;
				cout<<"--------------------------------------"<<endl;
				cout<<"Datos encontrados:"<<endl;
				cout<<"--------------------------------------"<<endl;
				for (int i = 0; i < NUM_MAX_JUEGOS; i++)
				{
					if (ptr_juegos[i].fecha_lanzamiento.mes == mes_buscar)
					{
						mostrar_ficha_tecnica(i);
					}
				}
				
				break;
			}
		default:
			{
				cout<<"Opcion no valida, intenta de nuevo"<<endl;
				break;
			}
	}	
	
	cout<<"--------------------------------------"<<endl<<endl;
	
	cout<<"Presiona cualquier tecla para continuar";
	getch();//presiona una tecla para continuar
	system("cls");// limpiar la pantalla
}
void Funcion_Salir()
{
	system("cls");// limpiar la pantalla
	cout<<"--------------------------------------"<<endl<<endl;
	cout<<"Cerrando Aplicacion"<<endl;
	cout<<"--------------------------------------"<<endl<<endl;
}
/* --------------------------------------------------------------- */
