#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

tuple<int, int, int> edge[100001];
vector<int> par(10000, -1);
int N, e, v;

int Find(int x) {
	return par[x] < 0 ? x : par[x] = Find(par[x]);
}

bool is_dif(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 0;
	if (par[x] == par[y]) par[x]--;
	if (par[x] < par[y]) par[x] = y;
	else par[y] = x;
	return 1;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for (int i = 1; i <= N; i++) par[i] = i;

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}
	sort(edge, edge + e);

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if(!is_dif(a, b)) continue;
		cnt++;
		ans += cost;
		if (cnt == v - 1) break;
	}
	cout << ans;
    return 0;
}
