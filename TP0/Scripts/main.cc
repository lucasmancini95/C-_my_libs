#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include <cmdline.h>
#include "complejo.h"
using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_samples_length(string const &);
static void opt_log_file(string const &);
static void opt_help(string const &);
void RF_process(istream *, ostream *);

// Tabla de opciones de línea de comando. El formato de la tabla
// consta de un elemento por cada opción a definir. A su vez, en
// cada entrada de la tabla tendremos:
//
// o La primera columna indica si la opción lleva (1) o no (0) un
//   argumento adicional.
//
// o La segunda columna representa el nombre corto de la opción.
//
// o Similarmente, la tercera columna determina el nombre largo.
//
// o La cuarta columna contiene el valor por defecto a asignarle
//   a esta opción en caso que no esté explícitamente presente
//   en la línea de comandos del programa. Si la opción no tiene
//   argumento (primera columna nula), todo esto no tiene efecto.
//
// o La quinta columna apunta al método de parseo de la opción,
//   cuyo prototipo debe ser siempre void (*m)(string const &arg);
//
// o La última columna sirve para especificar el comportamiento a
//   adoptar en el momento de procesar esta opción: cuando la
//   opción es obligatoria, deberá activarse OPT_MANDATORY.
//
// Además, la última entrada de la tabla debe contener todos sus
// elementos nulos, para indicar el final de la misma.
//

/**************** Elementos globales ******************/
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "N", "samples_length", "-", opt_samples_length, OPT_DEFAULT},
	{1, "log", "log_file", "-", opt_log_file, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static int samples_length;
static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static ostream *log = 0;
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)
static fstream logfs;



/*****************************************************/

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

static void
opt_samples_length(string const &arg)
{
	istringstream iss(arg);

	// Intentamos extraer el factor de la línea de comandos.
	// Para detectar argumentos que únicamente consistan de
	// números enteros, vamos a verificar que EOF llegue justo
	// después de la lectura exitosa del escalar.
	//
	if (!(iss >> samples_length)
	    || !iss.eof()) {
		cerr << "non-integer: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read integer factor."
		     << endl;
		exit(1);
	}
}

static void
opt_help(string const &arg)
{
	cout << "tp0 [-N nsamples] [-i file] [-o file] [-log file]"
	     << endl;
	exit(0);
}

static void
opt_log_file(string const &arg){

	if (arg == "-"){
		logfs.open("log.txt", ios::out);
		log = &ofs;

	} else {
		logfs.open(arg.c_str(), ios::out);
		log = &ofs;
	}

	if (!log->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}
		
		


void
RF_process(istream *is, ostream *os)
{
	complejo num, aux;
	bool is_EOF=false;

	while(is_EOF==false){
		num=0;


		int i;
		for(i=0; i<samples_length;i++){

			if( !(*is >> aux )){
				is_EOF = true;
				break;
			}

			num = num + aux;
		}

		num = num / i;

		*os << num.abs() << "\n";   

	}


	if (os->bad()) {
		cerr << "cannot write to output stream."
		     << endl;
		exit(1);
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
		     << endl;
		exit(1);
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
		     << endl;
		exit(1);
	}
}

//Carga los complejos en un vector
//Calcula el promedio de los complejos dentro del vector (los despliega por pantalla)
//Elige un miembro del vector al azar y lo despliega en archivo de salida

void
RF_process2(istream *is, ostream *os) 
{
	complejo aux, *vector_complejos, prom;
	vector_complejos = new complejo[samples_length];
	
	bool is_EOF=false;

	while(is_EOF==false){
		int i;
		prom = 0;
		for(i=0; i<samples_length;i++){

			if( !(*is >> aux )){
				is_EOF = true;
				break;
			}

			vector_complejos[i] = aux;

			prom = prom + aux;
		}

		cout << prom/i << "\n";

		if(i != samples_length){ //Veo si llego a llenar todo el vector

			for(;i<samples_length;i++){
				vector_complejos[i] =  0;
			}
		}

//		for(i=0;i<factor;i++)
//			cout << vector_complejos[i] << "\n"; //Comprobamos que la subida anduvo bien, sigue procesar los datos

		i = rand() % samples_length; // elige un valor al azar para seleccionar del vector. Falta contemplar el caso en que el vector se llena con 0 para que no se elija el 0

	*os << vector_complejos[i].abs() << "\n";

	}


	if (os->bad()) {
		cerr << "cannot write to output stream."
		     << endl;
		exit(1);
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
		     << endl;
		exit(1);
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
		     << endl;
		exit(1);
	}
}

complejo complex_vector_avarage(complejo **complex_vector, int length){

	complejo prom = 0;

	for(int i=0;i<length; i++){

		prom = prom + (*complex_vector)[i];
	}


	return prom/length;
}
		

void
RF_process3(istream *is, ostream *os) 
{

	complejo aux, *vector_complejos, prom;
	int i;

	vector_complejos = new complejo[samples_length];

	bool is_EOF=false;
	prom = 0;

	for(i=0; i<samples_length;i++){	//Se llena el vector con los primeros "samples_length" numeros

		if( !(*is >> aux )){
			is_EOF = true;
			break;
		}
		vector_complejos[i] = aux;

		prom = prom + aux;
	}

	i=0;

	while(is_EOF==false){

		if(i == samples_length){
			i=0;
		} 

		if( !(*is >> aux )){
			is_EOF = true;
			break;
		}

		vector_complejos[i] = aux;

		
		*os << complex_vector_avarage(&vector_complejos, samples_length) << "\n";

		i++
		

	}



	if (os->bad()) {
		cerr << "cannot write to output stream."
		     << endl;
		exit(1);
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
		     << endl;
		exit(1);
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
		     << endl;
		exit(1);
	}
}

int
main(int argc, char * const argv[])
{
	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
	RF_process2(iss, oss);	    // Función externa, no es un metodo de ninguna clase o estructura usada en el código
}
