#include<iostream>
#include<algorithm>
#define F first
#define S second

using namespace std;

int N, ans;
pair<int, int> task[100000];

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> task[i].S >> task[i].F;
	sort(task, task + N);
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (task[i].S >= t) {
			ans++;
			t = task[i].F;
		}
	}
	cout << ans;
	return 0;
}