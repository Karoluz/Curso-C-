/*
 *Crea una calculadora que pueda realizar
 * las siguientes funciones; sumar, restar,
 * dividir, sacar raíz y elevar un numero a
 * cualquier potencia. Utiliza una función
 * para cada operación.
 *
 * El programa debe de tener un menú donde
 * el usuario pueda elegir qué operación
 * realizar, después se debe de mostrar
 * el resultado y mostrar la opción de
* realizar otra operación o finalizar
* el programa.
*/
#include <iostream>
#include <math.h>
using namespace std;

/* Definicion de funciones */
template <class tiposuma>
tiposuma suma(tiposuma a, tiposuma b);
template <class tiporesta>
tiporesta resta(tiporesta a, tiporesta b);
template <class tipomulti>
tipomulti multiplica(tipomulti a, tipomulti b);
template <class tipodivide>
tipodivide divide(tipodivide a, tipodivide b);
template <class tiporaiz>
tiporaiz raiz(tiporaiz a);
template <class tipopotencia>
tipopotencia potencia(tipopotencia a, tipopotencia b);

int main()
{
	int opcion;
	int continuar = 1;
	float resultado;
	float a, b;
	int x, y;
	
	while (continuar <= 1)
	{
		cout<<"-------------------------"<<endl;
		cout<<"Calculadora con funciones"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"Selecciona una opcion: "<<endl;
		cout<<"1.- Suma"<<endl;
		cout<<"2.- Resta"<<endl;
		cout<<"3.- Multiplicar"<<endl;
		cout<<"4.- Dividir"<<endl;
		cout<<"5.- Raiz"<<endl;
		cout<<"6.- Potencia"<<endl;
		cin>>opcion;
		cout<<"-------------------------"<<endl;
		
		switch (opcion)
		{
			case 1:
				{
					cout<<"Introduce el primer operando: ";
					cin>>a;
					cout<<"Introduce el segundo operando: ";
					cin>>b;
					resultado = suma(a, b);
					cout<<"El resultado es: "<<resultado<<endl;
					break;
				}
			case 2:
				{
					cout<<"Introduce el primer operando: ";
					cin>>a;
					cout<<"Introduce el segundo operando: ";
					cin>>b;
					resultado = resta(a, b);
					cout<<"El resultado es: "<<resultado<<endl;
					break;
				}
			case 3:
				{
					cout<<"Introduce el primer operando: ";
					cin>>a;
					cout<<"Introduce el segundo operando: ";
					cin>>b;
					resultado = multiplica(a, b);
					cout<<"El resultado es: "<<resultado<<endl;
					break;
				}
			case 4:
				{
					cout<<"Introduce el primer operando: ";
					cin>>a;
					cout<<"Introduce el segundo operando: ";
					cin>>b;
					resultado = divide(a, b);
					cout<<"El resultado es: "<<resultado<<endl;
					break;
				}
			case 5:
				{
					cout<<"Introduce el primer operando: ";
					cin>>a;
					resultado = raiz(a);
					cout<<"El resultado es: "<<resultado<<endl;
					break;
				}
			case 6:
				{
					cout<<"Introduce el primer operando: ";
					cin>>x;
					cout<<"Introduce el segundo operando: ";
					cin>>y;
					resultado = potencia(x, y);
					cout<<"El resultado es: "<<resultado<<endl;
					break;
				}
			default:
				{
					cout<<"Opcion no valida"<<endl;
					break;
				}
		}
		
		cout<<"Quieres hacer otra operacion?"<<endl;
		cout<<"1.- Si"<<endl;
		cout<<"2.- No"<<endl;
		cin>>continuar;
	}
	
	return 0;
}

/* Declaracion de funciones */
template <class tiposuma>
tiposuma suma(tiposuma a, tiposuma b)
{
	return a + b;
}
template <class tiporesta>
tiporesta resta(tiporesta a, tiporesta b)
{
	return a - b;
}
template <class tipomulti>
tipomulti multiplica(tipomulti a, tipomulti b)
{
	return a * b;
}
template <class tipodivide>
tipodivide divide(tipodivide a, tipodivide b)
{
	return a / b;
}
template <class tiporaiz>
tiporaiz raiz(tiporaiz a)
{
	return sqrt(a);
}
template <class tipopotencia>
tipopotencia potencia(tipopotencia a, tipopotencia b)
{
	return a ^ b;
}
