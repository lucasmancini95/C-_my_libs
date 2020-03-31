//Imple Conjunto sobre ABB

# ifndef ABB_H
# define ABB_H

template <class T>
class Conjunto
{
 private:

 class nodo
 {
   public:
        T info;
        nodo *izq;
        nodo *der;
        nodo *padre;
        nodo(T i, nodo *iz=0, nodo *de=0, nodo * pa=0): info(i),izq(iz),der(de),padre(pa){}
        friend class Conjunto;
 };


 nodo *raiz;

 void destruir(nodo * p)
 {
    if (p!=0)
       {
       destruir(p->izq);
       destruir(p->der);
       delete p;
       }
 }

 public:

 class IteradorInorden
{
 private:
  nodo * apun;
  IteradorInorden(nodo * p):apun(p) {}

 public:
  IteradorInorden():apun(0){}
  IteradorInorden(const Conjunto &a):apun(a.raiz){}
  IteradorInorden & operator=(const IteradorInorden& i ) {apun = i.apun; return *this;}
  bool  operator==(const IteradorInorden& i ) { return apun== i.apun;}
  bool  operator!=(const IteradorInorden& i ) { return apun!= i.apun;}

IteradorInorden sig_inorden()
{
nodo * i=this->apun;
nodo*pad;
 bool subir;
 if (i->der!=0)
   {
     i=i->der;
     while (i->izq!=0)
        i=i->izq;
   }
 else
   {
      subir=true;
      while (subir)
        {
          pad= i->padre;
          if (pad==0)
            {
               i=0;
               subir=false;
             }
          else
             if (pad->der!=i)
             {
               i= pad;
               subir=false;
              }
              else i= pad;
          }
   }
return IteradorInorden(i);
}

T& operator*(){return apun->info;}


friend class Conjunto<T>;
friend class nodo;
};                            ///fin clase IteradorInorden


 Conjunto<T>()
 {
      raiz=0;

 }

IteradorInorden primero() const
{
  nodo *p;
  if (raiz)
           {
            p=raiz;
            while (p->izq!=0)
             p= p->izq;
            return p;
            }
    else return 0;
      }



IteradorInorden final() const
{
 return 0;
}

const T& info(const IteradorInorden n) const
{
  return (n.apun->info);
}



void alta(T d)
{
if (!raiz)
  this->raiz= new nodo(d);
else {
       nodo *aux=raiz;
       bool ready=false;
       while (!ready)
               {
                if (d<aux->info)
                {
                 if(aux->izq)
                 aux=aux->izq;
                 else
                   {
                    aux->izq=new nodo(d,0,0,aux);
                    ready=true;
                   }
                }
              else
               {
                if (d>aux->info)
                {
                if(aux->der)
                  aux=aux->der;
                else
                    {
                   aux->der=new nodo(d,0,0,aux);
                   ready=true;
                     }
               }
               else
                 ready=true;
                }
             }
       }
}

~Conjunto()
{
    destruir(raiz);
}

friend class IteradorInorden;
friend class nodo;
};

# endif


#include <cstdlib>
#include <iostream>

#include "ABB.h"


using namespace std;

int main ()
    {
    Conjunto<char> a;
    Conjunto<char>::IteradorInorden p;
    char i;
std::cout<<"Ingrese caracteres, * para fin"<<endl;
    std::cin>>i;
    while (i!='*')
    {
          a.alta(i);
          cin>>i;
    }
cout<<"Valores ingresados, se usa iterador inorden"<<endl;
for (p=a.primero();p!=a.final();p=p.sig_inorden())
          cout << *p << ' ';
    cout << endl;


    cout << endl;
    cin>>i;
    return 0;
    }
