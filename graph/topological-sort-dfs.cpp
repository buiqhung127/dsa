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
void topologicalSort(adjacentList* graph, int* isVisited, int n,int *inorderList, int u,  bool &isValid, int &k){
    cout << u <<endl ; 
    if (isValid == false)
        return ; 
    vertex *p = graph[u].head ; 
    while (p){ 
        if (isVisited[p->val] == -1){
            isVisited[p->val] = 1 ; 
            topologicalSort(graph, isVisited, n, inorderList, p->val, isValid, k) ; 
        } else 
        if (isVisited[p->val] == 1){ // there is an cycle
            isValid = false ; 
            return ; 
        }
        p = p->next ; 
    }
    inorderList[k++] = u ; 
    isVisited[u] = 2 ; 
}
int main(){
    fstream fi("input-topo-sort.txt", ios::in) ;
    int n, m, d = 0, k = 0; 
    bool isValid = true ; 
    fi >> n >> m; 
    int * isVisited = new int[n] ;
    int * queue = new int[n] ; 
    bool * degPos0 = new bool[n] ; 
    int * inorderList = new int[n] ; 
    adjacentList* graph = new adjacentList[n] ; 
    for (int i = 0 ; i < n ; i++){
        graph[i].head = nullptr ; 
        isVisited[i] = -1 ; 
        degPos0[i] = true ; 
    }
    for (int i = 0 ; i < m ; i++){
        int x, y ; 
        fi >> x >> y ; // x direct to y
        pushNode(graph, x, y) ; // direct to list 
    }

    for (int i = 0 ; i < n ; i++){
        vertex *p = graph[i].head ; 
        while (p){
            degPos0[p->val] = false ; 
            p = p->next ; 
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (degPos0[i])
            queue[d++] = i ; 
    }
    
    for (int i = 0 ; i < d ; i++)
        topologicalSort(graph, isVisited, n, inorderList, queue[i], isValid, k) ; 
    if (!isValid){
        cout <<"This graph can't be topological sorted !\n" ;  
    }
    else { 
        for (int i = 0 ; i < k ; i ++)
            cout << inorderList[i] <<" " ; 
    }
    

    delete[] isVisited ; 
    delete[] inorderList ; 
    fi.close() ; 
    return 0 ; 
}