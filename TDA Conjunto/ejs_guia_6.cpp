/*Ejercicio 1
Dada una posible implementación dinámica de árboles binarios en C++,*/
template<typename T>
class bintree {
T *t_;
int n_;
bintree *izq_;
bintree *der_;
publi:
// ...
};
/*
Hallar una relación matemática simple entre el número de punteros null y la cantidad de nodos del árbol, n.
Mostrar, además, que esta relación no depende de la forma del árbol. Discutir, a partir de este resultado, cuánto espacio
se “desperdicia” en punteros null.*/

 la exprecion es ---> NULL(numero_nodos)=numero_nodos - 1 ;

/*Ejercicio 2 ♣
(a) Programar una función recursiva que, dado un árbol binario de n nodos, imprima la clave de cada nodo del árbol.
Además, la complejidad debe ser una O(n).*/

void preorder_recursivo(nodo* raiz){
  if(raiz==NULL){}
  else{
    cout<<(raiz->info);
    if(raiz->izq!=NULL){preorder_recursivo(raiz->izq);}
    if(raiz->der!=NULL){preorder_recursivo(raiz->der);}

  }
}
void Inorder_recursivo(nodo* raiz){
  if(raiz==NULL){}
  else{

    if(raiz->izq!=NULL){preorder_recursivo(raiz->izq);}
    cout<<(raiz->info);
    if(raiz->der!=NULL){preorder_recursivo(raiz->der);}

  }
}

void postorder_recursivo(nodo* raiz){
  if(raiz==NULL){}
  else{
    if(raiz->izq!=NULL){preorder_recursivo(raiz->izq);}
    cout<<(raiz->info);
    if(raiz->der!=NULL){preorder_recursivo(raiz->der);}

  }
}



/*(b) Programar una función no recursiva que, dado un árbol binario de n nodos, imprima la clave de cada nodo del
árbol. Usar una pila como estructura de datos auxiliar. Además, la complejidad debe ser una O(n).*/

void pre_printer(arbol & a){
  cout<<(a.info); //imprimo la raiz
  _pre_printer(a.derecha);
  _pre_printer(a.izquierda);
}

void _pre_printer(nodo* x){ //recibo un puntero a un nodo
  nodo *aux;
  pila_AB p; //creo pila de punteros a nodos
  p.apilar(x); // apilo la derecha/izquierda (segun el caso) de la raiz
  while(p.vacia()!=true){
    aux=p.desapilar();
    cout<<(aux->info);
    if(aux->derecha!=NULL) p.apilar(aux->derecha));
    if(aux->izquierda!=NULL) p.apilar(aux->izquierda));

  }
}

class nodo_AB{
  int info;
  nodo* izquierda, derecha;

}

/*
(c) Programar una función que, dado un árbol binario de n nodos, imprima la clave de cada nodo del árbol. Además,
sólo se permite usar una cantidad de espacio de almacenamiento constante (es decir, la cantidad de memoria extra
a usar -sin contar la memoria consumida por la representación del árbol- no debe depender de n). No se permite
modiVcar el árbol, ni siquiera temporalmente, durante el proceso. La complejidad resultante debe ser una O(n).

Nota: se puede suponer que la implementación provee un método up() que, dado un nodo o subárbol, devuelve el
padre de ese nodo en tiempo constante.*/


void pre_printer(arbol & a){
  cout<<(a.info); //imprimo la raiz
  _pre_printer(a.derecha);
  _pre_printer(a.izquierda);
}

void _pre_printer(nodo* x){ //recibo un puntero a un nodo
  nodo *aux;

while(aux->derecha || aux->izquierda || up(aux)->derecha==aux){  //hasta llegar a la punta derecha en total es O(n)

  while(aux->derecha || aux->izquierda){
aux=aux->izquierda;
cout<<(aux->info);
  } // con esto voy hasta la punta izquierda -- O(niveles)---> en el peor caso(arbol lista) O(n);
//ahora aux es la punta izquierda del arbol y se imprimieron todos hasta ese punto

aux=up(aux)->derecha;//va a la derecha del padre del elemento aux

}
