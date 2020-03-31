#include "FourierTransform.h"

void Dft::fourier_transform(Vector &in_vector, Vector &out_vector){

  size_t s = in_vector.RetSize();

  for(size_t k = 0; k<s;k++){
      double real_sum = 0;
      double imag_sum = 0;

    for(size_t n = 0; n<s;n++){
      double fase = n * k * 2 * PI / s;
      real_sum +=  in_vector[n].re() * cos(fase) + in_vector[n].im() * sin(fase);
      imag_sum += -in_vector[n].re() * sin(fase) + in_vector[n].im() * cos(fase);
    }
    out_vector[k] = complejo(real_sum, imag_sum);
  }
}

void Dft::inverse_fourier_transform(Vector &in_vector, Vector &out_vector){

  size_t s = in_vector.RetSize();

  for(size_t n = 0; n<s;n++){
      double real_sum = 0;
      double imag_sum = 0;

    for(size_t k = 0; k<s;k++){
      double fase = n * k * 2 * PI / s;
      real_sum += in_vector[k].re() * cos(fase) - in_vector[k].im() * sin(fase);
      imag_sum += in_vector[k].re() * sin(fase) + in_vector[k].im() * cos(fase);


    }
    out_vector[n] = (complejo(real_sum, imag_sum))/s;

  }
}

Vector fft(Vector &X){

  complejo aux;
  size_t N;

  Vector Xout(N=X.RetSize());


  if( N >= 2){
    Vector P(N/2+ N%1), P_TF(N/2);
    for(size_t i=0, j=0; j<P.RetSize(); j++, i= i+2)
      P[j] = X[i];

    Vector Q(N/2), Q_TF(N/2);
    for(size_t i=1, j=0; j<Q.RetSize(); j++, i= i+2)
      Q[j] = X[i];
    P_TF = fft(P);
    Q_TF = fft(Q);


    for(size_t k = 0; k<N/2;k++){
      complejo angle = complejo(cos(2*PI*k/N),-sin(2*PI*k/N)) *  Q_TF[k];
      Xout[k] = P_TF[k] + angle;
      Xout[k+ N/2] = P_TF[k] - angle;
    }

  }
  else{
      Xout = X;
  }
  return Xout;

}

void Fft::fourier_transform(Vector &in_vector, Vector &out_vector){
  out_vector = fft(in_vector);
}

void Fft::inverse_fourier_transform(Vector &in_vector, Vector &out_vector){

  for(size_t i = 0, N = out_vector.RetSize(); i < N; i++)
    in_vector[i].conjugar();

  out_vector = fft(in_vector);

  for(size_t i = 0, N = out_vector.RetSize(); i < N; i++)
    out_vector[i] = out_vector[i] / N;
}
