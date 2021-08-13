#include<iostream>
using namespace std ;
void interchangeSort(int *a, int n){
    for (int i = 0 ; i < n - 1 ; i++){
        for (int j = i + 1  ; j < n ; j++)
            if (a[i] > a[j]){
                int c = a[i] ;
                a[i] = a[j] ; 
                a[j] = c ; 
            }
    }
} 
int main(){
    int n  ; 
    cin >> n ; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 

    interchangeSort(a, n) ; 
    for (int i = 0 ; i < n ; i++)
        cout <<a[i] << " " ;  


    delete[] a ; 
    return 0; 
}