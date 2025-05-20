#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, m;
int d[101][101];
int nxt[101][101]; //d[i][j]: i에서 출발했을 때, j노드의 다음 경로

void floyd() {
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				//d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				if (d[i][j] > d[i][k] + d[k][j]) {
					// 2를 거치는 경우가 최단경로일 경우, 2를 거쳐 가도록
					// 즉, k=2일 경우, (1 -> 5) => (1->2->5)로 업데이트 
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
}

void traverse(int start, int end) {
	vector<int> path;
	while (start != end) {
		path.push_back(start);
		start = nxt[start][end];
	}
	path.push_back(end);

	cout << path.size() << " ";
	for (int e : path) cout << e << " ";
	path.clear();
	cout << "\n";
}

int main(void) {
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < n + 1; i++) {
		fill(d[i], d[i] + n+1, INF);
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		d[u][v] = min(d[u][v], c);
		nxt[u][v] = v;
	}
	floyd();

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << (d[i][j] == INF ? 0 : d[i][j]) << " ";
		}
		cout << "\n";
	}
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (d[i][j] == INF || d[i][j] == 0) cout << 0 << '\n';
			else traverse(i, j);
		}
	}

	return 0;
}