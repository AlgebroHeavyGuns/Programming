/*

	(C)Algebro.



*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.


int main(int argc, char** argv){

  srand (time(NULL));
  vector<type> v1;

  for(unsigned int i=0;i<10;i++)
    v1.push_back(i);

  unsigned int buscado = rand()%15;

  vector<type>::iterator it = v1.begin();
  while(it!=v1.end() && *it!=buscado){
    ++it;
  }

  if(*it==buscado)
    cout << "\nEncontrado el elemento " << buscado << " !!\n";
  else
    cout << "\nNo encontrado el elemento " << buscado << " !!\n";


  return 0;
}
