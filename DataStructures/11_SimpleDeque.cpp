/*

	(C)Algebro.



*/

#include <iostream>
#include <deque>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.


int main(int argc, char** argv){

  deque<type> d1;

  for(unsigned int i=0;i<10;i++)
    d1.push_back(i);

  cout << "\nD1  : \n";
  for(unsigned int i=0;i<d1.size();i++)
    cout << d1[i] << "\t";


  deque<type> d2(10,1);

  d2[4] = 2;

  cout << "\nD2  : \n";
  for(unsigned int i=0;i<d1.size();i++)
    cout << d2.at(i) << "\t";

  deque<type> d3(d2);

  d3.resize(5);
  cout << "\nLast element in D3 : " << d3.back();
  cout << "\nFist element in D3 : " << d3.front();

  cout << "\nD3  : \n";
  while(!d3.empty()){
      cout << d3.front() << "\t";
      d3.pop_front();
  }


  cout << endl;

  return 0;
}
