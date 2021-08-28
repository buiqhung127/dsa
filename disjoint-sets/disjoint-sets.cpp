#include<iostream>
using namespace std ; 
int find(int par[], int p){
    if (par[p] < 0) // p dont have any parent
        return p ;  // par of the top of the tree hold the number of element
    par[p] = find(par, par[p]) ; // path compression technique, skip connection
    // just visit straight to the top 
    return par[p] ; 
}
void merge(int par[], int i, int j){
    i = find(par, i); // find the top of the set holding i 
    j = find(par, j); // find the top of the set holding j 
    if (i == j) return ; // same set then do nothing
    if (par[i] < par[j]){ // the j set is bigger so we just swap it to 
    // always merge to i's set
        int c = i ; 
        i = j ; 
        j = i ; 
    }
    // always merge to i 
    par[i] += par[j] ; // the size of the i's tree is updated
    par[j] = i ; // merge j to i 
}

int main(){
    int n; 
    cin >> n ; 
    int *parent = new int[n]; 
    for (int i = 0 ; i < n ; i++){
        parent[i] = -1 ; // if par[i] < 0, mean par[i] in the box i and 
        // -par[i] is the number element of par[i]
    }
    while (true){
        int cmd ; 
        cout << "Task ?\n>>" ; 
        cin >> cmd ; 
        if (cmd == 1){
            int x, y ; 
            cin >> x  >> y;
            merge(parent, x, y) ;  
        } else if (cmd == 2){
            int x ; 
            cin >> x ; 
            cout << find(parent, x) ; 
        }
    }
    delete[] parent ; 
    return 0 ; 
}