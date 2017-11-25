#include <iostream>
#include <cstdlib>
#include "Node.h"
using namespace std;
/*Red-Black Tree
	Julio Cesar Machado Alvares
	Engenharia de Computacao, turma 2015.1
	Instituto Federal de Minas Gerais - campus Bambui
*/
Node *Node::search_node(int key){
	if(this->get_key() == key){
		return this;
	}else if(key < this->get_key()){
		return this->get_left()->search_node(key);
	}
	return this->get_right()->search_node(key);
}

void Node::left_rotate(){
	Node *aux = new Node(0);
	Node *aux2 = new Node(0);
	aux = this->get_parent();
	aux2 = this->get_left();
	char tmp = this->get_color();
	if(this->get_left() != NULL){
		this->set_left(aux); // = aux;
		aux->set_right(aux2); //right = aux2;
		this->set_parent(aux->get_parent()); //parent = aux->parent;
		aux2->set_parent(aux); //parent = aux;
		aux->set_parent(this); //parent = this;
		this->set_color((this->get_left())->get_color());// = this->left->get_color();
		(this->get_left())->set_color(tmp); //this->left->get_color() = tmp;
	}else{
		this->set_left(aux); //left = aux;
		this->set_parent(aux->get_parent()); //parent = aux->parent;
		aux->set_parent(this);//parent = this;
		this->set_color(this->get_left()->get_color());//color = this->left->get_color();
		this->get_left()->set_color(tmp);//left->color = tmp;
	}
}

void Node::right_rotate(){
	Node *aux;
	Node *aux2;
	char tmp = this->get_color();
	aux = this->get_parent();
	aux2 = this->get_right();
	if(this->get_right() != NULL){
		if(aux->get_parent() == NULL) this->set_parent(NULL);
		else this->set_parent(aux->get_parent());
		aux->set_parent(this);
		this->set_right(aux);
		aux->set_left(aux2);
		aux2->set_parent(aux);
		this->set_color(aux->get_color());
		aux->set_color(tmp);
	}else{
		if(aux->get_parent() == NULL) this->set_parent(NULL);
		else this->set_parent(aux->get_parent());
		//cout << "this->parent: " << this->parent->key << endl;
		this->set_right(aux);
		cout << "this->right: " << this->right->key << endl;
		aux->set_parent(this);
		cout << "aux->parent: " << aux->parent->key << endl;
		this->set_color(aux->get_color());
		aux->set_color(tmp);
		cout << "left->parent: " << this->left->parent->key << endl;
	}
}
/*
void Node::right_rotate(){
	Node *aux = this->get_parent();
	Node *aux2 = this->get_right();
	char tmp = this->get_color();
	if(this->get_right() != NULL){
		this->set_right(aux);
		aux->set_left(aux2);
		this->set_parent(aux->get_parent());
		aux2->set_parent(aux);
		aux->set_parent(this);
		this->set_color(this->get_right()->get_color());
		this->get_right()->set_color(tmp);
	
		this->right = aux;
		aux->left = aux2;
		this->parent = aux->parent;
		aux2->parent = aux;
		aux->parent = this;
		this->color = this->right->color;
		this->right->color = tmp;
	}else{
		cout << "aux: " << aux->key << endl;
		this->set_right(aux);
		cout << "this->right: " << this->right->key << endl;
		if(aux->get_parent() == NULL) this->set_parent(NULL);
		else this->set_parent(aux->get_parent());
		cout << "this->parent: " << this->parent->key << endl;
		aux->set_parent(this);
		cout << "aux->parent: " << aux->parent->key << endl;
		this->set_color(this->get_right()->get_color());
		this->get_right()->set_color(tmp);
		
		this->right = aux;
		this->parent = aux->parent;
		aux->parent = this;
		this->color = this->right->color;
		this->right->color = tmp;
	}
}*/


void Node::inorder_walk(){
	if(this->get_left() != NULL)	this->get_left()->inorder_walk();
	cout << this->key << " ";
	if(this->get_right() != NULL)	this->get_right()->inorder_walk();
	
}

void Node::insert_node(Node *new_node){
	if(this->key < new_node->key){
		if(this->right == NULL){
			this->right = new_node;
			new_node->parent = this;
		}else{
			this->right->insert_node(new_node);
		}
	}else{
		if(this->left == NULL){
			this->left = new_node;
			new_node->parent = this;
		}else{
			this->left->insert_node(new_node);
		}
	}
}


