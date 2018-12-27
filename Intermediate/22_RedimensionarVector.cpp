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
    delete[] vector;
    vector = aux;
}


int main(){

  int tam;
  cout << "Indicar tamanio : ";
  cin >> tam;

  int* vec = VectorDinamico(tam);

  for(int i=0;i<tam;i++)
    vec[i]=i+1;

  int newTam = 2*tam;

  Redimensionar(vec, tam, newTam);


  cout << "\nVector dinamico : \n";

  for(int i=tam; i<newTam; i++)
    vec[i]=i-tam+1;   //vuelve a comenzar a contar

  for(int i=0;i<newTam;i++)
    cout << vec[i] << "\t";

  cout << endl;

  delete[] vec;    //libera espacio ocupado;

}


/*
		En detalle
		-----------------------

    Es importante liberar la memoria que reservamos.

*/
