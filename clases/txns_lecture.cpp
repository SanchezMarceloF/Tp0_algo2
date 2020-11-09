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
	Array <output_t> aux(n_tx_out);
	Array <output_t> outputs(aux);
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


	//seter
	Transaction::setOut(int n, Array<output_t>& aux){
		
		

	
	//getters				
	output_t& getOut(size_t); //devuelve el output con indice como argumento  
	
						
