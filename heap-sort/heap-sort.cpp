#include<iostream>
using namespace std; 
void heapify(int *a, int posRoot ,int n) {
	int maxPos = posRoot; // all child must smaller than parent 
	int l = 2 * posRoot + 1; // left child 
	int r = 2 * posRoot + 2; // right child

	// get the maximum to make it to be the new parent
	if (l < n && a[maxPos] < a[l])  
		maxPos = l; 
	if (r < n && a[maxPos] < a[r]) 
		maxPos = r;

	if (maxPos != posRoot) { // conflict to the properties, swap the weaker to be child and the stronger to be parent
		int t = a[posRoot]; 
		a[posRoot] = a[maxPos]; 
		a[maxPos] = t; 
		heapify(a, maxPos , n); // maybe the weaker is smaller in the next subtree so we must examine and adjust it
	}

}
void heapSort(int *a, int n) {
	for (int i = n / 2  - 1; i >= 0; i--) { // elements that has position >= n/2 don't have any child ( (n/2) * 2 + 1 = n + 1, n + 1 > n - 1 )
		heapify(a, i, n); // build the heap tree from the parent of leaves, solve the heap properties  
		//from the smaller subtree to the bigger one
	}
	for (int i = n - 1; i > 0 ; i--) {
		swap(a[0], a[i]); // get the maximimum then put it into the true position for sorting results
		//for (int i = 0; i < n; i++)
		//	cout << a[i] << " ";
		//cout << endl;
		heapify(a, 0, i); // we have just get the maximum and replace it by a leaf, need to heapify it again with a limit
		// to preserve the true order
	}
}
int main() {
	int n, a[100]; 
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	heapSort(a, n); 
	for (int i = 0 ; i < n ; i++)
		cout <<a[i] <<" " ; 

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