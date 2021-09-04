#include<iostream>
using namespace std ; 
void quickSort(int *a, int left, int right){
    int i = left ;
    int j = right ; 
    int mid = a[(i+j)/2] ; 
    while (i <= j){
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
    if (left < j) quickSort(a, left, j) ; 
    if (right > i) quickSort(a, i, right) ; 
}
int binarySearch(int *a, int left, int right, int key){
    if (left > right)
        return -1 ; 
    int mid = (left + right) / 2; 
    if (a[mid] == key)
        return mid ; 
    else if (a[mid] < key)
        return binarySearch(a, mid+1, right, key) ;
    else 
        return binarySearch(a, left, mid - 1, key) ; 
}
int main(){
    int n, key ; 
    cin >> n  >> key; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 
    quickSort(a, 0, n - 1) ; 
    for (int i = 0 ; i < n ; i++)
        cout <<a[i] <<" "  ; 
    int pos = binarySearch(a, 0, n-1, key) ;
    if (pos == -1){
        cout <<"\nNot found" ; 
    } 
    else 
        cout <<endl <<pos ; 
    delete[] a ; 
    return 0 ; 
}