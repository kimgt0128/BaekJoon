#include<iostream>
#include<deque>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

deque<int> dq;
int n, m, cnt;
int arr[50];

int main(void) {
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) dq.push_back(i + 1);


	for (int i = 0; i < m; i++) {

		auto it = find(dq.begin(), dq.end(), arr[i]);
		int idx = distance(it, dq.begin());
	
		//중간과 마지막 중 작은 거리를 비교하여 추가 1 2 3 4 5 중 4를 제거할 때 1~4 거리, 4~5거리 중 최소
		cnt += min(distance(dq.begin(), it), distance(it, dq.end()));
		rotate(dq.begin(), it, dq.end());
		dq.pop_front();
	}
	cout << cnt;
	return 0;
}