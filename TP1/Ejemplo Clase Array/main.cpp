#include <cstdlib>
#include <iostream>
#include "Array.h"
#include "ErrorSubin.h"


using namespace std;

int main(int argc, char *argv[])
{
Array a, b(5), c(a);
int i;
for(i=0;i<10;i++) a[i]=i+1;
c=a;
for(i=0;i<5;i++) b[i]=i*2;
a.emitir();
c.emitir();
b.emitir();
std::cout<<"Probando excepcion fuera de rango"<<endl;

try
{
std::cout<<"emitir b[6]"<< b[6]<<endl;
}
catch(ErrorSubin &e)
{std::cout<<"excepcion atrapada por el catcher"<<endl;}

    
system("PAUSE");
return EXIT_SUCCESS;
}
