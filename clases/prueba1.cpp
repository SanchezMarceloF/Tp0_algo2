//se prueba el constructor por defecto de la clase Transaction
// y el Template Array con sus contructores
//solo con 1 output para simplificar

#include <iostream>
#include <string>
#include "txns_lecture.h"
#include "Array.h"

using namespace std;

int main() {
	cout<<":: Bienvenido a prueba1.cpp ::\n"<< endl;
	Transaction txns_a,txns_b;
	
	input_t in_j, in_k;
	output_t out_m, out_n;
	
	in_j.tx_id = "SOY TX ID ENTRADA";
	in_j.idx = 4;
	in_j.addr = "SOY ADDR ENTRADA";

	out_m.value = 324.56;
	out_m.addr = "SOY ADDR SALIDA";
	
	cout<<"Prueba métodos input"<<endl<<endl;
	
	//pruebo setter setTx con argumento input_t e índice
	txns_a.setTx(in_j,0);
	txns_a.setTx(in_j,1);
	
	//pruebo getter getIn con argumento input_t e índice
	in_k = txns_a.getIn(0);
	cout<<"valores in_k.tx_id = "<<in_k.tx_id<<" ini_k.idx = "<<in_k.idx<<"in_k.addr = "<<in_k.addr<<endl<<endl;

	cout<<"Prueba métodos output"<<endl<<endl;
	
	//pruebo setter setTx con argumento output_t e índice
	txns_a.setTx(out_m,0);
	txns_a.setTx(out_m,1);
	
	//pruebo getter getOut con argumento output_t e índice
	out_n = txns_a.getOut(0);
	cout<<"valores out_n.value = "<<out_n.value<<" out_n.addr = "<<out_n.addr<<endl;
	
return 0;
}


