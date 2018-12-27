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


int* Mezcla(const int* vector1, const int* vector2, const unsigned int tam){
  int* mezcla = VectorDinamico(2*tam);
  for(int i=0; i<2*tam; i++)
      mezcla[i] = i%2 ? vector1[i/2] : vector2[i/2];
  return mezcla;
}

int main(){
  int vector[] = {1,2,3,4,5,6,7,8,9,10};
  int tam = 10;

  cout << "\nVector antes : \n";
  for(int i=0;i<tam;i++)
    cout << vector[i] << "\t";

  int* mix = Mezcla(vector, vector+tam/2, tam/2);
  for(int i=1; i<tam; i++){   //tam-1 mezclas.
    mix = Mezcla(mix, mix+tam/2, tam/2);

    cout << "\nVector despues de " << i << " mezclas : \n";
    for(int i=0;i<tam;i++)
      cout << mix[i] << "\t";
  }

  cout << endl;

  delete[] mix;
}


/*
		En detalle
		-----------------------

    cuando se hacen tam-1 mezclas, se vuelve al vector original.


*/
