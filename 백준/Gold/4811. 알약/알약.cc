#include<iostream>
#include<cstring>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

long long d[31][31];

long long dp(int a, int b) {
	if (a == 0) {
		d[a][b] = 1;
		return d[a][b];
	}
	if (b == 0) {
		if (d[a][b] != 0) return d[a][b];
		return d[a][b] = dp(a - 1, b + 1);
	}
	if (d[a][b] != 0) return d[a][b];
	return d[a][b] = dp(a-1, b+1) + dp(a, b-1);
}

int n;
int main(void) {
	FAST_IO;
	
	while (true) {
		cin >> n;
		if (!n) break;
		//memset(d, 0, sizeof(d));

		cout << dp(n, 0) << "\n";
	}
	return 0;
}