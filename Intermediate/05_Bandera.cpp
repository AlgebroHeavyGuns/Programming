/*

	(C)Algebro.


  Ejercicio haciendo uso de operadores a nivel de bits.
  Simulacion del analisis de un resultado de un jurado
  expresado en binario (1 favorable 0 desfavorable)

*/

#include <iostream>


using namespace std;


const unsigned char JUEZ_1 = 1;     // 00001
const unsigned char JUEZ_2 = 2;     // 00010
const unsigned char JUEZ_3 = 4;     // 00100
const unsigned char JUEZ_4 = 8;     // 01000
const unsigned char JUEZ_5 = 16;    // 10000


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

  unsigned int entrada;

  cout << "Introducir un numero de 0 a 31 : ";
  cin >> entrada;
  entrada += 32;

  cout << "\nResultado del jurado : " << Binario(entrada)
  << "  (numerados de derecha a izquierda)";


  if(entrada & JUEZ_5)
    cout << "\nJuez 5 voto favorable";

  if((entrada&JUEZ_3) | (entrada&JUEZ_4))
    cout << "\nJuez 3 ó Juez 4 voto favorable";
  else
    cout << "\nJueces 3 y 4 votaron desfavorable";


  if(((entrada>>1)&JUEZ_1) ^ (entrada&JUEZ_1))
    cout << "\nJueces 1 y 2 no estan de acuerdo";
  else
    cout << "\nJueces 1 y 2 estan de acuerdo";

  cout << endl;

  return 0;

}



/*
		En detalle
		-----------------------

    La funcion Binario(int) utiliza el codigo
    del ejercicio 01 (Cambio Base)


*/
