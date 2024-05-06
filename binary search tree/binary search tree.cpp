// binary search tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
* insert 
* search 
*delete
* access
* root
* depth
* height
* edges
* leaf 
* siblings
* parent
* child
* ancestor
*/
#include<iostream>
# include<queue>
using namespace std;
class BinaryTree {
	struct node {
		int value;
		node* left;
		node* right;
		node(int val) {
			value = val;
			right =left= NULL;
		}
	};
	node* root = NULL;
	int depth = 0;
	void insert_rec(node* ptr, int val) {
		if(val <= ptr->value){
			if (ptr->left == NULL) {
				node* newele = new node(val);
				ptr->left = newele;
			}
				
			else
				insert_rec(ptr->left, val);
		}
		else {
			if (ptr->right == NULL) {
				node* newele = new node(val);
				ptr->right = newele;
			}
				
			else
				insert_rec(ptr->right, val);
		}
		
	}
	int get_max_helper(node*ptr) {
		if (ptr->right == NULL) {
			return ptr->value;
		}
		else
			return get_max_helper(ptr->right);
	}
	int get_min_helper(node* ptr) {
		if (ptr->left == NULL) {
			return ptr->value;
		}
		else
			return get_min_helper(ptr->left);
	}
	bool search(node* ptr, int val) {
		if (val <= ptr->value) {
			if (val == ptr->value) return true;
			else if (ptr->left == NULL) return false;
			return search(ptr->left, val);
		}
		else {
			if (val == ptr->value) return true;
			else if (ptr->right == NULL) return false;
			return search(ptr->right, val);
		}
		
		

	}
	int getdepth(node* ptr, int val) {
		if (isempty())return -1;
		if (val <= ptr->value) {
			if (val == ptr->value) {
				return depth;
			}
			else {
				depth++;
				return getdepth(ptr->left, val);
			}
		   }
		else {
			if (val == ptr->value) {
				return depth;
			}
			else if (ptr->right == NULL) return -1;
			else {
				depth++;
				return getdepth(ptr->right, val);
			}
		}
		}
	int getheight(node* ptr) {
		if (ptr == NULL)return -1;
		int left_subtree = getheight(ptr->left);
		int right_subtree = getheight(ptr->right);
		return 1 + max(left_subtree, right_subtree);
	} 
	void bfshelper(node* ptr) {
		if (ptr == NULL) return;
		queue <node*> container;
		container.push(ptr);
		while (!container.empty()) {
			node* cur = container.front();
			cout << cur->value << " ";
			if (cur->left != NULL)
				container.push(cur->left);
			if (cur->right != NULL)
				container.push(cur->right);
			container.pop();
		}

	}
	node* removehelper(node* root, int data) {
		if (root == NULL) return root;
		else if (data < root->value)
			root->left = removehelper(root->left, data);
		else if (data > root->value)
			root->right = removehelper(root->right, data);
		else 
		{
			if (root->left == NULL)
			{
				node* tmp = root->right;
				delete root;
				return tmp;
		    }
			else if (root->right == NULL) {
				node* tmp = root->left;
				delete root;
				return tmp;
			}
			else {
				int maxvalue = this->get_max_helper(root->left);
				root->value = maxvalue;
				root->left = removehelper(root->left, maxvalue);
			}
		}
		return root;
	}
public:
	bool isempty() {
		return root == NULL;
	}
	void insert_iter(int val) {
		
		node* newele = new node(val);
		if (root == NULL) {
			root = newele;
		}
		else {
			node* tmp = root;
			node* ptr = NULL;
			while (tmp!=NULL){
			if (val <= tmp->value) {
				ptr = tmp;
				tmp = tmp->left;
			}
			else {
				ptr = tmp;
				tmp = tmp->right;
			}
			}
			if (val <= ptr->value) {
				ptr->left = newele;
		   }
			else {
				ptr->right = newele;
			}
		}
	 }
	void insert_rec(int val) {
		if (root == NULL) {
			node* newele = new node(val);
			root = newele;
		}
		else {
			insert_rec(root, val);
		}
	}
	void get_max() {
		node* tmp = root;
		while (tmp->right != NULL) {
			tmp = tmp->right;
		}
		cout << " the max value is : " << tmp->value<<endl;
	}
	void get_min() {
		node* tmp = root;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		cout << " the min value is : " << tmp->value << endl;
	}
	int max_rec() {
		return get_max_helper(root);
	}
	int min_rec() {
		return get_min_helper(root);
	}
	bool search(int val) {
		return search(root, val);
	}
	int getdepth(int val) {
		return getdepth(root, val);
	}
	int getheight() {
		return getheight(root);
	}
	void bfs() {
		bfshelper(root);
	}
	void remove(int val) {
		root = removehelper(root, val);
	}
	
 };
int main() {
	BinaryTree list;
	list.insert_rec(100);
	list.insert_rec(80);
	list.insert_rec(120);
	list.insert_rec(70);
	list.insert_rec(90);
	list.insert_rec(400);
	list.insert_rec(500);
	list.insert_rec(600);
	list.insert_rec(700);
	list.get_max();
	list.get_min();
	list.max_rec();
	list.min_rec();
	cout << "------------------------------\n";
	cout<<list.search(100)<<endl;
	cout<<list.search(80) <<endl ;
	cout<<list.search(120)<<endl  ;
	cout<<list.search(70) <<endl ;
	cout<<list.search(90) <<endl ;
	cout<<list.search(40) <<endl ;
	cout << "---------------------------\n";
	cout << "the height of tree is : " << list.getheight()<<endl;
	cout << " the depth of  700 : " << list.getdepth(700);
	cout << "\n-------------------------------------\n";
	list.bfs();
	

}

