/*

	(C)Algebro.



*/

#include <iostream>
#include <stack>
#include <deque>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.


int main(int argc, char** argv){

  deque<type> d1(0);

  for(unsigned int i=0;i<10;i++)
    d1.push_back(i);


  stack<type> s1(d1);
  stack<type> s2;

  cout << "\nS1  : \n";
  while(!s1.empty()){
    cout << s1.top() << "\t";
    s2.push(s1.top());
    s1.pop();
  }


  cout << "\nS1 inverse : \n";
  while(!s2.empty()){
    cout << s2.top() << "\t";
    s2.pop();
  }

  cout << endl;

  return 0;
}
