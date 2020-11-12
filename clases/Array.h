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
	Array<T>& setArray(const T&, int);
		
	//getters
	int getSize();
		
	//otros metodos	
	Array<T> &operator=(const Array<T> &);
	bool operator==(const Array<T> &);
	T &operator[](int);
	//void emitir();

private:
	int size;
	T *ptr;
};

//constructor sin argumentos
template <class T>
Array<T>::Array(){
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
	for(int i=0; i<size; i++)
		ptr[i] = init.ptr[i];
}

//Destructor
template <class T>
Array<T>::~Array(){
	if(ptr)
		delete []ptr;
}

//setters
//carga de un objeto en 
template <class T>
Array<T>& Array<T>::setArray(const T& aux, int inx){
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
int Array<T>::getSize(){
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
			for (int i = 0; i < size; i++)
				{ptr[ i ] = rigth.ptr[ i ];}
			return *this;
		}
		else{
		 	for ( int i = 0; i < size; i++ )
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
		for ( int i = 0; i < size; i++ )
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
