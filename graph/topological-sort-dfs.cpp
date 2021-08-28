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
    // isVisited has 3 status, isVisited = -1 mean we haven't visited this vertex before
    // isVisited = 1 when we have visited it but we haven't visit all the vertices that are pointed by this vertex.
    // isVisited = 2 when we have visited it and all the vertices that this vertex points to . 
    if (isValid == false) // if the graph have a cycle, out the function. 
        return ; 
    vertex *p = graph[u].head ; 
    while (p){ // travel all the node being point by this vertex
        if (isVisited[p->val] == -1){ // if the vertex is not visited
            isVisited[p->val] = 1 ; // mark it as not-fully-visited vertex then visit this vertex by recursion. 
            topologicalSort(graph, isVisited, n, inorderList, p->val, isValid, k) ; 
        } else 
        if (isVisited[p->val] == 1){ // there is an cycle (a not fully visited node connect to the same status one)
            isValid = false ; // mark it as not valid graph and return
            return ; 
        }
        p = p->next ; 
    }
    inorderList[k++] = u ; // this vertex is now fully visited
    isVisited[u] = 2 ; // mark this vertex to the fully visited status. 
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