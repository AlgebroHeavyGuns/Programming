/*

	(C)Algebro.



*/
#include <iostream>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.

struct Vector{
  static const unsigned int MAX_VSIZE =100;
  type vec[MAX_VSIZE];
  unsigned int size;
};

void createVector(Vector& vector, unsigned int newsize){
  if(newsize <= Vector::MAX_VSIZE)
    vector.size = newsize;
}

void cleanVector(Vector& vector){
  vector.size = 0;
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
