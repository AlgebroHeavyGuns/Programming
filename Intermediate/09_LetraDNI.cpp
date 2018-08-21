/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;



int main(){

  const char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
  long long DNI;

  cout << "Introducir numero de DNI : ";
  cin >> DNI;

  cout << "Letra : " << letras[DNI%23] << endl;



  return 0;
}


/*
		En detalle
		-----------------------




*/
