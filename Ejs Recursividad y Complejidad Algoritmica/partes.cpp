
//Implementación en C++ del algoritmo recursivo estudiado en clase para computar el conjunto de partes de un conjunto dado

#include <iostream>
#include "conjunto.h"
using namespace std;

#define conj_conj_T  conjunto< conjunto<T> >

template<class T>
void agregar_a_todos(conj_conj_T &conj, const T& elem)
{
	typename conj_conj_T::iterador it(conj);
	for(; !it.extremo(); it.avanzar())
		it.dato().agregar(elem);
}

template<class T>
conj_conj_T partes(const conjunto<T> &S)
{
	conj_conj_T resultado;

	if (S.vacio())
		// Caso base: P({}) = {{}}
		resultado.agregar(conjunto<T>());
	else
	{
		// En este caso, S = {s_1,...,s_n}, n > 0
		// Luego,
		// P({s_1,...,s_n}) = P({s_2,...,s_n}) U { X U {s_1} / X C P({s_2,...,s_n}) }
		// Mapeamos esto al código de la siguiente manera:
		//    * S.elem() -->  s_1
		//    * S - elem --> {s_2,...,s_n}
		//    * partes_sin_elem --> P({s_2,...,s_n})
		//    * agregar_a_todos(partes_sin_elem, elem) -->
		//      { X U {s_1} / X C P({s_2,...,s_n}) }
		T elem = S.elem();
		conj_conj_T partes_sin_elem = partes(S - elem);
		resultado = partes_sin_elem;
		agregar_a_todos(partes_sin_elem, elem);
		// En este punto, partes_sin_elem es un conjunto de conjuntos cuyos conjuntos
		// contienen todos a elem (s_1). El nombre de la variable ya no refleja lo
		// que realmente representa.
		resultado.unir(partes_sin_elem);
	}

	return resultado;
}

int main(int argc, char **argv)
{
	conjunto<int> S;

	cout << "P({}) = " << partes(S) << endl;

	S.agregar(1);

	cout << "P({1}) = " << partes(S) << endl;

	S.agregar(5);
	S.agregar(2);
	S.agregar(7);

	cout << "P({1,5,2,7}) = " << partes(S) << endl;  

	return 0;
}
