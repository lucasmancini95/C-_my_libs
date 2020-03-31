#include <iostream>
#include <stdlib.h>
using namespace std;



class nodo_trie{
  class friend Trie;
  private:
  nodo_trie* arreglo_punteros[4];
};

class Trie{
  public:
  nodo_trie* inicio;

  private:
  // los metodos serian, constructor, destructor, insertar  buscar
  bool esta_en_trie(cadena c){
    if(inicio==NULL) return false;
    else{
      int aux=numero_para_char(c[1]);
      cadena c_aux;
      c_aux=armar_cadena_sin_primer_elemento(c);
      _esta_en_trie(c_aux,c[aux]);
    }
    return false;
  }


  bool _esta_en_trie(cadena c,nodo_trie* p){
    if(cadena.vacia()==true){
      if(c[TAMAÑO_MAX_ARREGLO]==NULL) return false;
      else{return true;}
    }
    int aux=numero_para_char(c[1]);
    cadena c_aux;
    c_aux=armar_cadena_sin_primer_elemento(c);
    _esta_en_trie(c_aux,c[aux]);

  }

  int numero_para_char(char a){
    switch (a) {
      case a:
        return 0;
        break;
      case b:
        return 1;
        break;
      case c:
        return 2;
        break;
    }
    return -1; // indica error
  }

};
