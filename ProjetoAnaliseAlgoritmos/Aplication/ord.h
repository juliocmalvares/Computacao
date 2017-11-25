#ifndef __ORD__
#define __ORD__

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstdio>
using namespace std;

bool max_string(string s1, string s2){
	int i = 0;
	while(i < s1.length() && i < s2.length()){
		if(tolower(s1[i]) < tolower(s2[i])) {
			return true;
		}else if(tolower(s1[i]) > tolower(s2[i])) return false;
		i++;
	}
	if(i >= s1.length()){
		return true;
	}else{
		return false;
	}
} //retorna true se S1 for menor e false se s2 for menor


void insertion(string *v, int n) {
	string chave; 
	int j;
	
	for(int i=1; i<n; i++) {
		chave = v[i];
		j = i-1;
		
		while(j >= 0 && max_string(chave, v[j])) {
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = chave;
	}
}

void insertion_invertido(string *v, int n) {
	string chave; 
	int j;
	
	for(int i=1; i<n; i++) {
		chave = v[i];
		j = i-1;
		
		while(j >= 0 && max_string(v[j], chave)) {
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = chave;
	}
}



void heapify(string vet[], int i, int size){
	int sonLeft, sonRight;
	if(i == 0){
		sonLeft = 1;
		sonRight = 2;
	}else{
		sonLeft = i*2;
		sonRight = i*2+1;
	}
	if(size - 1 >= 1 && sonRight <= size){
		heapify(vet, sonLeft, size);
		heapify(vet, sonRight, size);

		if(max_string(vet[i],vet[sonLeft])){
			string tmp = vet[i];
			vet[i] = vet[sonLeft];	//troca filho da esquerda
			vet[sonLeft] = tmp;
		}

		if(max_string(vet[i],vet[sonRight])){
			string tmp = vet[i];
			vet[i] = vet[sonRight]; //troca filho da direita
			vet[sonRight] = tmp;
		}
	}
}

void heap(string vet[], int size){
	string *w = new string[size+1];
	for(int i = 0; i < size; i++){
		w[i] = vet[i];
	}

	for(int i = 0; i < size; i++){
		heapify(w, 0, size - i);
		vet[size - i - 1] = w[0];
		w++;
	}
}


void do_merge(string v[], int p, int q, int r) {
	int i = p;
	int j = q;
	int k = 0;
	string *w = new string[(r-p)+1];


	// Recombina o resultado entre os subconjuntos em w
	while(i < q && j <= r) {
		if(max_string(v[i], v[j])) w[k++] = v[i++];
		else w[k++] = v[j++];
	}

	while(i<q) w[k++] = v[i++];

	while(j<=r) w[k++] = v[j++];

	for(i=p,j=0;i<=r;i++,j++) v[i] = w[j];
}

void merge(string v[], int p, int q) {
	if(p < q){
		int k=(p+q)/2;
		merge(v,p,k);
		merge(v,k+1,q);
		do_merge(v,p,k+1,q);
	} 
}


int partition(string v[], int p, int q) {
	string pivot = v[p], tmp;
	int i = p+1;
	int j = q;
	
	for(;;) {
		while(v[i] < pivot && i < q) {
			i++;
		}
		
		while(v[j] > pivot) {
			j--;
		}

		if(i<=j) {
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			++i;
			--j;
		}else{
			v[p] = v[j];
			v[j] = pivot;
			return j;
		}
	}
}

void quick(string v[],int p,int q) {
	if(p < q) {
		int k = partition(v,p,q);
		quick(v,p,k-1);
		quick(v,k+1,q);
	}
}


/*int shellkey(int s){
	if(s == 1) return 1;
	return 3*shellkey(s-1)+1;
}*/

void shell(string *v, int size){
	int h = 0; //shellkey(size);
	string aux;
	int j;
	while (h <= size) h = 3*(h-1)+1;

	while(h >= size) h = (h-1)/3;

	while(h > 0){
		//cout << h << endl;
		for(int i = h; i < size; i++){
			aux = v[i];
			j = i;
			
			while(max_string(aux, v[j-h])){
				v[j] = v[j - h];
				j -= h;
				if(j <= h) break;
			}
			v[j] = aux;
		}
		
		if(h == 0) return;
		h = (h - 1)/3;
	}
}

#endif
