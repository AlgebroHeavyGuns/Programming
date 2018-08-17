/*

	(C)Algebro.

  Muestra el tamanio de los tipos de datos mas comunes
  haciendo uso de la funcion sizeof


*/

#include <iostream>


using namespace std;





int main(){

  double n = 65.2401;
  unsigned int i = 2147483648; //Maximum for signed int 2147483647


  cout << "Valor real : " << n
    << "\nValor entero : " << (int)n
    << "\nValor caracter : " << (char)n
    << "\nValor booleano : " << (bool)n;

  cout << "\n\nValor entero : " << i
  << "\nValor con signo : " << (int)i  //desborda (y se vuelve negativo)
  << "\nValor coma flotante : " << (float)i << endl;


    return 0;
}


/*
		En detalle
		-----------------------


*/
