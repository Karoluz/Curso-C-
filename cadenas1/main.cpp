#include <iostream>
#include <string.h>
using namespace std;
/* Crea un programa en C++ donde el usuario pueda
 * introducir el abecedario en una cadena (en minúsculas),
 * para después pasar los datos a otra cadena, y posteriormente
 * pasar a mayúsculas el abecedario de la segunda cadena.
 * Imprima todo en pantalla. (Al final tendremos dos cadenas,
 * una con el abecedario en minúsculas y otro en mayúsculas). 
 */

int main() 
{
	char abecedarioMinus[29];
	char abecedarioMayus[29];
	
	cout<<"Introduce el abecedario: "<<endl;
	cin.getline(abecedarioMinus,29,'\n');
	strcpy(abecedarioMayus,abecedarioMinus);
	strupr(abecedarioMayus);
	
	cout<<"El abecedario introducido es: "<<abecedarioMinus<<endl;
	cout<<"El abecedario en mayusculas es: "<<abecedarioMayus<<endl;
	
	return 0;
}
