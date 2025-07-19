#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int N; 
int ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> problems;

int main(void) {
	FAST_IO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int day, cnt;
		cin >> day >> cnt;
		problems.push_back({ day, cnt });
		
	}
	sort(problems.begin(), problems.end());

	for (auto p : problems) {
		int day = p.first;
		int cnt = p.second;

		if (pq.empty()) {
			pq.push({ cnt, day });
			continue;
		}
;
		if (pq.size() < day) pq.push({ cnt, day });
		else {
			if (cnt > pq.top().first) {
				pq.pop();
				pq.push({ cnt, day });
			}
		}
	}

	// 합 구하기
	while (!pq.empty()) ans += pq.top().first, pq.pop();

	cout << ans;
	return 0;

}