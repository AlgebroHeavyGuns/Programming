/*

	(C)Algebro.




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

void muestra(MatrizDentada& matriz){
  muestra(matriz.matriz, matriz.filas, matriz.columnas);
}


tipo minimo(tipo vector[], int tam){
  tipo min = vector[0];
  for(int i=1;i<tam;i++)
    if(vector[i]<min)
      min = vector[i];
  return min;
}

tipo minimo(MatrizDentada matriz){
  tipo minimos[MAX_TAM];
  for(int i=0;i<matriz.filas;i++)
    minimos[i]= minimo(matriz.matriz[i] , matriz.columnas[i]);
  return minimo(minimos, matriz.filas);
}

tipo maximo(tipo vector[], int tam){
  tipo max = vector[0];
  for(int i=1;i<tam;i++)
    if(vector[i]>max)
      max = vector[i];
  return max;
}

tipo maximo(MatrizDentada matriz){
  tipo maximos[MAX_TAM];
  for(int i=0;i<matriz.filas;i++)
    maximos[i]= maximo(matriz.matriz[i] , matriz.columnas[i]);
  return maximo(maximos, matriz.filas);
}

int main(){

  MatrizDentada dentada;
  dentada.filas = 3;
  dentada.columnas[0]= dentada.columnas[2] = 2;
  dentada.columnas[1]=3;

  /*
      2 4
      3 1 6
      3 0
  */

  dentada.matriz[0][0]= 2;  dentada.matriz[0][1]= 4;
  dentada.matriz[1][0]= 3;  dentada.matriz[1][1]= 1;  dentada.matriz[1][2]= 6;
  dentada.matriz[2][0]= 3;  dentada.matriz[2][1]= 0;

  muestra(dentada);

  cout << "\nMinimo : " << minimo(dentada) << endl;
  cout << "Maximo : " << maximo(dentada) << endl;

  return 0;
}


/*
		En detalle
		-----------------------



*/
