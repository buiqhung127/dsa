#include<iostream>
#include<fstream>
#define maxN 12072002
using namespace std ; 
int main(){
    int n, m, s, t; 
    fstream fi("input-dijkstra.inp",ios::in) ;
    fi >> n >> m >>s >>t; 
    int *d_from_s = new int[n + 1]; 
    int *prev = new int[n+1] ; 
    bool *visited = new bool[n+1] ;  
    int weight[100][100] ; 
    for (int i = 0 ; i <= n ; i++){ // init the weight
        d_from_s[i] = maxN ;
        visited[i] = false ;   
        for (int j = 0 ; j <=n ; j++)
            weight[i][j] = maxN ; // if any pair of vertex does not have any connection between them, mark it as 
            // very big number so the program will avoid it. 
    }
    for (int i = 0 ; i < m ; i++){
        int x,y,w ; 
        fi >> x >> y >>w ; 
        weight[x][y] = w ; 
        weight[y][x] = w ; 
    }

    d_from_s[s] = 0 ;
    prev[s] = s ; 
    for (int k = 0 ; k <= n ; k++) { // consider all the vertex, remember if any pair of vertex does not have any connection between them,
        // mark it as very big number so the program will avoid it. 
        int min_length = maxN ; 
        int vertex_minimized = 0 ; 
        for (int i = 0 ; i <= n ; i++) // get the node that is not visited yet and have shortest path from the start vertex
            if (d_from_s[i] < min_length && !visited[i]){
                min_length = d_from_s[i] ; // update the minimum
                vertex_minimized = i ; 
            }
        visited[vertex_minimized] = true ; // mark it as a visited node
        if (vertex_minimized == t) break ; // sucessfullu minimize the length of path from the starting node to the destination 
        //so we can break out . 
        for (int i = 0 ; i <= n ; i++)
            if (!visited[i] && d_from_s[i] > (d_from_s[vertex_minimized] + weight[vertex_minimized][i])){ // use the vertex to 
            // minimize length of path from starting point to any unvisited node. 
                prev[i] = vertex_minimized ; 
                d_from_s[i] = d_from_s[vertex_minimized] + weight[vertex_minimized][i] ;             
            }
    }
    cout <<d_from_s[t] ; 


    delete[] visited ; 
    delete[] d_from_s ; 
    delete[] prev ; 
    fi.close() ; 
    return 0 ; 
}