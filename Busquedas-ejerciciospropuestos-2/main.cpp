#include <iostream>
using namespace std;

/*
 * Crea un programa en C++ que busque un número dentro
 * de un arreglo ordenado del 1 al 12 y menciona que mes
 * le corresponde. Ejemplo; 1 = Enero, 2 = Febrero.
 * Utiliza tu lógica y lo aprendido anteriormente para imprimir.
 */

int main()
{
	/* Arreglo de dos dimensiones, primera dimension para los meses, segunda dimension para los caracteres del nombre */
	char arreglo_meses[12][11] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	int mes_a_buscar = 0;
	int indice_centro = 0, indice_inicial = 0, indice_final = 0;
	bool mes_encontrado = false;
	
	/* Inicializa lo valores del indice del arreglo */
	indice_inicial = 0;
	indice_final = 11;
	
	cout<<"Introduce el numero del mes a buscar: ";
	cin>>mes_a_buscar;
		
	while (indice_inicial <= indice_final)
	{
		indice_centro = (indice_inicial + indice_final) / 2;
		if (indice_centro == (mes_a_buscar-1))
		{
			mes_encontrado = true;
			break;
		}
		else if (indice_centro > (mes_a_buscar-1))
		{
			indice_final = indice_centro - 1;
		}
		else
		{
			indice_inicial = indice_centro + 1;
		}
	}
	
	if (mes_encontrado)
	{
		cout<<"El numero "<<mes_a_buscar<<" corresponde al mes: "<<arreglo_meses[indice_centro];
	}
	else
	{
		cout<<"El numero no es valido";
	}
	
	return 0;
}
