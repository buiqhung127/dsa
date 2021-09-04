#include<iostream>
#include<cmath>
using namespace std ; 
int nearestPrime(int n){
    int init = n ; 
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
void pushHashTable(int *data, int *hashTable, int size, int h1, int h2, int key, int info){
    int i = 0, k ; 
    do { // ((key % prime_number_1 ) + i * ( key % prime_number_2)) % size
        k = (key % h1 + i * (key % h2)) % size ; 
        i++ ; 
    } while (hashTable[k] != -1 ) ; 
    hashTable[k] = key ; 
    data[k] = info ; 
}
int searchHashTable(int *data, int *hashTable, int size, int h1, int h2, int key){
    int i = -1 , k; 
    do {
        k = (key % h1 + i * (key % h2)) % size ; 
        i++ ; 
        if (i == size) return -1 ; 
    } while (hashTable[k] != key ) ;
    return data[k] ;  
}
int main(){
    int n, key, info; 
    cin >> n ; 
    int initHash = nearestPrime(int(1.75* n));
    int finalHash = nearestPrime(initHash) ;  
    int sizeHashTable = nearestPrime(finalHash) ; 

    int *hashTable = new int[sizeHashTable] ;
    int *data = new int[sizeHashTable] ; 
    for (int i = 0 ; i < sizeHashTable ; i++){
        hashTable[i] = -1  ; 
        data[i] = -1 ; 
    }
    for (int i = 0 ; i < n ; i++){
        cin >> key >> info  ; 
        pushHashTable(data, hashTable, sizeHashTable, initHash, finalHash, key, info) ; 
    }
    for (int i = 0 ; i < sizeHashTable ; i++)
        cout <<hashTable[i] <<" "  ; 
    cout <<endl ; 
    for (int i = 0 ; i < sizeHashTable ; i++)
        cout <<data[i] <<" "  ; 

    cin >> key ; 
    cout << searchHashTable(data, hashTable, sizeHashTable, initHash, finalHash, key)    ; 
    return 0 ;
}