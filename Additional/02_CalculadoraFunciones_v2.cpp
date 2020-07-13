/*

	(C)Algebro.




*/

#include <iostream>

using namespace std;

float Suma(float a, float b)
{
    return a+b;
}

float Producto(float a, float b)
{
    return a*b;
}

float Pow(float left, int right){
    float aux = 1;
    for(int i=0; i<right;++i) aux *= left;
    return aux;
}

bool IsExit(char c)
{
    return c=='q';
}

bool IsOperation(char c)
{
    return IsExit(c) || c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}




float Apply(char operation, float left, float right)
{
    switch(operation){
        case '+':
            return Suma(left,right);
        case '-':
            return Suma(left, -right);
        case '*':
            return Producto(left, right);
        case '/':
            return Producto(left, 1/right);
        case '^':
            return Pow(left, right);
        default:
            return 0;
    }

}


int main(){

  char operation;
  float left_value;
  float right_value;

  cin >> left_value;
  do{
      cin >> operation;
  }while(!IsOperation(operation));
  while(!IsExit(operation))
  {
      cin >> right_value;
      float result = Apply(operation, left_value, right_value);

      cout << "\nCalculated :  " << left_value << " " << operation << " " << right_value
        << "  = " << result << endl;

      left_value=result;

      do{
          cin >> operation;
      }while(!IsOperation(operation));
  }

  return 0;
}


/*
		En detalle
		-----------------------



*/
