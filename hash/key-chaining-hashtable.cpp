#include<iostream>
#include<cmath>
using namespace std ;
struct node{
    int info ; 
    int key ; 
    node * next ; 
} ; 
struct linkedList{
    node * head ; 
} ; 
int nearestPrime(int n){
    int init = int(1.75 * n) ; 
    while (true){
        bool chk = true ; 
        for (int i = 2 ; i < sqrt(init) ; i++)
            if (init % i == 0 ){
                chk = false ; 
                break ; 
            }
        if (chk) 
            return init ; 
        else 
            init++ ; 
    }
}
node *newNode(int key, int info){
    node *p = new node ; 
    p->info = info ; 
    p->key = key ; 
    p->next = nullptr ; 
    return p ;
}
void push(linkedList* hashTable, int size, int key, int info){
    int pos = key % size ; 
    node * oldHead = hashTable[pos].head ; 
    hashTable[pos].head = newNode(key, info) ; 
    hashTable[pos].head->next = oldHead ; 
}
int search(linkedList* hashTable, int size, int key){
    int pos = key % size ; 
    node *p = hashTable[pos].head ; 
    while (p){
        if (p->key == key)
            return p->info ; 
        p = p->next ; 
    } 
    return -1 ; 
}
void deleteElement(linkedList* hashTable, int size, int key){
    int pos = key % size ; 
    node *p = hashTable[pos].head ; 
    if (!p)
        return ; 
    if (p->key == key){
        hashTable[pos].head = p->next ; 
        delete p ; 
        return ; 
    }
    while (p->next){
        if (p->next->key == key){
            node * p = p->next ; 
            p->next = p->next->next ; 
            delete p ; 
        } 
        p = p->next ; 
    }
}
void traverse(linkedList *ll, int size){
    for (int i = 0 ; i < size ; i++){
        node *p = ll[i].head ; 
        while (p){ 
            cout << p->key <<" " <<p->info <<endl ;
            p = p->next ; 
        }
    }
}
int main(){
    int n , key, info; 
    cin >> n ; 
    int sizeHashTable = nearestPrime(n) ; 
    linkedList * hashTable = new linkedList[sizeHashTable] ;
    for (int i = 0 ; i < sizeHashTable ; i++)
        hashTable[i].head = nullptr ;  
    for (int i = 0 ; i < n ; i++){
        cin >> key ; 
        cin >> info ;
        push(hashTable, sizeHashTable, key, info) ;  
    }
    cout <<"------------end the input----------\n" ; 
    traverse(hashTable , sizeHashTable) ; 
    cin >> key ; 
    cout << search(hashTable, sizeHashTable, key) <<endl ; 
    deleteElement(hashTable, sizeHashTable, key) ;
    cout << search(hashTable, sizeHashTable, key) <<endl;  
    traverse(hashTable, sizeHashTable) ; 
    return 0 ; 
}