#include<iostream>
using namespace std ; 
void radixSort(int *a, int n, int max){
    int maxDigs = 0, pow10 = 1; 
    int *tmp = new int[n] ; 
    int *cntList = new int[10] ;   // is used for counting sort

    while (max > 0){ // count the number of digit in the maximum
        maxDigs++ ;
        max /= 10 ;  
    }
    for (int i = 0 ; i < maxDigs ; i++){ // consider all the digits of all number from the right most digit to the left most digit
        for (int j = 0 ; j < 10 ; j++)
            cntList[j] = 0 ; 

        for (int j = 0 ; j < n ; j++)
            cntList[int(a[j] / pow10) % 10]++ ; // counting the appearence of digit

        for (int j = 1 ; j < 10 ; j++)
            cntList[j] = cntList[j-1] + cntList[j] ; // prepare position for counting sort
        for (int j = n - 1 ; j >= 0 ; j--){ // must use backward loop for determining the larger right digits old value when adjust position
        // almost the value by the current digits
            tmp[--cntList[int(a[j] / pow10) % 10]] = a[j] ;  // keep push the right digits larger value to the further when they have the
            // same current digit 
        }
        for (int j = 0 ; j < n ; j++)
            a[j] = tmp[j] ; // move value from temporary array to the array
        pow10 *= 10 ; // prepare for getting 
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