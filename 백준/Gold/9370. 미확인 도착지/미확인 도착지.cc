#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define F first
#define S second
#define INF 0xffffff
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;
typedef pair<int, int> PII;

int n, m, t, T, s, g, h;
vector<vector<PII>> adj; // 인접 리스트 방식
int dist_s[2001];
int dist_g[2001];
int dist_h[2001];
vector<int> dest;
int w;


void dijkstra(int start, int dist[]) {
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();
		if (cur.F != dist[cur.S]) continue;
		for (PII nxt : adj[cur.S]) {
			if (dist[nxt.S] <= dist[cur.S] + nxt.F) continue;
			dist[nxt.S] = dist[cur.S] + nxt.F;
			pq.push({ dist[nxt.S], nxt.S });
		}
	}
}

void solve() {
	vector<int> ans;
	fill(dist_s, dist_s + n + 1, INF);
	fill(dist_g, dist_g + n + 1, INF);
	fill(dist_h, dist_h + n + 1, INF);
	dijkstra(s, dist_s);
	dijkstra(g, dist_g);
	dijkstra(h, dist_h);
	for (int e : dest) {
		if (dist_s[e] == dist_s[g] + w + dist_h[e] || dist_s[e] == dist_s[h] + w + dist_g[e]) ans.push_back(e);
	}
	sort(ans.begin(), ans.end());
	for (int e : ans) cout << e << " ";
	cout << '\n';
	ans.clear();
	dest.clear();
}

int main(void) {
	FAST_IO;
	
	cin >> T;
	
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		adj = vector<vector<PII>>(n+1);

		while (m--) {
			int a, b, cost;
			cin >> a >> b >> cost;
			adj[a].push_back({ cost, b });
			adj[b].push_back({ cost, a });
			if (a == g && b == h || a == h && b == g) w = cost;
		}
		while (t--) {
			int x;
			cin >> x;
			dest.push_back(x);
		}
		solve();
	}
	return 0;
}