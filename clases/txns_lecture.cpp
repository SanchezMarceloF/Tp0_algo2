#include <iostream>
#include <string>
#include <fstream>
#include "txns_lecture.h"
#include "Array.h"

//std::ifstream infile("thefile.txt");

//Constructor sin argumentos
Transaction::Transaction(){ 
	n_tx_out = 1;
	Array <output_t> outputs(n_tx_out);
}

//Destructor
//Transaction::~Transaction(){ 
//	std::cout<<"entro al destructor"<<std::endl;
//	if(outputs)
//		delete []outputs;
//}


//setters
//setea un input dentro del arreglo inputs.
void Transaction::setTx(const input_t& inic, unsigned index){
	if(n_tx_in <= index)
		std::cout<<"índice >= n_tx_in"<<std::endl;
	else
		(this -> inputs)[index] = inic;
}
		

//setea un output dentro del arreglo outputs.
void Transaction::setTx(const output_t& inic, unsigned index){
	if(n_tx_out <= index)
		std::cout<<"índice >= n_tx_in"<<std::endl;
	else
		(this -> outputs)[index] = inic;
}
		
		
//getters 
//se obtiene un input pasando el índice al Array outputs
input_t& Transaction::getIn(unsigned index){
	if(n_tx_in <= index){
		std::cout<<"índice fuera de rango"<<std::endl;
	}
	else	
		return (this -> inputs)[index]; 	
}

//se obtiene un output pasando el índice al Array outputs
output_t& Transaction::getOut(unsigned index){
	if(n_tx_out <= index){
		std::cout<<"índice fuera de rango"<<std::endl;
	}
	else	
		return (this -> outputs)[index]; 	
}
	
						
