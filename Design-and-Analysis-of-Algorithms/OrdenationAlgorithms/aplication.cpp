#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "leitura.h"
#include "ord.h"
#include <clocale>
using namespace std;

double calcula_tempo(clock_t inicio, clock_t fim);
void coder_insertion();
void aux_coder_insertion(string *names, int n);
double auxiliar_insertion(string *names, int n);
void coder_heapsort();
void aux_coder_heap(string *names, int n);
void coder_quicksort();
void aux_coder_quick(string *names, int n);
void aux_coder_merge(string *names, int n);
void coder_merge();
void aux_coder_shell(string *names, int n);
void coder_shell();

int main(){
	setlocale(LC_ALL, "Potuguese");
	int option;
	
	for(;;){
		cout << "\n--------------Menu--------------" << endl;
		cout << "  1 - Insertion sort" << endl;
		cout << "  2 - Heap sort" << endl;
		cout << "  3 - Quick sort" << endl;
		cout << "  4 - Merge sort" << endl;
		cout << "  5 - Shell sort" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opção: ";
		cin >> option;
		switch(option){
			case 1:
				coder_insertion();
				break;
			case 0:
				return 0;
			case 2:
				coder_heapsort();
				break;
			case 3:
				coder_quicksort();
				break;
			case 4:
				coder_merge();
				break;
			case 5:
				coder_shell();
				break;
			default:
				cout << "Opção inválida. Digite outra opção: ";
				cin >> option;
				break;
		}
	}
	return 0;
}

double calcula_resultado(clock_t begin, clock_t end){
	return (end - begin) / (double)(CLOCKS_PER_SEC);
}

double calcula_execucao(string *names, int n, int op){
	clock_t inicio, fim;
	int option = op;
	switch(option){
		case 1:
			inicio = clock();
			insertion(names, n);
			fim = clock();
			return calcula_resultado(inicio, fim);
		case 2:
			inicio = clock();
			heap(names, n);
			fim = clock();
			return calcula_resultado(inicio, fim);
		case 3:
			inicio = clock();
			quick(names, 0, n);
			fim = clock();
			return calcula_resultado(inicio, fim);
		case 4:
			inicio = clock();
			merge(names, 0, n);
			fim = clock();
			return calcula_resultado(inicio, fim);
		case 5:
			inicio = clock();
			shell(names, n);
			fim = clock();
			return calcula_resultado(inicio, fim);
	}
}

void aux_coder_insertion(string *names, int n){
	int i = 0;
	string *real = new string[n];
	bool flag = false;
	while(i < n){
		while(flag == false){
			real[i] = names[i];
			i++;
			if(i % 3 == 0 || i == n) flag = true;
		}
		//cout << i << endl;
		insertion(real, i);
		flag = false;
	}
}

