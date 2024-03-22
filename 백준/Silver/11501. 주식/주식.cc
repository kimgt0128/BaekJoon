#include<iostream>
#include<vector>

using namespace std;

long long day[1000000];
long long N, m, invest, ans;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		m = invest = ans = 0;
		for (int i = 0; i < N; i++) cin >> day[i];
		for (int i = N - 1; i >= 0; i--) {
			if (m < day[i]) m = day[i];
			else {
				ans += m - day[i];
			}
		}
		cout << ans << "\n";
	}
}