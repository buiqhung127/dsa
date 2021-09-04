// wild implementation
#include<iostream>
using namespace std; 
struct Node {
	int value; 
	int weight; 
	Node* lChild; 
	Node* rChild; 
};
struct AVLTree {
	Node* root; 
};
int max(int& a, int& b) {
	return (a > b) ? a : b; 
}
Node* newNode(int val){
	Node *p = new Node; 
	p->lChild = nullptr; 
	p->rChild = nullptr; 
	p->weight = 1; 
	p->value = val; 
	return p; 
}

int getWeight(Node *p) {
	if (!p)
		return 0;
	else
		return p->weight; 
}


Node* rightRotate(Node* p) {
	Node* pivot = p->lChild; 

	p->lChild = pivot->rChild;
	pivot->rChild = p; 

	p->weight = 1 + max(getWeight(p->lChild), getWeight(p->rChild));
	pivot->weight = 1 + max(getWeight(pivot->lChild), getWeight(pivot->rChild));

	return pivot; 
}
Node* leftRotate(Node *p) {
	Node* pivot = p->rChild; 

	p->rChild = pivot->lChild;
	pivot->lChild = p;

	p->weight = 1 + max(getWeight(p->lChild), getWeight(p->rChild)); 
	pivot->weight = 1 + max(getWeight(pivot->lChild), getWeight(pivot->rChild));
	return pivot; 
}
Node* checkAndRotate(Node *p) {
	if (getWeight(p->lChild) > 1 + getWeight(p->rChild)) { // Left
		if (getWeight(p->lChild->lChild) > getWeight(p->lChild->rChild)) // Left
			return rightRotate(p);
		else {  // right
			p->lChild = leftRotate(p->lChild);
			return rightRotate(p); 
		}
	}
	else if (getWeight(p->lChild) + 1 < getWeight(p->rChild)) { //Right
		if (getWeight(p->rChild->lChild) > getWeight(p->rChild->rChild)) {// Left
			p->rChild = rightRotate(p->rChild);
			return leftRotate(p);
		}
		else // right
			return leftRotate(p); 
	}
	return p; 
}

Node* pushNode(Node* &pos, int x) {
	if (!pos) {
		pos = newNode(x);
		return pos;
	}
	if (x > pos->value)
		pos->rChild = pushNode(pos->rChild, x);
	else if (x < pos->value)
		pos->lChild = pushNode(pos->lChild, x);
	else
		return pos; 
	pos->weight = 1 + max(getWeight(pos->lChild), getWeight(pos->rChild));
	
	return checkAndRotate(pos); 
	
}
void traverse(Node *p) {
	if (!p) return; 
	traverse(p->lChild); 
	cout << p->value <<":" <<p->weight <<" " ;
	if (p->lChild) cout << p->lChild->value << " ";
	if (p->rChild) cout << p->rChild->value << " ";
	cout << endl; 
	traverse(p->rChild);
}
void destroyTree(Node*& p) {
	if (p) {
		if (p->lChild) destroyTree(p->lChild);
		if (p->rChild) destroyTree(p->rChild);
		delete p;
		p = nullptr;
	}
}
Node* deleteNodeAVL(Node* p, int key) {
	if (!p)
		return p;
	else {
		if (p->value > key) {
			p->lChild = deleteNodeAVL(p->lChild, key);
			p->weight = 1 + max(getWeight(p->lChild), getWeight(p->rChild));
			return checkAndRotate(p); // check rotate everywhere
		}
		else if (p->value < key) {
			p->rChild = deleteNodeAVL(p->rChild, key);
			p->weight = 1 + max(getWeight(p->lChild), getWeight(p->rChild));
			return checkAndRotate(p);
		}
		else {
			if (!p->lChild && !p->rChild) {
				delete p;
				return nullptr;
			}
			else if (!p->lChild && p->rChild) {
				Node* t = p->rChild;
				delete p;
				p = nullptr;
				return t;
			}
			else if (p->lChild && !p->rChild) {
				Node* t = p->lChild;
				delete p;
				p = nullptr;
				return t;
			}
			else {
				Node* t = p->lChild;
				while (t->rChild) // get the predecessor, place it to the delete cell then delete the old one 
					t = t->rChild;
				p->value = t->value;
				p->lChild = deleteNodeAVL(p->lChild, p->value); 
				p->weight = 1 + max(getWeight(p->lChild), getWeight(p->rChild));
				return checkAndRotate(p); // is same to the binary tree delete but the calculation about 2 side weight and adjust 
			}
		}
	}

}
int main() {
	int n, x; 
	AVLTree avl; 
	avl.root = nullptr; 
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> x; 
		avl.root = pushNode(avl.root, x); 
		traverse(avl.root);
		cout << "---------\n";
	}
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		avl.root = deleteNodeAVL(avl.root, x);
		traverse(avl.root);
	}
	// 19
	// 50 30 80 70 90 75 95 98 93 20 72 78 76 60 55 57 58 73 71
	// 9
	// 50 30 80 70 90 75 95 98 93

	traverse(avl.root); 
	destroyTree(avl.root);
	return 0; 
}