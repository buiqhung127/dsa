#include<iostream>
#include<fstream>
#define MAX 999999
using namespace std ; 
int min(int a, int b){
    return (a < b) ? a : b ; 
}
int main(){
    fstream fi("input.txt", ios::in) ;
    int n, m, weight[100][100], d[100], pre[100], totalWeight = 0; 
    bool visited[100] ; 
    fi >> n >> m ; 
    for (int i = 0 ; i <= n ; i++) {
        d[i] = MAX ; 
        visited[i] = false ; 
        for (int j = 0 ; j <= n ; j++)
            weight[i][j] = MAX ; 
    }
    for (int i = 0 ; i < m ; i++){
        int x, y, w;
        fi >> w >> x >> y ;  
        weight[x][y] = w ; 
        weight[y][x] = w ; 
    }
    d[0] = 0 ; 
    // visited[0] = true ; 
    for (int k = 0 ; k <= n ; k++){
        int nearestNode ;
        int minWay = MAX ;  
        for (int i = 0 ; i <= n ; i++){
            if (d[i] < minWay && !visited[i]){
                nearestNode = i ; 
                minWay = d[i] ; 

            }
        }
        totalWeight += minWay ; 
        visited[nearestNode] = true ;
        // cout << nearestNode <<endl ;  
        for (int i = 0 ; i <= n ; i++){
            if (!visited[i]){
                if (d[i] > minWay + weight[nearestNode][i]) {
                    d[i] = minWay + weight[nearestNode][i] ; 
                    pre[i] = nearestNode ; 
                } 
            }
                
        }
    }
    cout << 0 << endl ; 
    for (int i = 1 ; i <= n ; i++)
        cout << i <<" "<< pre[i] <<endl ; 


    fi.close() ; 
    return 0 ; 
}