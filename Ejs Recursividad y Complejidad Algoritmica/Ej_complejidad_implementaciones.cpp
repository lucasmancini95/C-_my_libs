//Implementación (muy simple) de una pila con un array, y analisis de su costo temporal Big O

class pila{

  private:

    int v[100];
    int TOS;


  public:

    bool overflow(){
      if(TOS==100)return true;
      else return false;
    }

    bool empty(){
      if(TOS==0)return true;
      else return false;
    }

    bool push(int x){ // analisis temporal (big O del peor caso) de apilar: 2*O(1)+2*O(1)=>= O(1)
        v[TOS+1]=x; // 2 O.E.
        TOS++; // 2 O.E.
    }

    void pop(){ //analisis temporal (big O del peor caso) de desapilar: O(1)

      aux=v[TOS]; // 2 O.E.
      TOS--; // 2 O.E.

    }

    int peek(){ //analisis temporal (big O del peor caso) de pedir el elemento de arriba: O(1)
      int aux; // 1 O.E.
      aux=v[TOS]; // 2 O.E.
      TOS--; // 2 O.E.
      return aux;

    }

}










//Implementación (muy simple) de una pila con un una lista, y analisis de su costo temporal Big O
class pila{

  private:
    nodo* x;
    int TOS;
  public:

    pila(){
      x=NULL;
      TOP=0;
    }

    void pop(){ //analisis temporal (big O del peor caso) de desapilar: O(1)
      nodo* aux1,aux2;
      aux1=x;

      while((aux1->sig)!=NULL){
        aux2=aux1;
        aux1=aux1->sig;

      }
      delete aux1;
      aux2->sig=NULL;
      TOS--;


    }
    int push(int d){ //analisis temporal (big O del peor caso) de pedir el elemento de arriba: O(1)* O(n)=> O(n)
      nodo* aux1;
      aux1=x;

      while((aux1->sig)!=NULL){ // O(n) depende de la longitud de la lista
        aux1=aux1->sig;
      }

      aux1->sig=new nodo; // O(1)
      aux1=aux1->sig; // O(1)
      aux1->sig=NULL; // O(1)
      aux1->dato=d; // O(1)
      TOS++; // O(1)

    }
}
class nodo{
  int dato;
  nodo* sig;
public:
  nodo(){sig=NULL}

}












//analisis temporal (big O del peor caso) de suma vectorial

int suma(int v[], int N)
{
if (N==0) return v[0];
else return (v[N] + suma (v, N-1)) ;
}

//T(n)=O(1)+O(1)+T(N-1)
// T(n)=>O(0)









//analisis del big O de un pedaso de codigo

int i=1, n; // O(1)
cin>>n; // + O(1)
while (i<n) // pienso la tabla de valores
i=i*2;
/*tabla de valores:
valor de i: 1 | 2 | 4 | 8 | 16 | 32 .... | 2^i
valor de n: 1 | 2 | 3 | 4 | 5  | 6...... n
..... entonces:  2^i>=n ---> i>=(log2 n)
T(n)=>O(log N)
*/



// otro codigo

int i=1, n; //O(1)
cin>>n; //O(1)
while (i<100) // O(1) * 100
i=i*2; //O(1)
int n, a; //O(1)*2
cin>>n; //O(1)
if(n>10)// mejor rama, ya que es O(1)
a=20;//O(1)
else// peor rama
{
n=n+30;//O(1)
for (i=0;i<n;i++) //O(n) + O(1) + 2*O(1)
cout<<a; //O(1)
a++; //O(1) *2
}
//entonces T(n)=C1*O(1)+O(n)*C2*O(1) => O(n)
