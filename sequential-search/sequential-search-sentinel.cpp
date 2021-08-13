#include<iostream>
using namespace std ;

int sequentialSearchSentinel(int* a, int n, int x){
    int i = 0 ; 
    a[n] = x ; 
    while (a[i] != x)
       i++ ; 
    return i; 
}
int main(){
    int n,x ; 
    cin >> n ; 
    int *a = new int[n + 1] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ;
    cin >> x ; 
    int pos = sequentialSearchSentinel(a, n, x) ; 
    if (pos == n)
        cout <<"Not found" ;
    else 
        cout <<"Position : " << pos ;  


    delete[] a ; 
    return 0; 
}