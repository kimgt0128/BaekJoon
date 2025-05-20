#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

int n, m;
int d[101][101];

void floyd() {
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
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
	}
	floyd();

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << (d[i][j] == INF ? 0 : d[i][j]) << " ";
		}
		cout << "\n";
	}

	return 0;
}