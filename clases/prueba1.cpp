//se prueba el constructor por defecto de la clase Transaction
// y el Template Array con sus contructores
//solo con 1 output para simplificar

#include <iostream>
#include <string>
#include "txns_lecture.h"
#include "Array.h"

using namespace std;

int main() {
	std::cout<<"estamos en main de prueba1.cpp"<< std::endl;
	Transaction a;
	output_t m, n;
	m.value = 324.56;
	m.addr = "64a4171b3c45d34131f16a10405003b3515f13131355133057";
	
	//pruebo setter setTx con argumento output_t e índice
	a.setTx(m,0);
	a.setTx(m,1);
	
	//pruebo getter getOut con argumento output_t e índice
	n = a.getOut(0);
	cout<<"valores m.value = "<<n.value<<" m.addr = "<<n.addr<<endl;
	
return 0;
}


