#include<iostream>
#include<stack>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int K;
stack<int> sta;
int ans;

int main(void) {
	FAST_IO;

	cin >> K;
	while (K--) {
		int n;
		cin >> n;
		if (n == 0) sta.pop();
		else sta.push(n);
	}

	while (!sta.empty()) {
		ans += sta.top();
		sta.pop();
	}
	cout << ans;
	return 0;
}