#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include "complejo.h"
#include "ErrorSubin.h"

class Vector{

  private:
    complejo *array;
    size_t size;

  public:
    //Constructores y destructores
    Vector();
    Vector(const Vector &);
    Vector(size_t);
    ~Vector();


    //Metodos
    size_t RetSize(void){return size;}

    //Operadores
    complejo &operator[ ]( size_t );
    Vector &operator=( const Vector & );

};



#endif
