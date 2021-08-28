#include<iostream>
using namespace std ;
void interchangeSort(int *a, int n){
    for (int i = 0 ; i < n - 1 ; i++){ // just need n-1 iteration, the remain position always true
        for (int j = i + 1  ; j < n ; j++) // consider all pair 
        // except the true order sub-sequence sorted
            if (a[i] > a[j]){ // if there is a conflict, just swap 
                int c = a[i] ;
                a[i] = a[j] ; 
                a[j] = c ; 
                for (int k = 0 ; k < n ; k++)
                    cout << a[k] <<" " ; 
                cout <<endl ; 
            }
    }
} 
int main(){
    int n  ; 
    cin >> n ; 
    int *a = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>a[i] ; 

    interchangeSort(a, n) ; 
    for (int i = 0 ; i < n ; i++)
        cout <<a[i] << " " ;  


    delete[] a ; 
    return 0; 
}