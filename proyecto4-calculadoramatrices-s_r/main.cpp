#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int matrizA[20][20];
	int matrizB[20][20];
	int matrizRES[20][20];
	int orden_matrizA, orden_matrizB;
	int operacion;
	
	cout<<"Introduce el orden de la primer matriz "<<endl;
	cin>>orden_matrizA;
	cout<<"Introduce los valores de matriz 1 : "<<endl;
	for (int i = 0; i < orden_matrizA; i++)
	{
		for (int j = 0; j < orden_matrizA; j++)
		{
			cin>>matrizA[i][j];
		}
	}
	cout<<"Introduce el orden de la segunda matriz"<<endl;
	cin>>orden_matrizB;
	
	while (orden_matrizB != orden_matrizA)
	{
		cout<<"El orden debe ser igual que la primer matriz "<< orden_matrizA<<endl;
		cout<<"Introduce el orden de la segunda matriz"<<endl;
		cin>>orden_matrizB;
	}
	
	cout<<"Introduce los valores de matriz 2 : "<<endl;
	for (int i = 0; i < orden_matrizB; i++)
	{
		for (int j = 0; j < orden_matrizA; j++)
		{
			cin>>matrizB[i][j];
		}
	}
	
	/* Mostrando matrices */
	/* matrizA */
	cout<<"La Matriz A"<<endl;
	for (int i = 0; i < orden_matrizA; i++){
		for (int j = 0; j < orden_matrizA; j++){
			cout<<" "<<matrizA[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	/* matrizB */
	cout<<"La Matriz B"<<endl;
	for (int i = 0; i < orden_matrizB; i++){
		for (int j = 0; j < orden_matrizB; j++){
			cout<<" "<<matrizB[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Selecciona una opcion : "<<endl;
	cout<<"1.- SUMAR"<<endl;
	cout<<"2.- RESTAR"<<endl;
	cin>>operacion;
	
	if (operacion == 1)
	{
		/* Sumando matrices */
		for (int i = 0; i < orden_matrizB; i++){
		   for (int j = 0; j < orden_matrizA; j++){
				matrizRES[i][j] = matrizA[i][j] + matrizB[i][j];
		   }
		}
	}
	else if (operacion == 2)
	{
		/* Restando matrices */
		for (int i = 0; i < orden_matrizB; i++){
		   for (int j = 0; j < orden_matrizA; j++){
				matrizRES[i][j] = matrizA[i][j] - matrizB[i][j];
		   }
		}
	}
	else
	{
		cout<<"Operacion no valida";
	}
	
	/* Mostrando matriz resultado*/
	/* matrizRES */
	cout<<"La Matriz resultado es: "<<endl;
	for (int i = 0; i < orden_matrizA; i++){
		for (int j = 0; j < orden_matrizA; j++){
			cout<<" "<<matrizRES[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}
