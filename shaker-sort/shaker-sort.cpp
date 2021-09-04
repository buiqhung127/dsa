#include<iostream>
using namespace std ;
void swap(int &x, int &y){
    int z = x ; 
    x = y ; 
    y = z ; 
} 
void shakerSort(int *a, int n){
    int left = 0, right = n - 1, k = 0; 
    while (left < right){
        left = k ;  
        for (int i = left ; i < right ; i++)
            if (a[i] > a[i+1]){
                swap(a[i], a[i+1]) ; 
                k = i ; 
            }
        right = k ; 
        for (int i = right ; i > left ; i--)
            if (a[i] < a[i-1]){
                swap(a[i], a[i-1]) ; 
                k = i ; 
            }
        left = k ; 
    }
}
int main(){
    int n ; 
    cin >> n ;
    int *a = new int[n] ;  
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 
    shakerSort(a, n) ; 
    for (int i = 0 ; i < n ; i++)
        cout << a[i] <<" " ; 

    delete[] a ; 
    return 0 ; 
}