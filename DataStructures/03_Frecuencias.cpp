/*

	(C)Algebro.



*/
#include <iostream>
#include <iomanip>


using namespace std;


struct Frecuencia{
  char value;
  unsigned int frequency;
};

struct Vector{
  Frecuencia* vec;
  unsigned int size;
};


void createVector(Vector& vector, unsigned int newsize){
  vector.vec = new Frecuencia[newsize];
  vector.size = newsize;
}

void deleteVector(Vector& vector){
  delete vector.vec;
  vector.size = -1;
}

void showFrequency(const Frecuencia& freq, ostream& out, const int total){
  out << freq.value << " : " << setw(2) << freq.frequency << "   " << 1.0*freq.frequency/total << endl;
}


int main(int argc, char**){
  Vector v;
  createVector(v, 256);

  for(unsigned int i=0;i<256;i++){
    v.vec[i].value = (char)i;
    v.vec[i].frequency = 0;
  }

  char value;
  unsigned int occurrences = 0;

  value = cin.get();
  while(!cin.eof()){
    v.vec[value].frequency+=1;
    occurrences+=1;
    value = cin.get();
  }

  for(unsigned int i=0;i<256;i++)
    if(v.vec[i].frequency > 0)
      showFrequency(v.vec[i], cout, occurrences);


  return 0;
}
