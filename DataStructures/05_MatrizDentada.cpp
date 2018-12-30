/*

	(C)Algebro.



*/
#include <iostream>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.


int main(int argc, char** argv){
  type** matrix;
  unsigned int fils;
  unsigned int* cols;

  cout << "Filas :  ";
  cin >> fils;



  matrix = new type* [fils];
  cols = new type [fils];

  for(unsigned int i=0;i<fils;i++){
    cout << "Columnas fila " << i << " :  ";
    cin >> cols[i];
    matrix[i]= new type[cols[i]];
  }


  unsigned int cont=0;
  for(unsigned int i=0;i<fils;i++)
    for(int j=0;j<cols[i];j++, cont++)
      matrix[i][j] = cont;

  for(unsigned int i=0;i<fils;i++){
    cout << endl;
    for(int j=0;j<cols[i];j++)
      cout << matrix[i][j] << "\t";
  }


  for(unsigned int i=0;i<fils;i++)
    delete[] matrix[i];
  delete[] matrix;

  cout << endl;

  return 0;
}
