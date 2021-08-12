#include<iostream>
#define RED true 
#define BLACK false 
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
	p->color = RED; // all new node must be red
	p->key = k; 
	p->value = val; 
	p->parent = nullptr; 
	p->left = nullptr; 
	p->right = nullptr; 
	return p; 
}
bool getColor(nodeRB * p){
	if (!p)
		return BLACK ; 
	else 
		return p->color ; 
}
void assignColor(nodeRB* &p, bool color){
	if (p) 
		p->color = color ; 
}
int checkProb(nodeRB * p, nodeRB *&par, nodeRB *&sib) { // check null , p is grand parent
	if (getColor(p->left) == RED && getColor(p->left->left) == RED) { // left left
		par = p->left;
		sib = p->left->left;
		return 1;
	}
	if (getColor(p->left) == RED && getColor(p->left->right) == RED) { // left right
		par = p->left;
		sib = p->left->right;
		return 2;
	}
	if (getColor(p->right) == RED && getColor(p->right->right) == RED) { // right right
		par = p->right;
		sib = p->right->right;
		return 3;
	}
	if (getColor(p->right) == RED && getColor(p->right->left) == RED) { // right left
		par = p->right;
		sib = p->right->left;
		return 4;
	}
	//cout << "Do nothing !\n"; 
	return 0; // all right, sib and par will be nullptr 
}
nodeRB* leftRotation(nodeRB *sib, nodeRB *par, RedBlackTree &rb) {
	nodeRB* t = sib->left; 
	sib->left = par; 
	sib->parent = par->parent ; 
	par->parent = sib; 
	par->right = t;
	if (t)
		t->parent = par;
	if (rb.root == par) {
		rb.root = sib; 
 	}
	return sib; // return the new highest node, parent of this node is already changed inside this 
}
nodeRB* rightRotation(nodeRB* sib, nodeRB* par, RedBlackTree &rb) {
	nodeRB* t = sib->right;
	sib->right = par;
	sib->parent = par->parent ; 
	par->parent = sib;
	par->left = t;
	if (t)
		t->parent = par;
	if (rb.root == par) {
		rb.root = sib;
	}
	return sib; // return the new highest node
}
void swapColor(nodeRB* a, nodeRB* b) {
	bool c = getColor(a); 
	assignColor(a,getColor(b)); 
	assignColor(b,c) ; 
}
nodeRB* judgment(nodeRB* grandpar, RedBlackTree rb) { // check nullptr 
	nodeRB* par = nullptr;
	nodeRB* sib = nullptr;
	int sit = checkProb(grandpar, par, sib); // check the situation, par and sib is red
	if (getColor(grandpar->left) == RED && getColor(grandpar->right) == RED && sit != 0) { // uncle and parent are red
		assignColor(grandpar->left, BLACK);
		assignColor(grandpar->right, BLACK);
		assignColor(grandpar, RED);
		return grandpar;
	}
	// uncle is black
	if (sit == 1) { // left left
		swapColor(par, grandpar) ;
		return  rightRotation(par, grandpar, rb); 
	}
	else if (sit == 2) { // left right 
		grandpar->left = leftRotation(sib, par, rb);
		swapColor(grandpar, grandpar->left); 
		return rightRotation(grandpar->left, grandpar, rb); 
	}
	else if (sit == 3) { // right right
		swapColor(par, grandpar) ; 
		return  leftRotation(par, grandpar, rb);
	}
	else if (sit == 4) { // right left
		grandpar->right = rightRotation(sib, par, rb);
		swapColor(grandpar, grandpar->right);
		return leftRotation(grandpar->right, grandpar, rb);	
	} else  // if black red, do nothing
		return grandpar ; 
}
nodeRB* pushNode(nodeRB *p, nodeRB* t , RedBlackTree rb) {
	if (!p) {
		p = t; 
	}
	else {
		if (t->value > p->value) {
			p->right = pushNode(p->right, t, rb); // pass as a highest node 
			p->right->parent = p;
		}
		else {	
			p->left = pushNode(p->left, t, rb);
			p->left->parent = p; 
		}
		p = judgment(p, rb); 
	}
	return p; 
}
void initialize(RedBlackTree& RBTree) {
	RBTree.root = nullptr;
}
void traverse(nodeRB* p) {
	if (!p) return;
	traverse(p->left);
	cout << p->value << " : " << p->color << "\t|";
	if (p->left) cout << "Left : " << p->left->value << "\t|";
	if (p->right) cout << "Right : " << p->right->value << "\t|";
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
nodeRB* searchRB(nodeRB* p, int key) {
	if (!p)
		return nullptr; 
	if (p->value == key) {
		return p;
	}
	else if (p->value > key) {
		return searchRB(p->left, key);
	}
	else
		return searchRB(p->right, key); 
}
void update(nodeRB *grandpar, bool isGrandparLeft) {
	if (grandpar->parent && isGrandparLeft) {
		grandpar->parent->left = grandpar;
	}
	else if (grandpar->parent && !isGrandparLeft) {
		grandpar->parent->right = grandpar;
	}
}
void fixDoubleBlack(nodeRB* &grandpar, bool isLeft, RedBlackTree &rb) {
	if (!grandpar)
		return; 
	bool isGrandparLeft = (grandpar->parent && grandpar->parent->left == grandpar) ? true : false; 
	nodeRB *uncle = (isLeft) ? grandpar->right : grandpar->left;
	if (!uncle) {
		return;
	}
	if (getColor(uncle) == BLACK) {
		if (isLeft) {
			if (getColor(uncle->right) == RED) { // right right 
				assignColor(uncle->right, BLACK);
				swapColor(uncle, grandpar); 
				//cout << uncle->value << " " << grandpar->value << endl; 
				grandpar = leftRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft); 
				traverse(rb.root); 
				cout << rb.root; 
				cout << "HERE 1\n" ; 
				// cout << grandpar->value << " " << grandpar->left->value << " " <<grandpar->right->value << " " << grandpar->parent->value <<endl;
				// cout << grandpar->parent->left->value << " " << grandpar->parent->right->value << endl; 

			}
			else if (getColor(uncle->left) == RED) { // right left
				assignColor(uncle->left, BLACK);
				uncle = rightRotation(uncle->left, uncle, rb);
				swapColor(uncle, grandpar);
				grandpar = leftRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft);
				cout << "HERE 1.2\n";
			}
			else { // all children of uncle is black
				assignColor(uncle, RED); // jump fix later, need mark the double black for grandpar here
				if (getColor(grandpar) == BLACK) {
					// become double black
					update(grandpar, isGrandparLeft);
					fixDoubleBlack(grandpar->parent, isGrandparLeft , rb); 
				}
				else {
					assignColor(grandpar, BLACK); 
				}
				cout << "HERE 1.3\n";
			}
		}
		else {
			if (getColor(uncle->left) == RED) { // left left
				assignColor(uncle->left, BLACK);
				swapColor(uncle, grandpar);
				grandpar = rightRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft);
				cout << "HERE 1.4\n";
			}
			else if (getColor(uncle->right) == RED) { // left right
				assignColor(uncle->right, BLACK);
				uncle = leftRotation(uncle->right, uncle, rb);
				swapColor(uncle, grandpar);
				grandpar = rightRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft);
				cout << "HERE 1.5\n";
			} 
			else { // black black in all children of uncle
				assignColor(uncle, RED); 
				if (getColor(grandpar) == BLACK) {
					// become double black
					update(grandpar, isGrandparLeft);
					fixDoubleBlack(grandpar->parent,  isGrandparLeft, rb);

				}
				else {
					assignColor(grandpar, BLACK);
				}
				cout << "HERE 1.6\n";
			}
		}
	}
	else { // uncle red
		if (isLeft) {
			swapColor(uncle, grandpar); 
			grandpar = leftRotation(uncle, grandpar, rb); // need mark the black
			update(grandpar, isGrandparLeft);
			fixDoubleBlack(grandpar->left,  true, rb); 
		}
		else {
			swapColor(uncle, grandpar);
			grandpar = rightRotation(uncle, grandpar, rb); // need mark the black
			update(grandpar, isGrandparLeft);
			fixDoubleBlack(grandpar->right, false, rb);

		}
	}
	//update(grandpar, isGrandparLeft);
	traverse(rb.root); 
	cout << "HERE 2\n";
	// cout <<grandpar->parent->value <<" " << grandpar->parent->left->value << " " << grandpar->parent->right->value << endl;
	// cout << grandpar->left->value << " " << grandpar->right->value << endl; 
	// traverse(rb.root);
}
void deleteNodeRB(nodeRB*& p, int x, RedBlackTree& rb) { // p : parent, which is kept
	if (!p)
		return ;
	if (p->value < x)
		deleteNodeRB(p->right, x, rb);
	else if (p->value > x)
		deleteNodeRB(p->left, x, rb);
	else { // 1 child
		if (p->left && !p->right) {
			if (getColor(p->left) == RED || getColor(p) == RED) { // parent and sib are not red at the same time
				p->value = p->left->value;
				assignColor(p, BLACK); 
				delete p->left;
				p->left = nullptr;
			}
			else { // parent and children are black
				nodeRB* par = p->parent; //p will be delete
				bool isLeft = (par->left == p) ? true : false; // p become double black
				p->value = p->left->value;
				assignColor(p, BLACK);
				delete p->left;
				p->left = nullptr;
				fixDoubleBlack(par, isLeft, rb);
			}
		}
		else if (!p->left && p->right) {
			if (getColor(p->right) == RED || getColor(p) == RED) { // parent and sib are not red at the same time
				p->value = p->right->value;
				assignColor(p, BLACK);
				delete p->right;
				p->right = nullptr;
			}
			else { // parent and children are black
				nodeRB* par = p->parent; //p will be delete
				bool isLeft = (par->left == p) ? true : false; // p become double black
				p->value = p->right->value;
				assignColor(p, BLACK);
				delete p->right;
				p->right = nullptr;
				fixDoubleBlack(par, isLeft, rb);
			}
		}
		else if (!p->left && !p->right) { // 2 child black null
			if (p->color == RED || p == rb.root) {
				delete p;
				p = nullptr; 
				return;
			}
			else {
				nodeRB* par = p->parent; //p will be delete
				bool isLeft = (par->left == p) ? true : false; // p become double black
				//assignColor((isLeft) ? par->right : par->left, RED);
				delete p;
				p = nullptr; // p become nullptr
				traverse(rb.root);
				cout << "\nfast check \n";  
				//if (getColor(par) == BLACK) {
					// become double black
					fixDoubleBlack(par, isLeft, rb);
					cout << "HERE 4\n";
				//}
				//else { // parent red
				//	assignColor(par, BLACK);
				//}
			}
		}
		else if (p->left && p->right) {
			nodeRB* t = p->left;
			while (t->right)
				t = t->right;
			p->value = t->value;
			deleteNodeRB(p->left, p->value, rb);
		}
	}
	return; 
}
bool isTreeEmpty(RedBlackTree rb) {
	if (!rb.root)
		return true;
	else
		return false; 
}
int main() {
	RedBlackTree RBTree; 
	initialize(RBTree); 
	int n, x;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> x;
		nodeRB *p = newNode(i, x); 
		RBTree.root = pushNode(RBTree.root, p, RBTree);
		assignColor(RBTree.root, BLACK) ;
		//cout << "\n------------------------------------------------------------------\n";
		//cout << x << endl; 
		//traverse(RBTree.root); 
	}
	//cin >> x; 
	//nodeRB* p = searchRB(RBTree.root, x); 
	//cout << p->key << endl; 
	cout << "\n---------------------End the Input------------------------------------\n";
	//traverse(RBTree.root);
	while (true) {
		cin >> x;
		if (!searchRB(RBTree.root, x)) {
			cout << "Not found\n"; 
			continue; 
		}
		/*RBTree.root = */ deleteNodeRB(RBTree.root, x, RBTree);
		if (isTreeEmpty(RBTree)) {
			cout << "This tree is empty now \n"; 
			break; 
		} 
		else 
			traverse(RBTree.root);
		cout << RBTree.root;
		cout << "\n------------------------------------------------------------------\n";
	}
	// 8 
	// 80 70 90 75 95 98 93 20
	// 90 95 80 70 75 98 93 20
	// 20 70 75 80 90 93 95 98

	// 19
	// 50 30 80 70 90 75 95 98 93 20 72 78 76 60 55 57 58 73 71
	destroyTree(RBTree.root); 
	return 0; 
}