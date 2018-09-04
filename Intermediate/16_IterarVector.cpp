/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;




int main(){

  int vector[] = {1,2,3,4,5,6,7,8,9,-1};    // -1 terminador.
  int* inicio;

  inicio = vector;  // inicio = &vector[0];

  while(*inicio != -1){
    cout << *inicio << "\t";
    inicio += 1;
  }

  cout << endl;

  return 0;

}


/*
		En detalle
		-----------------------



*/
