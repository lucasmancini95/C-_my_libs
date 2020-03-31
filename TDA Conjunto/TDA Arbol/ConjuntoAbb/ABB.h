
#ifndef ABB_H_
#define ABB_H_


template <class T>
class ABB
{
private: 
  struct nodo
  {
  T info;
  struct nodo *izq;
  struct nodo *der;
  struct nodo *padre;
  };
         
  struct nodo *raiz;
  int nelementos;
 
 void destruir(nodo * p)  
 {
    if (p!=0)
       {
       destruir(p->izq);
       destruir(p->der);
       delete p;
       }
 }
    
 void copiar(nodo *& dest, nodo * orig) 
 {
    if (orig==0)
            dest= 0;
    else 
          {
           dest= new nodo;
           dest->info= orig->info;
           copiar (dest->izq,orig->izq);
           copiar (dest->der,orig->der);
           if (dest->izq!=0)
              dest->izq->padre= dest;
           if (dest->der!=0)
              dest->der->padre= dest;
           }
 }
      
 public:
              
 typedef struct nodo *Iterador;
           
 ABB()
 {
      raiz=0;
      nelementos=0;
 }
    
 ABB (const ABB<T>& v) 
{
   copiar (raiz,v.raiz);
   if (raiz!=0)
      raiz->padre= 0;
   nelementos=v.nelementos;
}
    
ABB<T>& operator = (const ABB<T> &v) 
{
   if (this!=&v)
         {
           destruir(raiz);
           copiar (raiz,v.raiz);
           if (raiz!=0)
           raiz->padre= 0;
           nelementos=v.nelementos;
         }
   return *this;
}



Iterador primero() const 
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
    
Iterador siguiente(Iterador i) const
{
 nodo *padre;
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
          padre= i->padre;
          if (padre==0)
            { 
               i=0;
               subir=false;
             }
          else 
             if (padre->der!=i)
             {
               i= padre; 
               subir=false;
              }
              else i= padre;
          }
   }
return i;
}
    
Iterador final() const  
{
 return 0;
}
    
const T& info(const Iterador n) const 
{
  return (n->info);
}
    
Iterador buscar(const T& e) const 
{
  Iterador i;
  i=raiz;
  while (i!=0)
    {
      if (i->info<e)
        i=i->der;
      else 
         if (e<i->info)
           i=i->izq;
         else return i;
    }
  return final();
}
    
bool insertar(const T& e)
 {  //1   
    bool fin,dev;
    nodo *p;
    if (raiz==0)
       {  //2
       raiz = new nodo;
       raiz->padre= raiz->izq= raiz->der= 0;
       raiz->info= e;
       nelementos++;
       return true;
       }  //2
    else   
       {  //3
            p= raiz;
            fin=false;
            while (!fin)
            {   //4
                if (e<p->info)
                   {   //5
                      if (p->izq==0)
                               {  //6
                                p->izq= new nodo;
                                p->izq->padre=p;
                                p=p->izq;
                                p->der= p->izq= 0;
                                fin=true;
                                dev= true;
                                }  //6
                        else p= p->izq;
                     }  //5
                 else 
                    if (p->info<e)
                     {   //7
                        if (p->der==0)
                             {  //8
                                 p->der= new nodo;
                                 p->der->padre=p;
                                 p=p->der;
                                 p->der= p->izq= 0;
                                 fin=true;
                                 dev= true;
                             }   //8
                          else p= p->der;
                     }    //7
                      else
                          {  //9
                           fin=true;
                           dev=false;
                          }  //9
            }//4
            }//3 
            p->info= e;
            if (dev)
               nelementos++;
            return dev;
 }//1 
              
Iterador borrar(const Iterador p) 
{
  nodo *q, *aux, *dev;
  dev= siguiente(p);
  nelementos--;
  if (p->izq==0 && p->der==0)
   {
     if (p==raiz)
          {
          delete p;
          raiz=0;
          }
     else 
          {
            q=p->padre;
            delete p;
            if (q->izq==p)
              q->izq=0;
            else q->der=0;
          }
   }
    else 
       if (p->izq==0)
              {
              if (p==raiz)
                 {
                 raiz= p->der;
                 delete p;
                 raiz->padre= 0;
                  }
            else 
               {
                  q=p->padre;
                  if (q->izq==p)
                      {
                      q->izq=p->der;
                      p->der->padre=q;
                      delete p;
                      }
                   else 
                      {
                       q->der=p->der;
                       p->der->padre=q;
                       delete p;
                       }
                }
              }
          else 
            if (p->der==0)
                    {
                    if (p==raiz)
                       {
                       raiz= p->izq;
                       delete p;
                       raiz->padre= 0;
                       }
                    else 
                    {
                       q=p->padre;
                       if (q->der==p)
                          {
                            q->der=p->izq;
                            p->izq->padre=q;
                            delete p;
                          }
                       else 
                          {
                             q->izq=p->izq;
                             p->izq->padre=q;
                             delete p;
                           }
               }
            }
                 else {
                         q=p->der;
                         while (q->izq!=0)
                           q=q->izq;
                         aux= q->padre;
                         if (q->der==0)
                             {
                               if (aux->izq==q)
                                aux->izq= 0;
                               else aux->der=0;
                              }
                         else 
                             {
                              if (aux->izq==q)
                                 aux->izq=q->der;
                              else aux->der= q->der;
                              q->der->padre=aux;
                              }
      q->izq= p->izq;
      q->der= p->der;
      q->padre= p->padre;
      if (q->padre!=0)
         {
         aux= q->padre;
         if (aux->izq==p)
         aux->izq= q;
         else aux->der= q;
         }
      else raiz=q;
      if (q->izq!=0)
          q->izq->padre=q;
      if (q->der!=0)
          q->der->padre=q;
      delete p;
      } 
    return dev;
}
    
    void clear() {
    destruir(raiz);
    raiz= 0;
    nelementos= 0;
}
    
int size() const  
{
    return nelementos;
}
    
bool empty() const 
{
    return raiz==0;
}
    
bool operator == (const ABB<T>& v) const 
{
    Iterador p,q;
    if (nelementos!=v.nelementos)
       return false;
    for (p=this->primero(),q=v.primero();p!=final();p=this->siguiente(p),q=v.siguiente(q))
    if (this->info(p)!=v.info(q))
        return false;
    return true;
    }
    
bool operator != (const ABB<T>& v) const 
{
    return !(*this==v);  
}
    
~ABB()  
{
    destruir(raiz);
}      
};
      
#endif 
      
