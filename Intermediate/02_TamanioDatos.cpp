/*

	(C)Algebro.

  Muestra el tamanio de los tipos de datos mas comunes
  haciendo uso de la funcion sizeof


*/

#include <iostream>


using namespace std;





int main(){

  cout << "\nTamanio char    :  " << sizeof(char)*8 << " bits"
    << "\nTamanio char sin signo   :  " << sizeof(unsigned char)*8 << " bits"
    << "\nTamanio entero corto con signo : " << sizeof(short)*8 << " bits"
    << "\nTamanio entero corto sin signo : " << sizeof(unsigned short)*8 << " bits"
    << "\nTamanio entero con signo   : " << sizeof(int)*8 << " bits"
    << "\nTamanio entero sin signo   : " << sizeof(unsigned int)*8 << " bits"
    << "\nTamanio booleano      : " << sizeof(bool)*8 << " bits"
    << "\nTamanio entero largo  : " << sizeof(long)*8 << " bits"
    << "\nTamanio entero doble largo : " << sizeof(long long)*8 << " bits"
    << "\nTamanio coma flotante : " << sizeof(float)*8 << " bits"
    << "\nTamanio real       : " << sizeof(double)*8 << " bits"
    << "\nTamanio real largo : " << sizeof(long double)*8 << " bits\n";


    return 0;
}


/*
		En detalle
		-----------------------

    Algunos tipos de datos depende del sistema operativo para
    determinar la memoria que ocupa.


*/
