#include<iostream>
#define ll long long
using namespace std ; 
void quickSort(long long *a, int left, int right){
    int mid = a[(left + right) / 2]; 
    int i = left, j = right ; 
    while (i <= j ){
        while (a[i] < mid) i++ ; 
        while (a[j] > mid) j-- ; 
        if (i <= j){
            int c = a[i] ; 
            a[i] = a[j] ; 
            a[j] = c ; 
            i++ ; 
            j-- ; 
        }
    }
    if (i < right) quickSort(a, i, right) ; 
    if (j > left) quickSort(a, left, j) ; 
}
int main(){
    int n ; 
    cin >> n ;
    long long *a = new ll[n] ;  
    for (int i = 0 ; i < n ; i++)
        cin >> a[i] ; 
    quickSort(a, 0, n - 1) ;
    delete[] a ; 
}