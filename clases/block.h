#ifndef BLOCK_INCLUDED
#define BLOCK_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include "txns_lecture.h"
#include "Array.h"
#include "sha256.h"

// Se crea la clase Block para organizar sus campos,  un Array de
// transacciones(class Transaction)
// 
// Se hicieron sólo 2 constructores. 1 sin argumentos y otro
// con 1(una) transacción.
// 
// Luego las transacciones se pueden agregar de a 1(una) por vez, y se
// agrega al Array de transacciones de forma consecutiva, sin posibili
// dad de cambio. Por lo que tiene que estar previamente creada
// 
// Se crea getTxns para probar la clase, se usa luego en setHash.

class Block{
private:
	//HEADER
	std::string prev_block;
	std::string txns_hash;//hash de todas las transacciones incluidas en el bloque
	size_t bits;
	int nonce;
	//BODY
	size_t txn_count;//cantidad total de transacciones
	Array <Transaction> txns;

public:
	Block();
	Block(const Array<Transaction>&);//recibe solo 1 transaction
	~Block();
	//seters
	void setTxns(const Transaction&);
	bool setHash();	
	bool setNonce();
	
	//getters
	std::string getTxns();
	std::string getTxns(unsigned indx);//se pasa el nro de Txns
	std::string getTxnsHash();
	std::string getHeader();
	
	//otros
	bool checkDifficulty(int,const std::string&);
};


// :: Funciones no miembro de la clase ::
//--------------------------------------------------------------------

//
//	for(int i=0; i < difficulty; i++){
//		if(hash[i]!='0')
//			return false;
//	}
//	return true;
//}
#endif //BLOCK
