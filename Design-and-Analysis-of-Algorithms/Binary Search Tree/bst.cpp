#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct node{
	node *direita;
	node *esquerda;
	node *pai;
	int chave;
};

void inserir(node *&n, node *novo_n){
	if(novo_n->chave < n->chave){
		if(n->esquerda == NULL){
			n->esquerda = novo_n;
			novo_n->pai = n;
		}else{
			inserir(n->esquerda, novo_n);
		}
	}else{
		if(n->direita == NULL){
			n->direita = novo_n;
			novo_n->pai = n;
		}
		else{
			inserir(n->direita, novo_n);
		}
	}
}

void inorder_walk(node *raiz){
	if(raiz != NULL){
		inorder_walk(raiz->esquerda);
		cout << raiz->chave << " ";
		inorder_walk(raiz->direita);
	}
}

node *search(node *&no, int chave){
	if(no == NULL || no->chave == chave){
		return no;
	}
	if(chave < no->chave){
		return search(no->esquerda, chave);
	}
	return search(no->direita, chave);	
}

node *minimo(node *n){
	node *aux = n;
	while(aux->esquerda != NULL){
		aux = aux->esquerda;
	}
	return aux;
}
void excluir(node *&n){
	node *aux;
	if(n->direita == NULL && n->esquerda != NULL){
		if(n->pai == NULL){
			aux = n->esquerda;
			aux->pai = NULL;
		}else{
			aux = n->pai;
			n->esquerda->pai = aux;
			if(aux != NULL){
				if(aux->esquerda == n){
					aux->esquerda = n->esquerda;
				}else{
					aux->direita = n->esquerda;
				}
			}
		}
	}else if(n->esquerda == NULL && n->direita != NULL){
		if(n->pai != NULL){
			aux = n->pai;
			n->direita->pai = aux;
			if(aux != NULL){
				if(aux->esquerda == n){
					aux->esquerda = n->direita;
				}else{
					aux->direita = n->esquerda;
				}
			}
		}else{
			aux = n->direita;
			aux->pai = NULL;
		}
	}else if(n->direita == NULL && n->esquerda == NULL && n->pai != NULL){
		if(n->pai->esquerda == n){
			n->pai->esquerda = NULL;
		}else{
			n->pai->direita = NULL;
		}
	}else{
		aux = minimo(n->direita);
		aux->esquerda = n->esquerda;
		if(aux->pai != NULL){
			if(aux->pai->esquerda == aux){
				aux->pai->esquerda = NULL;
			}else{
				aux->pai->direita = NULL;
			}
		}
		if(n->direita != aux){
			inserir(aux, n->direita);
		}
	}
	cout << "Elemento excluído" << endl;
	delete n;
}

/*
void excluir(node *&no){
	node *aux;
	if(no->direita == NULL && no->esquerda != NULL){
		aux = no->esquerda;
		aux->pai = no->pai;
		aux->pai->esquerda = no->esquerda;
	}else if(no->direita != NULL && no->esquerda == NULL){
		aux = minimo(no->direita);
		aux->pai = no->pai;
		if(aux->pai != NULL) aux->pai->direita = no->direita;
		if(aux->direita != NULL){
			inserir(aux, aux->direita);
		}else{
			if(aux->esquerda != NULL){
				inserir(aux, aux->esquerda);
			}
		}
	}else if(no->direita != NULL && no->esquerda != NULL){

	}
}*/


int main(){

	fstream f;
	int valor;
	node *raiz, *n;
	f.open("numeros.csv");
	raiz = new node();
	raiz = NULL;
	
	while(!f.eof()){
		f >> valor;
		n = new node();
		n->chave = valor;
		n->esquerda = NULL;
		n->direita = NULL;
		n->pai = NULL;
		if(raiz == NULL) {
			raiz = n;
		}else{
		 	inserir(raiz, n);
		}
	}
	f.close();
	int opt;
	for(;;){
		cout << "\nControle de arvore" << endl;
		cout << "1 - Exibir in-ordem" << endl;
		cout << "2 - Inserir um novo elemento" << endl;
		cout << "3 - Retirar elemento" << endl;
		cout << "4 - Menor elemento" << endl;
		cout << "5 - Maior elemento" << endl;
		cout << "6 - Extrair máximo (achar e retirar" << endl;
		cout << "7 - Extrair Mínimo (achar e retirar)" << endl;
		cout << "8 - Salvar em arquivo não degenerada" << endl;
		cout << "0 - Sair" << endl;
		cin >> opt;
		switch(opt){
			case 1:
				inorder_walk(raiz);
				break;
			case 0:
				return 0;
			case 2:
				n = new node();
				cout << "Digite um valor para a nova chave: ";
				cin >> n->chave;
				n->esquerda = NULL;
				n->direita = NULL;
				n->pai = NULL;
				if(raiz == NULL) raiz = n;
				else inserir(raiz, n);
				break;
			case 3:
				int chave;
				cout << "Informe o valor que deseja retirar: ";
				cin >> chave;
				n = search(raiz, chave);
				if(n == NULL){
					cout << "A chave informada não existe." << endl;
				}else{
					excluir(n);
				}
				break;

			default: 
				cout << "Opção inválida, digite outra: ";
				cin >> opt;
				break;
		}
	}

	return 0;
}