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
bool isEmpty(adjacentList* graph, int u){
    if (!graph[u].head)
        return true ; 
    else 
        return false ; 
}
void deleteVertex(adjacentList* graph, int u, int v){
    vertex *p = graph[u].head ;
    if (!p) return ; 
    if (p->val == v){
        graph[u].head = p->next ;  
        delete p ; 
    } 
    else 
    while (p->next){
        if (p->next->val == v){
            vertex* t = p->next ; 
            p->next = p->next->next ; 
            delete t ; 
            return ; 
        }
        p = p->next ; 
    }
}
int topologicalSort(adjacentList* graph, int n,int *inorderList){
    int * queue = new int[n] ;  
    bool * isVisited = new bool[n] ; 
    int d = 0, front = 0, back = -1; 
    // initialize 
    for (int i = 0 ; i < n ; i++){ // init the queue by the vertices that are not directed to another vertices
        if (isEmpty(graph, i)){
            queue[++back] = i ;
            isVisited[i] = true ; // mark this as a visited vertex
        } 
    }
    while (front <= back){ // while the queue is not empty
        int top = queue[front++] ; 
        inorderList[d++] = top ; // push the vertex which is the front of the queue to the order-saving array
        for (int i = 0 ; i < n ; i++){
            deleteVertex(graph, i, top) ; // delete all the edge that comes to this vertex 
            if (!isVisited[i] && isEmpty(graph,i)){ 
            // after deleting that edge, push the remain vertex to the queue if 
            // it is not directed to another vertices
                queue[++back] = i ; 
                isVisited[i] = true ; 
            }
        }
    }

    for (int i = 0 ; i < n ; i++)
        if (!isEmpty(graph,i))
            return -1 ; 

    return d ; 
    delete[] isVisited ; 
    delete[] queue ; 

}
int main(){
    fstream fi("input-topo-sort.txt", ios::in) ;
    int n, m; 
    fi >> n >> m; 
    bool * isVisited = new bool[n] ; 
    int * inorderList = new int[n] ; 
    adjacentList* graph = new adjacentList[n] ; 
    for (int i = 0 ; i < n ; i++){
        graph[i].head = nullptr ; 
        isVisited[i] = false ; 
    }
    for (int i = 0 ; i < m ; i++){
        int x, y ; 
        fi >> x >> y ; // x direct to y
        pushNode(graph, x, y) ; // direct to list 
    }
    int d = topologicalSort(graph, n, inorderList) ; 
    if (d == -1){
        cout << "This graph is not valid for topological sorting.\n" ; 
    } 
    else {
        cout << d <<endl; 
        for (int i = d - 1 ; i >= 0 ; i--)
            cout <<inorderList[i] <<" " ;
    }

    delete[] isVisited ; 
    delete[] inorderList ; 
    fi.close() ; 
    return 0 ; 
}