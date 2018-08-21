/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;


bool Iguales(const char cad1[],const char cad2[]){
  int i=0;
  while(cad1[i]==cad2[i] && cad1[i]!='\0')
    i++;
  return cad1[i]==cad2[i];

}


int main(){

  const char cadena0[] = "cadena";
  char cadena1[] = {'c','a','d','e','n','a','s','\0'};
  char cadena2[] = "cadenas";
  char cadena3[] = {'c','a','d','e','n','a','\0'};



  cout << "cadena 0 y 1 : " << (Iguales(cadena0, cadena1) ? "Igual" : "No es igual")
    << "\ncadena 0 y 2 : "  << (Iguales(cadena0, cadena2) ? "Igual" : "No es igual")
    << "\ncadena 1 y 2 : "  << (Iguales(cadena1, cadena2) ? "Igual" : "No es igual")
    << "\ncadena 0 y 3 : " << (Iguales(cadena0, cadena3) ? "Igual" : "No es igual") << endl;


  return 0;
}


/*
		En detalle
		-----------------------



*/
