#include<iostream>
using namespace std; 
void swap(int &a, int &b){
	int c = a; 
	a = b; 
	b = c; 
}
int partion(int* a, int l, int r) {
	int j = r; 
	for (int i = r ; i > l ; i--)
		if (a[i] < a[l]) 
			swap(a[j--], a[i]); 
	swap(a[l], a[j]); 
	for (int i = 0; i < 9; i++)
		cout << a[i] << " "; 
	cout << endl; 
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