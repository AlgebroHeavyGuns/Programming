/*

	(C)Algebro.



*/

#include <iostream>
#include <vector>


using namespace std;

typedef unsigned int type;		//nos permite cambiar el tipo de forma uniforme.


int main(int argc, char** argv){

  vector<type> v1;

  for(unsigned int i=0;i<10;i++)
    v1.push_back(0);

  cout << "\nV1  : \n";
  for(unsigned int i=0;i<v1.size();i++)
    cout << v1[i] << "\t";


  vector<type> v2(10,1);

  v2[4] = 2;

  cout << "\nV2  : \n";
  for(unsigned int i=0;i<v1.size();i++)
    cout << v2.at(i) << "\t";

  vector<type> v3(v2);

  v3.resize(5);
  cout << "\nLast element in V3 : " << v3.back();
  cout << "\nFist element in V3 : " << v3.front();

  v3.pop_back();
  cout << "\nCurrent last element in V3 : " << v3.back();

  vector<type> v4(v2);
  cout << "\nSize of V4 before clear : " << v4.size();
  v4.clear();
  cout << "\nSize of V4 after clear : " << v4.size();


  cout << endl;

  return 0;
}
