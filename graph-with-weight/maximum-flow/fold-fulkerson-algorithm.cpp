#include<iostream>
#include<fstream>
#define maxN 5000
#define minRes 10e9 + 1
#define ll long long
using namespace std ; 
bool bfs(int n, ll **r, ll **c, int *trace, int s, int t){
    int top = -1, back = 0;
    int *queue = new int[n];
    bool *isVisited = new bool[n] ;  


    for (int i = 0 ; i < n ; i++)
        isVisited[i] = false ; 
    queue[back++] = s ;  
    isVisited[s] = true ; 
    while (++top < back){
        for (int i = 0 ; i < n ; i++)
            if (r[queue[top]][i] > 0 && !isVisited[i]){
                isVisited[i] = true ; 
                queue[back++] = i ;
                trace[i] = queue[top] ; 
                if (i == t) {
                    delete[] isVisited ; 
                    delete[] queue; 
                    return true; 
                }
            }
    }  
    delete[] isVisited ; 
    delete[] queue; 
    return false ; 
    

}
ll maximizeFlow(int n, ll **r, ll **c, int s, int t){
    int *trace = new int[n]; 
    ll maximum_flow = 0 ; 
    trace[s] = -1 ; 
    while (bfs(n,r,c, trace, s, t)){
        int i = t ; 
        ll min = minRes ;  
        while (trace[i] != -1){
            min = (r[trace[i]][i] < min) ? r[trace[i]][i] : min  ; 
            i = trace[i] ; 
        }
        i = t ; 
        while (trace[i] != -1){
            r[trace[i]][i] -= min ; 
            r[i][trace[i]] += min ; 
            i = trace[i] ; 
        }
        maximum_flow += min ; 
    }

    delete[] trace ; 
    return maximum_flow ; 
}
int main(){
    //fstream fi("input.txt", ios::in) ; 
    int n, m, s, t; // source is 1, sink is n 
    //fi >>n >> m >> s >> t ; 
    cin >> n >> m >> s >> t ;
    s-- ; 
    t-- ;
    ll **c = new ll*[n]; 
    ll **r = new ll*[n];
    for (int i = 0 ; i < n ; i++){
        c[i] = new ll[n] ;
        r[i] = new ll[n] ;  
    }
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            r[i][j] = 0 ; 
    for (int i = 0 ; i < m ; i++){
        int x,y ; 
        cin >> x >> y ;
        x -= 1 ; 
        y -= 1 ;   
        cin >> c[x][y] ; 
        r[x][y] = c[x][y];  
    }
    cout << maximizeFlow(n, r, c, s,t ) ; 


    for (int i = 0 ; i < n ; i++){
        delete[] c[i] ; 
        delete[] r[i] ;   
    }
    delete[] c ; 
    delete[] r ; 
    //fi.close() ; 
    return 0 ; 
}