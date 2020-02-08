#include <iostream>
#include <string.h>
using namespace std;

/* Azul Web acaba de sacar una nueva plataforma de video,
 * donde se van a publicar pel�culas. Las pel�culas tiene
 * los siguientes atributos; Nombre de la pel�cula y Fecha
 * de lanzamiento.
 *
 * Crea un programa en C++ que haga lo siguiente:
 * 1.- Permitir guardar 20 registros en una matriz; Nombre de pel�cula y a�o de lanzamiento.
 * 2.- Un men� que nos va a dar tres opciones:
 * >> a) Mostrar pel�culas desde las m�s viejas a las m�s nuevas.
 * >> b) Mostrar pel�culas desde las m�s nuevas a las m�s viejas.
 * >> c) Mostrar pel�culas de un a�o en concreto.
 * 3.- Opci�n de regresar al men� o salir del programa.
 * Utiliza solo lo aprendido en los m�dulos anteriores.
 */

int main()
{
	int launchyear[5] = {2021, 2002, 2006, 2020, 2016};
	string moviename[5] = {"potter", "camion", "gravity", "pega", "nintendo"};
	string auxmov;
	char opcion, seguir;
	int yeartofind;
	int aux =0, minimo = 0;
	int fue_encontrado;
	
	do
	{
		fue_encontrado = 0;
		
		for (int i = 0 ; i<5; i++)
		{
			//cout<<"Introduce el nombre de la pelicula:"<<endl;
			//cin>>moviename[i];
			
			//cout<<"Introduce el a�o de lanzamiento: ";
			//cin>>launchyear[i];
			
			cout<<launchyear[i]<<" ";
		}
		
		cout<<"Selecciona una opcion: "<<endl;
		cout<<"a) Mostrar pel�culas desde las mas viejas a las mas nuevas."<<endl;
		cout<<"b) Mostrar pel�culas desde las mas nuevas a las mas viejas."<<endl;
		cout<<"c) Mostrar pel�culas de un a�o en concreto."<<endl;
		cin>>opcion;
	
		switch (opcion)
		{
			case 'a':
				{
					cout<<"Has elegido de la mas vieja a las mas nueva"<<endl;
					/* ordenando de menor a mayor */
					for (int i=0; i<5; i++)
					{
						minimo = i;
						for (int j=i+1; j<5; j++)
						{
							if (launchyear[j] < launchyear[minimo])
							{
								minimo = j;
							}
						}
						
						aux = launchyear[i];
						auxmov = moviename[i];
						launchyear[i] = launchyear[minimo];
						moviename[i] = moviename[minimo];
						launchyear[minimo] = aux;
						moviename[minimo] = auxmov;
					}
					/* mostrando la lista ordenada */
					for (int i = 0; i<5; i++)
					{
						cout<<moviename[i]<<" ";
						cout<<launchyear[i]<<" "<<endl;
					}
				}
				break;
			case 'b':
				{
					cout<<"Has elegido de las mas nueva a las mas vieja"<<endl;
					/* ordenando de mayor a menor */
					for (int i = 0; i<5; i++)
					{
						for (int j = 0; j<5; j++)
						{
							if (launchyear[j]<launchyear[j+1])
							{
								aux = launchyear[j];
								auxmov = moviename[j];
								launchyear[j] = launchyear[j+1];
								moviename[j] = moviename[j+1];
								launchyear[j+1] = aux;
								moviename[j+1] = auxmov;
							}
						}
					}
					/* mostrando la lista ordenada */
					for (int i = 0; i<5; i++)
					{
						cout<<moviename[i]<<" ";
						cout<<launchyear[i]<<" "<<endl;
					}
				}
				break;
			case 'c':
				{
					cout<<"Introduce un a�o: ";
					cin>>yeartofind;
					
					for (int j = 0; j<5; j++)
					{
						if (launchyear[j] == yeartofind)
						{
							cout<< "Pelicula: "<<moviename[j];
							cout<<" a�o de lanzamiento: "<<launchyear[j]<<endl;
							fue_encontrado = 1;
							break;
						}						
					}
					
					if (fue_encontrado == 0)
					{
						cout<<"El a�o no fue encontrado"<<endl;
					}
				}
				break;
			default:
				{
					cout<<"Has seleccionado una opcion invalida";
				}
				break;
		}
		cout<<"Deseas regresar al menu, S/N: ";
		cin>>seguir;
			
	}while((seguir == 's') || (seguir == 'S'));
	
	return 0;
}
