/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;

enum Casilla {p1 = 'o', p2 = 'x', out = ' '};


Casilla Comprobar(Casilla tablero[]){

  for(int i=0;i<3;i++){
    if(tablero[3*i] != out && tablero[3*i] == tablero[3*i+1] && tablero[3*i+1] == tablero[3*i+2])
      return tablero[3*i];
    if(tablero[i] != out && tablero[i]== tablero[i+3] && tablero[i+3]==tablero[i+6])
      return tablero[i];
  }

  if(tablero[4] != out){
      if(tablero[4] == tablero[0] && tablero[4] == tablero[8])
        return tablero[4];
      if(tablero[4] == tablero[2] && tablero[4] == tablero[6])
        return tablero[4];
  }


  return out;

}

void MostrarTablero(Casilla tablero[]){

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      cout << " " << (char)tablero[3*i+j];
    cout << endl;
  }



}


int main(){

  Casilla tablero1[] = {p1,p2,p1,p1,p2,p2,p2,p1,p1};  //MODIFICARLOS LIBREMENTE
  Casilla tablero2[] = {p2,p1,p1,p1,p2,p2,p1,p1,p2};  //MODIFICARLOS LIBREMENTE

  char resultado = Comprobar(tablero1);
  cout << "Tablero 1 : ";
  if(resultado == out)
    cout << "Hubo empate.\n";
  else
    cout << "Ganador : " << resultado << endl;
  MostrarTablero(tablero1);


  resultado = Comprobar(tablero2);
  cout << "Tablero 2 : ";
  if(resultado == out)
    cout << "Hubo empate.\n";
  else
    cout << "Ganador : " << resultado << endl;
  MostrarTablero(tablero2);

  return 0;
}


/*
		En detalle
		-----------------------



*/
