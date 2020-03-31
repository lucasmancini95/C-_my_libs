#include <cstdlib>
#include <iostream>
#include "ABB.h"

using namespace std;

int main ()
    {
    ABB<int> a;
    ABB<int>::Iterador p;
    float i;
cout<<"Ingrese enteros, 0 para fin"<<endl;
    cin>>i;
    while (i!=0)
    {
          a.insertar(i);
          cin>>i;
    }
cout<<"Valores ingresados"<<endl;    
for (p=a.primero();p!=a.final();p=a.siguiente(p))
          cout << a.info(p) << ' ';
    cout << endl;
cout<<"se eliminaran los multiplos de 5" <<endl;       
for (p=a.primero();p!=a.final();)
          if (a.info(p)%5==0)
              p=a.borrar(p);
          else p=a.siguiente(p);
cout<<"Datos que han quedado en el arbol"<<endl;
for (p=a.primero();p!=a.final();p=a.siguiente(p))
          cout << a.info(p) << ' ';
    cout << endl;
    cin>>i;
    return 0;
    }
