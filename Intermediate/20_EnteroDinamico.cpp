/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;


int* EnteroDinamico(){
  int* p = new int;   // reserva espacio para un entero.
  return p;
}


int main(){

  int* pent = EnteroDinamico();
  *pent = 10;

  cout << "Entero dinamico = " << *pent << endl;

  delete pent;    //libera espacio ocupado;

}


/*
		En detalle
		-----------------------

    Es importante liberar la memoria que reservamos.

*/
