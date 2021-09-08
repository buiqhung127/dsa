// max prime number from 1 to n
#include<iostream>
#include<cmath>
using namespace std ;
bool isPrime(int x){
    if (x <= 1 )
        return false ; 
    if (x == 2)
        return true; 
    for (int i = 2 ; i <= sqrt(x) ; i++)
        if (x % i == 0)
            return false ;
    return true ; 
} 
int main(){
    int n ; 
    cin >> n ; 
    if (n == 1){
        cout << "There are no prime number equal or less than 1" ; 
    } else
    for (int i = n ; i >= 1 ; i--){
        if (isPrime(i)){
            cout <<"The maximum prime number from 0 to n : " << i ; 
            break ; 
        }
    }
    return 0 ; 
}