// utiliza la Clase cmdline parar parsear los argumentos pasados por 
// linea de comnados. El bloque genera un puntero a un stream para 
// procesar los datos del programa desde el main.
//Se verifica que la dificultad pasada por argumento sea menor a 6.
//
// $Id: main.cc,v 1.5 2012/09/15 12:23:57 lesanti Exp $

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "cmdline.h"
#include "sha256.h"
#include "txns_lecture.h"
#include "block.h"

using namespace std;


static void opt_input(string const &);
static void opt_output(string const &);
static void opt_difficulty(string const &);
static void opt_help(string const &);

// Tabla de opciones de l�nea de comando. El formato de la tabla
// consta de un elemento por cada opci�n a definir. A su vez, en
// cada entrada de la tabla tendremos:
//
// o La primera columna indica si la opci�n lleva (1) o no (0) un
//   argumento adicional.
//
// o La segunda columna representa el nombre corto de la opci�n.
//
// o Similarmente, la tercera columna determina el nombre largo.
//
// o La cuarta columna contiene el valor por defecto a asignarle
//   a esta opci�n en caso que no est� expl�citamente presente
//   en la l�nea de comandos del programa. Si la opci�n no tiene
//   argumento (primera columna nula), todo esto no tiene efecto.
//
// o La quinta columna apunta al m�todo de parseo de la opci�n,
//   cuyo prototipo debe ser siempre void (*m)(string const &arg);
//
// o La �ltima columna sirve para especificar el comportamiento a
//   adoptar en el momento de procesar esta opci�n: cuando la
//   opci�n es obligatoria, deber� activarse OPT_MANDATORY.
//
// Adem�s, la �ltima entrada de la tabla debe contener todos sus
// elementos nulos, para indicar el final de la misma.
//
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	//{1, "f", "factor", NULL, opt_factor, OPT_MANDATORY},
	{1, "d", "difficulty", NULL, opt_difficulty, OPT_MANDATORY},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};
//static int factor;
static int difficulty;
static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;
static string input;
static string output;

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;
	} else {
		ifs.open(arg.c_str(), ios::in);
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
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;
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
		exit(1);
	}
}


static void
opt_difficulty(string const &arg)
{
	istringstream iss(arg);
	
	// Intentamos extraer la dificultad de la l�nea de comandos.
	// Para detectar argumentos que �nicamente consistan de 
	// n�meros enteros, vamos a verificar que EOF llegue justo
	// despu�s de la lectura exitosa del escalar.
	//
	if (!(iss >> difficulty)
	    || !iss.eof()) {
		cerr << "non-integer difficulty: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read integer difficulty."
		     << endl;
		exit(1);
	}
}

static void
opt_help(string const &arg)
{
	//cout << "cmdline -f factor [-i file] [-o file]"
	cout << "cmdline -d difficulty [-i file] [-o file]"
	     << endl;
	exit(0);
}

bool
CheckNum(const string& val){
	bool cheq = false;
	for( unsigned i = 0; i < val.size(); i++){
		if(val[i] < '0' || val[i] > '9')
			return false;
	}
	return true;
}

void
leer(istream *is, ostream *os)
{
	char check_aux;
	unsigned n_in, n_out;
	bool tx_load = true;
	bool good = true;
	bool bad = false;
	Block block_a;
	Transaction txns_a;
	input_t in_j;
	output_t out_m;
	

	
	do{
		if(!(*is>>n_in)){
			tx_load = false;
			if(!(is->eof())){
				bad = true;
				good = false;
			}
		}	
		else{
			for(unsigned i=0; i<n_in ; i++){
				*is >> in_j.tx_id; 		
				*is >> in_j.idx;
				*is >> in_j.addr;
				txns_a.setTx(in_j);
			}
			//chequeo si hay un '\n'
			//if(is->eof() || (*is >> check_aux && check_aux == '\n'))
			//	tx_load = false;
			//if(tx_load)
			//	is->putback(check_aux);
			//chequeo siga un unsigned para los outputs
			if(!(*is >> n_out)){
				tx_load = false;
				if(!(is->eof())){
					bad = true;
					good = false;
				}
			}
			else{
				for(unsigned i=0; i<n_out ; i++){
					*is >> out_m.value;
					*is >> out_m.addr;
					txns_a.setTx(out_m);
				}
			}		
		}
		if(good && !(is->eof()))
		//se carga la transacción en el bloque
			block_a.setTxns(txns_a);
			
	}while(tx_load && !(is->eof()));
	
	//si el archivo se leyó bien		
	if(good){
		//calculo hash y nonce en el bloque	
		block_a.setHash();
		block_a.setNonce();
		//lo envío a la salida
		*os <<  block_a.getHeader();
		*os <<  block_a.getTxns();
	}
	
	//si no pude leer la entrada
	//seteo el flag bad de *ios
	if(bad)
		is->clear(ios::badbit);

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
	cmdline cmdl(options); //cmdline es una clase definida en cmdline.h
	cmdl.parse(argc, argv);
	
	leer(iss, oss);
	

}

//static void
//opt_factor(string const &arg)
//{
//	istringstream iss(arg);
//	
//	// Intentamos extraer el factor de la l�nea de comandos.
//	// Para detectar argumentos que �nicamente consistan de 
//	// n�meros enteros, vamos a verificar que EOF llegue justo
//	// despu�s de la lectura exitosa del escalar.
//	//
//	if (!(iss >> factor)
//	    || !iss.eof()) {
//		cerr << "non-integer factor: "
//		     << arg
//		     << "."
//		     << endl;
//		exit(1);
//	}
//
//	if (iss.bad()) {
//		cerr << "cannot read integer factor."
//		     << endl;
//		exit(1);
//	}
//}

