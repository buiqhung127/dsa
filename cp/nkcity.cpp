#include<iostream>
#define maxN 1000
#define maxV 1000000
using namespace std ; 
int prim(int a[][maxN], int n){
    bool *isVisited = new bool[n];
    int *d = new int[n] ; 
    int sum = 0 ;  
    for (int i = 0 ; i < n ; i++){
        d[i] = maxV ; 
        isVisited[i] = false ; 
    }
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            //cout <<a[i][j] <<endl ;  
    d[0] = 0 ; 
    for (int k = 0 ; k < n ; k++){
        int ver = 0 ; 
        int min_d = maxV ; 
        for (int i = 0 ; i < n ; i++)
            if (d[i] < min_d && isVisited[i] == false) {
                min_d = d[i] ; 
                ver = i ;  
            }
        //cout << min_d <<endl; 
        sum = max(min_d,sum) ; 
        isVisited[ver] = true ; 
        for (int i = 0 ; i < n ; i++)
            if (d[i] > a[ver][i] && isVisited[i] == false)
                d[i] = a[ver][i] ; 
    }
    delete[] d ; 
    delete[] isVisited ; 
    return sum ; 
}

int main(){
    int n, m, a[maxN][maxN]; 
    cin >>n >> m; 
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            a[i][j] = maxV ;  
    for (int i = 0 ; i < m ; i++){
        int x, y ; 
        cin >> x >> y ; 
        cin >> a[x-1][y-1] ; 
        a[y-1][x-1] = a[x-1][y-1] ; 
    }
    cout <<prim(a,n) ; 
    return 0 ; 
}