/*

	(C)Algebro.


  Se esta diseñando un videojuego de rol, de exploracion de mapas.
  La idea del juego es que una zona puede tener como maximo dos caminos para avanzar,
  y, salvo la zona origen, dispondra de un camino de retorno.
  Cada zona contiene una referencia a los dos posibles caminos, un titulo, y una
  etiqueta del tipo de zona que es.

  En el juego se distinguen tres tipos zonas:
    - Ciudad:     Zona que dispone de un unico camino, si lo tuviese.
    - Territorio: Zona normal, puede tener hasta dos caminos.
    - Catacumba:  Zona que no tiene caminos.

  Se requiere de implementar las siguientes funcionalidad:

  CaminosRestantes  Recibe un nodo, y según el tipo de nodo y su topologia actual,
                indicará el numero de caminos (hijos) nuevos que puede tener dicho nodo.

  HuecosLibres  Recibe un nodo, e indica el numero de caminos que podria tener él
                o cualquier descendiente a cualquier profundidad.

  PosiblesPadres  Recibe el arbol, y devuelve una cola de todos los nodos que podrian
                crear un nuevo camino. Dicha cola debera estar ordenada por niveles.
                (Si el elemento i pertenece a un nivel n, el elemento i+1  pertenece a un nivel >=n)

  Distancia     Recibe dos nodos, e indica el numero de pasos para llegar de un nodo a otro,
                teniendo en cuenta los caminos de retorno y avance.



*/

#include <iostream>
#include "bintree/bintree.h"
#include <deque>
#include <string>

using namespace std;

enum typezone{
  CIUDAD=24, TERRITORIO=1, CATACUMBA=96
};

struct Zone{
  string title;
  typezone type;
};


typedef bintree<Zone>::node  bnode;

ostream& operator<< (ostream& out, const Zone& zone){
  out << zone.title << " (" << zone.type << ") ";
}




unsigned int CaminosRestantes (const bnode& n){
  if(n.null())
    return 0;
  if((*n).type==CATACUMBA)
    return 0;
  unsigned int children = 0;
  if(!n.left().null())
    children++;
  if(!n.right().null())
    children++;
  return (*n).type==CIUDAD ? 1-children : 2-children;
}


unsigned int HuecosLibres(const bnode& n){
  if(n.null())
    return 1; //Es un hueco

  if((*n).type==CIUDAD)
    return HuecosLibres(n.left()) + HuecosLibres(n.right()) - 1;
  if((*n).type==CATACUMBA)
    return 0;
  return HuecosLibres(n.left()) + HuecosLibres(n.right());
}



deque<bnode> PosiblesPadres (bintree<Zone>& tree){
  deque<bnode> padres, nodos;
  bnode actual;
  nodos.push_back(tree.root());
  while(!nodos.empty()){
    actual = nodos.front();
    nodos.pop_front();
    if(!actual.null()){
      nodos.push_back(actual.left());
      nodos.push_back(actual.right());
      if(CaminosRestantes(actual) > 0)
        padres.push_back(actual);
    }
  }
  return padres;
}

/*
deque<bnode> PosiblesPadres (bintree<Zone>& tree){
  deque<bnode> deque;
  for(bintree<Zone>::level_iterator i = tree.begin_level(); i!=tree.end_level(); ++i){
    if(CaminosRestantes(*i) > 0)
      deque.push_back(*i);
  }
  return deque;
}
*/




inline const Zone zone(string title, typezone type){
  Zone z = {title, type};
  return z;
}


void gen(bintree<Zone>& tree){
  tree.insert_left(tree.root(), zone("GreenValley", TERRITORIO));
  tree.insert_right(tree.root(), zone("SandStorm", TERRITORIO));
  tree.insert_left(tree.root().left(), zone("GreenCity", CIUDAD));
  tree.insert_right(tree.root().left(), zone("GreenCave", CATACUMBA));
  tree.insert_right(tree.root().right(), zone("SandSparkly", TERRITORIO));
  tree.insert_left(tree.root().left().left(), zone("GreatForest", TERRITORIO));
  tree.insert_left(tree.root().right().right(), zone("TheCrater", CIUDAD));
  tree.insert_right(tree.root().right().right(), zone("WarmBeach", TERRITORIO));
  tree.insert_left(tree.root().left().left().left(), zone("PalmTree", TERRITORIO));
  tree.insert_right(tree.root().right().right().left(), zone("AridSteppe", TERRITORIO));
  tree.insert_right(tree.root().right().right().right(), zone("CrazyCoconut", CIUDAD));
  tree.insert_right(tree.root().left().left().left().left(), zone("ColossalForest", CATACUMBA));
  tree.insert_right(tree.root().right().right().left().right(), zone("DirtyRavine", CIUDAD));
  tree.insert_right(tree.root().right().right().right().right(), zone("MysticalCave", CATACUMBA));
}


int main(int argc, char** argv){

  Zone origin = {
    "Origin",
    TERRITORIO,
  };

  bintree<Zone> maps(origin);

  gen(maps);

  cout << "Raiz tiene " << CaminosRestantes(maps.root()) << " caminos restantes, \n" <<
        "su hijo a la izquierda " << CaminosRestantes(maps.root().left()) << " y a la derecha " <<
        CaminosRestantes(maps.root().right()) << endl;

  cout << *maps.root().left().right() << "  tiene " << CaminosRestantes(maps.root().left().right()) << " caminos restantes\n";


  cout << "\nHuecos en el arbol " << HuecosLibres(maps.root());

  cout << "\nPosibles padres :  \n";
  deque<bnode> nodes = PosiblesPadres(maps);
  for(deque<bnode>::iterator it = nodes.begin(); it!=nodes.end(); ++it)
    cout << *(*it) << " -- ";

  cout << "\n\n";

  for(bintree<Zone>::level_iterator i = maps.begin_level(); i!=maps.end_level(); ++i)
    cout << *i << " ";

  cout << "\n\n";

  return 0;
}
