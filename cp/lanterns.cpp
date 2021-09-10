// https://codeforces.com/problemset/problem/492/B
#include<iostream>
#include<iomanip>
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
    long long l; 
    cin >> n ;
    cin >> l ; 
    long long *a = new ll[n] ;  
    for (int i = 0 ; i < n ; i++)
        cin >> a[i] ; 
    quickSort(a, 0, n - 1) ; // sort the cordinates
    double m = (a[0] > l - a[n-1]) ? a[0] : (l - a[n-1]) ; // get the minimized radius to enlight the head and tail of the route 
    for (int i = 1 ; i < n; i++)
       m = (m > ((a[i] - a[i-1]) / 2.0) ) ? m : ((a[i] - a[i-1]) / 2.0 ) ; // consider each distance between 2 lamppost, get the half 
       // as the radius
    cout << setprecision(9) << fixed << m  ;  
    delete[] a ; 
}