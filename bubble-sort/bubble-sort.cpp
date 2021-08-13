#include<iostream>
using namespace std ; 
void bubbleSort(int *a, int n){
    for (int i = 0 ; i < n - 1 ; i++){
        bool check = true ; 
        for (int j = n - 1; j > i ; j-- )
            if (a[j] < a[j-1]){
                int c = a[j] ; 
                a[j] = a[j-1] ; 
                a[j-1] = c ;
                check = false ;  
            }
        if (check) return ; 
    }
}
int main(){
    int n  ; 
    cin >> n ; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 

    bubbleSort(a, n) ; 
    for (int i = 0 ; i < n ; i++)
        cout <<a[i] << " " ;  


    delete[] a ; 
    return 0; 
}