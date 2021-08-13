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
node* newNode(linkedList ll, int x, int key){
    node *p = new node ; 
    p->next = ll.head ; 
    p->value = x ; 
    p->key = key ; 
    return p ; 
}
bool isEmptyLinkedList(linkedList ll){
    if (!ll.head)
        return true ; 
    return false ; 
}
void pushNode(linkedList &ll, int x, int key){
    if (!ll.head){
        ll.head = newNode(ll, x, key) ;
        ll.head->next = ll.head ;
    } 
    else {
        node *p = ll.head ; 
        while (p->next != ll.head)
            p = p->next ; 
        p->next = newNode(ll, x, key) ; 
    } 
}
void traverseLinkedList(linkedList ll){
    if (isEmptyLinkedList(ll)) 
        return ; 
    node *p = ll.head ; 
    do {
        cout <<p->value <<" " ; 
        p = p->next ; 
    } while (p != ll.head) ; 
    cout <<endl ; 
}

void deleteElementLinkedList(linkedList &ll, int key){
    if (isEmptyLinkedList(ll)) return ; 
    node *p = ll.head ;
    if (ll.head->key == key){
        if (ll.head->next == ll.head){
            delete ll.head ; 
            ll.head = nullptr ; 
        }
        node *t = ll.head->next ; // new head 
        while (p->next != ll.head)
            p = p->next ; 
        p->next = t ; 
        delete ll.head ;  
        ll.head = t ; 
    } else 
        do {
            if (p->next->key == key){
                node *t = p->next ; 
                p->next = p->next->next ; 
                delete t ;
                return ;  
            }
            p = p->next ; 
        } while (p != ll.head);
}
node* searchingElementLinkedList(linkedList &ll, int x){
    if (isEmptyLinkedList(ll)) {
        cout <<"This linked list is empty\n" ;
        return nullptr ;  
    }
    node *p = ll.head ; 
    do {
        if (p->value == x)
            break ; 
        p = p->next ; 
    } while (p != ll.head) ; 
    return p ; 
}
int main(){
    linkedList ll ; 
    ll.head = nullptr ; 
    int n, x, key; 
    cin >> n ; 
    for (int i = 0 ; i < n ; i++){
        cin >> x ; 
        pushNode(ll, x, i) ; 
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