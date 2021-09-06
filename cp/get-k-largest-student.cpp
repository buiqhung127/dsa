// Compulsory time complexity : O(n)
#include<iostream>
#define maxScore 10
#define minScore 0
#define distance 0.5
using namespace std ;
float getThreshold(int *a, int n, int k){
    int size = (maxScore - minScore) / distance + 1 ; 
    int *countMark = new int[size] ; 
    for (int i = 0 ; i < size ; i++)
        countMark[i] = 0 ;
    for (int i = 0 ; i < n ; i++)
        countMark[a[i] * 2]++ ; 
     
    int cnt = 0, i ; 
    for (i = size - 1 ; i >= 0 && cnt + countMark[i] <= k ; i--){
        cnt+= countMark[i] ; 
        //cout << i << " " <<cnt <<endl ;
    }
    delete[] countMark ; 
    return  (i+1) / 2.0 ; 
} 
int main(){
    int n, k; 
    cin >> n >> k ; 
    int * a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >> a[i] ; 
    cout <<getThreshold(a, n, k) ; 

    return 0 ; 
}