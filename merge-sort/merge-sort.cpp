#include<iostream>
using namespace std; 
void mergeSort(int* a, int l, int r) {
	if (l >= r) return; 

	int m = (l + r) / 2, j1 = 0, j2 = 0;
	int *left = new int[m - l + 2];
	int* right = new int[r - (m + 1) + 2]; 

	mergeSort(a, l, m); 
	mergeSort(a, m+1, r);


	for (int i = l; i <= m; i++) 
		left[j1++] = a[i]; 
	left[j1] = -1; 
	for (int i = m+1; i <= r; i++) 
		right[j2++] = a[i];
	right[j2] = -1; 
	
	j1 = 0;
	j2 = 0;
	for (int i = l; i <= r; i++) {
		if (left[j1] > right[j2]) 
			a[i] = left[j1++];
		else 
			a[i] = right[j2++];
	}
	delete[] left; 
	delete[] right;  
}



int main() {
	int n, a[100];
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	mergeSort(a, 0, n - 1); 
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";  


	return 0; 
}