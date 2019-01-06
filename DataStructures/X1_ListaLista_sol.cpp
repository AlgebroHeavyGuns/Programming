/*

	(C)Algebro.


  Para un festival de heavy metal internacional muy importante
  necesitan un programa para organizar los grupos que van a tocar
  en el festival.
  Para almacenar el plan se debe usar una lista para cada uno de los días
  del festival que contendrán una lista con la banda que toca esos días.

  Las bandas contienen la siguiente informacion:
    -Un string (sin espacios) para almacenar el titulo.
    -Un entero positivo para almacenar el numero de 'medias horas' que van a tocar (un 3 significa 90 minutos)
    -Un entero positivo para almacenar la valoracion del grupo (popularidad)

  Un dia de festival no puede contener mas de 5 horas de concierto.

  Las funciones requeridas son:
  InsertaBanda. Recibe el plan actual, y la banda a insertar,
                y busca el primer dia que pueda introducir dicho grupo,
                si no es posible, agregará un nuevo dia de festival.
                Devuelve true si ha insertado un nuevo dia, false en caso contrario.
  BandasEnDia.  Recibe el plan actual, y un dia de festival (un numero entero entre 0 y el total de dias),
                y devuelve las bandas que tocan ese día ordenadas de menor a mayor valoracion.
  MejorPar.     el plan actual, busca los dos dias consecutivos con mayor valoracion,
                y devuelve una lista con ambas listas (una lista con dos elementos)



*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

static const unsigned int MAX_TIME = 10;

struct Banda{
  string titulo;
  unsigned int mediashoras;
  unsigned int valoracion;
};

/**1**/
ostream& operator << (ostream& out, const Banda& banda){
  out << banda.titulo << "  " << banda.mediashoras << "  " << banda.valoracion;
}

ostream& operator << (ostream& out, const list<Banda>& bandas){
  out << "-----\n";
  for (list<Banda>::const_iterator it=bandas.cbegin(); it!=bandas.cend(); ++it)
    out << (*it) << endl;
  out << "-----";
}


ostream& operator << (ostream& out, const list<list<Banda> >& plan){
  out << "-----------------\n";
  for (list<list<Banda> >::const_iterator it=plan.cbegin(); it!=plan.cend(); ++it)
    out << (*it) << endl;
  out << "-----------------";
}


/**2**/
bool HuecoEnDia(const list<Banda>& dia, const unsigned int necesario){
  unsigned int acumulado = 0;
  for (list<Banda>::const_iterator it=dia.cbegin(); it!=dia.cend() && acumulado+necesario<=MAX_TIME; ++it)
    acumulado += it->mediashoras;
  return acumulado+necesario<=MAX_TIME;
}

/**3**/
bool InsertaBanda(list<list<Banda> >& plan, const Banda& banda){
  for (list<list<Banda> >::iterator it=plan.begin(); it!=plan.end(); ++it){
    if(HuecoEnDia(*it, banda.mediashoras)){
      (*it).push_back(banda);
      return false;
    }
  }
  list<Banda> lista;
  lista.push_back(banda);
  plan.push_back(lista);
  return true;
}

bool compare(const Banda& first, const Banda& second){
  if(first.valoracion==second.valoracion)
    return first.mediashoras < second.mediashoras;
  return first.valoracion < second.valoracion;
}


bool OrdenaPlan(list<list<Banda> >& plan){
  for (list<list<Banda> >::iterator it=plan.begin(); it!=plan.end(); ++it)
    (*it).sort(compare);
}


/**4**/
list<Banda> BandasEnDia (const list<list<Banda> >& plan, unsigned int dia){
  list<list<Banda> >::const_iterator it=plan.cbegin();
  for(;it!=plan.cend() && dia>0; --dia, ++it);
  list<Banda> bandas(*it);
  return bandas;
}


unsigned int Valoracion(const list<Banda>& dia){
  unsigned int acumulado = 0;
  for (list<Banda>::const_iterator it=dia.cbegin(); it!=dia.cend(); ++it)
    acumulado += it->valoracion;
  return acumulado;
}


