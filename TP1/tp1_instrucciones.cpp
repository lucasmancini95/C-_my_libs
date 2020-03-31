




int main(){

//comand line 

foureir_transformation FT_input ( ft_in ); //ft_out y ft_in  son tipos enumerativos transformation_fourier_t
foureir_transformation FT_output ( ft_out );

vector<complex> input_comple_vector (bolck_size);
vector<complex> output_comple_vector (bolck_size);

process
ecua djbn
process



}


Entra a main

Toma los command line y guarda las variables

Crea los los vectores estaticos output e input vacios

definimos dos objetos "transformada de fourier" que seran uno de input y otro de output

Process():
Entramos en la funcion process... dentrro de la misma en un bucle mientras no se termine el archivo de entrada, guardamos cada dato que recibimos en el vector input correspondiente. y al llenarlo lo mando a el objeto "transformada de fourier" de input.
En un archivo (o estructura) intermedio o auxiliar imprimimos lo obtenido por la transformada, esto debe hgacerse para poder manipular los datos mas tarde en el programa. 
Salimos process.

//CREO QUE TAP Y TODO ESO SE HACE EN ESTA PARTE

Luego aplicamos process_inv(), la inversa de process
Durante este proceso se imprime en el archivo de salida lo obtenido en cada vector.

Terminacion
