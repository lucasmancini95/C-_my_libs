#ifndef RANDOM_CLASS
#define RANDOM_CLASS

/* ES ta clase fue obtenida del Apendice B del libro Data Structures and Program Design in C++] de Robert L Kruse */ 

#include <iostream>
#include <stdlib.h>
#include <random>
#include <fstream>

class Random{
  private:
    int seed, multiplier, add_on; // constants for use in arithmetic operations

    int reseed(){
      seed = seed * multiplier + add_on;
      return seed;
    }


  public:
    Random(bool pseudo = true){
      if (pseudo) seed = 1;
      else seed = time(NULL) % max_int;
      multiplier = 2743;
      add_on = 5923;
    }

    int Random :: poisson(double mean){     /* Post: A random integer, reflecting a Poisson distribution with parameter mean, is returned. */

      double limit = exp(−mean);
      double product = random_real( );
      int count = 0;
      while (product > limit) {
        count++;
        product *= random_real( );
      }
      return count;
    }

    int Random ::random_integer(int low, int high){ /* Post: A random integer between low and high (inclusive) is returned. */

      if (low > high) return random_integer(high, low);
      else return ((int) ((high − low + 1) * random_real( ))) + low;
    }

    double Random ::random_real( ){/* Post: A random real number between 0 and 1 is returned. */

      double max = max_int + 1.0;
      double temp = reseed( );
      if (temp < 0) temp = temp + max;
      return temp/max;
    }

};