void coder_insertion(){
	string *names = NULL;
	clock_t comeco, fim;
	double resultado = 0;
	int n = 0;
	int option;
	for(;;){
		cout << "\n\t--------------Insertion Sort--------------" << endl;
		cout << "\t   1 - Caso médio, complexidade imprecisa! Tende a se aproximar de O(n²)" << endl;
		cout << "\t   2 - Melhor caso, complexidade Ω(n)" << endl;
		cout << "\t   3 - Pior caso, complexidade Θ(n²)" << endl;
		cout << "\t   4 - Caso particular, ainda pior que o pior caso." << endl;
		cout << "\t   5 - Calcular tempo de saida" << endl;
		cout << "\t   6 - Calcula tempo pior caso" << endl;
		cout << "\t   7 - Calcula tempo melhor caso" << endl;
		cout << "\t   0 - Sair" << endl;
		cout << "\tOpção:";
		cin >> option;
		switch(option){
			case 1:
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				comeco = clock();
				cout << "Wait ..." << endl;
				insertion(names, n);
				fim = clock();
				resultado = calcula_resultado(comeco, fim);
				cout << "O caso médio do algoritmo Insertion sort apresentou um tempo de execução de " << resultado << " segundos." << endl;
				escrita(names, n, "InsertionMedio");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 2:
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				cout << "Gerando vetor ordenando ... " << endl;
				try{
					insertion(names, n);
					cout << "Gerado com sucesso" << endl;
				}catch(int e){
					cout << "Uma exceção ocorreu, Erro ao gerar o vetor! Exception number: " << e << endl;
				}
				comeco = clock();
				cout << "Começando a calcular o caso!" << endl;
				cout << "Wait ..." << endl;
				insertion(names, n);
				fim = clock();
				resultado = calcula_resultado(comeco, fim);
				cout << "O melhor caso do algoritmo Insertion sort apresentou um tempo de execução de " << resultado << " segundos." << endl;
				escrita(names, n, "InsertionMelhor");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 3:
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				cout << "Gerando o vetor inversamente ordenado ..." << endl;
				try{
					insertion_invertido(names, n);
					cout << "Gerado com sucesso" << endl;
				}catch(int e){
					cout << "Uma exceção ocorreu, Erro ao gerar o vetor! Exception number: " << e << endl;
				}
				comeco = clock();
				cout << "Começando a calcular o caso!" << endl;
				cout << "Wait ..." << endl;
				insertion(names, n);
				fim = clock();
				resultado = calcula_resultado(comeco, fim);
				cout << "O pior caso do algoritmo Insertion sort apresentou um tempo de execução de " << resultado << " segundos." << endl;
				escrita(names, n, "InsertionPior");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 4:
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				cout << "Gerando o vetor inversamente ordenado." << endl;
				try{
					insertion_invertido(names, n);
					cout << "Gerado com sucesso!\nComeçando o caso particular: " << endl;
				}catch(int e){
					cout << "Erro na geração do vetor inverso! Erro número " << e <<endl;
				}
				comeco = clock();
				cout << "Wait ..." << endl;
				aux_coder_insertion(names, n);
				fim = clock();
				resultado = calcula_resultado(comeco, fim);
				cout << "O caso particular do algoritmo Insertion sort apresentou um tempo de execução de " << resultado << " segundos." << endl;
				cout << "O caso particular faz a inserção e ordenação do total de elementos em intervalos de 3 em 3 elementos." << endl;
				escrita(names, n, "InsertionParticular");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 0:
				return;
			default:
				cout << "Opção inválida! Digite uma opção válida: ";
				cin >> option;
				break;
			case 5:
				n = 0;
				names = leitura(n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 1), "saida_insertion");
					names = leitura(n);
				}
				break;
			case 6:
				names = leitura(n);
				insertion_invertido(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 1), "saida_insertion_piorCaso");
					names = leitura(n);
					insertion_invertido(names, n);
				}
				break;
			case 7:
				names = leitura(n);
				insertion(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 1), "saida_insertion_melhorCaso");
					names = leitura(n);
					quick(names,0, n);
				}
				break;
		}
	}
}

void aux_coder_heap(string *names, int n){
	int i = 0;
	string *real = new string[n];
	bool flag = false;
	while(i < n){
		while(flag == false){
			real[i] = names[i];
			i++;
			if(i % 100 == 0 || i == n) flag = true;
		}
		cout << i << endl;
		heap(real, i);
		flag = false;
	}
}

