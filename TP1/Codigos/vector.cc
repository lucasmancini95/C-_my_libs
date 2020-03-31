#include "vector.h"



Vector::Vector(){
  size = 1;
  array = new complejo[size];
}

Vector::Vector(const Vector &V){
  size = V.size;
  array = new complejo[size];

  for(size_t i = 0; i<size; i++)
    array[i] = V.array[i];
}

Vector::Vector(size_t sz){
  size = sz;
  array = new complejo[size];
}

Vector::~Vector(){
  delete [] array;
}

complejo& Vector::operator [ ]( size_t subscript ){
  if( (0 > subscript)|| (subscript > size) )throw ErrorSubin();
  else{
    return array[ subscript ]; // retorna referencia
  }
}

Vector& Vector::operator=( const Vector &rigth ){

  if ( &rigth != this ){ // chequea para evitar autoasignaciones
                        // para arrays de diferentes tamaños, libera espacio usado y
                        //luego genera zona nueva y la carga

    if ( size != rigth.size ){
      complejo *aux; //auxiliar por si no se obtiene el espacio; en ese caso se eligió dejar el array como estaba
      aux=new complejo[ rigth.size ]; //se pide espacio; si no se obtiene new lanza bad_alloc
      delete [] array; // si llegó acá es que obtuvo el espacio;libera el anterior espacio
      size =rigth.size ; // asigna el tamaño adecuado
      array=aux; //apunta a la nueva zona
      for ( size_t i = 0; i < size; i++ )
        array[ i ] = rigth.array[ i ]; // copia el array en el nuevo objeto
      return *this; // al retornar una referencia permite x = y = z;
    }
    else{ //si tienen el mismo tamaño, sólo hay que reasignar valores
      for ( size_t i = 0; i < size; i++ )array[ i ] = rigth.array[ i ]; // copia el array en el nuevo objeto
    }
  }
  return *this;
}
