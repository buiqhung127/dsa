#include<iostream>
#include<fstream>
#define maxV 100000
using namespace std ;
int dijkstra(int **graph, int n, int s, int t){
    int sum = 0 ;  int *d = new int[n * n] ;  int *prev = new int[n * n] ;   // init value
    bool *isVisited = new bool[n * n] ;
    for (int i = 0 ; i < n * n ; i++){ // initialize the distance from starting vertex and the visted status
        d[i] = maxV ;
        isVisited[i] = false ; 
    } d[s] = 0 ; prev[s] = -1 ; // init for the starting vertex
    for (int k = 0 ; k < n * n ; k++){ // dijkstra's algorithm
        int min = maxV, pos = 0; 
        for (int i = 0 ; i < n * n ; i++)
            if (min > d[i] && isVisited[i] == false){
                min = d[i] ; 
                pos = i ; 
            }
        isVisited[pos] = true ; 
        if (pos == t){
            sum = d[pos] ; 
            break ; 
        }
        for (int i = 0 ; i < n * n ; i++)
            if (graph[pos][i] + min < d[i] && isVisited[i] == false ){
                d[i] = graph[pos][i] + min ; 
                prev[i] = pos; // trace the path later
            }
    }
    int i = t, cnt = 0;
    while (i != -1){ // trace the path
        d[cnt++] = i ; 
        i = prev[i] ; 
    }
    for (int i = cnt - 1 ; i >= 0 ; i--)
        cout << d[i] / n <<" " << d[i] % n <<endl; // display the path 
    delete[] d ;  delete[] isVisited; delete[] prev ;
    return sum ; 
} 
int main(){
    fstream fi("input-traffic-jam.txt",ios::in) ; 
    int n, sx, sy, tx, ty;
    fi >> n;
    fi >> sx >> sy >> tx >> ty ; 
    int **graph = new int*[n * n] ;  
    for (int i = 0 ; i < n * n ; i++){
        graph[i] = new int[n * n] ; 
    }
    for (int i = 0 ; i < n * n ; i++)
        for (int j = 0 ; j < n * n ; j++)
            graph[i][j] = maxV ; 
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++){
            int x ; 
            fi >> x ; 
            if (i * n + j - 1 >= 0)
                graph[i * n + j - 1][i * n + j] = x + 1 ;
            if ((i - 1) * n + j >= 0)
                graph[(i - 1) * n + j][i * n + j] = x + 1; 
            if (i * n + j + 1 < n * n)
                graph[i * n + j + 1][i * n + j] = x + 1;
            if ((i + 1) * n + j < n * n)
                graph[(i + 1) * n + j][i * n + j] = x + 1; 
        }
    
    
    cout <<"The one of the best way to travel is : \n" <<dijkstra(graph,n, sx * n + sy, tx * n + ty) ; 

    for (int i = 0 ; i < n * n ; i++){
        delete[] graph[i];
    }
    delete[] graph ;   
    return 0 ; 
}