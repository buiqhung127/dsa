#include<iostream>
#define maxN 13 
using namespace std; 

void createHashTable(int *a, int n, int *hashed) {
	for (int i = 0; i < n; i++) {
		int j = 0; 
		while (hashed[(a[i] + j * j) % maxN] != -1)
			j++; 
		hashed[(a[i] + j * j) % maxN] = a[i];
		for (int i = 0; i < maxN; i++)
			cout << hashed[i] << "\t";
		cout << endl; 
	}
}
int main() {
	int n, a[100], hashed[maxN]; 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 13; i++) {
		cout << i << "\t"; 
		hashed[i] = -1;
	}
	cout << endl; 

	createHashTable(a, n, hashed); 
	// 7
	// 4088 10 23 36 49 12 38


	return 0; 
}