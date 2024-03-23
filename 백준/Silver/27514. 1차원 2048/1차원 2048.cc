#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;


int cnt[63];
LL val, ans;
int N;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		if (val != 0) {
			val = log2(val);
			cnt[val]++;
		}
	}
	for (int i = 0; i < 62; i++) cnt[i + 1] += cnt[i] / 2;

	for (int i = 62; i >= 0; i--) {
		if (cnt[i]) {
			ans = (LL)pow(2, i);
			break;
		}
	}
	cout << ans;
	return 0;
}
