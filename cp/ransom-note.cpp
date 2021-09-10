#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define MAX_SIZE_HASH 47629
using namespace std;
void findPrime(int sizeHash, int modulo[]){ // find 2 prime number to construct the hash function
    int d = 0 ;
    while (d < 2){ // find each prime number
        sizeHash-- ;
        bool check = true ;
        for (int i = 2 ; i < int(sqrt(sizeHash)); i++) // check the prime properties
            if (sizeHash % i == 0){
                check = false ;
                break ;
            }
        if (check)
            modulo[d++] = sizeHash ; // store the prime numbers
    }
}
void hashFunction(string key, int modulo[], string hashTable[], int sizeHash, int *cnt, int &record){
    int temp = 0 ;
    for (int i = 0 ; i < key.length() ; i++)
        temp += int(key[i]) ; // get the number representation before hash
    int i = 0, k;
    do {
        k = (temp % modulo[0] + i * (temp % modulo[1])) % sizeHash ; // hash
        if (hashTable[k] == key) break ; // the key already exist, just increase the count variable
        i++ ;
    } while (hashTable[k] != "") ; // find the blank space
    record = max(record, i) ; // check this to avoid the cycle (infinity loop)
    hashTable[k] = key ;
    cnt[k]++ ; // count it
}
bool decode(string key, int modulo[], string hashTable[], int sizeHash, int *cnt, int record){
    int temp = 0 ;
    for (int i = 0 ; i < key.length() ; i++)
        temp += int(key[i]) ; // get the representation number
    int i = 0, k;
    do {
         k = (temp % modulo[0] + i * (temp % modulo[1])) % sizeHash ; // rehash 
         if (hashTable[k] == key && cnt[k] > 0){
            cnt[k]-- ; // reduce the counting array
            return true ;
         }
         record-- ;
         i++ ;
    } while (cnt[k] > 0 && record + 1 >= 0) ;
    return false ; // mean key is not exist or the quantity is not enough
}
void checkMagazine(vector<string> magazine, vector<string> note) {
    int sizeHash = MAX_SIZE_HASH ;
    int modulo[2], cnt[MAX_SIZE_HASH], record = 0 ;
    findPrime(sizeHash, modulo) ;
    string hashTable[MAX_SIZE_HASH] ;
    for (int i = 0 ; i < sizeHash ; i++){ //initialize these variables
        hashTable[i] = "" ;
        cnt[i] = 0 ;
    }
    for (int i = 0 ; i < magazine.size() ; i++)
        hashFunction(magazine[i], modulo, hashTable, sizeHash, cnt, record); // hash and count

    for (int i = 0 ; i < note.size() ; i++)
        if (!decode(note[i], modulo,  hashTable, sizeHash, cnt, record)){ // decode and check the quantity
            cout <<"No" ;
            return ;
        }
    cout <<"Yes" ;
}

int main()
{
    vector<string> magazine ; 
    vector<string> note ; 
    int n,m ; 
    cin >> m >> n ;
    for (int i = 0 ; i < m ; i++){
        string temp ; 
        cin >> temp ; 
        magazine.push_back(temp) ; 
    }
    for (int i = 0 ; i < n ; i++){
        string temp ; 
        cin >> temp ; 
        note.push_back(temp) ; 
    }
    checkMagazine(magazine, note) ; 
    return 0 ; 
}
