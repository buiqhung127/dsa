#include<iostream>
using namespace std;
void swap(int &a, int &b) {
	int c = a; 
	a = b; 
	b = c;
}
void recursiveBubbleSort(int* a, int left, int right) {
	cout << left << " " << right << endl;
	if (right - left + 1 > 2) {
		int mid = (left + right) / 2;
		recursiveBubbleSort(a, mid, right); 
		recursiveBubbleSort(a, left, mid); 
	}
	else if (right == left + 1 ) {
		cout << "Check : " <<left <<" "<<right <<endl ;  
		if (a[left] > a[right]) 
			swap(a[left], a[right]); 
	}
}
int main() {
	int n, a[100];
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	 
	for (int i = 0 ; i < n-1 ; i++) {
		recursiveBubbleSort(a, i, n-1);
		cout << "------\n" ; 
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	// 10
	// 6 7 1 2 0 5 3 9 4 8

	return 0; 
}