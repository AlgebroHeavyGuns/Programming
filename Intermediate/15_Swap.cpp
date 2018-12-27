/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;


void swap(int& a, int& b){
  int aux = a;
  a = b;
  b = aux;
}


int main(){

  int edad_antonio = 20;
  int edad_manolo = 16;

  int* puntero;
  puntero = &edad_antonio;  // puntero almacena la direccion de edad_antonio.

  cout << "\nEdad antonio : "  << *puntero;  // mostrar el valor apuntado.

  swap(edad_antonio, edad_manolo);

  cout << "\nEdad antonio : "  << *puntero;

  *puntero = 25;

  cout << "\nEdad antonio : "  << *puntero << endl;


    return 0;
}


/*
		En detalle
		-----------------------

    Lon punteros almacenan una direccion de memoria.

    int* p;   Declaracion del puntero.
    *p;       Valor almacenado en la direccion que indica p.
    &p;       Direccion en la que se encuentra p (generalmente usado con variables,
              no con puntero)



*/
