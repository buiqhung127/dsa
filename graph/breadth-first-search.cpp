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
void tracer(int *trace, int f){
    int u = f ; 
    do {
        cout << u <<" "; 
        u = trace[u] ; 
    } while (trace[u] != -1) ; 
    cout <<endl ;  
}
void breadthFirstSearch(adjacentList* graph, bool *isVisited, int u, int f, int* trace, int n){ 
    int *queue = new int[n] ;
    int top = 0, bot = 0 ; 
    queue[top] = u;  
    isVisited[u] = true ; 
    trace[u] = -1 ; 
    while (top <= bot){
        u = queue[top++] ; 
        vertex *p = graph[u].head ; 
        while (p) {
            if (p->val == f){
                tracer(trace, f) ;  
            }
            if (!isVisited[p->val]){
                isVisited[p->val] = true ; 
                queue[++bot] = p->val ; 
                trace[p->val] = u ; 
            }
            p = p->next ; 
        }       
    }
    delete[] queue ; 
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
    breadthFirstSearch(graph, isVisted, s, f, trace, n) ; 

    delete[] isVisted ; 
    delete[] trace ; 
    fi.close() ; 
    return 0 ; 
}