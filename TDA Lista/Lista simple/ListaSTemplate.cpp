
// Codigo sencillo, no robusto, como primer ejemplo de plantilla de la clase lista
#include <iostream>
using namespace std;

template <class T>
class nodo
{
private:
T info;
nodo<T> *sig;
public:
nodo(T x,nodo<T> *p=0):info(x),sig(p){};
T Getinfo() {return info;}
nodo<T> *Getsig() {return sig;}
void Setinfo(T i) {info=i;}
void Setsig (nodo<T> *n) {sig=n;}
};


template <class T>
class lista
{
private:
nodo<T> *p;
public:
lista();               //constructor sin argumentos; (agregar el constructor copia)
~lista();              //destructor
void altafin(T);       // alta al final
void altaprin(T);      //alta al principio
void baja(T);          //baja de la primera aparicion de un elemento determinado
bool esta(T);          // retorna un bool indicando si el entero pasado por argumento está en la lista
void emite();          //emite la lista
};

template <class T>
void lista<T>::altafin(T x)
{
nodo<T> *aux=p, *aux2;
while ((aux)&&(aux->Getsig()))
aux=aux->Getsig();
if (aux)
{
aux->Setsig(new nodo<T>(x,aux->Getsig()));
}
else p=new nodo<T>(x,p);
}

template <class T>
void lista<T>::altaprin(T x)
{
p=new nodo<T>(x,p);
}

template <class T>
void lista<T>::baja(T x)  //Elimina la primera aparicion del dato pasado por argumento
{
if (p)
{
if((p->Getinfo()!=x) && (p->Getsig()))
{
nodo<T> *aux1 =p, *aux2 =p->Getsig();
while ((aux2->Getinfo()!=x) && (aux2->Getsig()!=NULL))
{
aux1=aux2 ;
aux2 =aux2->Getsig();
}
if (aux2->Getinfo()==x)
{
aux1->Setsig(aux2->Getsig());

delete aux2;
}
}
else if(p->Getinfo()==x)
{
nodo<T> *aux =p;
p=p->Getsig();
delete aux;
}
}
}

template <class T>
lista<T>::~lista()
{
if (p)
{
nodo<T> *aux=p;
while (aux)
{
p=p->Getsig();
delete aux;
aux=p;
}
}
}

template <class T>
bool lista<T>::esta(T x) 
{
nodo<T> *aux=p;
while(aux)
  {
   if (aux->Getinfo() == x) return true;
                       else aux=aux->Getsig();
  }
  return false;
}

template <class T>
void lista<T>::emite()
{
nodo<T> *aux=p;
while (aux)
{
cout<<aux->Getinfo();
aux=aux->Getsig();
}
}

template <class T>
lista<T>::lista():p(0){}

int main()
{
lista<int> l;
cout<<"\n alta al final de 1\n";
l.altafin(1);
l.emite();
cout<<"\n alta al final de 2\n";
l.altafin(2);
l.emite();
cout<<"\n alta al final de 3\n";
l.altafin(3);
l.emite();
cout<<"\n alta al final de 4\n";
l.altafin(4);
l.emite();
cout<<"\n alta al principio de 5\n";
l.altaprin(5);
l.emite();
cout<<"\n baja 4\n";
l.baja(4);
l.emite();
cout<<"\n baja 1\n";
l.baja(1);
l.emite();
cout<<endl;

lista<char> s;
cout<<"\n alta al final de a\n";
s.altafin('a');
s.emite();
cout<<"\n alta al final de b\n";
s.altafin('b');
s.emite();
cout<<"\n alta al final de c\n";
s.altafin('c');
s.emite();

system("pause");
return 0;

}
