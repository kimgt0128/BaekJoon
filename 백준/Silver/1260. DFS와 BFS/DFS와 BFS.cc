#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

vector<vector<int>> grafh;

int n, k, s;
vector<int> ans;
bool visit[1001];

void bfs(int start) {

	queue<int> que;
	que.push(start);
	visit[start] = true;
	ans.push_back(start);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i = 0; i < grafh[cur].size(); i++) {
			int nxt = grafh[cur][i];
			if (visit[nxt]) continue;
			que.push(nxt);
			visit[nxt] = true;
			ans.push_back(nxt);
		}
	}
}

void dfs(int start) {

	stack<int> sta;
	sta.push(start);
	
	while (!sta.empty()) {
		int cur = sta.top();
		sta.pop();
		if (visit[cur]) continue;
		visit[cur] = true;
		ans.push_back(cur);

		for (int i = grafh[cur].size() - 1; i >= 0;  i--) {
			int nxt = grafh[cur][i];
			if (visit[nxt]) continue;
			sta.push(nxt);
		}
	}
}



int main(void) {

	FAST_IO;

	cin >> n >> k >> s;

	grafh.resize(n + 1);

	while (k--) {
		int u, v;
		cin >> u >> v;
		grafh[u].push_back(v);
		grafh[v].push_back(u);
	}
	for (int i = 1; i < n + 1; i++) sort(grafh[i].begin(), grafh[i].end());



	dfs(s);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << "\n";
	
	ans.clear();
	memset(visit, 0, sizeof(visit));
	bfs(s);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	
	return 0;
}