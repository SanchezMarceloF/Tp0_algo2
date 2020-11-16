#include<iostream>
#ifndef ARRAYTEMP_H
#define ARRAYTEMP_H

template <class T>
class Array{
public:
	//Constructores
	Array();
	Array(const Array<T> &);
	Array(size_t);
	//Destructor
	~Array();
	
	//seters
	Array<T>& setArray(const T& elem);
	Array<T>& setArray(const T&, size_t);
		
	//getters
	size_t getSize();
		
	//otros metodos	
	Array<T> &operator=(const Array<T> &);
	bool operator==(const Array<T> &);
	T &operator[](int);
	//void emitir();

private:
	size_t size;
	T *ptr;
};

//constructor sin argumentos
template <class T>
Array<T>::Array(){
	//std::cout<<"CONSTRUCTOR ARRAY SIN ARGUMENTOS"<<std::endl;
	ptr=new T[10];
	size=10;
}

//constructor con parametro tamaño
template <class T>
Array<T>::Array(size_t n){
	size = n;
	ptr = new T[size];
}

//constructor con Array como parametro
template <class T>
Array<T>::Array(const Array<T> &init){
	size = init.size;
	ptr = new T[size];
	for(unsigned i=0; i<size; i++)
		ptr[i] = init.ptr[i];
}

//Destructor
template <class T>
Array<T>::~Array(){
	if(ptr)
		delete []ptr;
}

//setters
//carga de un elemento a al Final del Array 
template <class T>
Array<T>& Array<T>::setArray(const T& elem){
	T *aux;
	size = size+1;
	aux = new T[ size ];
	for (unsigned i = 0; i < size-1; i++){
		//std::cout<<i<<std::endl;
		aux[i] = ptr[i];
	}
	aux [size-1] = elem; 
	delete []ptr;
	ptr = aux;	
	return *this;
}

//se carga un elemento en el índice inx
template <class T>
Array<T>& Array<T>::setArray(const T& aux, size_t inx){
	if (size < inx-1){
		return *this;
	}
	else{
		ptr[inx] = aux;
		return *this;
	}
}


//getters
//metodo para obtener parametro size
template <class T>
size_t Array<T>::getSize(){
	return size;
}

//otros metodos
template <class T>
Array<T>& Array<T>::operator=( const Array<T> &rigth ){
	if ( &rigth != this ){
		if ( size != rigth.size ){
			T *aux;
			aux = new T[ rigth.size ];
			delete [] ptr;
			size = rigth.size ;
			ptr = aux;
			for (unsigned i = 0; i < size; i++)
				{ptr[ i ] = rigth.ptr[ i ];}
			return *this;
		}
		else{
		 	for ( unsigned i = 0; i < size; i++ )
				ptr[ i ] = rigth.ptr[ i ];
		return *this;
		}
	}
	return *this;
}

template <class T>
bool Array<T>::operator==( const Array<T> &rigth ){
	if ( size != rigth.size )
		return false;
	else
		for ( unsigned i = 0; i < size; i++ )
			if ( ptr[i] != rigth.ptr[i] )
				return false;
	else
		return true;
}

template <class T>
T & Array<T>::operator[]( int subscript ){
	return ptr[ subscript ];
}

#endif
