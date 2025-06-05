#include<iostream>
#include<queue>
#include<vector>
#define IN(X) (X > 0 && X <= N)
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

vector<vector<int>> g;
int cnt[300001];
bool check[300001];
int d[2] = { 1, -1 };

int N, M, S, E;

int Bfs(int start) {
	queue<int> que;
	que.push(start);
	check[start] = true;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == E) return cnt[cur];
		
		// nxt가 0이면 방문 안함! and 첫 방문이 무조건 최초 방문 보장!
		for (int i = 0; i < 2; i++) {
			int nxt = cur + d[i];
			if (!check[nxt] && IN(nxt)) {
				check[nxt] = true;
				que.push(nxt);
				cnt[nxt] = cnt[cur] + 1;
			}
		}
		if (g[cur].size() != 0) {
			for (int nxt : g[cur]) {
			
				if (!check[nxt] && IN(nxt)) {
					check[nxt] = true;
					que.push(nxt);
					cnt[nxt] = cnt[cur] + 1;
				}
			}
		}
	
	}
}


int main(void) {
	FAST_IO;

	cin >> N >> M >> S  >> E;

	g.resize(N+1);

	while (M--) {
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << Bfs(S);

	return 0;
}