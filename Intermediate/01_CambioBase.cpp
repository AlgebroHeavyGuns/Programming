/*

	(C)Algebro.

  Cambio de base 10 a base N.


*/

#include <iostream>


using namespace std;





int main(){

  int numero, resultado=0, base, contador=1;
  cout << "Introducir un numero (base 10) : ";
  cin >> numero;

  do{
    cout << "Introducir base : ";
    cin >> base;
  }while(base < 2 || base > 9);

  while(numero > 0){
    resultado += numero%base * contador;
    numero = numero/base;
    contador *= 10;
  }

  cout << "\nResultado : " << resultado << endl;


}


/*
		En detalle
		-----------------------




*/
