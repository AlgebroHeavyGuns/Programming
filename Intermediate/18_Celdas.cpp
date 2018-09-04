/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;


struct Celda{
  int valor;
  Celda* next;
};


int main(){

  Celda* inicio;

  Celda vector[3];

  inicio =  vector;

  vector[0].valor = 1;
  vector[0].next =  vector+1;

  vector[1].valor = 2;
  vector[1].next =  vector+2;

  vector[2].valor = 3;
  vector[2].next =  0;    // ultimo

  while(inicio != 0){
    cout << inicio->valor << "\t";
    inicio = inicio->next;
  }

  cout << endl;

    return 0;
}


/*
		En detalle
		-----------------------



*/
