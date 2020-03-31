#include <cstdlib>
#include <iostream>
#include "TempArray.h"

using namespace std;

int main()
{
 int i; 
 Array <int> a;
 for (i=0;i<10;i++)
    a[i]=i*2;
 for (i=0;i<10;i++)
    std::cout<<a[i]<<std::endl;
 
 Array <char> b;
 for(i=0;i<5;i++)
    b[i]=(char)(i+65);
 for (i=0;i<5;i++)
    std::cout<<b[i]<<std::endl;   
    
 system("PAUSE");
 return 0;
}