void coder_heapsort(){
	string *names = NULL;
	int n = 0, option = 0;
	clock_t inicio, fim;
	double resultado = 0;

	for(;;){
		cout << "\n\t--------------Heap Sort--------------" << endl;
		cout << "\t   1 - Caso médio, complexidade imprecisa! Tende a se aproximar de O(nlogn)" << endl;
		cout << "\t   2 - Melhor caso, complexidade Ω(nlogn)" << endl;
		cout << "\t   3 - Pior caso, complexidade Θ(nlogn)" << endl;
		cout << "\t   4 - Caso particular, ainda pior que o pior caso." << endl;
		cout << "\t   5 - Calcula execucao." << endl;
		cout << "\t   6 - Calcula execucao pior caso" << endl;
		cout << "\t   7 - Calcula execucao melhor caso." << endl;
		cout << "\t   0 - Sair" << endl;
		cout << "\tOpção:";
		cin >> option;
		switch(option){
			case 1:
				n = 0;
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				inicio = clock();
				cout << "Wait ... " << endl;
				heap(names, n);
				fim = clock();
				resultado = calcula_resultado(inicio, fim);
				cout << "O caso médio do algoritmo Heap Sort teve tempo de execução de " << resultado << " segundos!" << endl;
				cout << "O caso médio ordena o vetor em um cenário onde os elementos estão aleatoriamente dispostos." << endl;
				escrita(names, n, "HeapMedio");
				cout << "Um arquivo txt foi gerado com os resultados." << endl;
				break;
			case 2:
				n = 0;
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				try{
					cout << "Tentando gerar vetor ordenado." << endl;
					insertion(names, n);
					cout << "Vetor gerado!" << endl;
				}catch(int e){
					cout << "Houve um erro na geração do vetor ordenado! Erro numero " << resultado << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				heap(names, n);
				fim = clock();
				resultado = calcula_resultado(inicio, fim);
				cout << "O melhor caso do algoritmo Heap Sort teve tempo de execução de " << resultado << " segundos!" << endl;
				cout << "O melhor caso ordena um vetor onde os seus elementos já estão ordenados." << endl;
				cout << "O pior caso ordena um vetor onde os seus elementos estão inversamente ordenados." << endl;
				escrita(names, n, "HeapMelhor");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 3:
				n = 0;
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				try{
					cout << "Tentando gerar vetor inversamente ordenado." << endl;
					insertion_invertido(names, n);
					cout << "Vetor gerado!" << endl;
				}catch(int e){
					cout << "Houve um erro na geração do vetor inversamente ordenado! Erro numero " << resultado << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				heap(names, n);
				fim = clock();
				resultado = calcula_resultado(inicio, fim);
				cout << "O pior caso do algoritmo Heap Sort teve tempo de execução de " << resultado << " segundos!" << endl;
				cout << "O pior caso ordena um vetor onde os seus elementos estão inversamente ordenados." << endl;
				escrita(names, n, "HeapPior");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 4:
				n = 0;
				names = leitura(n);
				cout << "Total de " << n << " elementos a serem trabalhados." << endl;
				/*cout << "Gerando o vetor inversamente ordenado." << endl;
				try{
					insertion_invertido(names, n);
					cout << "Gerado com sucesso!\nComeçando o caso particular: " << endl;
				}catch(int e){
					cout << "Erro na geração do vetor inverso! Erro número " << e <<endl;
				}*/
				inicio = clock();
				cout << "Wait ..." << endl;
				aux_coder_heap(names, n);
				fim = clock();
				resultado = calcula_resultado(inicio, fim);
				cout << "O caso particular do algoritmo Heap sort apresentou um tempo de execução de " << resultado << " segundos." << endl;
				cout << "O caso particular faz a inserção e ordenação do total de elementos em intervalos de 3 em 3 elementos." << endl;
				escrita(names, n, "HeapParticular");
				cout << "Um arquivo com os resultados foi gerado." << endl;
				break;
			case 0:
				return;
			default:
				cout << "Opção inválida!" << endl;
				cout << "Digite outra opção: ";
				cin >> option;
				break;
			case 5:
				n = 0;
				names = leitura(n);
				cout << "Calculando ..." << endl;
				for(int i = 1; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 2), "saida_heap");
					names = leitura(n);
				}
				break;
			case 6:
				names = leitura(n);
				insertion_invertido(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 2), "saida_heap_piorCaso");
					names = leitura(n);
					insertion_invertido(names, n);
				}
				break;
			case 7:
				names = leitura(n);
				insertion(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 2), "saida_heap_melhorCaso");
					names = leitura(n);
					quick(names,0, n);
				}
				break;
		}
	}
}

void aux_coder_quick(string *names, int n){
	int i = 0;
	string *real = new string[n];
	bool flag = false;
	while(i < n){
		while(flag == false){
			real[i] = names[i];
			i++;
			if(i % 3 == 0 || i == n) flag = true;
		}
		if(n == i) break;
		cout << i << endl;
		quick(real,0, i);
		flag = false;
	}
	escrita(real, n, "QuickParticular");
}

