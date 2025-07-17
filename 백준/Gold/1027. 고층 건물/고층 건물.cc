#include<iostream>
#include<cmath>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
int height[50];
int ans[50];


void solve(int cur) {
	double pre = numeric_limits<double>::lowest();
	int cnt = 0;

	for (int i = cur + 1; i < n; i++) {
		double tmp = (double)(height[i] - height[cur]) / (i - cur); // 기울기 구하기

		if (tmp > pre) {
			pre = tmp;
			cnt++;
		}
	}

	pre = numeric_limits<double>::max(); // 최대 double 값
	for (int i = cur - 1; i >= 0; i--) {
		double tmp = (double)(height[cur] - height[i]) / (cur - i);
		if (tmp < pre) {
			pre = tmp;
			cnt++;
		}
	}
	ans[cur] = cnt;

}



int main(void) {

	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	for (int i = 0; i < n; i++) {
		solve(i);
	}
	int ret = -1;
	for (int i = 0; i < n; i++) {
		ret = max(ret, ans[i]);

	}
	cout << ret;
}