/**5**/
list<list<Banda> > MejorPar(const list<list<Banda> >& plan){
  if(plan.size()<3)
    return plan;
  unsigned int anterior, maximo, nuevo;
  list<list<Banda> >::const_iterator it=plan.cbegin();
  const list<Banda>* diaAnterior = &(*(it++));  //Del maximo
  const list<Banda>* diaPosterior = &(*(it++)); //Del maximo
  const list<Banda>* anteriorVisto = diaPosterior;

  anterior = Valoracion(*diaPosterior);
  maximo = anterior + Valoracion(*diaAnterior);

  for(; it!=plan.cend();++it){
    nuevo = Valoracion(*it);
    if(maximo < anterior+nuevo){
      maximo = anterior+nuevo;
      diaAnterior= anteriorVisto;
      diaPosterior = &(*it);
    }
    anterior = nuevo;
    anteriorVisto = &(*it);
  }

  list<list<Banda> > returned;
  returned.push_back(*diaAnterior);
  returned.push_back(*diaPosterior);
  return returned;
}



int main(int argc, char** argv){
  list<list<Banda> > plan;
  Banda banda;
  int dia;

  cin >> banda.titulo;
  while(!cin.eof()){
    cin >> banda.mediashoras;
    cin >> banda.valoracion;
    //cout << "\nBanda :  " << banda << endl;
    cout <<  (InsertaBanda(plan, banda) ? "\nNuevo dia insertado." : "\nInsertado en plan previo.") << "  dias : " << plan.size() << endl;
    cin >> banda.titulo;
  }

  OrdenaPlan(plan);

  cout << "Dia arbitario : ";
  //cin >> dia;
  dia = 2;
  cout << "Bandas el dia " << dia << " : \n" << BandasEnDia(plan, dia);


  cout << "\n--FESTIVAL--\n" << plan << endl;

  cout << "\n--Mejor bono 2 dias--\n" << MejorPar(plan) << endl;

  return 0;
}


/*
    -----------------------------
      COMENTARIOS
    -----------------------------

(1) Al sobrecargar cada uno de los operadores <<, podemos de forma
sencilla utilizarlos para minimizar el código de cada uno.
De manera que el último (el de banda) es el que realmente se ocupa de mostrar los datos,
dejando los demas como un simple 'relevo de responsabilidades'


(2) En el metodo HuecoEnDia se pueden apreciar algunos detalles.
El primero, la iteracion constante, puesto que solo queremos consultar los tiempos
no necesitamos modificar en absoluto nuestras listas.
El segundo, el uso del 'acumulado' y su introduccion en el for,
es importante llevar la cuenta de las horas que hay en un dia,
pero, si ese dia ya tiene suficientes horas como para no poder
ingresar las nuevas horas no es necesario continuar sumando.
(Ej.  Tenemos cuatro bandas con tiempos  3,2,1,1 y queremos meter una banda de duracion 6,
una vez hemos localizado las bandas de 3 y 2, ya sabemos que no hay espacio para la de 6)


(3) La primera parte del metodo (el bucle) consiste simplemente en buscar
el primer dia (la primera lista) que tenga hueco para la banda que queremos
insertar.
La segunda parte es, dado que no hay una lista ya creada que tenga hueco,
crear una nueva y añadir dicho dia a nuestro plan.


(4)Es una forma diferente de iterar N elementos, partimos de N,
y mientras sea mayor que 0, incrementamos el iterador.
Similar a:
  while(it!=plan.cend() && dia>0){
    --dia;
    ++it;
  }
Una vez encontrado el dia (la lista), creamos una copìa, y la devolvemos.
Esta funcion presupone que el dia tiene las bandas ordenadas (para eso se ha
implementado el metodo de ordenado); en caso contrario,
se deberia añadir la instruccion   ' (*it).sort(compare); '
para llamar a la función 'compare'.


(5) La funcion MejorPar, tiene varias formas de implementarse,
especialmente en cuanto a las variables y tipos que usar.

En este caso, el uso de los punteros sirve para evitar hacer copias,
es similar a ir guardando los indices, pero de manera que luego no hay
que volver a iterar las listas para encontrar qué objetos hay en los indices.
(Con un puntero apuntando al objeto se localizan rápido)

Es importante considerar que el mejor par incial son los dos primeros.

La instruccion  ' diaAnterior = &(*(it++)); '  puede asustar a verse,
pero si nos fijamos no es mas que un 'it++' para que se incremente
el iterador y devuelva el valor previo, el '*' para obtener el objeto
que determinaba dicho iterador; y finalmente, la '&' , para obtener
la dirección de memoria en la que se encuentra el objeto, y por tanto
dar valor a nuestro puntero  'const list<Banda>* diaAnterior'.

Hay que tener en cuenta que 'const' alude a la lista, no al puntero;
y que es importante, ya que no queremos modificar el plan, simplemente
consultarlo.

*/
