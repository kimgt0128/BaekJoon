#include<iostream>
#include<algorithm>

using namespace std;

int N, ans;
int a[50], b[50];

int main(void) {
	cin >> N;
	for(int i=0; i<N; i++) cin >> a[i];
	for(int i=0; i<N; i++) cin >> b[i];
	sort(a, a + N);
	sort(b, b + N);
	for (int i = 0; i < N; i++) ans += a[i] * b[N - 1  - i];
	cout << ans;
	return 0;
}