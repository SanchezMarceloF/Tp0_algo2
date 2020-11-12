#ifndef TXNS_LECTURE_INCLUDED
#define TXNS_LECTURE_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include "Array.h"

//std::ifstream infile("thefile.txt");

typedef struct{
	std::string tx_id;// el hash de la transaccion de donde este input toma fondos, 64 bytes fijos.
	size_t idx;//idx sirve de indice sobre la secuencia de outputs de la transaccion con hash tx_id
	std::string addr;//direccion de origen de los fondos, 64 bytes fijos(es un hash)
} input_t;

typedef struct{
	float value = 0;
	std::string addr; //dirección destino de los fondos, 64 bytes fijos (es un hash)
} output_t;

//
class Transaction{
private:
	//INPUTS 
	size_t n_tx_in;
	Array <input_t> inputs;
	//OUTPUTS
	size_t n_tx_out;
	Array <output_t> outputs;

public:
	//Constructores
	Transaction();	//sin argumentos
	//Transaction(int); 	//con nro txns in
	//Transaction(int, int); //con nro txns in & out
	//Destructor
	//~Transaction();

	//setters
	void setTx(const input_t&, unsigned);
	void setTx(const output_t&, unsigned);
	
	//getters				
	input_t& getIn(unsigned); //devuelve el input con indice como argumento  
	output_t& getOut(unsigned); //devuelve el output con indice como argumento  
	
};

#endif //TXNS_LECTURE_INCLUDED
