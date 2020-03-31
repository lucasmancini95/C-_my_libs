#include <iostream>
#include "Array.h"
#include "ErrorSubin.h"

using namespace std;


// Constructor por defecto sin argumentos
Array::Array()
{
ptr = new int[10];
size=10;
std::cout<<"Array()"<<endl;
}

Array::Array(int x)
{
if ((x<1)||(x>500)) size=10; else size=x;
ptr = new int[size];
std::cout<<"Array(int)"<<endl;
}

// Constructor copia recibe una referencia
Array::Array( const Array &init )
{
size=init.size ;
ptr = new int[ size ];
for ( int i = 0; i < size; i++ )
ptr[ i ] = init.ptr[ i ]; 
std::cout<<"Array(const Array &)"<<endl;
}
// Destructor
Array::~Array()
{
if (ptr)
delete [ ] ptr;
std::cout<<"~Array()"<<endl; // libera el espacio del array
}
// Retorna el tamaño del objeto
int Array::getSize() const { return size; }

// Sobrecarga del operador asignacion
Array& Array::operator=( const Array &rigth )
{
if ( &rigth != this ) // chequea para evitar autoasignaciones
{ // para arrays de diferentes tamaños, libera espacio usado y
//luego genera zona nueva y la carga

if ( size != rigth.size )
{
int *aux; //auxiliar por si no se obtiene el espacio; en ese caso se eligió dejar el array como estaba
aux=new int[ rigth.size ]; //se pide espacio; si no se obtiene new lanza bad_alloc
delete [] ptr; // si llegó acá es que obtuvo el espacio;libera el anterior espacio
size =rigth.size ; // asigna el tamaño adecuado
ptr=aux; //apunta a la nueva zona
for ( int i = 0; i < size; i++ )
ptr[ i ] = rigth.ptr[ i ]; // copia el array en el nuevo objeto
return *this; // al retornar una referencia permite x = y = z;
}
else //si tienen el mismo tamaño, sólo hay que reasignar valores
{
for ( int i = 0; i < size; i++ )ptr[ i ] = rigth.ptr[ i ]; // copia el array en el nuevo objeto

}
}
return *this;
}
// Determina si dos arrays son iguales, retornando true o false
bool Array::operator==( const Array &rigth ) const
{
if ( size != rigth.size )
return false; // arrays de diferentes tamaños
else
for ( int i = 0; i < size; i++ )
if ( ptr[ i ] != rigth.ptr[ i ] )
return false; // los arrays no son iguales
return true; // los arrays son iguales
}
// Sobrecarga del operador indexacion; la referencia retornada es un lvalue
int& Array::operator [ ]( int subscript )
{
if( (0 > subscript)|| (subscript > size) ) throw ErrorSubin();
else
{
return ptr[ subscript ]; // retorna referencia
}}

void Array::emitir()
{
int i ;
for(i=0;i<size;i++)
    cout<<ptr[ i ];
    cout<<endl;
}

