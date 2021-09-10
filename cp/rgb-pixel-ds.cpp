// contains 3d point
// given A(x,y,z), find all the point that distance from it to A is less than number k.
// assume that using Euclidean distance - real number
// simplicity finding k nearest neighbor 
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
struct Node {
	int r;
	int g;
    int b;
	bool isVisited; // use for traversal
    double dfromo;  // use for constructing the hybrid bst
	Node* parent ;  
	Node* left;
	Node* right;
};
struct BinarySearchTree {
	Node* root; 
};
Node* newNode(int r, int g, int b) {
	Node *p = new Node; // l2 norm 
	p->r = r; // assign the key to the node
	p->g = g; // assign the value to the node
	p->b = b ; 
	p->isVisited = false ;
    p->dfromo = sqrt(r*r + g*g + b*b) ; 
    p->left = nullptr; // become the leaf so 2 childs will be null
	p->right = nullptr; 
	return p; 
}
Node* search(Node *p, int r, int g, int b) { // same to the bst search
	double d = sqrt(r*r + g*g + b*b) ; // calculate the distance
	if (!p)
		return nullptr; 
	if (p->r == r && p->g == g && p->b == b )
		return p;
	else 
	if (p->dfromo > d)
		return search(p->left, r, g, b);
	else
		return search(p->right, r, g, b); 
}
double l2Norm(int r1, int g1, int b1, int r2, int g2, int b2 ){ // calculate the l2 norm
	return sqrt((r1 - r2) * (r1 - r2)  + (g1 - g2) * (g1 - g2)  + (b1 - b2) * (b1 - b2)) ; 
}
void visit(Node *ori, Node *p, int k){
	if (!p || p->r == -1 || p->isVisited) return ; // fake node / visited node / null node : out
	if (l2Norm(ori->r, ori->g, ori->b, p->r, p->g, p->b) >= k){ // distance is greater than k 
		return ; 
	};
	cout << p->r <<" " << p->g <<" " << p->b <<endl ; // display the point
	p->isVisited = true ;  
	visit(ori, p->parent, k) ; // visit the parent 
	visit(ori, p->left, k) ; // visit the left child
	visit(ori, p->right, k) ; // visit the right child
}
void getLessThankNN(Node *root, int r, int g, int b, int k){
	Node *p = search(root,r,g,b) ; 
	visit(p, p, k) ; 
}

void initialize(BinarySearchTree &bst) {
	bst.root = nullptr; 
}
bool isEmpty(BinarySearchTree bst) {
	return (!bst.root) ? true : false; 
}
void nodeInsertionWithoutRecursion(Node *&root, int r, int g, int b){
    Node * p = root ; 
	double d = sqrt(r*r + g*g + b*b) ; 
    if (!root) root = newNode(r, g, b) ; 
    else 
    while (true){
        if (p->dfromo < d){
            if (!p->right){
                p->right = newNode(r, g, b) ;
				p->right->parent  = p ; 
                break ; 
            } else 
                p = p->right ; 
        } else {
             if (!p->left){
                p->left = newNode(r, g, b) ;
				p->left->parent  = p ; 
                break ; 
            } else 
                p = p->left ; 
        }
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
int main() {
	int n, k, r_ori, g_ori, b_ori; 
	BinarySearchTree bst;
	Node *fakeNode = newNode(-1, -1, -1) ; 
	initialize(bst); 
	cin >> n >> k >> r_ori >> g_ori >> b_ori; 
	for (int i = 0 ; i < n ; i++){
		int r, g, b ; 
		cin >> r >> g >> b; 
		nodeInsertionWithoutRecursion(bst.root, r, g, b) ; 
	}
	cout <<"Less than K , the nearest neighbors are : \n" ; 
	getLessThankNN(bst.root, r_ori, g_ori, b_ori, k) ; 
	destroyTree(bst.root); 
	delete fakeNode ; 
	return 0; 
}
/*
8 138 136 34 201
136 34 201
81 22 89 
200 184 59
23 83 137
56 192 19
88 155 212
134 122 164
123 220 123
*/

/*
8 254 136 34 201
136 34 201
81 22 89 // 126
200 184 59 // 216
23 83 137 // 138
56 192 19 // 254
88 155 212 // 130
134 122 164 // 95
123 220 123 //202
*/