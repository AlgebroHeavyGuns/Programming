/*

	(C)Algebro.



*/
#include <iostream>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.


int main(int argc, char** argv){
  type** matrix;
  unsigned int fils, cols;

  cout << "Filas :  ";
  cin >> fils;
  cout << "Columnas :  ";
  cin >> cols;

  matrix = new type* [fils];
  for(unsigned int i=0;i<fils;i++)
    matrix[i]= new type[cols];

  for(unsigned int i=0;i<fils;i++)
    for(int j=0;j<cols;j++)
      matrix[i][j] = i*cols+j;

  for(unsigned int i=0;i<fils;i++){
    cout << endl;
    for(int j=0;j<cols;j++)
      cout << matrix[i][j] << "\t";
  }


  for(unsigned int i=0;i<fils;i++)
    delete[] matrix[i];
  delete[] matrix;

  cout << endl;

  return 0;
}
