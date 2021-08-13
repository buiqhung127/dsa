#include<iostream>
using namespace std ;

int sequentialSearch(int* a, int n, int x){
    for (int i = 0 ; i < n ; i++)
        if (a[i] == x)
            return i;
    return -1 ; 
}
int main(){
    int n,x ; 
    cin >> n ; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 

    cin >> x ; 
    int pos = sequentialSearch(a, n, x) ; 
    if (pos == -1)
        cout <<"Not found" ;
    else 
        cout <<"Position : " << pos ;  


    delete[] a ; 
    return 0; 
}