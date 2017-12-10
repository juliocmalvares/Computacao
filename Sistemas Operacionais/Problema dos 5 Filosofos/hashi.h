#ifndef HASHI_H_INCLUDED
#define HASHI_H_INCLUDED
#include <iostream>
#include <atomic>
#include <cstdlib>
using namespace std;

template <class T>
class Hashi{
	public:
		atomic<int> indice;
		atomic<bool> flag_bloq;

		Hashi(){
			this->flag_bloq.store(false, std::memory_order_seq_cst);
		}
		~Hashi(){}
		T set_indice(int indice);
		T set_flag(bool flag);
		T get_indice();
		T get_bloqueado();

};

template <class T>
T Hashi<T>::set_indice(int indice){
	this->indice.store(indice, std::memory_order_seq_cst);
}

template <class T>
T Hashi<T>::set_flag(bool flag){
	this->flag_bloq.store(flag, std::memory_order_seq_cst);
}

template <class T>
T Hashi<T>::get_indice(){
	int x;
	x = this->indice.load(std::memory_order_seq_cst);
	return x;
}

template <class T>
T Hashi<T>::get_bloqueado(){
	bool f;
	f = this->flag_bloq.load(std::memory_order_seq_cst);
	return f;
}


#endif // HASHI_H_INCLUDED
