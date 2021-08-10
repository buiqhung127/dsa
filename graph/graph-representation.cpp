#include<iostream>
using namespace std; 
bool isConnected(int** a, int n){
	int check = true ; 
	int* q = new int[n] ;
	for (int k = 0 ; k < n ; k++){
		if (a[k][k] != 0) continue ; 
		q[0] = k ; a[k][k] = 1 ;   
		int cnt = 1, i = 0; 
		while (i < cnt){
			int top = q[i++] ; 
			cout <<top <<" " ; 
			for (int j = 0 ; j < n ; j++)
				if (a[j][j] == 0 && a[top][j] == 1){
					q[cnt++] = j ; 
					a[j][j] = -1 ; 
				} 
		}
		if (cnt != n) check = false ; 
		cout <<endl  ; 
	}
	delete[] q ;
	return false ; 
}
int main() {
	int n, m;
	cin >> n >> m;
	int** adjacentMatrix = new int* [n];
	for (int i = 0 ; i < n ; i++) {
		adjacentMatrix[i] = new int[n] ; 
	}
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			adjacentMatrix[i][j] = 0 ;


	for (int i = 0; i < m; i++) {
		int x, y; 
		cin >> x >> y; 
		adjacentMatrix[x][y] = 1 ; 		
		adjacentMatrix[y][x] = 1 ; 
	}

	if (isConnected(adjacentMatrix, n))
		cout <<"Connected" ; 
	else 
		cout <<"Unconnected! "; 

	for (int i = 0 ; i < n ; i++) {
		delete[] adjacentMatrix[i] ;  
	}
	delete[] adjacentMatrix; 
}