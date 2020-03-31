
#ifndef ABB_H_
#define ABB_H_


template <class T>
class nodo{
  nodo* izq, der, padre;
  T* info;
}




template <class T>
class AB{
  nodo*raiz;;
  int n_elementos;

  public:

  AB(){ raiz=NULL; n_elementos=0; }


  AB(const AB<T>& c){
    n_elementos=c.n_elementos;

    copiar(raiz,c);
    if (raiz!=0) raiz->padre= 0;
  }
  void _copiar(nodo * o,nodo *& d){
   if (o==0)d= 0;
   else {
      d= new nodo;
      d->info= o->info;
      copiar (d->izq,o->izq);
      copiar (d->der,o->der);
      if (d->izq!=0)
         d->izq->padre= d;
      if (d->der!=0)
         d->der->padre= d;
      }
    }
}



  nodo* padre(const nodo* n){ //si se usan arboles con nodo de vuelta
    return n->padre;
  }


  nodo* padre(nodo* n){ //precondicion la lista no debe estar vacio(no tener raiz) pero si esta vacia se devuelve NULL, lo mismo que cuando no se encuentra el elemento
    if((aux=raiz)==NULL)return NULL;
    if(aux==n) return NULL; 
    if( (aux=_padre(aux.derecha,n)) !=NULL)return aux;
    if( (aux=_padre(aux.izquierda,n)) !=NULL)return aux;
    return NULL;
  }

  nodo* _padre(nodo* x,nodo* n){ //recibo un puntero a un nodo
    nodo *aux;
    pila_AB p; //creo pila de punteros a nodos
    p.apilar(x); // apilo la derecha/izquierda (segun el caso) de la raiz
    while(p.vacia()!=true){
      aux=p.desapilar();
      if(aux->izq==n || aux->der==n) return aux;
      if(aux->derecha!=NULL) p.apilar(aux->derecha));
      if(aux->izquierda!=NULL) p.apilar(aux->izquierda));
    }
    return NULL;
  }

  nodo* _padre_recursivo(nodo* raiz,nodo* n){ //alternativa recursiva en forma preorder
    if(raiz==NULL){}
    else{
      if(raiz->der==n || raiz->izq==n) return raiz;

      if(raiz->izq!=NULL){_padre_recursivo(raiz->izq);}
      if(raiz->der!=NULL){_padre_recursivo(raiz->der);}

    }

  }






    }

  }




}

#endif
