#include<iostream>
#define Ref Node*
using namespace std;
struct Node {
	int value; 
	Node* next; 
};
Ref newNode(int value) {
	Ref p = new Node;
	p->value = value; 
	p->next = nullptr; 
	return p; 
}
void pushNode(Ref& head, int val, Ref &tail) {
	Ref p = newNode(val); 
	if (!head) {
		head = p;
		tail = p; 
	}
	else {
		p->next = head; 
		head = p; 
	}
}
void traverse(Ref head) {
	while (head) {
		cout << head->value << " "; 
		head = head->next; 
	}
	cout << endl; 
}
void swap(int& x, int& y) {
	int z = x; 
	x = y; 
	y = z; 
}
Ref partition(Ref head, Ref right, Ref &mark, int &m) {
	Ref prehead = newNode(0); 
	Ref i = head; 
	prehead->next = head; 
	while (i != right) {
		if (i->value < right->value) {
			++m; 
			prehead = prehead->next; 
			swap(prehead->value, i->value); 
		}
		i = i->next; 
	}
	//traverse(head);
	mark = prehead; 
	prehead = prehead->next; 
	swap(prehead->value, right->value); 

	return prehead->next; 
}
void quickSort(Ref head, Ref right, int l, int r) {
	if (l >= r) return; 
	Ref mark_L; 
	Ref mark_R; 
	int m = l; 
	mark_R = partition(head, right, mark_L, m);
	quickSort(head, mark_L, l , m - 1); 
	quickSort(mark_R, right, m + 1, r); 
}
int main() {
	int n; 
	cin >> n;
	Ref head = nullptr;
	Ref tail = nullptr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x; 
		pushNode(head, x, tail); 
	}
	quickSort(head, tail, 0, n-1);
	traverse(head); 

	return 0;
}