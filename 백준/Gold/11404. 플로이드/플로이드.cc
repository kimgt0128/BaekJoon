#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f


using namespace std;

vector<vector<int>> graph;
vector<vector<int>> d;
int N, M;
int start, cnt;

int main(void) {
	cin >> N >> M;
	d = vector<vector<int>> (N + 1);

	for (int i = 1; i < N + 1; i++) {
		d[i] = vector<int>(N + 1, INF);
		d[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		d[u][v] = min(d[u][v], c);
	}

	for (int k = 1; k < N + 1; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (d[i][j] == INF) cout << 0;
			else cout << d[i][j];
			cout << " ";
		}
		cout << '\n';
	}
	return 0;

}
