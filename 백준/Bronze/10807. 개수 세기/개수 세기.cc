#include<iostream>

using namespace std;

int n, x;
int cnt[201];


int main(void) {
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		int idx = num + 100;
		cnt[idx]++;
	}
	cin >> x;
	cout << cnt[x + 100];

	return 0;
}