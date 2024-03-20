#include<iostream>
#include<algorithm>

using namespace std;
int N, sum, ans;
int p[1001];
int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	sort(p, p + N + 1);

	//solve
	for (int i = 1; i <= N; i++) {
		sum += p[i];
		ans += sum;
	}
	cout << ans;
	return 0;
}
