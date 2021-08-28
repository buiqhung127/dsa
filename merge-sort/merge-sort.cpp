#include<iostream>
#define MAX_VALUE 999999
using namespace std; 
void mergeSort(int* a, int l, int r) {
	if (l >= r) return; 
	int m = (l + r) / 2, j1 = 0, j2 = 0;
	int *left = new int[m - l + 2];
	int* right = new int[r - (m + 1) + 2]; 
	// divide and conquer, split the array into 2 subarray and then sort it
	mergeSort(a, l, m); 
	mergeSort(a, m+1, r);
	for (int i = l; i <= m; i++) 
		left[j1++] = a[i]; // put the value out to merge later
	left[j1] = MAX_VALUE; // create a the sentinel
	for (int i = m+1; i <= r; i++) 
		right[j2++] = a[i]; // put the value out to merge later
	right[j2] = MAX_VALUE; // create a sentinel
	j1 = 0;
	j2 = 0;
	for (int i = l; i <= r; i++)  // merge by putting the smaller value to array first, so the sentinel will mark the stop of subarrays
		if (left[j1] < right[j2]) 
			a[i] = left[j1++];
		else 
			a[i] = right[j2++];
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