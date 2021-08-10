#include<iostream>
using namespace std;
struct Node {
	int val;
	int key; // be used to check
	Node* left;
	Node* right;
};
struct BinarySearchTree {
	Node* root; 
};

Node* newNode(int key, int value) {
	Node *p = new Node; 
	p->key = key; 
	p->val = value; 
	p->left = nullptr;
	p->right = nullptr; 
	return p; 
}
Node* insert(Node* p, int key, int value) {
	if (!p) 
		p = newNode(key, value); 
	else {
		if (value > p->val)
			p->right = insert(p->right, key, value); 
		else 
			p->left = insert(p->left, key, value); 
	}
	return p;
}
void traverse(Node* p) {
	if (p) {
		cout << p->val << "\t| Key : " << p->key << "\t|\t" ;
		if (p->left) cout <<"Left Child: " << p->left->val <<"\t";
		if (p->right) cout <<"Right Child: " << p->right->val <<" ";
		cout << endl; 
		traverse(p->left); 
		traverse(p->right); 
	}
}
void destroyTree(Node* &p) {
	if (p) {
		if (p->left) destroyTree(p->left); 
		if (p->right) destroyTree(p->right);
		delete p; 
		p = nullptr; 
	}
}
Node* search(Node *p, int val) {
	if (!p)
		return nullptr; 
	if (p->val == val)
		return p;
	else 
	if (p->val > val)
		return search(p->left, val);
	else
		return search(p->right, val); 
}
Node* remove(Node* p, int val) {
	if (p) {
		//cout << "C0"; 
		if (p->val < val) {
			p->right = remove(p->right, val);
			return p; 
		}
		else if (p->val > val) {
			p->left = remove(p->left, val);
			return p;
		}
		else { 
			//cout << "C1"; 
			if (!p->right && !p->left) {
				delete p; 
				p = nullptr; 
				return p; 
			}
			if (!p->right && p->left) {
				//cout << "CL";
				Node* t = p->left;
				delete p; 
				p = nullptr; 
				return t; 
			} else 
			if (p->right && !p->left) {
				//cout << "CR";
				Node* t = p->right;
				delete p;
				p = nullptr;
				return t;
			}
			else {
				Node* t = p->right;
				while (t->left)
					t = t->left; 
				p->val = t->val; 
				p->right = remove(p->right, p->val); 
				return p; 
			}
		}
	} else
		return nullptr; 
}
void initialize(BinarySearchTree &bst) {
	bst.root = nullptr; 
}
bool isEmpty(BinarySearchTree bst) {
	return (!bst.root) ? true : false; 
}
int main() {
	int n, x; 
	BinarySearchTree bst;
	initialize(bst); 
	cin >> n; 
	for (int i = 0 ; i < n ; i++){
		cin >> x; 
		bst.root = insert(bst.root, i, x); 
	}
	traverse(bst.root); 
	cout << "\n----------------\nEnter the number that you want to find:\n>>";
	cin >> x; 
	Node *t = search(bst.root, x); 
	if (t)
		cout << t->key<<" " <<t->val;
	else
		cout << "Not found!"; 
	cout << "\n----------------\nEnter the number that you want to delete:\n>>"; 
	cin >> x; 
	bst.root = remove(bst.root, x); 
	traverse(bst.root); 
	cout << endl; 
	destroyTree(bst.root); 
	//7
	//53 26 22 51 75 98 80
	return 0; 
}