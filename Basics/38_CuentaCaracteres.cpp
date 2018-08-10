/*

	(C)Algebro.

	Utilizando un struct para contabilizar el numero de apariciones
	de una caracter, contar cuantas veces se repite dicha caracter.

*/

#include <iostream>

using namespace std;


struct Aparicion{
	char caracter;
	int aparicion=0;
};

int main(){

	const int TAM = 256; 	//Hay 256 caracteres diferentes.
	Aparicion apariciones[TAM];

	for(int i=0;i<TAM;i++)
		apariciones[i].caracter = i;

	char car;

	cout << "Introducir una frase : ";
	car = cin.get();
	while(car != '\n'){

		apariciones[car].aparicion++;

		car = cin.get();
	}


	for(int i=0;i<TAM;i++)
		if(apariciones[i].aparicion > 0)
			cout << "Caracter " << apariciones[i].caracter << " aparece " << apariciones[i].aparicion << endl;


	return 0;
}

/*
		En detalle
		---------------



*/
