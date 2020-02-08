#include <iostream>
using namespace std;
/* Programas de matrices */

int main()
{
	/* Programa 1 */
	/* Un programa pida datos al usuario los datos
	 * de una matriz de 2×2 y muestra su traspuesta
	 * (el resultado de intercambiar filas por columnas).
	 */
	int matrix[2][2]={0};
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout<<"Introduce el dato en ["<<i<<"],["<<j<<"] : ";
			cin>>matrix[i][j];
		}
	}
	/* Matriz normal */
	cout<<" La matriz normal es: "<<endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout<<"["<<matrix[i][j]<<"]";
		}
		cout<<endl;
	}
	cout <<" Su transpuesta es: "<<endl;
	/* Su transpuesta es */
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout<<"["<<matrix[j][i]<<"]";
		}
		cout<<endl;
	}
		
	return 0;
}
