/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;


int* VectorDinamico(const int tam){
  int* p = new int[tam];   // reserva espacio para un vector (tamanio tam)
  return p;
}

void Redimensionar(int*&vector, const int oldTam, const int newTam){
    int* aux = new int[newTam];
    for(int i=0;i<oldTam;i++)
      aux[i]= vector[i];
    delete vec;
}


int main(){

  int tam;
  cout << "Indicar tamanio : ";
  cin >> tam;

  int* vec = VectorDinamico(tam);




  delete[] vec;    //libera espacio ocupado;

}


/*
		En detalle
		-----------------------

    Es importante liberar la memoria que reservamos.

*/
