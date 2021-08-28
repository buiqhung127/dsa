#include<iostream>
using namespace std ; 
void insertionSort(int *a, int n){
    for (int i = 1 ; i < n ; i++){ // move the boundary split the array into 2 part. sorted one and 
    // unsorted one. 
        int j = i - 1 ; 
        int piv = a[i] ; // get the value that will be pushed, call piv
        while (piv < a[j] && j >= 0){ // keep running when the piv is still in the array and
        //smaller than the left one
            a[j+1] = a[j] ; // push to the left to get a blank
            j-- ; 
        }
        a[j+1] = piv ; // push the element into the spot
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