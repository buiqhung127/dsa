#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define MAX_SIZE_HASH 47629
using namespace std;
void findPrime(int sizeHash, int modulo[]){ // find 2 prime number to construct the hash function
    int d = 0 ;
    while (d < 2){
        sizeHash-- ;
        bool check = true ;
        for (int i = 2 ; i < int(sqrt(sizeHash)); i++)
            if (sizeHash % i == 0){
                check = false ;
                break ;
            }
        if (check)
            modulo[d++] = sizeHash ;
    }
}
void hashFunction(string key, int modulo[], string hashTable[], int sizeHash, int *cnt, int &record){
    int temp = 0 ;
    for (int i = 0 ; i < key.length() ; i++)
        temp += int(key[i]) ; // get the number before hash
    int i = 0, k;
    do {
        k = (temp % modulo[0] + i * (temp % modulo[1])) % sizeHash ; // hash
        if (hashTable[k] == key) break ;
        i++ ;
    } while (hashTable[k] != "") ; // find the blank space
    record = max(record, i) ; // check this to avoid the cycle
    hashTable[k] = key ;
    cnt[k]++ ;
}
bool decode(string key, int modulo[], string hashTable[], int sizeHash, int *cnt, int record){
    int temp = 0 ;
    for (int i = 0 ; i < key.length() ; i++)
        temp += int(key[i]) ;
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
    return false ;
}
void checkMagazine(vector<string> magazine, vector<string> note) {
    int sizeHash = MAX_SIZE_HASH ;
    int modulo[2], cnt[MAX_SIZE_HASH], record = 0 ;
    findPrime(sizeHash, modulo) ;
    string hashTable[MAX_SIZE_HASH] ;
    for (int i = 0 ; i < sizeHash ; i++){
        hashTable[i] = "" ;
        cnt[i] = 0 ;
    }
    for (int i = 0 ; i < magazine.size() ; i++)
        hashFunction(magazine[i], modulo, hashTable, sizeHash, cnt, record);

    for (int i = 0 ; i < note.size() ; i++)
        if (!decode(note[i], modulo,  hashTable, sizeHash, cnt, record)){
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
