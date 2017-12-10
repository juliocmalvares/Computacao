#include <iostream>
#include <cstdlib>
#include <ctime>
#include "filosofo.h"
#include "hashi.h"
#include <atomic>
#include <ctime>

using namespace std;


template <class T>
void Filosofo<T>::set_hashi1(int h1){
	this->hashi1 = h1;
}

template <class T>
void Filosofo<T>::set_hashi2(int h2){
	this->hashi2 = h2;
}

template <class T>
void Filosofo<T>::set_bloqueio(bool bloqueio){
	this->flag_bloqueado.store(bloqueio, std::memory_order_seq_cst);
}

template <class T>
int Filosofo<T>::pensar(Hashi<T> *h[]){
	srand(time(NULL));
	if(this->libera_hashi(h)){
		this->tempo_de_pensar = int(rand() % 10) + 1;
		this->set_bloqueio(true);
		return this->tempo_de_pensar;
	}
	return -1;
}

template <class T>
int Filosofo<T>::comer(Hashi<T> *h[]){
	srand(time(NULL));
	if(this->capturar_h1(h) == true && this->capturar_h2(h) == true){
		this->tempo_de_comer = int(rand() % 5) + 1;
		this->set_bloqueio(true);
		return this->tempo_de_comer;
	}
	return -1; // pensar?
}

template <class T>
bool Filosofo<T>::capturar_h1(Hashi<T> *h[]){
	if(h[this->hashi1]->get_bloqueado() == false){
		h[this->hashi1]->set_flag(true);
		return true;
	}
	return false;
}

template <class T>
bool Filosofo<T>::capturar_h2(Hashi<T> *h[]){
	if(h[this->hashi2]->get_bloqueado() == false){
		h[this->hashi2]->set_flag(true);
		return true;
	}
	return false;
}

template <class T>
bool Filosofo<T>::bloqueado(){
	bool f = this->flag_bloqueado.load(memory_order_seq_cst);
	return f;
}

template <class T>
bool Filosofo<T>::libera_hashi(Hashi<T> *h[]){
	h[this->hashi1]->set_flag(false);
	h[this->hashi2]->set_flag(false);
	return true;
}




