/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;


int* VectorDinamico(const int tam){
  int* p = new int[tam];   // reserva espacio para un vector (tamanio tam)
  return p;
}


int main(){

  int tam;
  cout << "Indicar tamanio : ";
  cin >> tam;

  int* vec = VectorDinamico(tam);
  for(int i=0;i<tam;i++){
    cout << "Valor casilla " << i << " : ";
    cin >> vec[i];
  }

  cout << "\nVector dinamico : \n";

  for(int i=0;i<tam;i++){
    cout << vec[i] << "\t";
  }

  cout << endl;

  delete[] vec;    //libera espacio ocupado;

}


/*
		En detalle
		-----------------------

    Es importante liberar la memoria que reservamos.

*/
