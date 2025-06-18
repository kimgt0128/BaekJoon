#include<iostream>
#include<queue>
#include<algorithm>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define F first
#define S second
#define INF 0x7ffffff

using namespace std;
typedef pair<int, int> PII;

int n, m;
priority_queue<PII, vector<PII>, greater<PII>> pq;
vector<PII> g[1001];
int dist[1001];
int pre[1001];
bool visit[1001];
vector<PII> path;


void dijkstra(int start) {
	pq.push({ 0, start }); // 시작 정점 = 0
	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();

		if (dist[cur.S] < cur.F) continue;

		for (PII nxt : g[cur.S]) {
			if (dist[nxt.S] > dist[cur.S] + nxt.F) {
				dist[nxt.S] = dist[cur.S] + nxt.F;
				pq.push({ dist[nxt.S], nxt.S });
				pre[nxt.S] = cur.S;
			}
		}
	}


}

void traverse(int node) {

	int cur = node;
	while (cur != 0 && !visit[cur]) {
		visit[cur] = true;
		if (pre[cur]) path.push_back({ pre[cur], cur });
		cur = pre[cur];
	}
}

int main(void) {
	FAST_IO;

	cin >> n >> m;

	fill(dist, dist + n+1, INF);
	dist[1] = 0;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({ c, v });
		g[v].push_back({ c, u });
	}

	dijkstra(1);
	
	for (int i = 1; i < n + 1; i++) {
		traverse(i);
	}
	cout << path.size() << "\n";
	for (auto e : path) {
		cout << e.F << " " << e.S << "\n";
	}

	return 0;

}