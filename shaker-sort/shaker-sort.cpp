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
            if (a[i] > a[i+1]){ // bring the unsorted largest to the true position
                swap(a[i], a[i+1]) ; 
                k = i ; // mark the last exchange
                // bring the largest in the informed region, if there is
                // only few larger numbers in the remain one and we don't swap then, mean it 
                // is already in the true position. 
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