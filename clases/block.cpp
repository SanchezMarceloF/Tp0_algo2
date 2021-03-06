#include <iostream>
#include <string>
#include <fstream>
#include "block.h"
#include "txns_lecture.h"
#include "Array.h"
#include "sha256.h"


//constructor sin argumentos
Block::Block(){
	//HEADER
	std::string prev_aux(64,'f');
	prev_block = prev_aux;
	txns_hash = "cd372fb85148700fa88095e3492d3f9f5beb43e555e5ff26d95f5a6adc36f8e6";//doble hash con transacciones vacías
	//BODY
	bits = 3;
	nonce = 0;
	txn_count = 0;
	Array <Transaction> txns_aux(txn_count);	
	txns = txns_aux;
}
	 	
//recibe solo una transacción
Block::Block(const Array<Transaction>& inic){
	//HEADER
	std::string prev_aux(64,'f');
	prev_block = prev_aux;
	std::string aux;
	txns_hash = aux;//hash vacío
	//BODY
	bits = 3;
	nonce = 0;
	txn_count = 1;
	txns = inic;	
}
Block::~Block(){
//el compilador va a llamar automaticamente a los destructores de
//la clase Array
//https://isocpp.org/wiki/faq/dtors#calling-member-dtors
}
	

//setters
void Block::setTxns(const Transaction& elem){
	txn_count = txns.setArray(elem).getSize();
}

bool Block::setHash(){
	if(txn_count > 0){
		txns_hash = sha256(sha256(getTxns()));	
		return true;
	}
	else
		return false;
}

bool Block::setNonce(){	
	
	this->nonce = 0;
	bool cheq = false;
	std::string hash_aux;

	do{
	nonce++;
	hash_aux = sha256(sha256(getHeader()));
	cheq = checkDifficulty(bits, hash_aux);
	}	
	while(!cheq);
	
	return cheq; 
}

//getters

std::string Block::getTxns(){
	//verifico que haya transacciones
	std::string txns_aux;
	if(txn_count > 0){
		for(unsigned i=0; i<txn_count; i++){
			txns_aux = txns_aux + (this->txns)[i].getAll();	
		}
		return txns_aux;
	}
	else 
		return txns_aux;
}

std::string Block::getTxns(unsigned indx){//se pasa el nro de Txns
	if(indx < txn_count)
		return (this->txns[indx]).getAll();
	return "nada";
}

std::string Block::getTxnsHash(){
	return txns_hash;
}

std::string Block::getHeader(){
	std::string head_aux;

	head_aux = prev_block + '\n';
	head_aux += txns_hash + '\n';
	head_aux += std::to_string(bits) + '\n';
	head_aux += std::to_string(nonce) + '\n';

	return head_aux;
}


bool Block::checkDifficulty(int dificultad,const std::string& hash){

	for(int i=0; i < dificultad; i++){
		if(hash[i] !='0')
			return false;
	}
	return true;
}

