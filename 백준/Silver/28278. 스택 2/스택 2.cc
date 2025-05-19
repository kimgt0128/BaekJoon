#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define MAX 1000000

using namespace std;

int sta[MAX];
int pos = 0;

bool empty() {
	return pos == 0 ? 1 : 0;
}
void push(int x) {
	sta[pos++] = x;
}

int pop() {
	if (pos == 0) return -1;
	return sta[(pos--) - 1];
}


int top() {
	if (pos == 0) return -1;
	return sta[pos - 1];
}

int size() {
	return pos;
}


int main(void) {
	FAST_IO;

	int N;
	cin >> N;
	
	while (N--) {
		int order;
		cin >> order;
		if (order == 1) {
			int dat;
			cin >> dat;
			push(dat);
		}
		else if (order == 2) cout << pop() << "\n";
		else if (order == 3) cout << size() << "\n";
		else if (order == 4) cout << empty() << "\n";
		else cout << top() << "\n";
	}
	return 0;
}