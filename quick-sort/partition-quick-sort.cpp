#include<iostream>
using namespace std; 
void swap(int &a, int &b){
	int c = a; 
	a = b; 
	b = c; 
}
int partion(int* a, int l, int r) {
	int j = l; 
	for (int i = l ; i < r ; i++)
		if (a[i] < a[r]) 
			swap(a[j++], a[i]); 
	swap(a[r], a[j]); 
	return j; 
}
void quickSort(int *a, int l, int r) {
	if (l >= r) return; 
	int m = partion(a, l, r); 
	quickSort(a, l, m - 1); 
	quickSort(a, m + 1, r); 
}
int main() {
	int n, a[100]; 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	quickSort(a, 0, n - 1); 
	for (int i = 0; i < n; i++)
		cout << a[i] <<" " ;
	cout << endl; 


	return 0; 
}