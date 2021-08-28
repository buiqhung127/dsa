#include<iostream>
using namespace std;
struct Node {
	int val;
	int key; 
	Node* left;
	Node* right;
};
struct BinarySearchTree {
	Node* root; 
};

Node* newNode(int key, int value) {
	Node *p = new Node; 
	p->key = key; // assign the key to the node
	p->val = value; // assign the value to the node
	p->left = nullptr; // become the leaf so 2 childs will be null
	p->right = nullptr; 
	return p; 
}
Node* insert(Node* p, int key, int value) {
	if (!p) // found an suitable spot
		p = newNode(key, value); // create new node and link to the tree
	else { // current node is already occupied
		if (value > p->val) // suitable spot must be on the right of this current node 
			p->right = insert(p->right, key, value);  // visit to the right (guarantee the properties)
		else // suitable spot must be on the left of this current node 
			p->left = insert(p->left, key, value); // visit to the left (guarantee the properties)
	}
	return p;
}
void traverse(Node* p) {
	if (p) { // if p is not null
		cout << p->val << "\t| Key : " << p->key << "\t|\t" ; // print the information
		if (p->left) cout <<"Left Child: " << p->left->val <<"\t"; // avoid to access an nullptr, if it is not null, print it
		if (p->right) cout <<"Right Child: " << p->right->val <<" "; // avoid to access an nullptr, if it is not null, print it
		cout << endl; 
		traverse(p->left); // recursive call to visit left node 
		traverse(p->right); // recursive call to visit right node
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
		if (p->val < val) { // if the value you want to deleted is larger than value of current node
			p->right = remove(p->right, val); // visit the right subtree to find
			return p; 
		}
		else if (p->val > val) { // if the value you want to deleted is smaller than value of current node
			p->left = remove(p->left, val); // visit the left subtree to find
			return p;
		} 
		// if the current value is the value you want to delete, this node is p
		else { 
			if (!p->right && !p->left) { // if p don't have any children, just delete it
				delete p; 
				p = nullptr; 
				return p; 
			}
			if (!p->right && p->left) { // if p has only left child, delete p then that position will be replaced by the left subtree
				Node* t = p->left;
				delete p; 
				p = nullptr; 
				return t; 
			} else 
			if (p->right && !p->left) { // if p has only right child, delete p then that position will be replaced by the right subtree
				Node* t = p->right;
				delete p;
				p = nullptr;
				return t;
			}
			else { // if p have 2 child, just replace the value by the predecessor's (maximum of smaller value) in that subtree
				Node* t = p->right;
				while (t->left)
					t = t->left; 
				p->val = t->val; 
				p->right = remove(p->right, p->val); // then delete the original node having maximum of smaller value
				return p; 
			}
		}
	} else // if the value does not exist
		return nullptr;  // do nothing
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