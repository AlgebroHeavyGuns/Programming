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


int* Mezcla(const int* vector1, const int* vector2, const unsigned int tam1, const unsigned tam2){
  int* mezcla = VectorDinamico(tam1+tam2);
  int it1 = 0, it2=0;
  while(it1<tam1 || it2<tam2){
    if(it1<=it2 || it2==tam2){
      mezcla[it1+it2]=vector1[it1];
      it1+=1;
    }else{
      mezcla[it1+it2]=vector2[it2];
      it2+=1;
    }
  }
  return mezcla;
}

int main(){
  int vector1[] = {1,3,5,7,8};
  int vector2[] = {2,4,6};
  int tam1 = 5, tam2 = 3;


  int* mix = Mezcla(vector1, vector2, tam1, tam2);

  for(int i=0;i<tam1+tam2;i++)
    cout << mix[i] << "\t";

  cout << endl;

  delete[] mix;
}


/*
		En detalle
		-----------------------




*/
