#include<iostream>
using namespace std ; 
void insertionSort(int *a, int n){
    for (int i = 1 ; i < n ; i++){
        int j = i - 1 ; 
        int piv = a[i] ; 
        while (piv < a[j] && j >= 0){
            a[j+1] = a[j] ; 
            j-- ; 
        }
        a[j+1] = piv ; 
    }
}
int main(){
    int n  ; 
    cin >> n ; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 

    insertionSort(a, n) ; 
    for (int i = 0 ; i < n ; i++)
        cout <<a[i] << " " ;  
        
    delete[] a ; 
    return 0; 
}