

/*Ejercicio 1
(a) Implementar en C++ una clase para representar listas doblemente enlazadas. Usar memoria dinámica y (al menos)
las siguientes operaciones:
bool vaia(), bool llena(), void insertar(onst T &) -inserta un elemento al comienzo de la lista-,
void agregar(onst T &) -inserta un elemento en el extremo Vnal-, y
T *busar(onst T &).
Además, diseñar e implementar un conjunto de pruebas de regresión de de la clase, a Vn de hacer validaciones en
el momento de hacer cambios en el código.

(b) Repetir el ejercicio anterior para una implementación estática, implementando la clase lista<N, T>, en donde
“N” es el tamaño máximo de la lista y “T” el tipo de los elementos contenidos. Sugerencia: usar templates.

*/

template <typename T>
class L_D{
  nodo* i;
  unsigned int t;
  unsigned int t_max;

public:
  bool vacia(){
    if(i==NULL) return true;
    else return false;
    }

  bool llena(){
    nodo* aux;
    aux=i;
    if(vacia()==true) return false;
    else{
      for(int x=0;aux->sig!=NULL;x++){
        aux=aux->sig;
      }
      if(x>=t_max) return true;
      else return false;
    }
 }

int insertar_principio(const T & d){}

int instertar_posicion(const T & d, int posicion){
  if(llena==true) return -1;
  else{
    nodo* aux=i;
    for(int x=0;aux->sig!=NULL;x++){
      aux=aux->sig;
    }
    if(x<=poiscion) return -1;
    else{
      aux=i;
      nodo* aux2,aux3;
      for(x=0;x!=posicion;x++0){
        aux=aux->sig;
      }
      aux2=aux;
      aux3=aux->sig;
      aux->sig=new nodo;
      aux=aux->sig;
      aux->sig=aux3;
      aux->ant=aux2;
      aux->dato=d;
    }

  }
return 0;
}

int agregar(const T & d){
  nodo* aux, aux2;
  aux = x;
if(llena==true) return -1;
else{
  while(aux->sig!=NULL){
    aux=aux->sig;
  }
  aux->sig= new nodo;
  aux2=aux;
  aux=aux->sig;
  aux->ant= aux2;
  aux->dato=d;
}
}
return 0;
  }


}

class nodo{
  nodo * sig;
  nodo * ant;
  T dato;

  public:

  nodo(){
    sig=NULL;
    ant=NULL;
  }

}




/*Ejercicio 2
Utilizando las clases del ejercicio anterior,
(a) Programar un método que borre el i-ésimo nodo de la lista, si es que existe.
(b) Programar un método para intercambiar los primeros dos elementos de la lista, teniendo en cuenta todos los casos
posibles.*/

//b)


int intercambiar{
  if(vacia==true) return -1; // error si esta vacia
  if(x->sig==NULL) return -1; // error si solo hay 1 elemento

  nodo* aux; // creo puntero a nodo

  aux= i; // gurdo  direccion del elemento 1 en aux
  i=i->sig; // apunto la lista al elemento 2
  aux2=i->sig; //  guardo la direccion del elemento 3 en aux2
  i->sig=aux; // apunto el sig del 2 a el 1
  aux2->ant=aux; // apunto el anterior  del 3 al 1
  aux->sig=aux2; // apunto el sigiente del 1 al 3
  i->ant=NULL; //apunto el ant del 2 a NUll
  aux->ant=i; // apunto el anterior del 1 al 2

  return 0;

}



/*Ejercicio 3
Escribir un programa que mezcle dos listas de enteros ordenadas en una única instancia de la clase. La función
mezlar() debe recibir dos referencias a cada uno de los objetos a mezclarse, y devolver un objeto que contenga la
lista mezclada.*/

class L_D{
  .
  .
  .
public:
  .
  .
  int tamaño{
    if(vacia()==true ) return -1;
    nodo* aux=x;
    int i;
    for(i=0;aux->sig!=NULL;i++){
      aux=aux->sig;
    }
    return i;
  }

  .
  .
  int elemento_lista(int posicion){

    nodo* aux,aux2;
    aux=x;
    for(int i=0; i<=posicion;i++){
        aux2=aux;
        aux=aux->sig;
    }
    return aux2->dato;
  }


}



&L_D mezclar(const L_D &L1,const L_D &L2){

    int largo1 = L1.largo;
    int largo2 = L2.largo;
    L_D* corto;

    int a=0;
    int b=0;
    L_D* pl = new L_D;


    while(a!=largo1 || b!=largo2){
      if( L1.elemento_lista(a) < L2.elemento_lista(b) ) { pl->agregar(L1.elemento_lista(a)); a++;}
      else { pl->agregar(L2.elemento_lista(b)); b++;}
    }
    while(a!=largo1){
      pl->agregar(L1.elemento_lista(a));
      a++;
    }
    while(b!=largo2){
      pl->agregar(L2.elemento_lista(b));
      b++;
    }
    return (*pl);
}


/*Ejercicio 9 ♣
Dados los caracteres (), [] y {}, y una cadena s, decimos que s está balanceada si tiene alguno de estos formatos:
s = ”” (string nulo)
s = (t)
s = [t]
s = {t}
s = tu
en donde t y u son cadenas balanceadas (en otras palabras, para cada paréntesis, llave o corchete abierto existe un
caracter de cierre correspondiente). Por ejemplo, s = ”{()[()]}” está balanceada.
Escribir un programa que use una pila de caracteres para determinar si una cadena está balanceada.*/









/*Ejercicio 10
(a) Escribir una función que acepte un string como argumento y devuelva un booleano indicando si el string ingresado
es un palíndromo. Ejemplos: “Yatay”, “Neuquen”.
*/

bool palindromo(const string &s){

    pila aux1;
    cola aux2;


  for(int i=0; i<(floor((s.size)/2)-1);i++){
    aux1.apilar(s[i]);
  }

  for(int i=(ceil(s.size/2);i<(s.size-1);i++){

  }
    aux2.encolar(s[i]);
  }

  bool iguales=true;

  while(iguales==true){
    if(aux1.desapilar==aux2.desencolar) iguales=true;
    else { iguales=false; return false;}
  }

  return true;

}

class string{
  char s[100];
  int size;
  public:

}
