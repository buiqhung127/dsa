#include"bst-other-utilities.h"
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