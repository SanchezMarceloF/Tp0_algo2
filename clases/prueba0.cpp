//prueba del Template Array con una 
//estructura output_t

#include <iostream>
#include <string>
#include "Array.h"

using namespace std;


typedef struct{
        float value;
        string addr; //dirección destino de los fondos, 64 bytes fijos (es un hash)
} output_t;

int main() {
	cout<<":: Bienvenido a prueba0.cpp ::"<< endl;
	Array<output_t> a, b(5);
	output_t c, z;

	c.value = 324.56;
	c.addr = "64a4171b3c45d34131f16a10405003b3515f13131355133057";
	a.setArray(c,3); //copio c en la pos 3 del Array
	z = a[3];
	cout<<"z.value = "<<z.value<<endl;
	cout<<"z.addr = "<<z.addr<<endl;

	cout<< "- Prueba de setArray sin argumentos -"<<endl;
	cout<<"------------------------------------------\n"<<endl;	
	//pruebo grabar al final del arreglo
	int tamb = b.getSize();
	cout<<"tamaño de b, antes : "<<tamb<<endl;
	b.setArray(c,0); //copio c en la posicion 0
	b.setArray(c); //copio c en la posicion 5, que no existía
	tamb = b.getSize();
	cout<<"tamaño de b después : "<<tamb<<endl;
	z = b[5];
	cout<<"z.value = "<<z.value<<endl;
	cout<<"z.addr = "<<z.addr<<endl;
	//Array d(c,3w;
		
return 0;
}


