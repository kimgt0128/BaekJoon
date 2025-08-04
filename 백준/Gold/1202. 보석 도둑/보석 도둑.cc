#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;


int n, k;
vector<pair<long, int>> items;
multiset<int> ms;
long long ans;


int main(void) {

	FAST_IO;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		long m, v;
		cin >> m >> v;
		items.push_back({ v,m });
	}

	for (int i = 0; i < k; i++) {
		int w;
		cin >> w;
		ms.insert(w);
	}

	sort(items.begin(), items.end(), greater<pair<int, int>>());

	for (int i = 0; i < n; i++) {
		auto bag_idx = ms.lower_bound(items[i].second);
		if (bag_idx == ms.end()) continue;
		ans += items[i].first;
		ms.erase(bag_idx);

	}
	cout << ans;

	return 0;
}