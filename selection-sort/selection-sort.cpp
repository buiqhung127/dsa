#include<iostream>
using namespace std ;
void swap(int &a, int &b){
    int c = a ; 
    a = b ; 
    b = c ; 
}
void selectionSort(int *a, int n){
    for (int i = 0 ; i < n - 1 ; i++){ // find the smallest element from ith element to n-1 element
    // to fill the ith position
        int min = a[i] ; // init the min as the first element of not yet sorted sub-array
        int pos = i ;   // mark the position
        for (int j = i + 1 ; j < n ; j++) // traverse not yet sorted sub-array
            if (min > a[j]){ // find the element smaller than the minimum
                min = a[j] ; 
                pos = j ; 
            }
        swap(a[i], a[pos]) ; // swap the element, fit the element to the suitable position
    }
}
int main(){
    int n; 
    cin >> n ; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >> a[i] ; 
    selectionSort(a, n) ;
    for (int i = 0 ; i < n ; i++)
        cout << a[i] <<" "  ;  
    delete[] a  ; 
    return 0 ; 
} 