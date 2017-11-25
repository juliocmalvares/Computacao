#ifndef __LEITURA__
#define __LEITURA__

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

string *leitura(int &n){
	fstream file;
	string buffer, *nomes;
	n = 0;
	file.open("nomes.txt");
	while(getline(file, buffer)) n++;

	nomes = new string[n];
	file.clear();
	file.seekg(0,ios::beg);
	for(int i = 0; i < n; i++) getline(file, nomes[i]);

	file.close();
	return nomes;
}

void escrita(string nomes[], int n, string nome){
	fstream file;
	nome = nome + ".txt";
	file.open(nome.c_str(), ios::out);
	for(int i = 0; i < n; i++) file << nomes[i] << endl;
	file.close();
}

void escreve_saida(double valor, string nome){
	nome += ".txt";
	fstream file;
	file.open(nome.c_str(), ios::app);
	file << valor << endl;
	file.close();
}

#endif