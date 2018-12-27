/*

	(C)Algebro.



*/
#include <iostream>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.

struct Vector{
  type* vec;
  unsigned int size;
};


void createVector(Vector& vector, unsigned int newsize){
  vector.vec = new type[newsize];
  vector.size = newsize;
}

void deleteVector(Vector& vector){
  delete[] vector.vec;
  vector.size = -1;
}

void fillVector(Vector& vector, const type value){
  for(unsigned int i=0; i<vector.size;i++)
    vector.vec[i]=value;
}

void showVector(const Vector& vector, ostream& out, const char separator = '\t'){
  for(unsigned int i=0; i<vector.size;i++)
    out << vector.vec[i] << separator;
  out << endl;
}

const type& maxInVector(const Vector& vector){
  const type* max = vector.vec;
  for(unsigned int i=1;i<vector.size;i++)
    if(*max < vector.vec[i])
      max = vector.vec+i;   // = &vector.vec[i]
  return *max;
}


int main(int argc, char** argv){
  Vector v;
  createVector(v,5);
  cout << "Vector size : " << v.size << endl;
  fillVector(v, 1);
  v.vec[2]= 2;
  showVector(v, cout);
  cout << "Maximum : " << maxInVector(v) << endl;


  return 0;
}
