/*

	(C)Algebro.

  Realizacion de un cálculo sencillo, media de tres reales introducidos
	por consola.
*/

#include <iostream>

using namespace std;


int main(){


	double num1, num2, num3;
	double media;

	cout << "Introducir tres numeros reales : ";
	cin >> num1;
	cin >> num2;
	cin >> num3;

	media =  (num1 + num2 + num3)/3;


	cout << endl << "La media es " << media << endl;


	return 0;
}
