#include <iostream>
#include <stdlib.h>
using namespace std;




/*class nodo_c{
  friend class Cola;
  nodo_c* sig;
  nodo_c* ant;
  int dato;
};

class Cola{
  private:
    nodo_c* frente;
    nodo_c* fondo;
  public:
    Cola(){
      frente=NULL;
      fondo=NULL;
    }
    ~Cola(){
      while(vacia()==false){
        desencolar();
      }
    }
    void encolar(int a){
      nodo_c* nodo_nuevo = new nodo_c;
      nodo_nuevo->dato=a;

        if(fondo){
          nodo_c* aux;
          aux=fondo;

          fondo=nodo_nuevo;

          aux->ant=nodo_nuevo;

          nodo_nuevo->sig=aux;
          nodo_nuevo->ant=NULL;

        }
        else{
          fondo=nodo_nuevo;
          frente=nodo_nuevo;
          nodo_nuevo->ant=NULL;
          nodo_nuevo->sig=NULL;
        }
    }
    int desencolar(){

        if(frente!=NULL){
          int resultado= frente->dato;
          nodo_c* aux;
          aux=frente->ant;
          delete frente;
          frente=aux;
          if(aux) aux->sig= NULL;
          return resultado;
        }
        else{
          frente=NULL;
          fondo=NULL;
          return -1;
        }
    }
    bool vacia(){
      if(frente==NULL && fondo==NULL) return true;
      return false;
    }
};*/


class nodo_abb{
  friend class Arbol_Binario_Busqueda;
  private:
    int dato;
    nodo_abb* hermano_der;
    nodo_abb* hermano_izq;
};

class Arbol_Binario_Busqueda{
private:
  nodo_abb* raiz;

public:
  Arbol_Binario_Busqueda(){ raiz=NULL;}

  ~Arbol_Binario_Busqueda(){
      nodo_abb* nodo_aux =raiz;
          if(nodo_aux!=NULL){
      cout << "el nodo de dato " << nodo_aux->dato << "  sera borrado" << endl;
      _borrar_preorden(nodo_aux->hermano_izq);
      _borrar_preorden(nodo_aux->hermano_der);
      delete nodo_aux;
    }
  }

  void _borrar_preorden(nodo_abb* n){
    nodo_abb* nodo_aux =n;
    if(nodo_aux!=NULL){
    cout << "el nodo de dato "<< nodo_aux->dato << "  sera borrado" << endl;
    _borrar_preorden(nodo_aux->hermano_izq);
    _borrar_preorden(nodo_aux->hermano_der);
    delete nodo_aux;
    }
  }

  void insertar_elemento(int d){

    nodo_abb* p_nodo_nuevo = new nodo_abb;
    p_nodo_nuevo->dato=d;

    if(vacio()==false){
      nodo_abb* aux;
      nodo_abb* aux2;
      aux=raiz;

      while((aux)!=NULL){

          if(aux->dato > p_nodo_nuevo->dato){
            aux2=aux;
            aux=aux->hermano_izq;
          }

          else{
            if(aux->dato != p_nodo_nuevo->dato){
            aux2=aux;
            aux=aux->hermano_der;
            }
            else{
              aux=NULL;
              aux2=NULL;
              delete p_nodo_nuevo;
            }
          }

          /*if(aux->dato == p_nodo_nuevo->dato){s

          }*/
        }

        if (aux2) { // si aux2 es != NULL
          if(aux2->dato > p_nodo_nuevo->dato){aux2->hermano_izq=p_nodo_nuevo;}
          if(aux2->dato < p_nodo_nuevo->dato){aux2->hermano_der=p_nodo_nuevo;}
        }

      }
      else{
        raiz = p_nodo_nuevo;
      }
  }

  bool vacio(){
    if(raiz==NULL){ return true;}
    return false;
  }

  void imprimir_raiz(){
    if(raiz!=NULL){ cout<< raiz->dato << endl;}
  }

  void preorden(){
    cout << "Preorden" << endl;
    nodo_abb* nodo_aux =raiz;
        if(nodo_aux){ // si nodo_aux es != NULL
    cout << nodo_aux->dato << endl;
    _preorden(nodo_aux->hermano_izq);
    _preorden(nodo_aux->hermano_der);
    }
  }

    void _preorden(nodo_abb* n){
      nodo_abb* nodo_aux =n;
      if(nodo_aux){ // si nodo_aux es != NULL
      cout << nodo_aux->dato << endl;
      _preorden(nodo_aux->hermano_izq);
      _preorden(nodo_aux->hermano_der);
      }
  }

  void inorden(){
    cout << "Inorden" << endl;
    nodo_abb* nodo_aux =raiz;
        if(nodo_aux){ // si nodo_aux es != NULL
    _inorden(nodo_aux->hermano_izq);
    cout << nodo_aux->dato << endl;
    _inorden(nodo_aux->hermano_der);
    }
  }

    void _inorden(nodo_abb* n){
      nodo_abb* nodo_aux =n;
      if(nodo_aux){ // si nodo_aux es != NULL
      _inorden(nodo_aux->hermano_izq);
      cout << nodo_aux->dato << endl;
      _inorden(nodo_aux->hermano_der);
      }
  }

  void postorden(){
    cout << "Postorden" << endl;
    nodo_abb* nodo_aux =raiz;
        if(nodo_aux){ // si nodo_aux es != NULL
    _postorden(nodo_aux->hermano_izq);
    _postorden(nodo_aux->hermano_der);
    cout << nodo_aux->dato << endl;
    }
  }

    void _postorden(nodo_abb* n){
      nodo_abb* nodo_aux =n;
      if(nodo_aux){ // si nodo_aux es != NULL
      _postorden(nodo_aux->hermano_izq);
      _postorden(nodo_aux->hermano_der);
      cout << nodo_aux->dato << endl;
      }
  }

  /*void orden_por_nivel(){
     Cola C;
     nodo_abb* nodo_aux=raiz;
     C.encolar(nodo_aux->dato);
     while(C.vacia() != true){
     nodo_aux->dato=C.desencolar();
     cout << nodo_aux->dato << endl;
     if(nodo_aux->hermano_izq != NULL) C.encolar((nodo_aux->hermano_izq)->dato);
     if(nodo_aux->hermano_der != NULL) C.encolar((nodo_aux->hermano_der)->dato);
   }
 }*/

   bool buscar(int b){
     nodo_abb* nodo_aux=raiz;
     while(nodo_aux!=NULL){
       if(nodo_aux->dato==b)return true;
       if(nodo_aux->dato >= b){nodo_aux=nodo_aux->hermano_izq; }
       else{nodo_aux=nodo_aux->hermano_der; }
     }
     return false;
   }
};



int main(){

  Arbol_Binario_Busqueda A;
  A.insertar_elemento(7);
  A.insertar_elemento(10);
  A.insertar_elemento(13);
  A.insertar_elemento(6);
  A.insertar_elemento(4);
  A.insertar_elemento(5);
  A.insertar_elemento(1);
  A.insertar_elemento(10);

  A.preorden();
  cout << endl << endl;
  A.inorden();
  cout << endl << endl;
  A.postorden();
  cout << endl << endl;
  /*A.orden_por_nivel();
  cout << endl << endl;*/

  if(A.buscar(5)) cout << "5 se encuentra en el arbol" << endl;
  cout << endl << endl;

}
