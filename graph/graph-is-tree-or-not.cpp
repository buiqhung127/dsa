#include<iostream>
using namespace std ; 
// Condition for the fact that graph is tree 
// Graph must connected and 
// If the vertex is connect to a visited node, it must be its parent
void treeTrarversal(bool ** adjMatrix, int *par, bool *isVisited, int n, int u, bool &condi){
    // queue<int> q ; 
    isVisited[u] = true ;  
    if (!condi) return ; 
    for (int i = 0 ; i < n ; i++)
        if (adjMatrix[u][i]){
           if (isVisited[i] && (par[u] != i)){ // use dfs so wrong since it can visit again before we complete the loop
               //cout << u <<" " <<i <<" " <<par[u] <<" "<<1<<endl ; 
               condi = false ; 
               return ; 
           }
           if (!isVisited[i]){
               par[i] = u ; 
               // cout << u <<" " <<i <<" " <<par[i] <<" " <<2<<endl ; 
               treeTrarversal(adjMatrix, par, isVisited, n, i, condi) ; 
           }
        }
}
bool isConnected(bool *isVisited, int n){
    for (int i = 0 ; i < n ; i++)
        if (!isVisited[i])
            return false ; 
    return true ; 
}
int main(){
    int n, m ; 
    cin >> n >> m ; 
    bool condi = true ; 
    bool **adjMatrix = new bool*[n] ;
    bool *isVisited = new bool[n];  
    int * par = new int[n] ; 
    for (int i = 0 ; i < n ; i++){
        adjMatrix[i] = new bool[n] ;
        for (int j = 0 ; j < n ; j++)
            adjMatrix[i][j] = false ; 
    } 

    for (int i = 0 ; i < m ; i++){
        int x, y ; 
        cin >> x >> y ; 
        adjMatrix[x][y] = true ; 
        adjMatrix[y][x] = true ; 
    }
    treeTrarversal(adjMatrix, par, isVisited, n, 0, condi) ;     
    if (condi && isConnected(isVisited, n)){
        cout << "This graph is also a tree" ; 
    } else {
        cout << "This graph cannot be a tree" ;
    }
    for (int i = 0 ; i < n ; i++)
        delete[] adjMatrix[i] ; 
    delete[] adjMatrix ; 
    delete[] isVisited ; 
    return 0 ; 
}
/*
5 4
1 0
0 2
0 3 
3 4
*/
/*
5 5
1 0  
0 2 
2 1
0 3
3 4
*/