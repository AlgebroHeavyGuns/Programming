/*

	(C)Algebro.
	
*/

#include <iostream>		//Nos permite utilizar 'cout' y 'cin', para salida y entrada de datos (respectivamente)

using namespace std;	//Define el espacio de nombres std.


int main(){				//Función principal de uso obligatorio. Nuestro programa comenzará ejecutándose por aquí.


	int variableA;
	int variableB;
	int resultado;

	cout << "Introducir valor para Variable A : ";
	cin >> variableA;		//Lee un dato (en nuestro caso, un entero) almacenándolo en A.

	cout << "Introducir valor para Variable B: ";
	cin >> variableB;		//Lee un dato (en nuestro caso, un entero) almacenándolo en B.

	resultado = variableA + variableB;		//Resultado (int) almacena el resultado de sumar ambas variables.


	cout << "La suma de A=" << variableA << " y B=" << variableB 
		<< " es " << resultado << endl;


	return 0;			//Con un 0 indicamos al sistema que se ha ejecutado nuestro programa correctamente.
}
