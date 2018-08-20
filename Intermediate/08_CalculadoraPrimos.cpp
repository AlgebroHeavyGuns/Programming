/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;


bool Divisible(int primos[], int n){
  for(int i=0; i<n; i++){
    if(primos[n]%primos[i]==0)
      return true;
  }
  return false;
}

void Next(int primos[], int n){
  primos[n] = primos[n-1]+1;
  while(Divisible(primos, n)){
    primos[n] +=1;
  }
}

void CalcularPrimos(int primos[], int n){
  primos[0]=2;
  cout << 2 << "\t";    //El primero.
  for(int i=1;i<n;i++){
    Next(primos, i);
    cout << primos[i] << "\t";    //Los muestra segun los va encontrando.
  }
}

int main(){

  const int MAX = 400000;
  int primos[MAX];
  int nprimos;

  cout << "Indicar cuantos primos se desean calcular : ";
  cin >> nprimos;

  if(nprimos <= MAX && nprimos> 0){
    CalcularPrimos(primos, nprimos);
  }

  cout << endl;


  return 0;
}


/*
		En detalle
		-----------------------





*/
