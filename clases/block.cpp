class Block{
private:
	//HEADER
	string prev_block="ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff\n";
	string txns_hash;//hash de todas las transacciones incluidas en el bloque
	size_t bits;
	size_t nonce;
	//BODY
	size_t txn_count;//cantidad total de transacciones
	Array <Transaction> txns;

public:
	Block();
	Block(size_t);//recibe solo txn_count
	Block(size_t, size_t);// recibe txn_count y bits 
	bool setNonce()
	
	//getters
	//std::string& getTxs();
	//std::string& getTx(int);
	calcTxHash();	
}

void setNonce(Block& aux){
	aux //calcular nonce con dificultad d verificando doble hash del header.
}


bool checkDifficulty(unsigned int difficulty, string hash){

	for(size_t i=0; i < difficulty; i++){
		if(hash[i]!='0')
			return false;
	}
	return true;
}

