#include <iostream>
#include <stdlib.h>
using namespace std;
#define FIL_MAX 10
#define COL_MAX 10

class Life{
private:
  int tabla[FIL_MAX][COL_MAX];
  int generacion;
  int numero_vecinos_vivos(int ubicacion_fila,int ubicacion_columna){
    int n_vecinos_vivos=0;
/*
    if (ubicaion_fila==0) {
      if(ubicacion_columna==COL_MAX){}
      if(ubicacion_columna==0){}

    } else if (ubicaion_columna==0) {
      if(ubicacion_fila==COL_MAX){}
      if(ubicacion_fila==0){}

    } else {

    }*/

    if(existe_posicion_f(ubicacion_fila-1)==true && existe_posicion_c(ubicacion_columna-1)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila-1][ubicacion_columna-1];}
    if(existe_posicion_f(ubicacion_fila-1)==true && existe_posicion_c(ubicacion_columna)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila-1][ubicacion_columna];}
    if(existe_posicion_f(ubicacion_fila-1)==true && existe_posicion_c(ubicacion_columna+1)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila-1][ubicacion_columna+1];}
    if(existe_posicion_f(ubicacion_fila)==true && existe_posicion_c(ubicacion_columna-1)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila][ubicacion_columna-1];}
    if(existe_posicion_f(ubicacion_fila)==true && existe_posicion_c(ubicacion_columna+1)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila][ubicacion_columna+1];}
    if(existe_posicion_f(ubicacion_fila+1)==true && existe_posicion_c(ubicacion_columna-1)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila+1][ubicacion_columna-1];}
    if(existe_posicion_f(ubicacion_fila+1)==true && existe_posicion_c(ubicacion_columna)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila+1][ubicacion_columna];}
    if(existe_posicion_f(ubicacion_fila+1)==true && existe_posicion_c(ubicacion_columna+1)==true){ n_vecinos_vivos=n_vecinos_vivos+tabla[ubicacion_fila+1][ubicacion_columna+1];}

    return n_vecinos_vivos;
    }

  bool existe_posicion_f(int posicion){
    if(posicion<=0 || posicion>=FIL_MAX) return false;
    else return true;
  }

  bool existe_posicion_c(int posicion){
    if(posicion<=0 || posicion>=COL_MAX) return false;
    else return true;
  }

public:
  ~Life(){};
  Life(){
    int i,j;
    generacion=0;
    for(i=0;i<FIL_MAX;i++){
      for(j=0;j<COL_MAX;j++){
        tabla[i][j]=0;
      }
     }
  }
  //Life(int* t){}
  //void inicializar_vector_posicion_vivos(int * v){}
  void inicializar(){
    int hay_mas_vivos=1;
    int aux_fil, aux_col, aux_contador;
    aux_fil=0;
    aux_col=0;
    aux_contador=1;
    cout << "A continuacion debera ingresar las posiciones de los vivos, recuerde que la tabla tiene un largo de " << FIL_MAX << "x" << COL_MAX <<endl;
    while(hay_mas_vivos==1){
    cout << "Ingrese la fila del vivo numero " << aux_contador << endl;
    cin >> aux_fil;
    cout << "Ingrese la columna del vivo numero " << aux_contador << endl;
    cin >> aux_col;

    if(aux_fil<=FIL_MAX && aux_col<=FIL_MAX){
      tabla[aux_fil][aux_col]=1;
      aux_contador++;
    }

    cout << "Ingrese 1 si desea seguir ingresando vivos y 0 si no desea ingresar mas"  << endl;
    cin >> hay_mas_vivos;
    if(hay_mas_vivos!=1 && hay_mas_vivos!=0){hay_mas_vivos=0;}

    }
    generacion++;
  }

  void imprimir_tabla(){
    int i,j;
    for(i=0;i<FIL_MAX;i++){
      for(j=0;j<COL_MAX;j++){
        cout<< caracter_correspondiente(tabla[i][j]) << " ";
      }
      cout << endl;
     }
     cout << "Esta es la generacion numero: " << generacion << endl;
  }

  char caracter_correspondiente(int a){
    char aux;
    aux = (a==0)? 'x':'O'; // variable = condición ? valor si cierto : valor si falso
    return aux;
  }
  void imprimir_reglas(){

cout << "Reglas:" <<endl;
cout << "Las posiciones ocupadas(con un 1) son celulas vivas. Las celulas vivas van cambiando de generacion en generacion, siguiendo las siguientes 5 reglas:" <<endl;
cout << "1. Los vecinos de una celula son los 8 que estan en contacto." <<endl;
cout << "2. Si una celula tiene 0 o 1 vecinos vivos esa celula muere de soledad." <<endl;
cout << "3. Si una celula tiene mas de 4 vecinos vivos esa la celula muere de sobrepoblacion." <<endl;
cout << "4. Si una celula tiene 2 o 3 vecinos vivos la celula sobrevive." <<endl;
cout << "5. Si una posicion tiene exactamente 3 vecinos vivos nace una nueva celula" <<endl;

  }
  void evolucionar(){
    int tabla_aux[FIL_MAX][COL_MAX];
        int i,j;
    for(i=0;i<FIL_MAX;i++){
      for(j=0;j<COL_MAX;j++){
        tabla_aux[i][j]=0;
      }
     }

    for(i=0;i<FIL_MAX;i++){
      for(j=0;j<COL_MAX;j++){
        switch (numero_vecinos_vivos(i,j)) {
          case 2:
            tabla_aux[i][j]=tabla[i][j];
            break;
          case 3:
            tabla_aux[i][j]=1;
            break;
          default:
            tabla_aux[i][j]=0;
        }
      }
    }
    for(i=0;i<FIL_MAX;i++){
      for(j=0;j<COL_MAX;j++){
        tabla[i][j]=tabla_aux[i][j];
      }
     }

    generacion++;
  }

};


int main(){

Life creacion;

creacion.imprimir_reglas();
creacion.inicializar();
creacion.imprimir_tabla();

int salir_menu=false;
int opcion_menu = 1;

while(salir_menu!=true){
  cout << "elegir la opcion que desea:" << endl;
  cout << "1: evolucionar" <<endl << "2: imprimir" << endl << "3:salir" << endl;
  cin >> opcion_menu;
  switch(opcion_menu){
   case 1:
    creacion.evolucionar();
    cout << "la creacion ha evolucionado" <<endl;
    break;
  case 2:
    creacion.imprimir_tabla();
    break;
   default:
   salir_menu=true;
   break;
   }
}


}
