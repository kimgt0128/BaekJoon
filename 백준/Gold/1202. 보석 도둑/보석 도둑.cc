#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;


int n, k;
vector<pair<int, long long>> items;
vector<int> bags;
priority_queue<long long> pq;
long long ans;

int main(void) {
	FAST_IO;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		long long m, v;
		cin >> m >> v;
		items.push_back({ m, v });
	}
	for (int i = 0; i < k; i++) {
		int w;
		cin >> w;
		bags.push_back(w);
	}

	sort(items.begin(), items.end());
	sort(bags.begin(), bags.end());

	int tmp = 0;
	for (int i = 0; i < k; i++) {
		int cur_weight = bags[i];
		
		while (tmp < n && items[tmp].first <= cur_weight) {
			pq.push(items[tmp].second);
			tmp++;
		}
		if (!pq.empty()) ans += pq.top(), pq.pop();

	}

	cout << ans;
	return 0;
}
