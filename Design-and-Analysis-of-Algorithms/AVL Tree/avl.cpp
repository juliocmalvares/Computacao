#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

struct Node{
	int chave;
	Node *dir;
	Node *esq;
	Node *pai;
	int fb;
};

void inserir(Node *&n, Node *novo_n){
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

void inorder_walk(Node *root){
	if(root != NULL){
		inorder_walk(root->esq);
		cout << root->chave << " ";
		inorder_walk(root->dir);
	}
}

Node *minimum(Node *no){
	Node *aux = no;
	while(aux->esq != NULL){
		aux = aux->esq;
	}
	return aux;
}

Node *search(Node *no, int chave){
	if(no == NULL || no->chave == chave){
		return no;
	}else if(no->chave > chave){
		return search(no->esq, chave);
	}
	return search(no->dir, chave);
}

void exclude(Node *no){
	Node *aux = NULL;
	int tmp;

	if(no->esq != NULL && no->dir != NULL){
		aux = minimum(no->dir);
		tmp = n->chave;
		n->chave = aux->chave;
		aux->chave = tmp;
		n = aux;
	}
}

int main(){

	return EXIT_SUCCESS;
}	
