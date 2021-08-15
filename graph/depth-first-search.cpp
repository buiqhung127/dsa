#include<iostream>
#include<fstream>
using namespace std ;
struct vertex{
    int val ;
    vertex* next ;  
};
struct adjacentList{
    vertex* head ; 
};
vertex* newNode(int val){
    vertex * v = new vertex ; 
    v->val = val ; 
    v->next = nullptr ; 
    return v ; 
}
void pushNode(adjacentList* graph, int a, int b){ // push b to a
    vertex * v = newNode(b) ;
    v->next = graph[a].head ; 
    graph[a].head = v ; 
}
void traceThePath(int *trace, int k){
    for (int i = 0 ; i < k ; i++)
        cout <<trace[i] << " " ; 
    cout <<endl ; 
}
void depthFirstSearch(adjacentList* graph, bool *isVisited, int u, int f, int* trace, int k){
    vertex * p = graph[u].head ; 
    isVisited[u] = true; 
    trace[k++] = u ; 
    while (p){
        int value = p->val ; 
        if (!isVisited[value]){ 
            if (value == f) {
                trace[k++] = value ; 
                traceThePath(trace, k) ;
            } 
            else depthFirstSearch(graph, isVisited, value, f, trace, k ) ; 
        }
        p = p->next ; 
    }
    isVisited[u] = false ; 

}
int main(){
    fstream fi("input.txt", ios::in) ;
    int n, m, s, f; 
    fi >> n >> m >> s >>f ; 
    bool *isVisted = new bool[n] ; 
    int * trace = new int[n] ; 
    adjacentList* graph = new adjacentList[n] ; 
    for (int i = 0 ; i < n ; i++){
        graph[i].head = nullptr ; 
        isVisted[i] = false ; 
    }
    for (int i = 0 ; i < m ; i++){
        int x, y ; 
        fi >> x >> y ; 
        pushNode(graph, x, y) ; 
        pushNode(graph, y, x) ; 
    }
    depthFirstSearch(graph, isVisted, s, f, trace, 0) ; 

    delete[] isVisted ; 
    delete[] trace ; 
    fi.close() ; 
    return 0 ; 
}