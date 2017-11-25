#ifndef NodeH
#define NodeH
#include <iostream>
#include <cstdlib>

class Node{
	public:
		Node *right;
		Node *left;
		Node *parent;
		int key;
	protected:
		char color;
	public:
		Node(int _key){ 
			key = _key;
			left = NULL;
			right = NULL;
			parent = NULL; 
			color = 'R';
		 }
		void left_rotate();
		void right_rotate();
		void left_right_rotate();
		void right_left_rotate();
		void fix_up();
		void set_right(Node *no_right){this->right = no_right;}
		void set_left(Node *no_left){this->left = no_left;}
		void set_parent(Node *no_parent){this->parent = no_parent;}
		void set_color(char _col){
			this->color = _col;
		}
		void change_color(){
			if(this->color == 'R') this->set_color('B');
			else this->set_color('R');
		}
		void insert_node(Node *new_node);
		void exclude_node(Node *no);
		void inorder_walk();
		int get_key(){return this->key;}
		char get_color(){ return this->color; }
		Node *get_right(){ return this->right;}
		Node *get_left() { return this->left;}
		Node *get_parent(){ return this->parent;}
		Node *search_node(int chave);
		Node *get_node(){return this;}
};

#endif
