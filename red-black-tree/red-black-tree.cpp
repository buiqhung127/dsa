#include<iostream>
#define RED true // simplify the code
#define BLACK false // simpify the code
using namespace std; 
struct nodeRB { // a little bit different to the node of binary search tree
	int key; // data
	int value;  //data
	bool color; // red : 1, black : 0 
	nodeRB* parent; // for simplicity, we need member that point out the parent of the current node
	nodeRB* left; // store the adress of left child, null if this node does not has left child. 
	nodeRB* right; // store the adress of right child, null if this node does not has right child. 
};
struct RedBlackTree {
	nodeRB* root; // we must store the address of the root.
};
void initialize(RedBlackTree& RBTree) {
	RBTree.root = nullptr; // null root means the tree is now empty.
}
nodeRB* newNode(int k, int val) {
	nodeRB* p = new nodeRB; 
	p->color = RED; // all new node must be red
	p->key = k; // store the data
	p->value = val; // store the data
	// the node created recently has not have connection to another one yet so all the member below is null.
	p->parent = nullptr; 
	p->left = nullptr; 
	p->right = nullptr; 
	return p; 
}
nodeRB* pushNode(nodeRB *p, nodeRB* t , RedBlackTree rb) {
	if (!p) { // find a leaf with a corrected spot to assign the new node ( nodeRB *t )
		p = t; 
	}
	else { // this current node is already occupied
		if (t->value > p->value) { // the potential spot for node t is on the right of p
			p->right = pushNode(p->right, t, rb); // pass as a highest node , visit the right node of p  
			p->right->parent = p; // after pushing, re-mark the parent of p child is p
		}
		else {	 // the potential spot for node t is on the left of p
			p->left = pushNode(p->left, t, rb); // pass as a highest node , visit the left node of p  
			p->left->parent = p; // after pushing, re-mark the parent of p child is p
		}
		p = judgment(p, rb); // adjust the tree if there is an conflict to the red black tree properties
	}
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
	// check if the parent of the red node is red. If it is, get the position case and the address of 2 consecutive red node.
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
	return 0; // all right (no conflict is found), sib and par will be nullptr 
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
nodeRB* judgment(nodeRB* grandpar, RedBlackTree rb) { // handle the conflict when insert
	nodeRB* par = nullptr;
	nodeRB* sib = nullptr;
	int sit = checkProb(grandpar, par, sib); // check the situation, par and sib is red and now they having the adress of 2 red nodes 
	if (getColor(grandpar->left) == RED && getColor(grandpar->right) == RED && sit != 0) { // uncle and parent are red
		assignColor(grandpar->left, BLACK); // make the parent and uncle to be black
		assignColor(grandpar->right, BLACK); // make the parent and uncle to be black
		assignColor(grandpar, RED); // make the grandparent to be red
		return grandpar; // go to the grand parent later
	}
	// uncle is black
	if (sit == 1) { // left left
		swapColor(par, grandpar) ; // swap color parent and grandparent
		return  rightRotation(par, grandpar, rb); // then right rotate grandparent and parent
	}
	else if (sit == 2) { // left right 
		grandpar->left = leftRotation(sib, par, rb); // left rotate to become situation 1 
		swapColor(grandpar, grandpar->left); // do the same to situation 1, swap the color 
		return rightRotation(grandpar->left, grandpar, rb);  // then right rotation
	}
	else if (sit == 3) { // right right
		swapColor(par, grandpar) ; // swap color parent and grandparent
		return  leftRotation(par, grandpar, rb); // then left rotate grandparent and parent
	}
	else if (sit == 4) { // right left
		grandpar->right = rightRotation(sib, par, rb);// right rotate to become situation 3 
		swapColor(grandpar, grandpar->right); // do the same to situation 3, first we swap the color 
		return leftRotation(grandpar->right, grandpar, rb);	// then left rotation
	} else  // if black red, do nothing
		return grandpar ; 
}


void traverse(nodeRB* p) { // inorder traverse
	if (!p) return; // avoid acessing a null pointer
	traverse(p->left); // go to the left subtree
	cout << p->value << " : " << p->color << "\t|"; // print out the value and the color
	if (p->left) cout << "Left : " << p->left->value << "\t|"; // print out the value of the left node
	if (p->right) cout << "Right : " << p->right->value << "\t|"; // print out the value of the right node
	cout << endl;
	traverse(p->right); // go to the right subtree
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
	if (!p) // p having key does not exist
		return nullptr;  // return null
	if (p->value == key) { // a node with the key that we want to find exists
		return p; // return that node
	}
	else if (p->value > key) { // current node's value is larger than the key
		return searchRB(p->left, key); // the node we want to find, is in the left sub tree of this current node, or does not exist
	}
	else // current node's value is smaller than the key
		return searchRB(p->right, key); // the node we want to find, is in the right sub tree of this current node, or does not exist
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
	bool isGrandparLeft = (grandpar->parent && grandpar->parent->left == grandpar) ? true : false; // check the grandparent is left child
	// or right child
	nodeRB *uncle = (isLeft) ? grandpar->right : grandpar->left; // dertermine the uncle
	if (!uncle) { // if the uncle is nil, just get out the function
		return;
	} // now the uncle is not nil
	if (getColor(uncle) == BLACK) { // if the uncle is black and 
		if (isLeft) { // determine the position
			if (getColor(uncle->right) == RED) { // uncle right uncle 's red child right  
				assignColor(uncle->right, BLACK); // make the considering child of uncle red
				swapColor(uncle, grandpar);  // swap the color between uncle and grandpar
				grandpar = leftRotation(uncle, grandpar, rb); // left rotatation 
				update(grandpar, isGrandparLeft);  // 
			}
			else if (getColor(uncle->left) == RED) { // right left
				assignColor(uncle->left, BLACK);
				uncle = rightRotation(uncle->left, uncle, rb);
				swapColor(uncle, grandpar);
				grandpar = leftRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft);
			}
			else { // all children of uncle is black
				assignColor(uncle, RED); // make the uncle to be red
				if (getColor(grandpar) == BLACK) { // grandpar is black
					// become double black
					update(grandpar, isGrandparLeft); // update the parent of grandparent
					fixDoubleBlack(grandpar->parent, isGrandparLeft , rb); // fix the double black of the granparent
				}
				else { // grandparent is red
					assignColor(grandpar, BLACK); // red + black => black, make the grandparent to be black 
				}
			}
		}
		else {
			if (getColor(uncle->left) == RED) { // left left
				assignColor(uncle->left, BLACK);
				swapColor(uncle, grandpar);
				grandpar = rightRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft);
			}
			else if (getColor(uncle->right) == RED) { // left right
				assignColor(uncle->right, BLACK);
				uncle = leftRotation(uncle->right, uncle, rb);
				swapColor(uncle, grandpar);
				grandpar = rightRotation(uncle, grandpar, rb);
				update(grandpar, isGrandparLeft);
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
			}
		}
	}
	else { // uncle red
		if (isLeft) { // mean uncle is right
			swapColor(uncle, grandpar); // swap color between uncle and grandpar 
			grandpar = leftRotation(uncle, grandpar, rb); // need mark the black, left rotate the uncle and grandpararent
			update(grandpar, isGrandparLeft); // update the parent of grandparent
			fixDoubleBlack(grandpar->left,  true, rb);  // fix the double black after rotate
		}
		else { // uncle is left
			swapColor(uncle, grandpar); // swap color between uncle and grandpar 
			grandpar = rightRotation(uncle, grandpar, rb); // need mark the black, right rotate the uncle and grandpararent
			update(grandpar, isGrandparLeft);
			fixDoubleBlack(grandpar->right, false, rb);// fix the double black after rotate
		}
	}
}
void deleteNodeRB(nodeRB*& p, int x, RedBlackTree& rb) { // p : parent, which is kept
	if (!p) // if reach the nil node, terminate the function
		return ;
	if (p->value < x)  // current node's value is smaller than the key
		deleteNodeRB(p->right, x, rb); // the node we want to find, is in the right sub tree of this current node, or does not exist
	else if (p->value > x)  // current node's value is larger than the key
		deleteNodeRB(p->left, x, rb); // the node we want to find, is in the left sub tree of this current node, or does not exist
	else { 
		// 1 child
		if (p->left && !p->right) { // have only left child
			if (getColor(p->left) == RED || getColor(p) == RED) { // parent and child are not red at the same time, either parent or child
			// is red
				p->value = p->left->value; // delete p then, replace by the child. Assign the color of p to be black
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
				fixDoubleBlack(par, isLeft, rb); // fix the double black 
			}
		}
		else if (!p->left && p->right) { // have only right child
			if (getColor(p->right) == RED || getColor(p) == RED) {  // parent and child are not red at the same time, either parent or child
				p->value = p->right->value; // delete p then, replace by the child . Assign the color of p to be black
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
				fixDoubleBlack(par, isLeft, rb); // fix the double black 
			}
		}
		else if (!p->left && !p->right) { // 2 child are nils
			if (p->color == RED || p == rb.root) { // if color of p is red or p is the root, just delete p, mark it as a nil node.
				delete p;
				p = nullptr; 
				return;
			}
			else { // p's color is black
				nodeRB* par = p->parent; //p will be delete
				bool isLeft = (par->left == p) ? true : false; // p become double black
				delete p;
				p = nullptr; // p become nullptr
				fixDoubleBlack(par, isLeft, rb); // fix the double black 
			}
		}
		else if (p->left && p->right) { //have 2 child is not nils
			nodeRB* t = p->left; 
			while (t->right)
				t = t->right;
			p->value = t->value; // replace the value by the predecessor then delete that original predecessor
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
		cin >> x; // read the value
		nodeRB *p = newNode(i, x); // create the new node by the index and the value
		RBTree.root = pushNode(RBTree.root, p, RBTree); // push the node into tree
		assignColor(RBTree.root, BLACK) ; // keep the root always black
	}
	traverse(RBTree.root); 
	cout << "\n---------------------End the Input------------------------------------\n";
	while (true) {
		cin >> x;
		if (!searchRB(RBTree.root, x)) {
			cout << "Not found\n"; 
			continue; 
		}
		deleteNodeRB(RBTree.root, x, RBTree);
		if (isTreeEmpty(RBTree)) {
			cout << "This tree is empty now \n"; 
			break; 
		} 
		else 
			traverse(RBTree.root);
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