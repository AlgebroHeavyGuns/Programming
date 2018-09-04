/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;




int main(){

  int vector[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int* puntoA;
  int* puntoB;

  puntoA = vector+3;    // vector+3  ==  vector[3]
  puntoB = vector+12;   // vector+12 ==  vector[12]

  cout << "Distancia de A (" << *puntoA << ") a B (" << *puntoB << ") es " << (puntoB-puntoA) << endl;


  return 0;

}


/*
		En detalle
		-----------------------



*/
