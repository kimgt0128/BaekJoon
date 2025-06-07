#include<iostream>
#include<queue>
#include<vector>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

vector<int> adj[1001];
int indegree[1001];
int ans[1001];
int n, m;

void TopologicalBfs() {
	queue<int> que;
	int sta = 0;
	for (int i = 1; i < n + 1; i++) {
		if (!indegree[i]) {
			ans[i] = 1;
			que.push(i);
		}
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int nxt : adj[cur]) {
			indegree[nxt]--;
			if (!indegree[nxt]) {
				ans[nxt] = ans[cur] + 1;
				que.push(nxt);
			}
		}
	}
}

int main(void) {
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	TopologicalBfs();


	for (int i = 1; i < n + 1; i++)  cout << ans[i] << " ";
	
	return 0;
}