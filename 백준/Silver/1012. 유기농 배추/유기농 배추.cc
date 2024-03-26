#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M, N, K;

//글로벌 배열 선언 q: queue, g: grafh, c: check
queue<pair<int, int>> q;
vector<vector<int>> g;
vector<vector<int>> c;

//x, y좌표를 입력받아 상하좌우를 탐색하는 Bfs함수
void Bfs(int x, int y) {
	int dx, dy, nx, ny; //d: direction, n: next direction

	//x, y의 상하좌우배열
	int arr_x[4] = { 1, -1, 0, 0 };
	int arr_y[4] = { 0, 0, 1, -1 };

	q.push({ x, y });
	c[x][y] = 1;

	while (!q.empty()) {
		dx = q.front().first;
		dy = q.front().second;
		q.pop();
		//상하좌우를 각각 구한 뒤에 범위 안에 있고(조건1) 배추가 방문체크가 안되어있음과 동시에 배추가 심어져 있으면(조건2) q에 추가하기
		for (int i = 0; i < 4; i++) {
			nx = dx + arr_x[i];
			ny = dy + arr_y[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (c[nx][ny] == false && g[nx][ny] == true) {
					q.push({ nx, ny });
					c[nx][ny] = 1;
				}
			}
		}
	}
}

void GetCount() {
	int count = 0;
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size();  j++) {
			if (g[i][j] == true && c[i][j] == false) {
				Bfs(i, j);
				count += 1;
			}

		}
	}
	cout << count;
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> M >> N >> K;
		g.resize(M);
		c.resize(M);
		for (int i = 0; i < M; i++) {
			g[i] = vector<int>(N, 0);
			c[i] = vector<int>(N, 0);
		}

		while (K--) {
			int a, b;
			cin >> a >> b;
			g[a][b] = 1;
		}
		GetCount();
		cout << "\n";

		g.clear();
		c.clear();
	}



	return 0;
}