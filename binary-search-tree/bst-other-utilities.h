#ifndef _BST_OTHER_UTILITIES_H_
#define _BST_OTHER_UTILITIES_H_
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
void preOrderWithoutRecursion(Node* root); 
void postOrderWithoutRecursion(Node* root); 
#endif
