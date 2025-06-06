#include<iostream>
#include<algorithm>
#include<queue>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define F first
#define S second

using namespace std;
typedef pair<int, int> PII;
int n, m, k;
int like, ans;
priority_queue<int, vector<int>, greater<int>> pq;
PII beer[200001];


int main(void) {
	FAST_IO;

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int v, c;
		cin >> v >> c;
		beer[i] = make_pair(c, v);
	}
	sort(beer, beer + k);

	for (int i = 0; i < k; i++) {
		// n개를 마신 상태에서 선호도를 모두 채웠으면 정답!
		if (like >= m && pq.size() == n) break;

		PII cur = beer[i];
		//일단 n개까지는 모두 채워야 함!
		if (pq.size() < n) {
			pq.push(cur.S);
			like += cur.S;
			ans = max(ans, beer[i].F);
			continue;
		}
		if (pq.top() > cur.S) continue; //현재 선호도가 지금까지 고른 모든 n개의 선호도보다 작으면 pass
		like -= pq.top();
		pq.pop();
		like += cur.S;
		pq.push(cur.S);
		ans = max(ans, cur.F);
	}
	if (like < m) cout << -1;
	else cout << ans;

	return 0;
}