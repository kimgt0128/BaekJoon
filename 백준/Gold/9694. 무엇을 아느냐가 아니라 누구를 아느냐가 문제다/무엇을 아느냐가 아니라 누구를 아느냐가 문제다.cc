#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define F first
#define S second

typedef pair<int, int> PII;

vector<PII> g[21];
int dis[21];
int pre[21];
int N, M, T;
const int inf = 1e9 + 10;
vector<int> path;

void dijkstra(PII start) {
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	dis[start.S] = 0;
	pq.push(start);
	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();
		if (cur.F != dis[cur.S]) continue;
		for (PII nxt : g[cur.S]) {
			if (dis[nxt.S] <= dis[cur.S] + nxt.F) continue;
			dis[nxt.S] = dis[cur.S] + nxt.F;
			pq.push({ dis[nxt.S], nxt.S });
			// path check
			pre[nxt.S] = cur.S;
		}
	}
}

int main(void) {
	FAST_IO;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i < 21; i++) g[i].clear();
		fill(dis, dis + 21, inf);
		fill(pre, pre + 21, -1);
		path.clear();
		for (int i = 0; i < N; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			g[u].push_back({ c, v });
			g[v].push_back({ c, u });
		}
		dijkstra({ 0, 0 });
		int cur = M - 1;
		cout << "Case #" << t + 1 << ": ";
		if (dis[cur] == inf) cout << -1;
		else {
			while (cur != -1) {
				path.push_back(cur);
				cur = pre[cur];
			}
			while (!path.empty()) {
				cout << path.back() << " ";
				path.pop_back();
			}
		}
		cout << "\n";
	}
	return 0;
}

