#include<iostream>
#define maxN 10000
using namespace std ; 
int main(){
    int n,m;
    int a[maxN][maxN] ;  
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++) 
            a[i][j] = 0 ; 
    for (int i = 0 ; i < m ; i++){
        int x, y ; 
        cin >> x >> y ; 
        a[x][y] = 1 ; 
        a[y][x] = 1 ; 
    }
    return 0 ; 
}