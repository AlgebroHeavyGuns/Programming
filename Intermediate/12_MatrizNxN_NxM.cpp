/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;

const int MAX_TAM = 12;
typedef unsigned int tipo;		//nos permite cambiar el tipo de forma uniforme.


struct MatrizNxN{
  tipo matriz [MAX_TAM][MAX_TAM];
  int n;    // filas=columnas=n
};

struct MatrizNxM{
  MatrizNxN base;
  int m;    // columnas
};

void inicia(tipo matriz[][MAX_TAM], int n, int m, tipo valor){
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      matriz[i][j]= valor;
}

void muestra(tipo matriz[][MAX_TAM], int n, int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cout << matriz[i][j] << " ";
    cout << endl;
  }
}


int main(){

  MatrizNxN cuadrada;
  cuadrada.n=3;
  inicia(cuadrada.matriz, cuadrada.n, cuadrada.n, 1);
  muestra(cuadrada.matriz, cuadrada.n, cuadrada.n);

  cout << endl;

  MatrizNxM rectangular;
  rectangular.base.n = 4;
  rectangular.m = 6;
  inicia(rectangular.base.matriz, rectangular.base.n, rectangular.m, 2);
  muestra(rectangular.base.matriz, rectangular.base.n, rectangular.m);

  cout << endl;

  rectangular.base = cuadrada;
  rectangular.m = 2;  //si no se modifica m, accedemos a casillas basura.  (detalle abajo)
  muestra(rectangular.base.matriz, rectangular.base.n, rectangular.m);


  return 0;
}


/*
		En detalle
		-----------------------

    La matriz cuadrada debe guardar el numero de filas, que es tambien
    el numero de columnas.

    La matriz rectangular requiere conocer el numero de filas y el de columnas
    (pudiendo este conincidir o no)


    Si no ponemos la instruccion   rectangular.m = Valor;
    Donde Valor sea menor o igual que la n que teniamos en cuadrada,
    puesto que no iniciamos (poner valores validos) la matriz MAX_TAM x MAX_TAM
    si no, la matriz NxN, las casillas existen pero no tienen valores validos.
    al ejecutar rectangular.base = cuadrada, hemos perdido la matriz antigua
    de rectangular, y con ello las columnas 'adicionales'.



*/
