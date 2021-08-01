#include<iostream>
using namespace std; 
struct nodeRB {
	int key; 
	int value; 
	bool color; // red : 1, black : 0 
	nodeRB* parent; 
	nodeRB* left;
	nodeRB* right; 
};
struct RedBlackTree {
	nodeRB* root;
};
nodeRB* newNode(int k, int val) {
	nodeRB* p = new nodeRB; 
	p->color = true; 
	p->key = k; 
	p->value = val; 
	p->parent = nullptr; 
	p->left = nullptr; 
	p->right = nullptr; 
	return p; 
}
int checkProb(nodeRB * p, nodeRB *&par, nodeRB *&sib) { // check null 

	if (p->left->color && p->left->left->color) { // left left
		par = p->left;
		sib = p->left->left;
		return 1;
	}
	if (p->left->color && p->left->right->color) { // left right
		par = p->left;
		sib = p->left->right;
		return 2;
	}
	if (p->right->color && p->right->right->color) { // right right
		par = p->right;
		sib = p->right->right;
		return 3;
	}
	if (p->right->color && p->right->left->color) { // right left
		par = p->right;
		sib = p->right->left;
		return 4;
	}

	return 0; 
}
nodeRB* leftRotation(nodeRB *sib, nodeRB *par) {
	sib->left = par; 
	par->parent = sib; 
	par->right = sib->left; 
	sib->left->parent = par; 
	return sib; 
}
nodeRB* rightRotation(nodeRB* sib, nodeRB* par) {
	sib->right = par;
	par->parent = sib;
	par->left = sib->right;
	sib->right->parent = par;
	return sib;
}
void swapColor(nodeRB* a, nodeRB* b) {
	bool c = a->color; 
	a->color = b->color; 
	b->color = c; 
}
nodeRB* judgment(nodeRB* grandpar) { // check nullptr 
	if (!grandpar || grandpar->key == -1)
		return grandpar;
	nodeRB* par = nullptr;
	nodeRB* sib = nullptr;
	if (grandpar->left->color && grandpar->right->color) {
		grandpar->left->color = grandpar->right->color = false; 
		grandpar->color = true; 
		if (grandpar->parent)
			grandpar->parent->parent = judgment(grandpar->parent->parent);
		return grandpar; 
	} 
	int sit = checkProb(grandpar, par, sib);
	if (sit == 1) {
		return  rightRotation(sib, par);
	}
	else if (sit == 2) {
		sib->left = rightRotation(sib, par);
		sib->left->parent = sib;
		swapColor(grandpar, grandpar->right); 
		return leftRotation(sib, grandpar); 
	}
	else if (sit == 3) {
		return  leftRotation(sib, par);
	}
	else if (sit == 4) {
		sib->right = leftRotation(sib, par);
		sib->right->parent = sib;
		swapColor(grandpar, grandpar->left);
		return rightRotation(sib, grandpar);
	}
}
nodeRB* pushNode(nodeRB *p, int k, int val) {
	if (!p || p->key == -1) {
		p = newNode(k, val);
		p->left = newNode(-1, -1); 
		p->right = newNode(-1, -1); 
	}
	else {

		if (k > p->value) {
			p->right = pushNode(p->right, k, val);
			p->right->parent = p;
		}
		else {
			p->left = pushNode(p->left, k, val);
			p->left->parent = p;
		}
		return judgment(p); 
	}
	return p; 
}
void initialize(RedBlackTree& RBTree) {
	RBTree.root = nullptr;
}
void traverse(nodeRB* p) {
	if (!p || (!p->left && !p->right)) return;
	traverse(p->left);
	cout << p->value << ":" << p->color << " ";
	if (p->left) cout << p->left->value << " ";
	if (p->right) cout << p->right->value << " ";
	cout << endl;
	traverse(p->right);
}
void destroyTree(nodeRB*& p) {
	if (p) {
		if (p->left) destroyTree(p->left);
		if (p->right) destroyTree(p->right);
		delete p;
		p = nullptr;
	}
}
int main() {
	RedBlackTree RBTree; 
	initialize(RBTree); 
	int n,x; 
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> x;
		RBTree.root = pushNode(RBTree.root, i, x); 
		RBTree.root->color = false; 
	}
	traverse(RBTree.root);

	// 19
	// 50 30 80 70 90 75 95 98 93 20 72 78 76 60 55 57 58 73 71
	destroyTree(RBTree.root); 
	return 0; 
}