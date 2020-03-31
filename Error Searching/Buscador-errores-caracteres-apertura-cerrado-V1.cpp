#include <iostream>
#include <stdlib.h>
#include <stack>
#include <fstream>
#define RUTA_ARCHIVO "hola.txt"
#define APERTURA_1 '('
#define APERTURA_2 '{'
#define APERTURA_3 '['
#define CERRADO_1 ')'
#define CERRADO_2 '}'
#define CERRADO_3 ']'

using namespace std;

bool caracter_buscado(char c){
  switch (c) {
    case APERTURA_1:
      return true;
      break;
    case APERTURA_2:
      return true;
      break;
    case APERTURA_3:
        return true;
        break;
    case CERRADO_1:
      return true;
      break;
    case CERRADO_2:
      return true;
      break;
    case CERRADO_3:
      return true;
      break;
    default:
      return false;
      break;
  }

  return false;
}

bool caracter_apertura(char c){
  switch (c) {
    case APERTURA_1:
      return true;
      break;
    case APERTURA_2:
      return true;
      break;
    case APERTURA_3:
        return true;
        break;
    default:
      return false;
      break;
  }

  return false;
}

bool caracteres_coincidentes(char abrir,char cerrar){
  switch(abrir){
    case APERTURA_1:
          if(cerrar==CERRADO_1) return true;
          break;
    case APERTURA_2:
        if(cerrar==CERRADO_2) return true;
        break;
    case APERTURA_3:
        if(cerrar==CERRADO_3) return true;
        break;
    default:
        break;
  }
  return false;
}


int main(){
  stack<char> pila_caracteres_apertura;

  char caracter_de_cerrado;

  ifstream archivo_lectura;
archivo_lectura.open(RUTA_ARCHIVO, ios::in );

char aux_caracter='x';

  while(archivo_lectura.get(aux_caracter)){
    if(caracter_buscado(aux_caracter)==true){ //pila_caracteres_apertura.push(aux_caracter);}
      if(caracter_apertura(aux_caracter)==true){
       pila_caracteres_apertura.push(aux_caracter);
      }
      else{
        caracter_de_cerrado=aux_caracter;
        if(caracteres_coincidentes(pila_caracteres_apertura.top(),aux_caracter)==false){
          cout << "error en el orden de los caracteres de apertura y cerrado: se encontro un " << caracter_de_cerrado << " mientras que se deberia haber encontrado el caracter de cerrado correspondiente a " << pila_caracteres_apertura.top() << endl;
          return 1;
        }
        else{
        pila_caracteres_apertura.pop();
      }
      }
    }

  }
  if(pila_caracteres_apertura.empty()!=true){ cout << "error falta un caracter de cerrado" << endl;}

  /*char aux;
while(pila_caracteres_apertura.empty()!=true){
char aux;
aux= pila_caracteres_apertura.top();
pila_caracteres_apertura.pop();
cout << aux << endl;
 }*/
return 0;
}
