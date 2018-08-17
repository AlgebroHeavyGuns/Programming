/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;


unsigned int Binario(int valor){
  unsigned int resultado=0,contador=1;
  while(valor > 0){
    resultado += valor%2 * contador;
    valor = valor/2;
    contador *= 10;
  }

  return resultado;

}


int main(){

  int numero =  11;

  cout << "\nIzquierda...";

  while(numero < 1024){
    cout << "\nNumero : " << numero << "\ten binario : " << Binario(numero);
    numero = numero <<  1;
  }

  cout << "\n\nDerecha...";

  numero = 560;
  while(numero > 0){
    cout << "\nNumero : " << numero << "\ten binario : " << Binario(numero);
    numero = numero >> 1;
  }

  cout << endl;

  return 0;
}


/*
		En detalle
		-----------------------

    La funcion Binario(int) utiliza el codigo
    del ejercicio 01 (Cambio Base)


*/
