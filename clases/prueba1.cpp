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
	size_t tam1 = txns_a.getNtxin();
	size_t tam2 = txns_a.getNtxout();
		
	cout<<tam1<<'\t'<<tam2<<"\n\n";
	
	input_t in_j, in_k;
	output_t out_m, out_n;
	// input y output de lal enunciado
	in_j.tx_id = "26429a356b1d25b7d57c0f9a6d5fed8a290cb42374185887dcd2874548df0779";
	in_j.idx = 2;
	in_j.addr = "f680e0021dcaf15d161604378236937225eeecae85cc6cda09ea85fad4cc51bb";
	out_m.value = 250.5;
	out_m.addr = "0618013fa64ac6807bdea212bbdd08ffc628dd440fa725b92a8b534a842f33e9";
	
	txns_a.setTx(in_j);
	txns_a.setTx(out_m);

	string aux = txns_a.getAll();
	tam1 = txns_a.getNtxin();
	tam2 = txns_a.getNtxout();
		
	cout<<tam1<<'\t'<<tam2<<"\n\n";
	cout<<aux;


// :: Pruebas para constructores, setters y getters ::
//--------------------------------------------------------------------------
//	in_j.tx_id = "SOY TX ID ENTRADA";
//	in_j.idx = 4;
//	in_j.addr = "SOY ADDR ENTRADA";
//
//	out_m.value = 324.56;
//	out_m.addr = "SOY ADDR SALIDA";
//	
//	cout<<"Prueba métodos input"<<endl<<endl;
//	
//	//pruebo setter setTx con argumento input_t e índice
//	if(int idx = 0 < txns_a.getNtxin())	txns_a.setTx(in_j,idx);
//	else cout<<"txns_a tiene menos de "<<idx+1<<" inputs: no se puede cargar un input en ese índice"<<endl;
//	//txns_a.setTx(in_j,1);
//	
//	//pruebo getter getIn con argumento input_t e índice
//	if(unsigned idx = 0 < txns_a.getNtxin()) 	in_k = txns_a.getIn(idx);
//	else cout<<"txns_a tiene menos de "<<idx+1<<" inputs: no se puede obtener el input seleccionado"<<endl;
//	
//	cout<<"valores in_k.tx_id = "<<in_k.tx_id<<" ini_k.idx = "<<in_k.idx<<"in_k.addr = "<<in_k.addr<<endl<<endl;
//
//	cout<<"Prueba métodos output"<<endl<<endl;
//	
//	//pruebo setter setTx con argumento output_t e índice
//	if(unsigned idx = 0 < txns_a.getNtxout())	txns_a.setTx(out_m,idx);
//	else cout<<"txns_a tiene menos de "<<idx+1<<" outputs: no se puede cargar un output en ese índice"<<endl;
//	
//	//pruebo getter getOut con argumento output_t e índice
//	if(unsigned idx = 0 < txns_a.getNtxout()) 	out_n = txns_a.getOut(idx);
//	else cout<<"txns_a tiene menos de "<<idx+1<<" inputs: no se puede obtener el output seleccionado"<<endl;
//	
//	cout<<"valores out_n.value = "<<out_n.value<<" out_n.addr = "<<out_n.addr<<endl;
//	
return 0;
}