void coder_quicksort(){
	int n = 0, option;
	clock_t inicio, fim;
	string *names = NULL;
	for(;;){
		cout << "\n\t--------------Quick Sort--------------" << endl;
		cout << "\t   1 - Caso médio, complexidade imprecisa! Tende a se aproximar de O(nlogn)" << endl;
		cout << "\t   2 - Melhor caso, complexidade Ω(n²)" << endl;
		cout << "\t   3 - Pior caso, complexidade Θ(nlogn)" << endl;
		cout << "\t   4 - Caso particular, ainda pior que o pior caso." << endl;
		cout << "\t   5 - Calcula execucao." << endl;
		cout << "\t   6 - Calcula execucao pior caso." << endl;
		cout << "\t   7 - Calcula execucao melhor caso." << endl;
		cout << "\t   0 - Sair" << endl;
		cout << "\tOpção:";
		cin >> option;
		switch(option){
			case 0:
				return;
			default:
				cout << "Opçao invalida, digite outra opcao: ";
				cin >> option;
				break;
			case 1:
				n = 0;
				names = leitura(n);
				cout << "Computando "<<n<< " elementos" << endl;
				inicio = clock();
				cout << "Wait ..." << endl;
				quick(names, 0, n);
				fim = clock();
				cout << "O caso medio do algoritmo Quick sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos." << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "QuickMedio");
				break;
			case 2:
				n = 0;
				names = leitura(n);
				cout << "Computando "<<n<< " elementos" << endl;
				try{
					cout << "Tentando gerar vetor ordenado." << endl;
					insertion(names, n);
					cout << "Vetor gerado com sucesso."<< endl;
				}catch(int e){
					cout << "Erro ao gerar vetor, erro numero " << e << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				quick(names,0, n);
				fim = clock();
				cout << "O melhor caso do algoritmo Quick sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos." << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "QuickMelhor");
				break;
			case 3:
				n = 0;
				names = leitura(n);
				cout << "Computando " << n << " elementos" << endl;
				try{
					cout << "Tentando gerar vetor inversamente ordenado" << endl;
					insertion_invertido(names, n);
					cout << "Gerado com sucesso." << endl;
				}catch(int e){
					cout << "Erro ao gerar vetor. " << e << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				quick(names,0, n);
				fim = clock();
				cout << "O pior caso do algoritmo Quick sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos" << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "QuickPior");
				break;
			case 4:
				n = 0;
				names = leitura(n);
				inicio = clock();
				cout << "Wait ..." << endl;
				aux_coder_quick(names, n);
				fim = clock();
				cout << "O caso particular do algoritmo Quick sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos" << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				
				break;
			case 5:
				n = 0;
				names = leitura(n);
				cout << "Calculando ..." << endl;
				for(int i = 1; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 3), "saida_quick");
					names = leitura(n);
				}
				break;
			case 6:
				names = leitura(n);
				insertion_invertido(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 3), "saida_quick_piorCaso");
					names = leitura(n);
					insertion_invertido(names, n);
				}
				break;
			case 7:
				names = leitura(n);
				insertion(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 3), "saida_quick_melhorCaso");
					names = leitura(n);
					quick(names,0, n);
				}
				break;
		}
	}
}

void aux_coder_merge(string *names, int n){
	int i = 0;
	string *real = new string[n];
	bool flag = false;
	while(i < n){
		while(flag == false){
			real[i] = names[i];
			i++;
			if(i % 3 == 0 || i == n) flag = true;
		}
		//cout << i << endl;
		merge(real,0, i-1);
		flag = false;
	}
}

void coder_merge(){
	int n = 0, option;
	clock_t inicio, fim;
	string *names = NULL;
	for(;;){
		cout << "\n\t--------------Merge Sort--------------" << endl;
		cout << "\t   1 - Caso médio, complexidade imprecisa! Tende a se aproximar de O(nlogn)" << endl;
		cout << "\t   2 - Melhor caso, complexidade Ω(nlogn)" << endl;
		cout << "\t   3 - Pior caso, complexidade Θ(n²)" << endl;
		cout << "\t   4 - Caso particular, ainda pior que o pior caso." << endl;
		cout << "\t   5 - Calcula execucao." << endl;
		cout << "\t   6 - Calcula execucao pior caso." << endl;
		cout << "\t   7 - Calcula execucao melhor caso." << endl;
		cout << "\t   0 - Sair" << endl;
		cout << "\tOpção:";
		cin >> option;
		switch(option){
			case 0:
				return;
			default:
				cout << "Opçao invalida, digite outra opcao: ";
				cin >> option;
				break;
			case 1:
				n = 0;
				names = leitura(n);
				cout << "Computando "<<n<< " elementos" << endl;
				inicio = clock();
				cout << "Wait ..." << endl;
				merge(names, 0, n-1);
				fim = clock();
				cout << "O caso medio do algoritmo Merge sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos." << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "MergeMedio");
				break;
			case 2:
				n = 0;
				names = leitura(n);
				cout << "Computando "<<n<< " elementos" << endl;
				try{
					cout << "Tentando gerar vetor ordenado." << endl;
					insertion(names, n);
					cout << "Vetor gerado com sucesso."<< endl;
				}catch(int e){
					cout << "Erro ao gerar vetor, erro numero " << e << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				merge(names, 0, n-1);
				fim = clock();
				cout << "O melhor caso do algoritmo Merge sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos." << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "MergeMelhor");
				break;
			case 3:
				n = 0;
				names = leitura(n);
				cout << "Computando " << n << " elementos" << endl;
				try{
					cout << "Tentando gerar vetor inversamente ordenado" << endl;
					insertion_invertido(names, n);
					cout << "Gerado com sucesso." << endl;
				}catch(int e){
					cout << "Erro ao gerar vetor. " << e << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				merge(names, 0, n-1);
				fim = clock();
				cout << "O pior caso do algoritmo Merge sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos" << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "MergePior");
				break;
			case 4:
				n = 0;
				names = leitura(n);
				inicio = clock();
				cout << "Wait ..." << endl;
				aux_coder_merge(names, n);
				fim = clock();
				cout << "O caso particular do algoritmo Merge sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos" << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "MergeParticular");
				break;
			case 5:
				n = 0;
				names = leitura(n);
				cout << "Calculando ..." << endl;
				for(int i = 1; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 3), "saida_merge");
					names = leitura(n);
				}
				break;
			case 6:
				names = leitura(n);
				insertion_invertido(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 4), "saida_merge_piorCaso");
					names = leitura(n);
					insertion_invertido(names, n);
				}
				break;
			case 7:
				names = leitura(n);
				insertion(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 0; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 4), "saida_merge_melhorCaso");
					names = leitura(n);
					quick(names,0, n);
				}
				break;
		}
	}
}

