/*

	(C)Algebro.

  Muestra el tamanio de los tipos de datos mas comunes
  haciendo uso de la funcion sizeof


*/

#include <iostream>


using namespace std;


struct CampoByte{
  bool var1 : 1;
  bool var2 : 1;
  unsigned char dado4 : 2;  //0...3
  unsigned char dado8 : 3;  //0...7
  unsigned char : 1;    //relleno
};


int main(){

  CampoByte campo;

  campo.var1 = true;
  campo.var2 = false;
  campo.dado4 = 3;
  campo.dado8 = 5;

  cout << "\nTamanio del struct :  " << sizeof(campo)*8 << " bits";
  cout << "\nValores : \nBooleanos : " << campo.var1 << " " << campo.var2
    << "\nDados : " << (unsigned short)campo.dado4 << " " << (unsigned short)campo.dado8 << endl;



    return 0;
}


/*
		En detalle
		-----------------------

    Algunos tipos de datos depende del sistema operativo para
    determinar la memoria que ocupa.


*/
