/*

	(C)Algebro.

  Para ver Matriz dentada en memoria dinamica:
  https://github.com/AlgebroHeavyGuns/Programming/blob/master/DataStructures/05_MatrizDentada.cpp

*/

#include <iostream>


using namespace std;

const int MAX_TAM = 12;
typedef unsigned int tipo;		//nos permite cambiar el tipo de forma uniforme.


struct MatrizDentada{
  tipo matriz [MAX_TAM][MAX_TAM];
  int filas;
  int columnas[MAX_TAM];  //cada casilla 'i' indica las columnas en la fila 'i' (detalle abajo)
};


void inicia(tipo matriz[][MAX_TAM], int n, int m[MAX_TAM], tipo valor){
  for(int i=0;i<n;i++)
    for(int j=0;j<m[i];j++)   //la posicion 'i' en el vector indica las columnas.
      matriz[i][j]= valor;
}


void muestra(tipo matriz[][MAX_TAM], int n, int m[MAX_TAM]){
  for(int i=0;i<n;i++){
    for(int j=0;j<m[i];j++)   //la posicion 'i' en el vector indica las columnas.
      cout << matriz[i][j] << " ";
    cout << endl;
  }
}


int main(){

  MatrizDentada cuadrada;
  cuadrada.filas = 2;
  cuadrada.columnas[0]= cuadrada.columnas[1] = 2;
  inicia(cuadrada.matriz, cuadrada.filas, cuadrada.columnas, 2);
  muestra(cuadrada.matriz, cuadrada.filas, cuadrada.columnas);

  cout << endl;

  MatrizDentada rectangular;
  rectangular.filas = 2;
  rectangular.columnas[0] = rectangular.columnas[1] = 4;
  inicia(rectangular.matriz, rectangular.filas, rectangular.columnas, 3);
  muestra(rectangular.matriz, rectangular.filas, rectangular.columnas);

  cout << endl;

  MatrizDentada dentada;
  dentada.filas = 3;
  dentada.columnas[0]=1;
  dentada.columnas[1]=4;
  dentada.columnas[2]=2;
  inicia(dentada.matriz, dentada.filas, dentada.columnas, 5);
  muestra(dentada.matriz, dentada.filas, dentada.columnas);



  return 0;
}


/*
		En detalle
		-----------------------

    La matriz cuadrada debe guardar el numero de filas, que es tambien
    el numero de columnas.

    La matriz rectangular requiere conocer el numero de filas y el de columnas
    (pudiendo este conincidir o no)

    La matriz dentada, requiere conocer el numero de columnas para cada fila.

    Como necesitamos almacenar un entero (entendemos que positivo) para cada
    fila, no queda otra que tener un vector con tantas casillas como filas.
    Y en cada posicion de ese vector (posicion i) guardar el numero de columnas
    de esa fila (fila i)


*/
