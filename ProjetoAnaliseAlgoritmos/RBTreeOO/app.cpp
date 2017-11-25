#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "Node.cpp"
using namespace std;


int main(){
	Node *root = NULL;
	Node *aux;
	Node *auxsearch;
	int op, key;
	bool flag = true;
	while(flag){
		cout << "\n\t1 - Insert node" << endl;
		cout << "\t2 - In order walk" << endl;
		cout << "\t3 - Search node" << endl;
		cout << "\t4 - Right rotate" << endl;
		cout << "\t0 - Exit" << endl;
		cout << "Option:";
		cin >> op;
		switch(op){
			case 1:
				aux = new Node(0);
				cout << "Provide an key: " ;
				cin >> aux->key;
				if(root == NULL) root = aux;
				else root->insert_node(aux);
				break;
			case 2:
				cout << "\nNodes: ";
				root->inorder_walk();
				cout << endl;
				break;
			default:
				cout << "Invalid option!" << endl;
				cout << "Please provide an valid option:";
				cin >> op;
			case 3:
				auxsearch = new Node(0);
				cout << "Provide a search key:";
				cin >> key;
				auxsearch = root->search_node(key);
				if(auxsearch != NULL) cout << "Found the node: " << auxsearch->get_key();
				else cout << "Node not found!" << endl;
				break;
			case 4:
				/*auxsearch = new Node(0);
				cout << "Rotate the node: ";
				cin >> key;
				auxsearch = root->search_node(key);
				auxsearch->right_rotate();*/
				root->get_left()->right_rotate();
				break;
			case 0:
				flag = false;
				break;
		}
	}
	return EXIT_SUCCESS;
}
