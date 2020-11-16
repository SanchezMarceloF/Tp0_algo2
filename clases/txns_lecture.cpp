#include <iostream>
#include <string>
#include <fstream>
#include "txns_lecture.h"
#include "Array.h"

//std::ifstream infile("thefile.txt");

//Constructor sin argumentos
Transaction::Transaction(){ 
	n_tx_in = 0;
	Array <input_t> aux_inputs(n_tx_in);
	inputs = aux_inputs;
	n_tx_out = 0;
	Array <output_t> aux_outputs(n_tx_out);
	outputs = aux_outputs;
}
//Contructor con número de inputs
Transaction::Transaction(const size_t num1){ 
	n_tx_in = num1;
	Array <input_t> inputs(n_tx_in);
}
//Constructor con número de inputs y outputs
Transaction::Transaction(const size_t num1, const size_t num2){ 
	n_tx_in = num1;
	Array <input_t> inputs(n_tx_in);
	n_tx_out = num2;
	Array <output_t> outputs(n_tx_out);
}
//Destructor
//no estoy seguro de que esté bien, deberían llamarse los de la clase
//Array automáticamente. Aquí no creamos nada con new.
Transaction::~Transaction(){ 
	std::cout<<"--DESTRUCTOR TRANSACTION--"<<std::endl;
	//if(inputs)
	//	delete []inputs;
	//if(outputs)
	//	delete []outputs;
}


//setters
//setea un nuevo input, agregando el elemento
//al Array (se redimensiona)
void Transaction::setTx(const input_t& inic){
	n_tx_in = inputs.setArray(inic).getSize();
}

//setea un nuevo output, agregando el elemento
//al Array (se redimensiona)
void Transaction::setTx(const output_t& inic){
	n_tx_out = outputs.setArray(inic).getSize();
}


//setea un input dentro del arreglo inputs.
void Transaction::setTx(const input_t& inic, unsigned index){
	(this -> inputs)[index] = inic;
}
		

//setea un output dentro del arreglo outputs.
void Transaction::setTx(const output_t& inic, unsigned index){
	(this -> outputs)[index] = inic;
}
		
		
//getters 
size_t Transaction::getNtxin(){
	return n_tx_in;
}

size_t Transaction::getNtxout(){
	return n_tx_out;
}

//se obtiene un input pasando el índice al Array outputs
input_t& Transaction::getIn(unsigned index){
	return (this -> inputs)[index]; 	
}

//se obtiene un output pasando el índice al Array outputs
output_t& Transaction::getOut(unsigned index){
	return (this -> outputs)[index]; 	
}
	
std::string Transaction::getAll(){
	//verifico que haya inputs
	std::string txns_aux;
	if(n_tx_in > 0){
		std::string idx_aux;
		for(unsigned i=0; i<n_tx_in; i++){
			txns_aux = txns_aux + inputs[i].tx_id + ' ';
			idx_aux = std::to_string(inputs[i].idx);
			txns_aux = txns_aux + idx_aux + ' '; 
			txns_aux = txns_aux + inputs[i].addr + '\n'; 
		}
	}
	//verifico que haya outputs
	if(n_tx_out > 0){
		std::string value_aux;
		for(unsigned i=0; i<n_tx_in; i++){
			value_aux = std::to_string(outputs[i].value);
			txns_aux = txns_aux + value_aux + ' ';
			txns_aux = txns_aux + outputs[i].addr + '\n'; 
		}
	}
	return txns_aux;
}

