#include<iostream>
#include<algorithm>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, ans, sum;
int cards[100000];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	FAST_IO;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		pq.push(c);
	}

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		sum = a + b;
		pq.push(sum);
		ans += sum;
	}
	cout << ans;
}