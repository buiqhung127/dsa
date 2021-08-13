#include<iostream>
using namespace std ;
struct node { 
    int value ; 
    int key ; 
    node* next ;
}; 
struct linkedList{
    node* head ; 
} ; 
node* newNode(int x, int key){
    node *p = new node ; 
    p->next = nullptr ; 
    p->value = x ; 
    p->key = key ; 
    return p ; 
}
void pushNodeToTail(linkedList &ll, int x, int key){
    if (!ll.head)
        ll.head = newNode(x, key) ;
    else {
        node *p = ll.head ; 
        while (p->next)
            p = p->next ; 
        p->next = newNode(x, key) ; 
    } 
}
void traverseLinkedList(linkedList ll){
    node *p = ll.head ; 
    while (p){
        cout <<p->value <<" " ; 
        p = p->next ; 
    }
    cout <<endl ; 
}
bool isEmptyLinkedList(linkedList ll){
    if (!ll.head)
        return true ; 
    return false ; 
}
void deleteElementLinkedList(linkedList &ll, int key){
    node *p = ll.head ;
    if (ll.head->key == key){
        node *t = ll.head->next ; 
        delete ll.head ;  
        ll.head = t ; 
    } else 
        while (p->next){
            if (p->next->key == key){
                node *t = p->next ; 
                p->next = p->next->next ; 
                delete t ;
                return ;  
            }
            p = p->next ; 
        }
}
node* searchingElementLinkedList(linkedList &ll, int x){
    node *p = ll.head ; 
    while (p){
        if (p->value == x)
            break ; 
        p = p->next ; 
    }
    return p ; 
}
int main(){
    linkedList ll ; 
    ll.head = nullptr ; 
    int n, x, key; 
    cin >> n ; 
    for (int i = 0 ; i < n ; i++){
        cin >> x ; 
        pushNodeToTail(ll, x, i) ; 
    }
    traverseLinkedList(ll) ;  
    cin >> key ; 
    deleteElementLinkedList(ll, key) ; 
    traverseLinkedList(ll) ; 
    cin >> x ; 
    node* p = searchingElementLinkedList(ll, x) ;
    cout <<p->key << " " <<p->value ;  
    

    return 0 ; 
}