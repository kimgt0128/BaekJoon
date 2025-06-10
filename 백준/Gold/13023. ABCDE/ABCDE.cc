#include<iostream>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;
bool visit[2000];
vector<vector<int>> g;
int n, m;
bool is_possible;

bool back_tracking(int depth, int cur) {
	if (depth == 4) return true;

	for (int nxt : g[cur]) {
		if (!visit[nxt]) {
			visit[nxt] = true;
			if (back_tracking(depth + 1, nxt)) return true;
			visit[nxt] = false;
		}
	}
	return false;
}

int main(void) {
	FAST_IO;

	cin >> n >> m;
	g.resize(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		// 양방향 그래프
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			if (back_tracking(0, i)) is_possible = true;
			visit[i] = false;
		}
	}

	cout << is_possible;
	return 0;




}