#include<iostream>
#include<vector>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int k, d, ans, depth;
vector<long long> decNum;
vector<long long> cur;
void backTracking(int n, int m) {
	if (n == depth) {
		long long num = 0;
		for (int i = 0; i < cur.size(); i++) num = num * 10 + cur[i];
		decNum.push_back(num);
		return;
	}
	for (int i = m-1; i >= 0; i--) {
		cur.push_back(i);
		backTracking(n + 1, i);
		cur.pop_back();
	}
}

int main(void) {
	FAST_IO;
	cin >> k;

	for (depth = 1; depth < 11; depth++) {
		for (int i = 0; i < 10; i++) {
			cur.push_back(i);
			backTracking(1, i);
			cur.pop_back();
		}
	}

	sort(decNum.begin(), decNum.end());
	if (k >= decNum.size()) cout << -1;
	else cout << decNum[k];

	return 0;
}
