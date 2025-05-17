#include<stack>
#include<iostream>
using namespace std;

int main(void) {
	int n;
	stack<int> sta;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		while (!sta.empty() && sta.top() <= cur) sta.pop();
		sta.push(cur);
	}

	cout << sta.size();


}