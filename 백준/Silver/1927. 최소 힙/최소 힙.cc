#include<iostream>

using namespace std;

int heap[100001];
int siz;

void push(int x) {
	heap[++siz] = x;
	int idx = siz;
	while (idx != 1) {
		int parent = idx / 2;
		if (heap[parent] <= heap[idx]) break;
		swap(heap[parent], heap[idx]);
		idx = parent;
	}
}

int top() {
	return heap[1];
}

void pop() {
	heap[1] = heap[siz--];
	int idx = 1;
	while (2 * idx <= siz) {
		int lc = 2 * idx, rc = 2 * idx + 1;
		int minChild = lc;
		if (rc <= siz && heap[rc] < heap[lc]) minChild = rc;
		if (heap[idx] <= heap[minChild]) break;
		swap(heap[idx], heap[minChild]);
		idx = minChild;
	}
}

void test() {
	for (int i = 0; i <= siz; i++) cout << heap[i] << " ";
	cout << "\n";
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		int order;
		cin >> order;
		if (order) push(order);
		else {
			if (!siz) cout << 0 << "\n";
			else {
				cout << top() << "\n";
				pop();
			}
		}
	}
	return 0;
}