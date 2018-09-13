/*

	(C)Algebro.



*/

#include <iostream>


using namespace std;


int Sumatoria(const int vector[], const int tam){
  int resultado = 0;
  const int* p = vector;
  while(p<vector+tam){
    resultado += *p;
    p++;
  }
  return resultado;
}


int main(){

  int vector[] = {1,2,3,4,5,6,7,8,9,10};
  const int TAM = 10;

  cout << "Sumatoria : " << Sumatoria(vector, TAM) << endl;


}


/*
		En detalle
		-----------------------

    La funcion recibe el vector como constantes
    ya que la no requiere modificar su contenido.s



*/