void aux_coder_shell(string *names, int n){
	int i = 0;
	string *real = new string[n];
	bool flag = false;
	while(i < n){
		while(flag == false){
			real[i] = names[i];
			i++;
			if(i % 10 == 0 || i == n) flag = true;
		}
		//cout << i << endl;
		shell(real, i);
		flag = false;
	}
	escrita(real, n, "ShellParticular");
}

void coder_shell(){
	int n = 0, option;
	clock_t inicio, fim;
	string *names = NULL;
	for(;;){
		cout << "\n\t--------------Shell Sort--------------" << endl;
		cout << "\t   1 - Caso médio, complexidade imprecisa! Tende a se aproximar de O(n)" << endl;
		cout << "\t   2 - Melhor caso, complexidade Ω(n)" << endl;
		cout << "\t   3 - Pior caso, complexidade Θ(n)" << endl;
		cout << "\t   4 - Caso particular, ainda pior que o pior caso." << endl;
		cout << "\t   5 - Calcula execucao. " << endl;
		cout << "\t   6 - Calcula execucao pior caso" << endl;
		cout << "\t   7 - Calcula execucao melhor caso. " << endl;
		cout << "\t   0 - Sair" << endl;
		cout << "\tOpção:";
		cin >> option;
		switch(option){
			case 0:
				return;
			default:
				cout << "Opçao invalida, digite outra opcao: ";
				cin >> option;
				break;
			case 1:
				n = 0;
				names = leitura(n);
				cout << "Computando "<<n<< " elementos" << endl;
				inicio = clock();
				cout << "Wait ..." << endl;
				shell(names, n);
				fim = clock();
				cout << "O caso medio do algoritmo Shell sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos." << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "ShellMedio");
				break;
			case 2:
				n = 0;
				names = leitura(n);
				cout << "Computando "<<n<< " elementos" << endl;
				try{
					cout << "Tentando gerar vetor ordenado." << endl;
					insertion(names, n);
					cout << "Vetor gerado com sucesso."<< endl;
				}catch(int e){
					cout << "Erro ao gerar vetor, erro numero " << e << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				shell(names, n);
				fim = clock();
				cout << "O melhor caso do algoritmo Shell sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos." << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "ShellMelhor");
				break;
			case 3:
				n = 0;
				names = leitura(n);
				cout << "Computando " << n << " elementos" << endl;
				try{
					cout << "Tentando gerar vetor inversamente ordenado" << endl;
					insertion_invertido(names, n);
					cout << "Gerado com sucesso." << endl;
				}catch(int e){
					cout << "Erro ao gerar vetor. " << e << endl;
				}
				inicio = clock();
				cout << "Wait ..." << endl;
				shell(names, n);
				fim = clock();
				cout << "O pior caso do algoritmo Shell sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos" << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				escrita(names, n, "ShellPior");
				break;
			case 4:
				n = 0;
				names = leitura(n);
				inicio = clock();
				cout << "Wait ..." << endl;
				aux_coder_shell(names, n);
				fim = clock();
				cout << "O caso particular do algoritmo Shell sort apresentou um tempo de execução de " << calcula_resultado(inicio, fim) << " segundos" << endl;
				cout << "Um arquivo com os resultados foi gerado" << endl;
				//escrita(names, n, "ShellParticular");
				break;
			case 5:
				n = 0;
				names = leitura(n);
				cout << "Calculando ..." << endl;
				for(int i = 1; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 5), "saida_shell");
					names = leitura(n);
				}
				break;
			case 6:
				names = leitura(n);
				insertion_invertido(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 1; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 5), "saida_shell_piorCaso");
					names = leitura(n);
					insertion_invertido(names, n);
				}
				break;
			case 7:
				names = leitura(n);
				insertion(names, n);
				cout << "Calculando ..." << endl;
				for(int i = 1; i < n; i+=500){
					escreve_saida(calcula_execucao(names, i, 5), "saida_shell_melhorCaso");
					names = leitura(n);
					quick(names,0, n);
				}
				break;
		}
	}
}
