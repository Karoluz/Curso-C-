/* 
 * 5.- Investiga sobre la sucesión de Fibonacci,
 * busca ejemplos de funciones recursivas sobre
 * este tema y crea un programa que calcule el
 * término n de la sucesión de Fibonacci de
 * forma recursiva.
 */
 
#include <iostream>
using namespace std;
int calcula_fibonacci(int n);
int main()
{
	int ntermino;
	cout<<"Calculo de Sucesion Fibonacci"<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<"Introduce el termino a calcular: ";
	cin>>ntermino;
	
	/*calculando secuencia*/
	for (int i = 0; i < ntermino; i++)
	{
		cout<<calcula_fibonacci(i)<<" ";
	}
	cout<<endl<<"-----------------------------"<<endl;
	
	return 0;
}

int calcula_fibonacci(int n)
{
	int var_ret;
	
	/* si es 0 o 1  se regresa ese valor */
	if ((n == 0) || (n == 1))
	{
		var_ret = n;
	}
	/* si es diferente de 0 o 1, se suma los dos terminos anteriores*/
	else
	{
		/* se llama a la funcion recursivamente para calcular el valor anterior*/
		var_ret = calcula_fibonacci(n-1) + calcula_fibonacci(n-2);
	}
	
	return var_ret;
}
