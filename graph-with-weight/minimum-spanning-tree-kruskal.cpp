#include<iostream>
#include<fstream>
using namespace std ;
struct edge{
    int vertex_1 ; 
    int vertex_2 ;
    int length ; 
} ; 
void swap(edge &a, edge &b){
    edge c = a ; 
    a = b ; 
    b = c ; 
}
void quickSort(edge *edges, int l, int r){
    int mid = edges[(l+r)/2].length ;
    int i = l ; 
    int j = r ; 
    while (i <= j){
        while (edges[i].length < mid) i++ ; 
        while (edges[j].length > mid) j-- ; 
        if (i <= j){
            swap(edges[i], edges[j]) ; 
            i++ ; 
            j-- ; 
        }
    } 
    if (l < j)
        quickSort(edges, l, j) ; 
    if (i < r)
        quickSort(edges, i, r) ; 
}
int main(){ 
    fstream fi("input.txt",ios::in) ; 
    int n, m, totalWeight = 0;
    fi >> n >> m ; 
    int *region = new int[n+1] ;
    for (int i = 0 ; i <= n ; i++)
        region[i] = -1 ;              
    edge * edges = new edge[m] ; 
    bool * tree = new bool[m] ; 
    for (int i = 0 ; i < m ; i++){
        int l, v1, v2; 
        fi >> l >> v1 >> v2  ; 
        edges[i].length = l ; 
        edges[i].vertex_1 = v1 ;
        edges[i].vertex_2 = v2 ;
        tree[i] = false ; 
    }
    quickSort(edges, 0, m - 1) ; 
   // for (int i = 0 ; i < m ; i++)
    //   cout <<edges[i].length<<endl ; 
    for (int i = 0 ; i < m ; i++){
        if (region[edges[i].vertex_1] == -1 && region[edges[i].vertex_2] == -1) {
            region[edges[i].vertex_1] = region[edges[i].vertex_2] =  edges[i].vertex_1 ; 
        }
        else if (region[edges[i].vertex_1] == -1 && region[edges[i].vertex_2] != -1)
            region[edges[i].vertex_1] = region[edges[i].vertex_2] ; 
        else if (region[edges[i].vertex_2] == -1 && region[edges[i].vertex_1] != -1)
            region[edges[i].vertex_2] = region[edges[i].vertex_1] ; 
        else if (region[edges[i].vertex_1] == region[edges[i].vertex_2])
            continue ; 
        else if (region[edges[i].vertex_1] != region[edges[i].vertex_2]){
            int unity = region[edges[i].vertex_1] ;
            int rein  = region[edges[i].vertex_2] ; 
            for (int j = 0 ; j <= n ; j++)
                if (region[j] == rein)
                    region[j] =  unity ;  
        }
        totalWeight += edges[i].length ; 
        tree[i] = true ; 

    }
    cout << totalWeight <<endl; 
    for (int i = 0 ; i < m ; i++)
        if (tree[i]){
            cout <<edges[i].vertex_1 <<" " <<edges[i].vertex_2 <<endl; 
        }
    delete[] region ;
    delete[] edges ;  
    delete[] tree ; 
    fi.close() ; 
    return 0 ; 
}