#include <cassert>
#include <iostream>
#include <stdio.h>

#ifndef TempArray_h
#define TempArray_h


template <class T>
class Array
{
public:
Array(); 
Array( const Array<T> & ); 
~Array( ); 
int getSize( ) const; 
Array<T>&operator=( const Array<T> & ); 
bool operator==( const Array<T> & ) const; 
T &operator[ ]( int ); 
private:
int size; 
T *ptr; 
};

template <class T>
Array<T>::Array()
{
ptr = new T[10];
size=10;
}


template <class T>
Array<T>::Array( const Array<T> &init )
{
size=init.size ;
ptr = new T[ size ];
for ( int i = 0; i < size; i++ )
ptr[ i ] = init.ptr[ i ]; //debe existir el = para la clase T !
}


template <class T>
Array<T>::~Array()
{
if (ptr)
delete [ ] ptr; 
}

template <class T>
int Array<T>::getSize() const { return size; }

template <class T>
Array<T>& Array<T>::operator=( const Array<T> &rigth )
{
if ( &rigth != this ) 
{ 
if ( size != rigth.size )
{
T *aux; 
aux=new T[ rigth.size ]; 
delete [] ptr; 
size =rigth.size ; 
ptr=aux; 
for ( int i = 0; i < size; i++ )
ptr[ i ] = rigth.ptr[ i ]; 
return *this; 
}
else 
{
for ( int i = 0; i < size; i++ )
ptr[ i ] = rigth.ptr[ i ]; 
return *this; 
}
}
return *this;
}

template <class T>
bool Array<T>::operator==( const Array<T> &rigth ) const
{
if ( size != rigth.size )
return false; 
else
for ( int i = 0; i < size; i++ )
if ( ptr[ i ] != rigth.ptr[ i ] )
       return false; 
 else 
       return true; 
}

template <class T>
T & Array<T>::operator [ ]( int subscript )
{
assert( (0 < subscript)|| (subscript < size) ) ; 
//usando assert para chequear errores durante el desarrollo
return ptr[ subscript ]; 
}

#endif

