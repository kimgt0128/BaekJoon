#include<iostream>

using namespace std;

int N, K, ans;
int coin[10];

int main(void) {
	cin >> N >> K;
	//input
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	//solve
	for(int i=N-1; i >= 0; i--) {
		int a = K / coin[i];
		ans += a;
		K -= coin[i] * a;
		if (K == 0)  break;
	}
	cout << ans;
	return 0;
}