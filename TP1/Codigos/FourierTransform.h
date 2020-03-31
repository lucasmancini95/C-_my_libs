#ifndef _FOURIER_TRANSFORM_
#define _FOURIER_TRANSFORM_

#include "complejo.h"
#include "vector.h"
#include <cmath>

#define PI 3.14159265359

typedef enum{DFT_FLAG, FFT_FLAG} FourierTransform_t;

class FourierTransform{

  public:
    virtual void fourier_transform(Vector  &in_vector, Vector  &out_vector){};
    virtual void inverse_fourier_transform(Vector  &in_vector, Vector  &out_vector){};
    virtual ~FourierTransform(){};

};

//Clase derivada de "FourierTransform":*****************************************
class Dft : public FourierTransform{ //se crea la clase Dft defivada de la transformada de fourier

  public:
    void fourier_transform(Vector &in_vector, Vector &out_vector);        //convierte a "fourier_transform" en funcion no virtual
    void inverse_fourier_transform(Vector &in_vector, Vector &out_vector);
    ~Dft(){};
};

//Clase derivada de "FourierTransform":*****************************************
class Fft : public FourierTransform{

  public:
    void fourier_transform(Vector &in_vector, Vector &out_vector);
    void inverse_fourier_transform(Vector &in_vector, Vector &out_vector);
    ~Fft(){};
};
#endif
