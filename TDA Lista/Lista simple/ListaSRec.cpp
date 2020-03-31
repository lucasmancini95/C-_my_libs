#include <iostream>
using namespace std;
class nodo
{
private:
int info;
nodo *sig;
public:
nodo();
nodo(int,nodo *);
int GetInfo(){return info;}
nodo* &  GetSig(){return sig;} 
void SetInfo(int x){info=x;} 
void SetSig(nodo *p){sig=p;}
};
nodo::nodo():info(0),sig(0){}
nodo::nodo(int x,nodo *p=0){info=x,sig=p;}
class lista
{
private:
nodo *p;
void AltaRe( nodo * &, int);
void BajaRe (nodo * &,int);
bool EstaRe (nodo *, int);
void EmiteRe ( nodo *) ;

public:
lista();  //constructor sin argumentos; agregar el constructor copia
~lista(); //destructor
void altafin(int);   // alta al final
void altaprin(int);  //alta al principio
void baja(int);      //baja de un elemento determinado
bool esta(int)  ;       // retorna un bool indicando si el entero pasado por argumento está en la lista
void emite() ;        //emite la lista
};

lista::lista():p(0){}
void lista::altafin(int x)
{
AltaRe(p, x);
}

void lista::altaprin(int x)
{
p=new nodo(x,p);
}

void lista::baja(int x)
{
BajaRe(p,x);
}

lista::~lista()
{
if (p)
{
nodo *aux=p;
while (aux)
{
p=p->GetSig();
delete aux;
aux=p;
}
}
}
bool lista::esta(int x)
{
return (EstaRe(p,x));
}

void lista::AltaRe(nodo* &q, int x)
{
if (!q) q=new nodo(x,0);
   else 
   {   
	   AltaRe(q->GetSig(),x);

   }
}
void lista::BajaRe (nodo * &q ,int x)
{
if(q)
    if (q->GetInfo() ==x) {
                       nodo * aux=q;
                       q=q->GetSig();
                       delete aux;
                      }
	else {
		  
		  BajaRe(q->GetSig(), x); 
		  
		  }
}
bool lista::EstaRe (nodo *q, int x) 
{
if (q)
    {
	  
	  int h = (q->GetInfo());
	  if(h==x) return true;
else {
	  nodo *  aux = q; 
	  return (EstaRe(aux, x));
}

}    
 else  return false;     
}

void lista::emite() 
{
EmiteRe(p);
}
void lista::EmiteRe(nodo *  q) 
{
if(q)
    {
	 nodo * aux=q;
	 int h=q->GetInfo();
     cout<<h<<" ";
     EmiteRe(q->GetSig());
    }
}
int main()
{
lista l;
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
cout<<"\n baja 5\n";
l.baja(5);
l.emite();
system("pause");
return 0;
}
