#include <iostream>
#include <string>
#include <fstream>
#include "txns_lecture.h"
#include "Array.h"

//std::ifstream infile("thefile.txt");

//Constructor sin argumentos
Transaction::Transaction(){ 
	std::cout<<"entro al constructor sin argumentos"<<std::endl;
	n_tx_out = 1;
	Array <output_t> outputs(n_tx_out);
}

//Constructor con nro txns in
//Arreglo::Arreglo(int tam){
//	std::cout<<"entro al constructor con tamanio"<<std::endl;
//	tamanio = tam;
//	ptr = new double[tamanio];
//}
//
////Constructor copia
//Arreglo::Arreglo(const Arreglo& inic){
//	std::cout<<"entro al constructor copia"<<std::endl;
//	tamanio = inic.tamanio;
//	ptr = new double[tamanio];
//	for (int i = 0; i<tamanio; i++){
//		ptr[i] = inic.ptr[i];
//	}
//}

//Destructor
//Transaction::~Transaction(){ 
//	std::cout<<"entro al destructor"<<std::endl;
//	if(outputs)
//		delete []outputs;
//}


//setters
//void Transaction::setTx(const & Array <input_t>, int){

//setea un output dentro del arreglo outputs.
void Transaction::setTx(const output_t& inic, unsigned index){
	if(n_tx_out <= index)
		std::cout<<"índice fuera de rango"<<std::endl;
	else
		(this -> outputs)[index] = inic;
}
		
		
//getters
//se obtiene un output con índice index  del Array outputs
output_t& Transaction::getOut(unsigned index){
	if(n_tx_out <= index){
		std::cout<<"índice fuera de rango"<<std::endl;
	}
	else	
		return (this -> outputs)[index]; 	
}
	
						
