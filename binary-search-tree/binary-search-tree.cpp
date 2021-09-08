#include<iostream>
#include<stack>
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
				Node* t = p->left;
				while (t->right)
					t = t->right; 
				p->val = t->val; 
				p->left = remove(p->left, p->val); // then delete the original node having maximum of smaller value
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
void preOrderWithoutRecursion(Node* root){
    // without using recursion
    stack<Node*> stk ; 
    stk.push(root) ; 
    while (!stk.empty()){
        Node *p = stk.top() ; 
        stk.pop() ; 
        cout <<p->val <<endl ;
        if (p->right) stk.push(p->right) ;  
        if (p->left) stk.push(p->left) ;  
    }
}
void postOrderWithoutRecursion(Node* root){
    //without recursion
    stack<Node*> stk ; 
    stk.push(root) ; 
    while (!stk.empty()){
        Node *p = stk.top() ; 
        stk.pop() ; 
        if (p->right) stk.push(p->right) ;  
        if (p->left) stk.push(p->left) ; 
        cout <<p->val <<endl ;
    }
}
void nodeInsertionWithoutRecursion(Node *&root, int key, int value){
    Node * p = root ; 
    if (!root) root = newNode(key,value) ; 
    else 
    while (true){
        if (p->val < value){
            if (!p->right){
                p->right = newNode(key,value) ; 
                break ; 
            } else 
                p = p->right ; 
        } else {
             if (!p->left){
                p->left = newNode(key,value) ; 
                break ; 
            } else 
                p = p->left ; 
        }
    }
}
void nodeDeletionWithoutRecursion(Node *&root, int value, Node *parent){
    Node *p = root ;
	bool isLeft = true ; 
	parent->left = root ;  
    while (p){
        if (p->val == value){
            if (!p->left && !p->right){
                delete p ; 
                p = nullptr ; 
				break ; 
            } else if (p->left && !p->right){
                Node * t = p->left ;  
                delete p ; 
                p = t ; 
				break ; 
            } else if (!p->left && p->right){
                Node * t = p->right ; 
                delete p ; 
                p = t ; 
				break ; 
            } else {
                parent = p ; 
                Node * t = p->left ; 
				isLeft = true ; 
                while (t->right){
                    parent = t ; 
                    t = t->right ;
					isLeft = false ;
                } 
                p->val = t->val  ; 
                value = t->val ; 
                p = t ; 
            }
        } 
        else if (p->val < value){
            parent = p ; 
            p = p->right ; 
            isLeft = false ; 
        }
        else {
            parent = p ; 
            p = p->left ; 
            isLeft = true ; 
        }
    } 
    if (isLeft)
        parent->left = p ; 
    else 
        parent->right = p ;
}
int main() {
	int n, x; 
	BinarySearchTree bst;
	Node *fakeNode = newNode(-1, -1) ; 
	initialize(bst); 
	cin >> n; 
	for (int i = 0 ; i < n ; i++){
		cin >> x; 
		//bst.root = insert(bst.root, i, x); 
		nodeInsertionWithoutRecursion(bst.root, i, x) ; 
	}
	traverse(bst.root); 
	//preOrderWithoutRecursion(bst.root) ; 
	/*cout << "\n----------------\nEnter the number that you want to find:\n>>";
	cin >> x; 
	Node *t = search(bst.root, x); 
	if (t)
		cout << t->key<<" " <<t->val;
	else
		cout << "Not found!";*/ 
	cout << "\n----------------\nEnter the number that you want to delete:\n>>"; 
	cin >> x; 
	//bst.root = remove(bst.root, x); 
	nodeDeletionWithoutRecursion(bst.root, x, fakeNode) ; 
	traverse(bst.root); 
	cout << endl; 
	destroyTree(bst.root); 
	//7
	//53 26 22 51 75 98 80
	delete fakeNode ; 
	return 0; 
}