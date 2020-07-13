/*

	(C)Algebro.




*/

#include <iostream>

using namespace std;


struct Operation
{
    float a;
    float b;
    char op;
};

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




float Apply(Operation operation)
{
    switch(operation.op){
        case '+':
            return Suma(operation.a, operation.b);
        case '-':
            return Suma(operation.a, -operation.b);
        case '*':
            return Producto(operation.a, operation.b);
        case '/':
            return Producto(operation.a, 1/operation.b);
        case '^':
            return Pow(operation.a, operation.b);
        default:
            return 0;
    }

}


int main(){

  Operation operation;

  cin >> operation.a;
  do{
      cin >> operation.op;
  }while(!IsOperation(operation.op));
  while(!IsExit(operation.op))
  {
      cin >> operation.b;
      float result = Apply(operation);

      cout << "\nCalculated :  " << operation.a << " " << operation.op << " " << operation.b
        << "  = " << result << endl;

      operation.a = result;

      do{
          cin >> operation.op;
      }while(!IsOperation(operation.op));
  }

  return 0;
}


/*
		En detalle
		-----------------------



*/
