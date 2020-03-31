#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>


//Librerias nuestras
#include "cmdline.h"
#include "vector.h"
#include "complejo.h"
#include "FourierTransform.h"

using namespace std;

//Prototipos:

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_forward_op(string const &);
static void opt_reverse_op(string const &);
static void opt_block_shift(string const &);
static void opt_taps(string const &);
static void opt_help(string const &);


/**************** Elementos globales **************************/
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "forward-op", "-", opt_forward_op, OPT_DEFAULT},
	{1, "r", "reverse-op", "-", opt_reverse_op, OPT_DEFAULT},
	{1, "b", "block-shift", "-", opt_block_shift, OPT_DEFAULT},
	{1, "t", "taps", "-", opt_taps, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		  // Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		    // Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)


static istream *taps = 0; //Variable para manejar el archivo con los coeficientes de ecualizacion
static fstream taps_fs; //Variable para la apertura del archivo con los coeficientes de ecualizacion
static int block_shift;

FourierTransform_t fourier_transformation_type;
FourierTransform_t fourier_transformation_type_inv;

/************************************************************/


//Implementacion de Prototipos:


/***************************************************************/
/*********Funcionas correspondientes a "command line"***********/
static void
opt_input(string const &arg){
	if (arg == "-")
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada

	else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}

	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg){
	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	}

  else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_help(string const &arg)
{
	cout << "tp1 [-f funcion(dft o fft)] [-r funcion(rdft o rfft)] [-b int] [-t int] [-i file] [-o file]"
	     << endl;
	exit(0);
}


//A continuación se implementan las funciones propias del presente Trabajo

//"opt_forward_op" y "opt_reverse_op" asignan en nuevos tipos enumerativos que operaciones van a realizarse
//para la transformación y la inversa. La razón por la cuál solo se asignan tipos enumerativos en dichas
//funciones es para, a la hora de crear los objetos correspondientes solo se creen los necesarios
static void
opt_forward_op(string const &arg){
	if (arg == "fft") {fourier_transformation_type= FFT_FLAG;}

	else{
		fourier_transformation_type = DFT_FLAG;
	}
}

static void
opt_reverse_op(string const &arg){
	if (arg == "ifft") {fourier_transformation_type_inv= FFT_FLAG;}

	else{
		fourier_transformation_type_inv = DFT_FLAG;
	}

}

static void
opt_block_shift(string const &arg){
  if (arg == "-") {
    block_shift = 1;
  }

  else{
    istringstream iss(arg);

    if(!(iss >> block_shift) || !iss.eof()){
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

  block_shift = pow(2,block_shift);
}




static void
opt_taps(string const &arg){

	if (arg == "-"){}//no se realiza ninguna operacion, mas adelante en el programa, si
									//el puntero "*taps_is" es cero, el vector con los coeficientes se
									//rellena con el valor 1

	else{
		taps_fs.open(arg.c_str(), ios::in);
		taps = &taps_fs;

		if(!taps->good()) {
			cerr << "cannot open "
		     	<< arg
		     	<< "."
		     	<< endl;
			exit(1);
		}
	}
}



/***************************************************************/
/*********Funcionas correspondientes a "main"*******************/

//La siguiente función crea el objeto que se utilizara para la transformacion (o inversa)
void assing_fourier_transformation_type(FourierTransform **pFT,FourierTransform_t  type){

	switch(type){
	   case DFT_FLAG:
			*pFT= new Dft;
			break;
	   case FFT_FLAG:
			*pFT= new Fft;
			break;
	   default:
			cerr << "fourier transformation not specified" << endl;
			exit(1);
	}
}

//La siguiente funcion realiza la transformacion de la señal de entrada hasta su
//paso por la ecualizacion e imprime su resultado
void process_signal(FourierTransform *pFT, FourierTransform *pFT_inv){

	bool is_EOF=false;
	Vector Xin(block_shift), Xout(block_shift);
	Vector Xout_inv(block_shift);
	complejo aux;

	Vector Taps(block_shift);

	//se inicializa el vector con los coeficientes de ecualizacion

	for(size_t i=0;i<(size_t)block_shift;i++){
		if( (taps==0 ) || !(*taps >> aux ) ){

			if(i<(size_t)block_shift)//se rellena el resto del vector con 1
				for (; i < (size_t)block_shift; i++)
					Taps[i] = 1;
		break;
		}

	Taps[i] = aux;
	}

	//se inicia el ciclo de procesamiento de la señal
	while(is_EOF==false){

		for(size_t i=0;i<(size_t)block_shift;i++){
			if( !(*iss >> aux )){
				is_EOF = true;

				if(i<(size_t)block_shift && (i != 0))//se rellena el resto del vector con 0

					for (; i < (size_t)block_shift; i++)
						Xin[i] = 0;

				break;
			}


			Xin[i] = aux;
		}

		if(is_EOF == false){//ver como hacer este corte mejor

			pFT->fourier_transform(Xin, Xout); //Se aplica la transformacion

			for(size_t i = 0; i<(size_t)block_shift;i++) //Se multiplica por los coeficientes
				Xout[i] *= Taps[i];


//			for(size_t i=0;i<(size_t)block_shift;i++) //para visualizar lo que hace la transformada
//				cout << Xout[i] << endl;

			pFT_inv->inverse_fourier_transform(Xout, Xout_inv);	//se aplica la inversa

			cout << "\n";

			for(size_t i=0;i<(size_t)block_shift;i++){
				*oss << Xout_inv[i] << endl;
			}

			cout << "\n";


		}
	}





	if (oss->bad()) {
		cerr << "unsuccessfull write (output file)" << endl;
		exit(1);
	}
	if (iss->bad()) {
		cerr << "unsuccessfull read (input file)" << endl;
		exit(1);
	}
	if (!iss->eof()) {
		cerr << "there isn't EOF on input file" << endl;
		exit(1);
	}

}

int main(int argc, char * const argv[]){
  cmdline cmdl(options);
	cmdl.parse(argc, argv);


	FourierTransform *p_FT = 0, *p_FT_inv = 0;
	assing_fourier_transformation_type(&p_FT,fourier_transformation_type);
	assing_fourier_transformation_type(&p_FT_inv,fourier_transformation_type_inv);



	process_signal(p_FT, p_FT_inv);




  return 0;
}
