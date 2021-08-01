#include<iostream>
using namespace std; 

void heapify(int *a, int posRoot ,int n) {
	int maxPos = posRoot; 
	int l = 2 * posRoot + 1; 
	int r = 2 * posRoot + 2; 

	if (l < n && a[maxPos] > a[l])  
		maxPos = l; 
	if (r < n && a[maxPos] > a[r]) 
		maxPos = r;

	if (maxPos != posRoot) {
		int t = a[posRoot]; 
		a[posRoot] = a[maxPos]; 
		a[maxPos] = t; 
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl; 
		heapify(a, maxPos , n); 
	}

}


void heapSort(int *a, int n) {
	for (int i = n / 2  - 1; i >= 0; i--) {
		heapify(a, i, n); 
	}
	for (int i = n - 1; i > 0 ; i--) {
		swap(a[0], a[i]); 
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		heapify(a, 0, i); 
	}
	//for (int i = 0; i < n; i++)
	//	cout << a[i] << " "; 
}



int main() {
	int n, a[100]; 
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	heapSort(a, n); 


	return 0;
}



/*
Min heap sort 
0 1 2 3 4 5 
6 2 1 3 8 5 
1 2 6 3 8 5
1 2 5 3 8 6


6 2 5 3 8 1
2 3 5 6 8 1

8 3 5 6 2 1
3 8 5 6 2 1
3 6 5 8 2 1

8 6 5 3 2 1
5 6 8 3 2 1 
8 6 5 3 2 1 
6 8 5 3 2 1
8 6 5 3 2 1 

*/