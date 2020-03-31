#ifndef Array_h
#define Array_h

class Array
{
public:
Array(); // constructor
Array( const Array & ); // constructor copia
Array(int); //constructor con argumentos
~Array( ); // destructor
int getSize( ) const; // retorna tamaño
Array &operator=( const Array & ); // operador asignacion
bool operator==( const Array & ) const; // operador comparacion
int &operator[ ]( int ); // operator indexacion
void emitir();
private:
int size; // size del array
int *ptr; // puntero al primer elemento del array
};

#endif
