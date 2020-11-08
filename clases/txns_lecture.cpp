#include <fstream>

std::ifstream infile("thefile.txt");

typedef struct{
	string tx_id;// el hash de la transaccion de donde este input toma fondos
	size_t idx;//idx sirve de indice sobre la secuencia de outputs de la transaccion con hash tx_id
} outpoint_t;

typedef struct{
	outpoint_t outpoint;
	string addr;//direccion de origen de los fondos
} input_t;

typedef struct{
	float value;
	string addr;
} output_t;

//TRANSACCIONES
class Transaction{
private:
	//INPUTS 
	size_t n_tx_in;
	Array <input_t> inputs;
	//OUTPUTS
	size_t n_tx_out;
	Array <output_t> outputs;

public:
	Transaction();
	
}


inputsLecture(){

};

outputsLecture(){
		
};

