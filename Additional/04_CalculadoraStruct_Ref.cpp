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
    float result;
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


bool Apply(Operation& operation)
{
    switch(operation.op){
        case '+':
            operation.result = Suma(operation.a, operation.b);
            break;
        case '-':
            operation.result = Suma(operation.a, -operation.b);
            break;
        case '*':
            operation.result = Producto(operation.a, operation.b);
            break;
        case '/':
            operation.result = Producto(operation.a, 1/operation.b);
            break;
        case '^':
            operation.result = Pow(operation.a, operation.b);
            break;
        default:
            operation.result = 0;
            return false;
    }
    return true;
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
      Apply(operation);

      cout << "\nCalculated :  " << operation.a << " " << operation.op << " " << operation.b
        << "  = " << operation.result << endl;

      operation.a = operation.result;

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
