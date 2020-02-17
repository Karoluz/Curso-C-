#include <iostream>
using namespace std;
/* Busqueda binaria */
/*  */

int main() 
{
	/* arreglo debe estar ordeano de manera ascendente */
	int lista[10] = {2,4,6,8,10,12,14,16,18,20};
	/* indice inferior (0), superior (9), centro (inf+sup/2 = 4), clave:numero a buscar */
    int iInferior = 0, iSuperior = 0, iCentro = 0, clave=0;
    char bandera = 'F';
     
    clave = 20; /*numero a buscar */
     
    iInferior = 0;
    iSuperior = 9;
     
    while(iInferior <= iSuperior) {
         
        iCentro = (iInferior+iSuperior)/2;
         
        if(lista[iCentro]==clave){
            bandera = 'V';
            break;
        } else if(lista[iCentro]>clave){
            iSuperior = iCentro -1;
        } else {
            iInferior = iCentro +1;
        }
    } 
     
    if(bandera=='V'){
        cout<<"El numero ha sido encontrado en la posicion "<<iCentro;
    } else if(bandera=='F'){
        cout<<"No se encontro el numero en la lista";
    }
         
    return 0;
}
