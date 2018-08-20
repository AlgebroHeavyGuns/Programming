/*

	(C)Algebro.




*/

#include <iostream>


using namespace std;



int main(){

  const int MAX_CASILLAS = 10;
  float calificaciones[MAX_CASILLAS];
  float pesos[MAX_CASILLAS];

  int asignaturas;
  float media=0, peso=0;

  cout << "Numero de asignaturas : ";
  cin >> asignaturas;

  if(asignaturas <= MAX_CASILLAS){
    for(int i=0; i<asignaturas; i++){
      cout << "\nCalificacion en asignatura " << i << " : ";
      cin >> calificaciones[i];
      cout << "\nPeso en calificacion " << i << " : ";
      cin >> pesos[i];
    }
    for(int i=0; i<asignaturas; i++){
      media += calificaciones[i]*pesos[i];
      peso += pesos[i];
    }
    media /= peso;

    cout << "\nCalificacion media : " << media << endl;

  }else
    cout << "\nDemasiadas asignaturas.\n";


  return 0;
}


/*
		En detalle
		-----------------------

    Podriamos haber usado directamente las variables estadisticas
    para realizar los calculos y ponderaciones ya que no necesitabamos
    almacenar los datos de las calificaciones.
    No obstantes, el objetivo es el uso de arrays.


*/
