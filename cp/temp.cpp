#include<iostream>
#include<string>
using namespace std ; 
int main(){
    string s ; 
    int t[51], cnt = 0, size = 1; 
    // encrypt 
    // 0001111100111
    // 10001111100111
    cin >> s ; 
    if (s[0] == '1')
        t[0] = 1 ;  
    else 
        t[0] = 0 ; 
    for (int i = 0 ; i < s.length() ; i++){
        if (s[i] - 48 != ((size + t[0] + 1) % 2)){
            t[size] = cnt ; 
            cnt = 1 ; 
            size = size + 1; 
        } else 
            cnt++ ; 
    }
    t[size] = cnt ; 
    size++ ; 
    for (int i = 0 ; i < size ; i++)
        cout << t[i] <<" "; 
    // decrypt
    // 6
    // 1 1 3 5 2 3
    int n ; 
    cin >> n ; 
    for (int i = 0 ; i < n ; i++)
        cin >> t[i] ; 
    int init = t[0] ; 
    for (int i = 1 ; i < n ; i++)
        for (int j = 0 ; j < t[i] ;  j++)
            cout <<(init+ i + 1) % 2 ; 

    return 0 ; 
}