#include<iostream>
using namespace std ; 
void radixSort(int *a, int n, int max){
    int maxDigs = 0, pow10 = 1; 
    int *tmp = new int[n] ; 
    int *cntList = new int[10] ;   

    while (max > 0){
        maxDigs++ ;
        max /= 10 ;  
    }
    for (int i = 0 ; i < maxDigs ; i++){
        for (int j = 0 ; j < 10 ; j++)
            cntList[j] = 0 ; 

        for (int j = 0 ; j < n ; j++)
            cntList[int(a[j] / pow10) % 10]++ ; 

        for (int j = 1 ; j < 10 ; j++)
            cntList[j] = cntList[j-1] + cntList[j] ; 
        for (int j = n - 1 ; j >= 0 ; j--){
            tmp[--cntList[int(a[j] / pow10) % 10]] = a[j] ;  
        }
        for (int j = 0 ; j < n ; j++)
            a[j] = tmp[j] ; 
        pow10 *= 10 ; 
    }
    delete[] tmp ; 
    delete[] cntList; 
}
int main(){
    int n, max = 0;
    cin >> n ; 
    int *a = new int[n] ;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i] ; 
        if (max < a[i])
            max = a[i] ; 
    }

    radixSort(a, n, max) ;     
    cout << "The array after being sorted : \n" ; 
    for (int i = 0 ; i < n ; i++)
        cout <<a[i] <<" "  ; 


    delete[] a ; 

    return 0 ; 
}